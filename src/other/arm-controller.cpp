#include "arm-controller.h"

double const SCALING_FACTOR = 10;

ArmController::ArmController(double kP, double kI, double kD,
                             pros::Motor& leftArmMotor, pros::Motor& rightArmMotor, pros::Rotation& rotationSensor)
    : pid(kP, kI, kD),
      leftArmMotor(leftArmMotor),
      rightArmMotor(rightArmMotor),
      rotationSensor(rotationSensor) {}

void ArmController::moveToPosition(double position) {
    targetPosition = position * 100.0;
    double const VELOCITY_THRESHOLD = 100.0; // centidegrees a second
    double tolerance = 250.0; // 2.5 degrees

    double meanVelocity = (leftArmMotor.get_actual_velocity() + rightArmMotor.get_actual_velocity()) / 2;

    while (fabs(currentPosition - targetPosition) > tolerance || fabs(meanVelocity) > VELOCITY_THRESHOLD) {
        currentPosition = rotationSensor.get_position();
        double error = targetPosition - currentPosition;

        // Calculate velocity using PID
        double velocity = pid.update(error, TIME_STEP);

        // Calculate voltage
        double voltage = velocity * SCALING_FACTOR;
        voltage = std::clamp(voltage, -12000.0, 12000.0);

        printf("Current Position: %f, Error: %f, Voltage: %f\n", currentPosition, error, voltage);

        leftArmMotor.move_voltage(voltage);
        rightArmMotor.move_voltage(voltage);

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

double ArmController::getPosition() const {
    return rotationSensor.get_position() / 100.0;
}
