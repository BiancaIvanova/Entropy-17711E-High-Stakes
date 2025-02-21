#ifndef ARM_CONTROLLER_H
#define ARM_CONTROLLER_H

#include "main.h"
#include "pros/motors.h"
#include "pros/rotation.hpp"
#include "pid-controller.h"

class ArmController {
    PIDController pid;
    double currentPosition = 0;
    double targetPosition;
    static const int TIME_STEP = 20;
    pros::Motor& leftArmMotor;
    pros::Motor& rightArmMotor;
    pros::Rotation& rotationSensor;

public:
    ArmController(double kP, double kI, double kD, 
                  pros::Motor& leftArmMotor, pros::Motor& rightArmMotor, pros::Rotation& rotationSensor);

    void moveToPosition(double position);

    void resetPosition(double newPosition);
};

#endif
