#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void new_north_side_red()
{
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-55, 11, 180);

    // Open mogo clamp
    mobile_stake_clamp.set_value(true);

    // Open arm mech
    arm_rotation_sensor.set_position(0);
    while (arm_rotation_sensor.get_position() < 5500)
    {
        arm.move_velocity(100);
    }
    arm.move_velocity(0);
    arm_flip.set_value(true);

    // Turn to alliance stake
    chassis.swingToHeading(245, DriveSide::RIGHT, 1000, {.maxSpeed=60}, false);
    arm.move_velocity(-100);
    pros::delay(1750);

    // Move back to stake
    chassis.moveToPoint(-20, 26, 1750, {.forwards=false, .maxSpeed=60});
    //chassis.moveToPoint(-12, 29, 1000, {.forwards=false, .maxSpeed=60});

    // Fold arm back
    arm_flip.set_value(false);

    // Clamp on stake
    chassis.waitUntilDone();
    pros::delay(500);
    mobile_stake_clamp.set_value(false);
    arm.move_velocity(0);
    pros::delay(1000);

    // Score first ring
    intake_controlled(600);
    chassis.turnToPoint(-24, 40, 1000, {.maxSpeed=70});
    chassis.moveToPoint(-24, 40, 1500, {.maxSpeed=70}, false);

    // Score second ring
    chassis.turnToPoint(-12, 41, 1000, {.maxSpeed=70});
    chassis.moveToPoint(-12, 41, 1000, {.maxSpeed=70}, false);
    pros::delay(500);

    // Move back
    chassis.moveToPoint(-21, 43, 1500, {.forwards=false, .maxSpeed=50}, false);

    // Score third ring
    chassis.turnToPoint(-10, 53, 1000, {.maxSpeed=90});
    chassis.moveToPoint(-10, 51, 1000, {.maxSpeed=70}, false);
    pros::delay(500);

    // Move back
    chassis.moveToPoint(-26, 40, 1500, {.forwards=false}, false);

    // Turn and touch ladder
    chassis.turnToPoint(-18, 2, 1000);
    chassis.moveToPoint(-18, 2, 3000);
    intake_controlled(0);

}


void north_side_red()
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

void north_side_blue()
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