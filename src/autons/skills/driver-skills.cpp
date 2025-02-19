#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void driver_skills_auton()
{
    //arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-56, 0, 270);

    // Open arm mech
    arm_rotation_sensor.set_position(0);
    while (arm_rotation_sensor.get_position() < 4500)
    {
        //arm.move_velocity(100);
    }
    //arm.move_velocity(0);
    arm_flip.set_value(true);

    // Move arm down
    //arm.move_velocity(-100);
    pros::delay(1750);

    chassis.moveToPoint(-48, 0, 700, {.forwards=false}, false);
    arm_flip.set_value(false);
    chassis.turnToPoint(-48, 22, 700, {.forwards=false}, false);
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-48, 22, 700, {.forwards=false}, false);
    //arm.move_velocity(0);
    chassis.waitUntilDone();
    mobile_stake_clamp.set_value(false);
}