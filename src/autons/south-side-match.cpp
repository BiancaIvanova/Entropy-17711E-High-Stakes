#include "autons.h"
#include "config.h"
#include "subsystem-control-functions.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void south_side_red()
{
    currentAllianceColour = AllianceColour::RED;
    chassis.setPose(-55, -8, 120);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(-61, -5, 400);
    arm.moveToPosition(205, true, 0.35);
    pros::delay(750);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-34, 21, 750, {.forwards=false}, false);
    arm.moveToPosition(ArmPosition::DOWN, true, 0.35);
    chassis.moveToPoint(-24, 26, 500, {.forwards=false, .maxSpeed = 75}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);

    // Get both rings from under the ladder
    chassis.turnToPoint(-10, -10, 500);
    chassis.moveToPoint(-10, -10, 750, {}, false);
    right_doinker.set_value(true);
    chassis.swingToPoint(15, -5, DriveSide::RIGHT, 500);
    left_doinker.set_value(true);

    // Back off
    chassis.moveToPoint(-42, -24, 1200, {.forwards=false});
    chassis.turnToHeading(90, 500, {}, false);
    left_doinker.set_value(false);
    right_doinker.set_value(false);

    // Intake all three rings
    intake.intake_control(600, {.jam_detection=true, .coloursort=true});
    chassis.moveToPoint(-15, -24, 1200, {}, false);
    chassis.moveToPoint(-46, -10, 1200, {.maxSpeed=50}, false);

    // Positive corner clear
    chassis.turnToPoint(-50, -60, 500);
    chassis.moveToPoint(-50, -60, 1000);
    left_doinker.set_value(true);
    chassis.turnToPoint(-50, -32, 500, {.direction=AngularDirection::CW_CLOCKWISE}, false);
}

void south_side_blue()
{
    // NOT PROGRAMMED
}