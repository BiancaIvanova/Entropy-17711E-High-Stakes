#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


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
    auton_skills_stage_3();
    // Finish by putting the two blue ring stakes into the corners
    //auton_skills_stage_4();

}


void auton_skills_stage_1()
{
    // FIRST STAGE OF AUTON -------------------------------------
    mobile_stake_clamp.set_value(true);
    pros::delay(500);
    chassis.moveToPoint(-42, 24, 1500, {.forwards=false});
    pros::delay(750);
    mobile_stake_clamp.set_value(false);
    pros::delay(750);

    // Move to pick up stake
    intake_controlled(600);
    
    // Move to collect first ring
    chassis.turnToPoint(-29, 23, 2000, {.maxSpeed = 50});
    chassis.moveToPoint(-29, 24, 2000);

    // Move to collect second ring
    chassis.turnToPoint(-24, 50, 2000, {.maxSpeed = 50});
    chassis.moveToPoint(-24, 50, 2000);

    // Move to collect third and fourth rings
    chassis.turnToPoint(-68, 52, 2000);
    chassis.moveToPoint(-68, 52, 2000, {.maxSpeed = 50});
    pros::delay(1500);

    // Move to collect fifth/last ring
    chassis.turnToPoint(-60, 48, 2000);
    chassis.moveToPoint(-60, 48, 2000, {.maxSpeed = 50});

    // Swing to dump the mobile stake in the corner and position to grab the other one
    chassis.turnToPoint(-72, 72, 2000, {.forwards = false});
    chassis.moveToPoint(-72, 72, 2000, {.forwards = false});
    intake_controlled(0);
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-54, 42, 2000, {.maxSpeed = 65});
    
}


void auton_skills_stage_2()
{
    // SECOND STAGE OF AUTON -----------------------------------------------
    // Move out into path of the stake
    chassis.turnToPoint(-64, -18, 2500, {.forwards = false, .maxSpeed = 60});

    // Drive backwards slowly to pick up the next stake
    chassis.moveToPoint(-64, -12, 3000, {.forwards=false, .maxSpeed = 50}, false);
    chassis.moveToPoint(-64, -18, 3000, {.forwards=false, .maxSpeed = 105}, false);
    pros::delay(500);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);

    // Reset pose
    chassis.setPose(-48, -28.5, 0);

    // Start scoring rings
    intake_controlled(600);

    // Move to collect first ring
    chassis.turnToPoint(-24, -24, 1000);
    chassis.moveToPoint(-24, -24, 1000);

    // Move to collect second ring
    chassis.turnToPoint(-20, -48, 1000);
    chassis.moveToPoint(-20, -48, 1000);

    // Move to collect third and fourth rings
    chassis.turnToPoint(-65, -53, 1000);
    chassis.moveToPoint(-65, -53, 2500, {.maxSpeed = 50}, false);
    pros::delay(500);

    // Swing to dump the mobile stake in the corne
    pros::delay(750);
    chassis.turnToPoint(-70, -73, 1000, {.forwards=false});
    chassis.moveToPoint(-70, -73, 1000, {.forwards = false}, false);
    mobile_stake_clamp.set_value(true);
    intake_controlled(0);

    chassis.turnToPoint(-42, -50, 1500, {.maxSpeed = 50});
    chassis.moveToPoint(-42, -50, 2000);

}


void auton_skills_stage_3()
{
    // THIRD STAGE OF AUTON -----------------------------------------------

    // Square off
    chassis.turnToPoint(-100, -50, 1000, {.forwards=false});
    chassis.moveToPoint(-100, -50, 2000, {.forwards=false, .maxSpeed=70});
    // Reset pose
    chassis.setPose(-32, -44, 85);

    // Move to collect first ring
    chassis.moveToPoint(-9, -47, 3000, {}, false);
    intake_controlled(600);
    // Actually collect first ring
    chassis.moveToPoint(22, -47, 3000, {.maxSpeed=50}, false);
    pros::delay(1000);
    intake_controlled(0);

    // Move to collect second ring
    chassis.turnToPoint(22, -22, 1000, {.maxSpeed=50});
    intake_controlled(600);
    chassis.moveToPoint(22, -22, 1000, {.maxSpeed=70});
    pros::delay(500);
    intake_controlled(0);
    pros::delay(1000);

    // Grab last empty stake and put the rings onto it
    chassis.turnToPoint(46, 2, 1000, {.forwards=false, .maxSpeed=70});
    chassis.moveToPoint(46, 2, 1000, {.forwards=false, .maxSpeed=70});
    pros::delay(1000);
    mobile_stake_clamp.set_value(false);
    intake.move_velocity(600);
    
    /*
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
    */
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