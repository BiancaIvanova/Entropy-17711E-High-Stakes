#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"



void square_test() {
    chassis.setPose(0, 0, 90);
    chassis.turnToPoint(0, 24, 1500);
    chassis.moveToPoint(0, 24, 1500);
    chassis.turnToPoint(24, 24, 1500);
    chassis.moveToPoint(24, 24, 1500);
    chassis.turnToPoint(24, 0, 1500);
    chassis.moveToPoint(24, 0, 1500);
    chassis.turnToPoint(0, 0, 1500);
    chassis.moveToPoint(0, 0, 1500);
}

void turn_test() {
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 24, 100000);
}

void auton_skills()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    
    // Robot starts with the back directly facing alliance wall stake
    chassis.setPose(-64, 24, 270);
    pros::delay(1000);
    // Put the preload on the alliance wall stake

    // Deal with the close left side of the field
    auton_skills_stage_1();
    // Do the same with the close right side of the field
    auton_skills_stage_2();
    // Move to the back of the field and fill the last empty stake
    //auton_skills_stage_3();
    // Finish by putting the two blue ring stakes into the corners
    //auton_skills_stage_4();

}


void auton_skills_stage_1()
{
    // FIRST STAGE OF AUTON -------------------------------------
    mobile_stake_clamp.set_value(true);

    // Move to pick up stake
    chassis.moveToPoint(-42, 24, 1500, {.forwards=false});
    pros::delay(750);
    mobile_stake_clamp.set_value(false);
    pros::delay(1500);
    intake.move_velocity(600);
    
    // Move to collect first ring
    chassis.turnToPoint(-24, 24, 2000);
    chassis.moveToPoint(-24, 24, 2000);

    // Move to collect second ring
    chassis.turnToPoint(-24, 52, 2000, {.maxSpeed = 60});
    chassis.moveToPoint(-24, 52, 2000);

    // Move to collect third and fourth rings
    chassis.turnToPoint(-68, 52, 2000);
    chassis.moveToPoint(-68, 52, 2000, {.maxSpeed = 50});
    pros::delay(1500);

    // Move to collect fifth/last ring
    chassis.turnToPoint(-60, 48, 2000);
    chassis.moveToPoint(-60, 48, 2000, {.maxSpeed = 80});

    // Swing to dump the mobile stake in the corner and position to grab the other one
    chassis.turnToPoint(-72, 72, 2000, {.forwards = false});
    chassis.moveToPoint(-72, 72, 2000, {.forwards = false});
    intake.move_velocity(0);
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-48, 48, 2000);
    
}


void auton_skills_stage_2()
{
    // SECOND STAGE OF AUTON -----------------------------------------------
    // Drive backwards quickly to pick up the next stake
    chassis.turnToPoint(-48, -28, 2500, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPoint(-48, -28, 3000, {.forwards=false, .maxSpeed = 50});
    pros::delay(1000);
    mobile_stake_clamp.set_value(false);

    //NEW
    chassis.turnToPoint(-200, -200, 2500, {.forwards = false, .maxSpeed = 40});
    chassis.moveToPoint(-200, -200, 3000, {.forwards=false, .maxSpeed = 50});

    /*

    // Move to collect first ring
    chassis.turnToPoint(-24, -24, 1000);
    intake.move_velocity(600);
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

    // Swing to dump the mobile stake in the corner
    chassis.swingToHeading(75, DriveSide::LEFT, 1000);
    chassis.moveToPoint(-54, -60, 1000);
    mobile_stake_clamp.set_value(true);

    */
}


void auton_skills_stage_3()
{
    // THIRD STAGE OF AUTON -----------------------------------------------
    // Move to collect first ring
    chassis.turnToPoint(24, -48, 1000);
    intake.move_velocity(600);
    chassis.moveToPoint(24, -48, 3000);
    intake.move_velocity(0);

    // Move to collect second ring
    chassis.turnToPoint(24, -24, 1000);
    chassis.moveToPose(24, -32, 0, 1000);
    intake.move_velocity(600);
    chassis.moveToPose(24, -24, 0, 1000);
    intake.move_velocity(0);

    // Grab last empty stake and put the rings onto it
    chassis.turnToPoint(43, -7, 1000, {.forwards=false});
    chassis.moveToPose(43, -7, 30, 1000, {.forwards=false});
    mobile_stake_clamp.set_value(false);
    intake.move_velocity(600);
    chassis.turnToPoint(48, 0, 1000, {.forwards=false});
    chassis.moveToPose(48, 0, 30, 1000, {.forwards=false});

    // Move to collect third ring
    chassis.turnToPoint(24, 24, 1000);
    chassis.moveToPose(24, 24, 315, 1000);

    // Move to collect fourth ring
    chassis.turnToPoint(24, 48, 1000);
    chassis.moveToPose(24, 48, 0, 1000);

    // Turn and drop the stake (which should now have four rings on it)
    chassis.turnToHeading(100, 1000, {.direction=lemlib::AngularDirection::CW_CLOCKWISE});
    mobile_stake_clamp.set_value(true);
}


void auton_skills_stage_4()
{
    // FOURTH STAGE OF AUTON -----------------------------------------------
    // Turn so the back is facing the right blue ring stake
    chassis.turnToPoint(58, -22, 1000, {.forwards=false});

    // Drive backwards and push that stake into the right side corner
    chassis.moveToPoint(58, -22, 3000, {.forwards=false, .minSpeed=40});
    chassis.turnToPoint(62, -54, 1000, {.forwards=false});
    chassis.moveToPoint(62, -54, 1000, {.forwards=false});

    // Shove it backwards again to be doubly sure
    chassis.moveToPoint(60, -36, 1000);
    chassis.moveToPoint(62, -54, 1000, {.forwards=false, .minSpeed=40});

    // Move to get in position for the other blue ring stake
    chassis.turnToPoint(54, 6, 1000);
    chassis.moveToPoint(54, 6, 3000, {.minSpeed=40});

    // Turn so the back is facing the left blue ring stake
    chassis.turnToPoint(58, -22, 1000, {.forwards=false});

    // Push in the other blue ring stake into the left corner (mirror the other code)
    chassis.moveToPoint(58, 22, 3000, {.forwards=false, .minSpeed=40});
    chassis.turnToPoint(62, 54, 1000, {.forwards=false});
    chassis.moveToPoint(62, 54, 1000, {.forwards=false});

    // Shove the last stale backwards again to be doubly sure
    chassis.moveToPoint(60, 36, 1000);
    chassis.moveToPoint(62, 54, 1000, {.forwards=false, .minSpeed=40});

    // Back off and finish auton
    chassis.moveToPoint(50, 28, 2000, {.minSpeed=40});
}

void drive_square() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 24, 0, 2000);
    chassis.turnToPoint(24, 24, 2000);
    chassis.moveToPose(24, 24, 90, 2000);
    chassis.turnToPoint(24, 0, 2000);
    chassis.moveToPose(24, 0, 180, 2000);
    chassis.turnToPoint(0, 0, 2000);
    chassis.moveToPose(0, 0, 270, 2000);
    chassis.turnToPoint(0, 24, 2000);
}