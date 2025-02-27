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

      
void ArmController::moveToPosition(double position, bool async, double maxSpeed) {
    if (async) {
        // Check if task already exists and is running
        if (moveTask != nullptr && moveTask->get_state() != pros::E_TASK_STATE_DELETED) {
            moveTask->remove();
            delete moveTask;
        }

        // Start a new task with the same pros::Task object
        moveTask = new pros::Task([=]() {
            this->moveToPositionTask(position, maxSpeed);
        });
    } else {
        moveToPositionTask(position, maxSpeed);
    }
}

void ArmController::moveToPositionTask(double position, double maxSpeed) {
    targetPosition = position * 100.0;
    double const VELOCITY_THRESHOLD = 100.0;
    double tolerance = 250.0;

    // Ensure maxSpeed is within a valid range (0.0 to 1.0)
    maxSpeed = std::clamp(maxSpeed, 0.0, 1.0);

    while (fabs(currentPosition - targetPosition) > tolerance ||
           fabs((leftArmMotor.get_actual_velocity() + rightArmMotor.get_actual_velocity()) / 2) > VELOCITY_THRESHOLD) {

        currentPosition = rotationSensor.get_position();
        double error = targetPosition - currentPosition;

        double velocity = pid.update(error, TIME_STEP);

        // Scale the voltage by maxSpeed (0 to 1 range)
        double voltage = velocity * SCALING_FACTOR * maxSpeed;

        // Clamp the voltage based on maxSpeed
        voltage = std::clamp(voltage, -12000.0 * maxSpeed, 12000.0 * maxSpeed);

        printf("Current Position: %f, Error: %f, Voltage: %f, MaxSpeed: %f\n", currentPosition, error, voltage, maxSpeed);

        leftArmMotor.move_voltage(voltage);
        rightArmMotor.move_voltage(voltage);

        pros::delay(TIME_STEP);
    }

    // Stop the motors
    leftArmMotor.move_velocity(0);
    rightArmMotor.move_velocity(0);
}


void ArmController::resetPosition(double newPosition) {
    currentPosition = newPosition;
    rotationSensor.reset_position();
    rotationSensor.set_position(newPosition);
}

double ArmController::getPosition() const {
    return rotationSensor.get_position() / 100.0;
}
