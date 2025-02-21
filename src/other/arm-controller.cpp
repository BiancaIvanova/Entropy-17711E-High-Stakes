#include "arm-controller.h"

ArmController::ArmController(double kP, double kI, double kD,
                             pros::Motor& leftArmMotor, pros::Motor& rightArmMotor, pros::Rotation& rotationSensor)
    : pid(kP, kI, kD),
      leftArmMotor(leftArmMotor),
      rightArmMotor(rightArmMotor),
      rotationSensor(rotationSensor) {}

void ArmController::moveToPosition(double position) {
    targetPosition = position * 10.0;
    double const VELOCITY_THRESHOLD = 100.0; // centidegrees a second
    double tolerance = 10.0; // 1 degree

    double meanVelocity = (leftArmMotor.get_actual_velocity() + rightArmMotor.get_actual_velocity()) / 2;

    while (fabs(currentPosition - targetPosition) > tolerance || fabs(meanVelocity) > VELOCITY_THRESHOLD) {
        currentPosition = rotationSensor.get_position();
        double error = targetPosition - currentPosition;

        // Calculate velocity using PID
        double velocity = pid.update(error, TIME_STEP);

        printf("Current Position: %f, Error: %f, Velocity: %f\n", currentPosition, error, velocity);

        leftArmMotor.move_voltage(velocity);
        rightArmMotor.move_voltage(velocity);

        pros::delay(TIME_STEP);
    }

    leftArmMotor.move_velocity(0);
    rightArmMotor.move_velocity(0);
}

void ArmController::resetPosition(double newPosition) {
    currentPosition = newPosition;
    rotationSensor.reset_position();
    rotationSensor.set_position(newPosition);
}
