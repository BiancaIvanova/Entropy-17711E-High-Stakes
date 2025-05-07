#include "autons.h"
#include "config.h"
#include "subsystem-control-functions.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void south_side_red_worlds()
{
    currentAllianceColour = AllianceColour::RED;
    chassis.setPose(-55, -8, 300);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(-61, -6.8, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, 1000, false);
    pros::delay(250);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-34, -21, 750, {.forwards=false}, true);
    chassis.moveToPoint(-24, -26, 500, {.forwards=false, .maxSpeed = 75}, false); // slower
    arm.moveToPosition(ArmPosition::DOWN);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);

    // Get both rings from under the ladder
    chassis.turnToPoint(-13, -15.5, 500);
    chassis.moveToPoint(-13, -15.5, 750, {.maxSpeed=65}, false);
    right_doinker.set_value(true);
    pros::delay(150);
    chassis.swingToPoint(15, -7, DriveSide::RIGHT, 500, {}, false);
    left_doinker.set_value(true);
    pros::delay(350);

    // Back off
    chassis.moveToPoint(-42, -26, 1200, {.forwards=false});
    chassis.turnToPoint(-25, -34, 750, {}, false);
    left_doinker.set_value(false);
    right_doinker.set_value(false);

    // Intake all three rings
    intake.intake_control(600, {.jam_detection=true, .coloursort=true});
    chassis.turnToPoint(-30, -19, 500, {}, false);
    chassis.moveToPoint(-30, -19, 500, {}, false);
    chassis.swingToPoint(-32, -48, DriveSide::RIGHT, 1000, {}, false);
    chassis.moveToPoint(-32, -48, 500, {}, false);
    pros::delay(250);

    // Positive corner clear
    chassis.turnToPoint(-58.5, -55.5, 650, {}, false);
    left_doinker.set_value(true);
    chassis.moveToPoint(-58.5, -55.5, 1000);

    // Touch the ladder
    chassis.turnToPoint(-25, -5, 500, {.direction=AngularDirection::CW_CLOCKWISE}, false);
    left_doinker.set_value(false);
    chassis.moveToPoint(-25, 5, 1500);
}

void south_side_blue_worlds()
{
    currentAllianceColour = AllianceColour::BLUE;
    chassis.setPose(55, -8, 60);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(61, -6.8, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, 1000, false);
    pros::delay(250);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(34, -21, 750, {.forwards=false}, true);
    chassis.moveToPoint(24, -26, 500, {.forwards=false, .maxSpeed = 75}, false); // slower
    arm.moveToPosition(ArmPosition::DOWN);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);

    // Get both rings from under the ladder
    chassis.turnToPoint(13, -15.5, 500);
    chassis.moveToPoint(13, -15.5, 750, {.maxSpeed=65}, false);
    left_doinker.set_value(true);
    pros::delay(150);
    chassis.swingToPoint(15, -7, DriveSide::LEFT, 500, {}, false);
    right_doinker.set_value(true);
    pros::delay(350);

    // Back off
    chassis.moveToPoint(42, -26, 1200, {.forwards=false});
    chassis.turnToPoint(25, -34, 750, {}, false);
    left_doinker.set_value(false);
    right_doinker.set_value(false);

    // Intake all three rings
    intake.intake_control(600, {.jam_detection=true, .coloursort=true});
    chassis.turnToPoint(30, -19, 500, {}, false);
    chassis.moveToPoint(30, -19, 500, {}, false);
    chassis.swingToPoint(32, -48, DriveSide::LEFT, 1000, {}, false);
    chassis.moveToPoint(32, -48, 500, {}, false);
    pros::delay(250);

    // Positive corner clear
    chassis.turnToPoint(58.5, -55.5, 650, {}, false);
    right_doinker.set_value(true);
    chassis.moveToPoint(58.5, -55.5, 1000);

    // Touch the ladder
    chassis.turnToPoint(25, 5, 500, {.direction=AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    right_doinker.set_value(false);
    chassis.moveToPoint(25, -5, 1500);
}