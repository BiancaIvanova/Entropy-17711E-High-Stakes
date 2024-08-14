#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"

void left_side_match_red()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    
    // Robot starts angled, with the back facing the flat side of the mobile stake, barely touching white tape line
    chassis.setPose(-50, 42, 300);
    // Drive to the mobile goal, backwards, and grab it
    chassis.moveToPose(-24, 24, 300, 2000, {.forwards=false});
    mobile_stake_clamp.set_value(true);
    // Start spinning intake/deposit
    intake.move_velocity(200);

    // Turn and drive to first ring stack
    chassis.turnToPoint(-8, 40, 1500, {.direction=AngularDirection::CW_CLOCKWISE});
    chassis.moveToPose(-8, 40, 45, 2500);
    // Turn and drive to second ring stack, slowly to avoid SG7
    chassis.turnToPoint(-5, 52, 1000);
    chassis.moveToPose(-5, 52, 0, 2500, {.maxSpeed= 60});
    // Turn and drive to third ring stack
    chassis.turnToPoint(-26, 45, 1500);
    chassis.moveToPose(-26, 45, 225, 2500);

    // THIS IS WHERE THE AUTON BECOMES DIFFERENT (AWP) ------------------

    // Turn and drive to last ring stack, which is inverted
    chassis.turnToPoint(-42, 10, 1000);
    intake.move_velocity(0);
    chassis.moveToPoint(-42, 10, 3000, {.minSpeed=30, .earlyExitRange=2});

    // Go forward while lifting intake to grab top ring
    intake_lift.set_value(true);
    intake.move_velocity(200);
    chassis.moveToPose(-48, 0, 225, 1500);
    intake_lift.set_value(false);
    // intake_into_arm(); Not an implemented function yet

    // Raise arm, move forward and deposit ring
    chassis.moveToPose(-60, 0, 270, 1500);

    // Drive directly backwards to touch ladder
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.moveToPose(-32, 0, 270, 2000, {.forwards=false, .minSpeed=30, .earlyExitRange=2});

}