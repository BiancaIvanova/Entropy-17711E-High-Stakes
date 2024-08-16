#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"

void auton_skills()
{
    // Robot starts with the back directly facing alliance wall stake
    chassis.setPose(-62, 0, 90);
    // Put the preload on the alliance wall stake

    // FIRST STAGE OF AUTON -------------------------------------

    // Move slightly forward, turn so the back is facing left mobile stake
    chassis.moveToPose(-58, 0, 90, 1000);
    chassis.turnToPoint(-48, 24, 1000, {.forwards=false});

    // Move to pick up stake
    chassis.moveToPose(-48, 24, 210, 1500, {.forwards=false}); // not sure if theta is correct
    mobile_stake_clamp.set_value(true);

    // Move to collect first ring
    chassis.turnToPoint(-24, 24, 1000);
    intake.move_velocity(200);
    chassis.moveToPose(-24, 24, 90, 1000);

    // Move to collect second ring
    chassis.turnToPoint(-24, 48, 1000);
    chassis.moveToPose(-24, 48, 0, 1000);

    // Move to collect third and fourth rings
    chassis.turnToPoint(-55, 48, 1000);
    chassis.moveToPose(-55, 48, 270, 1000);

    // Move to collect fifth/last ring
    chassis.turnToPoint(-50, 56, 1000);
    chassis.moveToPose(-50, 56, 45, 1000);
    intake.move_velocity(0);

    // Swing to dump the mobile stake in the corner and position to grab the other one
    chassis.swingToHeading(105, DriveSide::RIGHT, 1000);
    chassis.moveToPoint(-54, 60, 1000);
    mobile_stake_clamp.set_value(false);
    chassis.moveToPose(-48, 60, 135, 1000);
    chassis.turnToHeading(315, 800);

    // SECOND STAGE OF AUTON -----------------------------------------------

    // Drive backwards quickly to pick up the next stake
    chassis.moveToPose(-48, -24, 30, 3000, {.forwards=false, .minSpeed=40, .earlyExitRange=3});
    mobile_stake_clamp.set_value(true);

    // Move to collect first ring
    chassis.turnToPoint(-24, -24, 1000);
    intake.move_velocity(200);
    chassis.moveToPose(-24, -24, 90, 1000);

    // Move to collect second ring
    chassis.turnToPoint(-24, -48, 1000);
    chassis.moveToPose(-24, -48, 90, 1000);

    // Move to collect third and fourth rings
    chassis.turnToPoint(-55, 48, 1000);
    chassis.moveToPose(-55, 48, 270, 1000);

    // Move to collect fifth/last ring
    chassis.turnToPoint(-55, -50, 1000);
    chassis.moveToPose(-55, -56, 135, 1000);
    intake.move_velocity(0);

    // Swing to dump the mobile stake in the corner
    chassis.swingToHeading(75, DriveSide::LEFT, 1000);
    chassis.moveToPoint(-54, -60, 1000);
    mobile_stake_clamp.set_value(false);

    // THIRD STAGE OF AUTON
    // Go and put four rings on the last empty mobile stake

    // FOURTH STAGE OF AUTON
    // Dump both of the remaining mobile stakes (with the singular blue ring) in the corners
}