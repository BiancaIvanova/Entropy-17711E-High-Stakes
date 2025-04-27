#ifndef ARM_CONTROLLER_H
#define ARM_CONTROLLER_H

#include "main.h"
#include "pros/motors.h"
#include "pros/rotation.hpp"
#include "pid-controller.h"
#include "pros/rtos.hpp"

enum ArmPosition {
    DOWN = 0,
    LOAD = 28,
    WALL_STAKE = 140,
    ALLIANCE_STAKE = 185,
    MOGO_TIP = 235
};

class ArmController {
    PIDController pid;
    double currentPosition = 0;
    double targetPosition;
    static const int TIME_STEP = 20;
    pros::Motor& leftArmMotor;
    pros::Motor& rightArmMotor;
    pros::Rotation& rotationSensor;
    pros::Task* moveTask = nullptr;

    void moveToPositionTask(double position, double maxSpeed);

public:
    ArmController(double kP, double kI, double kD, 
                  pros::Motor& leftArmMotor, pros::Motor& rightArmMotor, pros::Rotation& rotationSensor);

    void moveToPosition(double position, bool async = true, double maxSpeed = 1.0);

    void resetPosition(double newPosition);

    double getPosition() const;
};

#endif
