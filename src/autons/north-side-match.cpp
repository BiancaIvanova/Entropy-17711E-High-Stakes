#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void north_side_red_worlds()
{
    currentAllianceColour = AllianceColour::RED;
    chassis.setPose(-55, 8, 240);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(-61, 5, 400);
    arm.moveToPosition(205, true, 0.35);
    pros::delay(750);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-34, 21, 750, {.forwards=false}, false);
    left_arm.move_voltage(-12000);
    right_arm.move_voltage(-12000);
    chassis.moveToPoint(-24, 26, 500, {.forwards=false, .maxSpeed = 75}, false); // slower
    left_arm.move_voltage(0);
    right_arm.move_voltage(0);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake.intake_control(600, {.jam_detection=true, .coloursort=true});
    chassis.turnToPoint(-27, 35, 1100, {.maxSpeed=50});
    arm.resetPosition(ArmPosition::DOWN);
    chassis.moveToPoint(-27, 40, 1200);
    chassis.moveToPoint(-27, 34, 800, {.forwards=false});
    
    // Grab second ring
    chassis.swingToPoint(-17, 41, DriveSide::LEFT, 750, {.maxSpeed=85});
    chassis.moveToPoint(-17, 41, 900);
    
    // Grab third ring
    chassis.swingToPoint(-20, 57, DriveSide::LEFT, 750);
    chassis.moveToPoint(-18, 59, 900);
    pros::delay(250);

    // Turn to corner
    chassis.turnToPoint(-62.5, 62, 900);
    right_doinker.set_value(true);
    chassis.moveToPoint(-62.5, 62, 1500, {}, false);
    pros::delay(250);

    // Sweep the corner
    chassis.turnToPoint(-25, -5, 500, {.direction=AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    chassis.moveToPoint(-25, -5, 1500, {.forwards=false}, false); // Ladder touch
}


void north_side_blue_worlds()
{
    currentAllianceColour = AllianceColour::BLUE;
    chassis.setPose(55, 8, 120);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(61, 5, 400);
    arm.moveToPosition(205, true, 0.35);
    pros::delay(750);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(34, 21, 750, {.forwards=false}, false);
    left_arm.move_voltage(-12000);
    right_arm.move_voltage(-12000);
    chassis.moveToPoint(24, 26, 500, {.forwards=false, .maxSpeed = 75}, false); // slower
    left_arm.move_voltage(0);
    right_arm.move_voltage(0);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake.intake_control(600, {.jam_detection=true, .coloursort=true});
    chassis.turnToPoint(27, 35, 1100, {.maxSpeed=50});
    arm.resetPosition(ArmPosition::DOWN);
    chassis.moveToPoint(27, 40, 1200);
    chassis.moveToPoint(27, 34, 800, {.forwards=false});
    
    // Grab second ring
    chassis.swingToPoint(17, 41, DriveSide::RIGHT, 750, {.maxSpeed=85});
    chassis.moveToPoint(17, 41, 900);
    
    // Grab third ring
    chassis.swingToPoint(-20, 57, DriveSide::RIGHT, 750);
    chassis.moveToPoint(-18, 59, 900);
    pros::delay(250);

    // Turn to corner
    chassis.turnToPoint(-62.5, 62, 900);
    left_doinker.set_value(true);
    chassis.moveToPoint(-62.5, 62, 1500, {}, false);
    pros::delay(250);

    // Sweep the corner
    chassis.turnToPoint(-25, -5, 500, {.direction=AngularDirection::CW_CLOCKWISE}, false);
    chassis.moveToPoint(-25, -5, 1500, {.forwards=false}, false); // Ladder touch
}