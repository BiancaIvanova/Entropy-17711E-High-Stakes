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
    pros::MotorGroup armMotors;  // MotorGroup for multiple motors

public:
    ArmController(double kP, double kI, double kD, double minPosition, double maxPosition, double maxVelocity, pros::Rotation rotationSensor, pros::MotorGroup armMotors)
        : pid(kP, kI, kD),
          minPosition(minPosition),
          maxPosition(maxPosition),
          maxVelocity(maxVelocity),
          rotationSensor(rotationSensor),
          armMotors(armMotors) {}

    void moveToPosition(double position) {
        targetPosition = fmin(fmax(position, minPosition), maxPosition);  // Clamp target position
        double const VELOCITY_THRESHOLD = 5;  // Stop moving when velocity is low enough
        double tolerance = 1.0;  // Position tolerance in degrees
    
        // Continue adjusting until the arm is within the tolerance of the target
        while (fabs(currentPosition - targetPosition) > tolerance || 
               fabs(armMotors.get_actual_velocity()) > VELOCITY_THRESHOLD) {
            currentPosition = rotationSensor.get_position();  // Update current position
            double error = targetPosition - currentPosition;  // Calculate the position error

            // Calculate velocity using PID controller
            double velocity = pid.update(error, TIME_STEP);
            velocity = fmin(fmax(velocity, -maxVelocity), maxVelocity);  // Clamp velocity

            // Move the motor group with the calculated velocity
            armMotors.move_velocity(velocity);

            // Wait for the next time step
            pros::delay(TIME_STEP);
        }

        // Stop the motor group when the target is reached
        armMotors.move_velocity(0);
    }
};
