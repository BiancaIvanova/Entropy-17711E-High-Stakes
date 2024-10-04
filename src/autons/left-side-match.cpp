#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"



void left_side_match_red()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

    mobile_stake_clamp.set_value(true);
    
    // Robot starts angled, with the back facing the flat side of the mobile stake, barely touching white tape line
    chassis.setPose(-52, 40, 300);
    // Drive to the mobile goal, backwards, and grab it
    chassis.moveToPose(-24, 24, 300, 1200, {.forwards=false}, true);
    pros::delay(500);
    mobile_stake_clamp.set_value(false);
    pros::delay(1000);
    chassis.waitUntilDone();
    
    // Start spinning intake/deposit
    intake.move_velocity(600);

    // Turn and drive to first ring stack
    chassis.turnToPoint(-15, 41, 1500, {.direction=AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-15, 41, 2000, {.maxSpeed = 60});
    
    // Turn and drive to second ring stack, slowly to avoid SG7
    chassis.turnToPoint(-15, 55, 2000);
    chassis.moveToPoint(-15, 55, 2000, {.maxSpeed= 60});

    
    // Turn and drive to third ring stack
    chassis.swingToPoint(-30, 44, lemlib::DriveSide::LEFT, 2000);
    chassis.moveToPoint(-30, 44, 2000);

    // THIS IS WHERE THE AUTON BECOMES DIFFERENT (AWP) ------------------    /

    // Turn and drive to last ring stack, which is inverted
    pros::delay(1000);
    chassis.turnToPoint(-58, 5, 2000, {.minSpeed=60});
    //chassis.moveToPoint(-58, 5, 2200);

    /*
    
    // Move to square off
    chassis.turnToPoint(-85, 3.25, 1500, {.forwards=false});
    chassis.moveToPoint(-90,3.25, 1500, {.forwards=false});
    pros::delay(500);

    // Deposit ring
    chassis.setPose(-65, 0, 90);
    chassis.moveToPoint(-79, 0, 1500);

    // Drive directly backwards to touch ladder
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

    
    intake.move_velocity(0);
    chassis.moveToPoint(16, 0, 2000, {.minSpeed=30});
    */
}

void left_side_match_blue()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

    mobile_stake_clamp.set_value(true);
    
    // Robot starts angled, with the back facing the flat side of the mobile stake, barely touching white tape line
    chassis.setPose(52, 40, 60);
    // Drive to the mobile goal, backwards, and grab it
    chassis.moveToPose(24, 24,60, 1200, {.forwards=false}, true);
    pros::delay(500);
    mobile_stake_clamp.set_value(false);
    pros::delay(1000);
    chassis.waitUntilDone();
    
    // Start spinning intake/deposit
    intake.move_velocity(600);

    // Turn and drive to first ring stack
    chassis.turnToPoint(15, 41, 1500, {.direction=AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.moveToPoint(15, 41, 2000, {.maxSpeed = 60});
    
    // Turn and drive to second ring stack, slowly to avoid SG7
    chassis.turnToPoint(15, 55, 2000);
    chassis.moveToPoint(15, 55, 2000, {.maxSpeed= 60});

    
    // Turn and drive to third ring stack
    chassis.swingToPoint(30, 44, lemlib::DriveSide::RIGHT, 2000);
    chassis.moveToPoint(30, 44, 2000);

    // THIS IS WHERE THE AUTON BECOMES DIFFERENT (AWP) ------------------

    // Turn and drive to last ring stack, which is inverted
    pros::delay(1000);
    chassis.turnToPoint(58, 5, 2000, {.minSpeed=60});
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(58, 5, 2200);

    
    // Move to square off
    chassis.turnToPoint(85, 3.25, 1500, {.forwards=false});
    chassis.moveToPoint(90,3.25, 3000, {.forwards=false});
    pros::delay(500);

    // Deposit ring
    chassis.setPose(65, 0, 270);
    chassis.moveToPoint(79, 0, 1500);

    // Drive directly backwards to touch ladder
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    intake.move_velocity(0);
    chassis.moveToPoint(20, 0, 2000, {.minSpeed=30});
}