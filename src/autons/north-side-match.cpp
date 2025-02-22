#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void north_side_red()
{
    chassis.setPose(-56, 12, 225);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE);

    // Move back and grab left 
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-27, 21, 750, {.forwards=false, .minSpeed = 60});
    chassis.moveToPoint(-21, 24, 500, {.forwards=false, .maxSpeed = 80}); // slower
    mobile_stake_clamp.set_value(false);

    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(-24, 51, 750);
    chassis.moveToPoint(-24, 51, 1000);

    // Grab second ring
    chassis.turnToPoint(-9, 51, 750);
    chassis.moveToPoint(-9, 51, 1000);
    chassis.moveToPoint(-14, 50, 1000, {.forwards=false}); // back off

    // Grab third ring
    chassis.turnToPoint(-8, 47, 750);
    chassis.moveToPoint(-8, 47, 1000);
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
}