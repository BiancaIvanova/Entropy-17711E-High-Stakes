#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void north_side_red()
{
    chassis.setPose(-53, 10, 235);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(-60.5, 6, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE);
    pros::delay(750);

    // Move back and grab left 
    mobile_stake_clamp.set_value(true);
    arm.moveToPosition(ArmPosition::DOWN);
    chassis.moveToPoint(-34, 19, 750, {.forwards=false});
    chassis.moveToPoint(-24, 24, 500, {.forwards=false, .maxSpeed = 50}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);

    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(-29, 49, 750);
    chassis.moveToPoint(-29, 49, 1000);

    // Grab second ring
    chassis.turnToPoint(-17, 52, 750);
    chassis.moveToPoint(-17, 52, 1000);
    chassis.moveToPoint(-23, 48, 750, {.forwards=false}); // back off

    // Grab third ring
    chassis.turnToPoint(-16.5, 46.5, 750);
    /*
    chassis.moveToPoint(-12, 46, 1000);
    
    chassis.moveToPoint(-17, 46, 1000, {.forwards=false}); // back off

    // Move to other side of field
    mobile_stake_clamp.set_value(true);
    chassis.moveToPose(-47, -7.5, 180, 2000, {.minSpeed=90});
    intake_controlled(0);

    // Turn and grab right stake
    chassis.turnToPoint(-24, -24, 1000, {.forwards=false});
    chassis.moveToPoint(-24, -24, 1000, {.forwards=false});
    mobile_stake_clamp.set_value(false);

    // Score current ring
    intake_controlled(600);

    // Score last ring
    chassis.turnToPoint(-24, -48, 1000);
    chassis.moveToPoint(-24, -48, 1000);

    //Turn and touch ladder
    chassis.turnToPoint(-24, -4, 1000);
    chassis.moveToPoint(-24, -44, 1000);
    */
}