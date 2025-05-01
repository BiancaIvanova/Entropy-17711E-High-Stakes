#include "arm-controller.h"
#include "pros/rtos.hpp"

double const SCALING_FACTOR = 10;
int const TIME_STEP = 20;

ArmController::ArmController(double kP, double kI, double kD,
                             pros::Motor& leftArmMotor, pros::Motor& rightArmMotor, pros::Rotation& rotationSensor)
    : pid(kP, kI, kD),
      leftArmMotor(leftArmMotor),
      rightArmMotor(rightArmMotor),
      rotationSensor(rotationSensor) {}

void ArmController::moveToPosition(double position, int timeout, bool async, double maxSpeed) {
    if (async) {
        // Check if task already exists and is running
        if (moveTask != nullptr && moveTask->get_state() != pros::E_TASK_STATE_DELETED) {
            moveTask->remove();
            delete moveTask;
        }

        // Start a new task with the same pros::Task object
        moveTask = new pros::Task([=]() {
            this->moveToPositionTask(position, timeout, maxSpeed);
        });
    } else {
        moveToPositionTask(position, timeout, maxSpeed);
    }
}

void ArmController::moveToPositionTask(double position, int timeout, double maxSpeed) {
    targetPosition = position * 100.0;
    double const VELOCITY_THRESHOLD = 100.0;
    double tolerance = 250.0;

    maxSpeed = std::clamp(maxSpeed, 0.0, 1.0);

    int elapsed = 0;

    while ((fabs(currentPosition - targetPosition) > tolerance ||
           fabs((leftArmMotor.get_actual_velocity() + rightArmMotor.get_actual_velocity()) / 2) > VELOCITY_THRESHOLD)) {

        // Check if timeout expired (unless maxSpeed is 0, meaning manual voltage setting)
        if (maxSpeed > 0.0 && timeout > 0 && elapsed >= timeout) {
            break;
        }

        currentPosition = rotationSensor.get_position();
        double error = targetPosition - currentPosition;

        double velocity = pid.update(error, TIME_STEP);

        double voltage = velocity * SCALING_FACTOR * maxSpeed;
        voltage = std::clamp(voltage, -12000.0 * maxSpeed, 12000.0 * maxSpeed);

        leftArmMotor.move_voltage(voltage);
        rightArmMotor.move_voltage(voltage);

        pros::delay(TIME_STEP);
        elapsed += TIME_STEP;
    }

    // Stop the motors after reaching position or timeout
    leftArmMotor.move_velocity(0);
    rightArmMotor.move_velocity(0);
}

void ArmController::resetPosition(double newPosition) {
    currentPosition = newPosition * 100;
    rotationSensor.reset_position();
    rotationSensor.set_position(newPosition * 100);
}

double ArmController::getPosition() const {
    return rotationSensor.get_position() / 100.0;
}
