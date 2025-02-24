#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

// FINISHED AWP, DO NOT TOUCH

void north_side_red()
{
    chassis.setPose(-53, 10, 240);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(-60.5, 6, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, true, 0.35);
    pros::delay(750);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-34, 21, 750, {.forwards=false}, false);
    arm.moveToPosition(ArmPosition::DOWN);
    chassis.moveToPoint(-24, 26, 500, {.forwards=false, .maxSpeed = 50}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(-29, 46, 750);
    chassis.moveToPoint(-29, 46, 1000);

    // Grab second ring
    chassis.turnToPoint(-20, 51, 750);
    chassis.moveToPoint(-20, 51, 900);
    chassis.moveToPoint(-23, 48, 750, {.forwards=false}, false); // back off

    // Move to other side of field
    chassis.turnToPoint(-49, 18, 750);
    chassis.moveToPoint(-49, 18, 1400);
    intake_controlled(0);
    mobile_stake_clamp.set_value(true);
    
    // Grab the two ring stack
    chassis.turnToPoint(-46, -11, 750, {.maxSpeed=85}, false);
    intake_controlled(600);
    chassis.moveToPoint(-46, 0, 1200, {});
    chassis.moveToPoint(-46, -11, 750);
    pros::delay(975);
    intake_controlled(0);

    // Grab the other mogo
    chassis.turnToPoint(-30, -20, 750, {.forwards=false});
    chassis.moveToPoint(-30, -20, 750, {.forwards=false}, false);
    chassis.moveToPoint(-23, -23, 1000, {.forwards=false, .maxSpeed=20}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    intake_controlled(600);

    // Touch the ladder
    chassis.turnToPoint(-28, 7, 500);
    chassis.moveToPoint(-28, 7, 2000);
}


void north_side_blue()
{
    chassis.setPose(53, 10, 120);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(60.5, 6, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, true, 0.35);
    pros::delay(750);

    // Move back and grab right stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(34, 21, 750, {.forwards=false}, false);
    arm.moveToPosition(ArmPosition::DOWN);
    chassis.moveToPoint(24, 26, 500, {.forwards=false, .maxSpeed = 50}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(29, 46, 750);
    chassis.moveToPoint(29, 46, 1000);

    // Grab second ring
    chassis.turnToPoint(20, 51, 750);
    chassis.moveToPoint(20, 51, 900);
    chassis.moveToPoint(23, 48, 750, {.forwards=false}, false); // back off

    // Move to other side of field
    chassis.turnToPoint(49, 18, 750);
    chassis.moveToPoint(-9, 18, 1400);
    intake_controlled(0);
    mobile_stake_clamp.set_value(true);
    
    // Grab the two ring stack
    chassis.turnToPoint(46, -11, 750, {.maxSpeed=85}, false);
    intake_controlled(600);
    chassis.moveToPoint(46, 0, 1200, {});
    chassis.moveToPoint(46, -11, 750);
    pros::delay(975);
    intake_controlled(0);

    // Grab the other mogo
    chassis.turnToPoint(30, -20, 750, {.forwards=false});
    chassis.moveToPoint(30, -20, 750, {.forwards=false}, false);
    chassis.moveToPoint(23, -23, 1000, {.forwards=false, .maxSpeed=20}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    intake_controlled(600);

    // Touch the ladder
    chassis.turnToPoint(28, 7, 500);
    chassis.moveToPoint(28, 7, 2000);
}