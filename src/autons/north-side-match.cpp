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
    chassis.moveToPoint(-27, 21, 1000, {.minSpeed = 60});
    chassis.moveToPoint(-21, 24, 500, {.maxSpeed = 80}); // slower
    mobile_stake_clamp.set_value(false);

    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(-24, 55, 1000);
    chassis.moveToPoint(-24, 55, 1500);

    // Grab next two rings
    chassis.moveToPoint(-8.652, 51.404, 5000);
    chassis.moveToPoint(-7.237, 44.042, 5000);
    chassis.moveToPoint(-45.458, 20.543, 5000);
    chassis.moveToPoint(-46.874, -6.92, 5000);
    chassis.moveToPoint(-25.356, -21.925, 5000);
    chassis.moveToPoint(-20.543, -25.039, 5000);
    chassis.moveToPoint(-22.242, -57.881, 5000);
}