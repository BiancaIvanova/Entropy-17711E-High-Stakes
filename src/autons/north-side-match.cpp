#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void north_side_red_worlds()
{
    currentAllianceColour = AllianceColour::RED;
    chassis.setPose(-54, 7, 180);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.swingToPoint(-72, 0, DriveSide::RIGHT, 500, {}, false);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, 750, false);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-24, 12.5, 750, {.forwards=false}, false);
    pros::delay(200);
    arm.moveToPosition(ArmPosition::DOWN, 750, true);
    chassis.moveToPoint(-20, 19, 750, {.forwards=false, .maxSpeed=60}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake.intake_control(600, {.jam_detection=true, .coloursort=false});
    chassis.turnToPoint(-16, 46, 850, {.maxSpeed=50});
    arm.resetPosition(ArmPosition::DOWN);
    chassis.moveToPoint(-16, 42, 850, {.maxSpeed=85}, false);
    pros::delay(500);
    chassis.moveToPoint(-16, 40, 500, {.forwards=false});
    
    // Grab second ring
    chassis.swingToPoint(10, 38, DriveSide::RIGHT, 750, {.maxSpeed=85});
    chassis.moveToPoint(-10, 38, 900, {.maxSpeed=50});
    
    // Grab third ring
    chassis.turnToPoint(0, 31, 750);
    chassis.moveToPoint(-9.5, 37.5, 900);
    pros::delay(800);
    
    // Back off
    chassis.moveToPoint(-16, 42, 750, {.forwards=false});

    // Go to ring stack
    chassis.turnToPoint(-48, 0, 750);
    chassis.moveToPoint(-38.5, 13, 1250, {}, false);
    pros::delay(250);
    left_doinker.set_value(true);
    pros::delay(400);

    // Pull ring away
    chassis.moveToPoint(-32, 22, 750, {.forwards=false}, false);
    pros::delay(250);
    left_doinker.set_value(false);
    chassis.moveToPoint(-35, 10, 500, {}, false); // score that ring
    pros::delay(400);
    
    // Touch ladder
    chassis.turnToPoint(-24, 0, 500);
    chassis.moveToPoint(-24, -10, 1500);
}


void north_side_blue_worlds()
{
    currentAllianceColour = AllianceColour::BLUE;
    chassis.setPose(54, 7, 180);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.swingToPoint(72, 0, DriveSide::LEFT, 500, {}, false);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, 750, false);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(26, 11, 750, {.forwards=false}, false);
    pros::delay(200);
    arm.moveToPosition(ArmPosition::DOWN, 750, true);
    chassis.moveToPoint(21, 19, 750, {.forwards=false, .maxSpeed=60}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);

    // Turn and grab first ring
    intake.intake_control(600, {.jam_detection=true, .coloursort=false});
    chassis.turnToPoint(25.5, 46, 850, {.maxSpeed=50});
    arm.resetPosition(ArmPosition::DOWN);
    chassis.moveToPoint(25.5, 46, 850, {.maxSpeed=85}, false);
    pros::delay(500);
    chassis.moveToPoint(25.5, 45, 500, {.forwards=false});

    // Grab second ring
    chassis.swingToPoint(-10, 38, DriveSide::LEFT, 750, {.maxSpeed=85}, false);
    pros::delay(150);
    chassis.moveToPoint(10.5, 47, 900, {.maxSpeed=50});
    
    // Grab third ring
    chassis.turnToPoint(0, 35.2, 750);
    chassis.moveToPoint(9.8, 43.4, 900);
    pros::delay(800);
    
    // Back off
    chassis.moveToPoint(16, 52, 750, {.forwards=false});
    
    // Go to ring stack
    chassis.turnToPoint(48, 0, 750);
    chassis.moveToPoint(39.5, 10, 1250, {}, false);
    pros::delay(250);
    right_doinker.set_value(true);
    pros::delay(250);
    

    // Pull ring away
    chassis.moveToPoint(32, 22, 750, {.forwards=false}, false);
    pros::delay(150);
    right_doinker.set_value(false);
    chassis.moveToPoint(34, 8, 500, {}, false); // score that ring
    pros::delay(250);
    
    // Touch ladder
    chassis.turnToPoint(24, 0, 500);
    chassis.moveToPoint(24, -10, 1500);
}