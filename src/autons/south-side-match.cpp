#include "autons.h"
#include "config.h"
#include "subsystem-control-functions.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void south_side_red()
{
    chassis.setPose(-50.5, -60, 270);
    mobile_stake_clamp.set_value(true);

    // Move to pick up stake on the autonomous line
    chassis.moveToPoint(-19, -60, 1500, {.forwards=false});
    //chassis.turnToPoint(0, -48, 1500, {.forwards=false, .maxSpeed=60});
    chassis.moveToPose(-6, -53.5, 240, 1500, {.forwards=false});
    pros::delay(1000);
    mobile_stake_clamp.set_value(false);
    pros::delay(1000);

    // Start scoring rings
    intake.move_velocity(600);

    // Move to pick up second ring
    chassis.turnToPoint(-18.5, -49, 1500);
    chassis.moveToPoint(-18.5, -49, 1500);

    // Move to pick up second stake
    chassis.turnToPoint(-24, -43, 1500);
    chassis.moveToPoint(-24, -43, 1500);

    // Let go of first stake
    pros::delay(1000);
    intake.move_velocity(0);
    mobile_stake_clamp.set_value(true);
    
    chassis.turnToPoint(-24, -25, 1500, {.forwards=false});
    chassis.moveToPoint(-24, -25, 1500, {.forwards=false});

    pros::delay(750);
    mobile_stake_clamp.set_value(false);

    //south_side_red_corner();
}


void south_side_red_middle()
{
    intake.move_velocity(-600);
    
    // Move to pick up third ring beside the ladder
    chassis.turnToPoint(-44, -3, 1500);
    chassis.moveToPoint(-44, -3, 1500);
    // intake until reaches sensor
    chassis.turnToPoint(-35, 7, 1500);
    // outtake ring fully
    chassis.turnToPoint(-48.5, 2, 1500);
    intake_controlled(600);
    chassis.moveToPoint(-48.5, 2, 1500, {.maxSpeed = 60});

    // Turn and touch ladder
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.turnToPoint(-26.5, 0, 1500);
    chassis.moveToPoint(-26.5, 0, 1500);
}


void south_side_red_corner()
{
    // Move to pick up third ring
    chassis.turnToPoint(-30, -56, 1500);
    chassis.moveToPoint(-30, -56, 1500);
    chassis.turnToPoint(-69, -67, 1500, {.minSpeed=60});
    chassis.moveToPoint(-69, -67, 1500);
    intake.move_velocity(600);
    pros::delay(750);

    // Move to touch ladder
    chassis.turnToPoint(-37, -52, 1500, {.forwards=false});
    chassis.moveToPoint(-37, -52, 1500, {.forwards=false});
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.turnToPoint(-26, -7, 1500);
    chassis.moveToPoint(-26,-7, 1500);
    intake.move_velocity(0);
}