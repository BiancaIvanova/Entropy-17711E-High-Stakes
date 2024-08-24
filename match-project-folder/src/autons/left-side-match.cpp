#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"

void left_side_match_red()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    
    // Robot starts angled, with the back facing the flat side of the mobile stake, barely touching white tape line
    chassis.setPose(-50, 40, 300);
    // Drive to the mobile goal, backwards, and grab it
    chassis.moveToPose(-24, 24, 300, 1000, {.forwards=false});
    mobile_stake_clamp.set_value(true);
    // Start spinning intake/deposit
    intake.move_velocity(200);

    // Turn and drive to first ring stack
    chassis.turnToPoint(-5, 40, 500, {.direction=AngularDirection::CW_CLOCKWISE});
    chassis.moveToPose(-5, 40, 45, 1000);
    // Turn and drive to second ring stack, slowly to avoid SG7
    chassis.turnToPoint(-5, 52, 500);
    chassis.moveToPose(-5, 52, 0, 500, {.maxSpeed= 60});
    // Turn and drive to third ring stack
    chassis.turnToPoint(-26, 45, 500);
    chassis.moveToPoint(-26, 45, 1000);

    // THIS IS WHERE THE AUTON BECOMES DIFFERENT (AWP) ------------------

    // Turn and drive to last ring stack, which is inverted
    chassis.turnToPoint(-48, 2, 3000);
    mobile_stake_clamp.set_value(false);
    chassis.moveToPoint(-48, 2, 1500);

    // Deposit ring backwards
    chassis.turnToPoint(-62, 0, 1200, {.forwards=false});
    chassis.moveToPoint(-62, 0, 1500, {.forwards=false});

    // Drive directly backwards to touch ladder
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.moveToPose(24, 0, 270, 2000, {.minSpeed=30});

}