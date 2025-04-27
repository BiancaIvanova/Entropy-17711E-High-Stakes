#include "arm-controller.h"
#include "pros/rtos.hpp"
#include <cmath>

double const SCALING_FACTOR = 10;
int const TIME_STEP = 20;

ArmController::ArmController(double kP, double kI, double kD,
                             pros::Motor& leftArmMotor, pros::Motor& rightArmMotor, pros::Rotation& rotationSensor)
    : pid(kP, kI, kD),
      leftArmMotor(leftArmMotor),
      rightArmMotor(rightArmMotor),
      rotationSensor(rotationSensor),
      controlTask([this] { controlLoop(); }) // Launch one task at construction
{
    rotationSensor.reset();
}

void ArmController::moveToPosition(double position, bool async, double maxSpeed) {
    targetPosition = position * 100.0;
    targetMaxSpeed = std::clamp(maxSpeed, 0.0, 1.0);
    moving = true; // Tell the control loop to start moving

    if (!async) {
        // Synchronous: block until movement is finished
        while (moving) {
            pros::delay(TIME_STEP);
        }
    }
}

void ArmController::controlLoop() {
    double const VELOCITY_THRESHOLD = 100.0;
    double tolerance = 250.0;

    while (true) {
        currentPosition = rotationSensor.get_position();

        if (moving) {
            double error = targetPosition - currentPosition;
            double velocity = pid.update(error, TIME_STEP);

            // Scale and clamp
            double voltage = velocity * SCALING_FACTOR * targetMaxSpeed;
            voltage = std::clamp(voltage, -12000.0 * targetMaxSpeed, 12000.0 * targetMaxSpeed);

            leftArmMotor.move_voltage(voltage);
            rightArmMotor.move_voltage(voltage);

            if (fabs(error) < tolerance &&
                fabs((leftArmMotor.get_actual_velocity() + rightArmMotor.get_actual_velocity()) / 2) < VELOCITY_THRESHOLD) {
                // Reached target
                leftArmMotor.move_velocity(0);
                rightArmMotor.move_velocity(0);
                moving = false;
            }
        } else {
            // If not moving, just maintain position
            leftArmMotor.move_velocity(0);
            rightArmMotor.move_velocity(0);
        }

        pros::delay(TIME_STEP);
    }
}

void ArmController::resetPosition(double newPosition) {
    currentPosition = newPosition;
    rotationSensor.reset_position();
    rotationSensor.set_position(newPosition);
}

double ArmController::getPosition() const {
    return rotationSensor.get_position() / 100.0;
}
