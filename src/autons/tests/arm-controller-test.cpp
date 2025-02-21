#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void arm_test()
{
    left_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.resetPosition(0.0);
    arm.moveToPosition(100.0);
    arm.moveToPosition(60.0);
    arm.moveToPosition(120.0);
}