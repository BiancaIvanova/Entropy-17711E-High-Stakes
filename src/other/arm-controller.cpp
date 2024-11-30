#include "main.h"
#include "config.h"
#include "pros/motors.h"
#include "pid-controller.h"

class ArmController {
    PIDController pid;
    double currentPosition = 0;
    double targetPosition;
    double minPosition, maxPosition;
    double maxVelocity;
    static const int TIME_STEP = 20;
    pros::Rotation rotationSensor;
    pros::Motor armMotor;

public:
    ArmController(double kP, double kI, double kD, double minPosition, double maxPosition, double maxVelocity, pros::Rotation rotationSensor, pros::Motor armMotor)
        : pid(kP, kI, kD),
          minPosition(minPosition),
          maxPosition(maxPosition),
          maxVelocity(maxVelocity),
          rotationSensor(rotationSensor),
          armMotor(armMotor) {}

    void moveToPosition(double position) {
        targetPosition = fmin(fmax(position, minPosition), maxPosition);
        double const VELOCITY_THRESHOLD = 5;
        double tolerance = 1.0;

        while (armMotor.get_actual_velocity() > VELOCITY_THRESHOLD) {
            currentPosition = rotationSensor.get_position();
            double error = targetPosition - currentPosition;
            double velocity = pid.calculate(error, TIME_STEP);
            velocity = fmin(fmax(velocity, -maxVelocity), maxVelocity);
            armMotor.move_velocity(velocity);
            pros::delay(TIME_STEP);
        }

        armMotor.move_velocity(0);
    }
};
