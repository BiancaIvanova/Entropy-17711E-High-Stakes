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

    // Deal with the close left side of the field
    auton_skills_stage_1();
    // Do the same with the close right side of the field
    auton_skills_stage_2();
    // Move to the back of the field and fill the last empty stake
    auton_skills_stage_3();
    // Finish by putting the two blue ring stakes into the corners
    auton_skills_stage_4();

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
    chassis.turnToPoint(-60, 52, 2000);
    chassis.moveToPoint(-60, 52, 2000, {.maxSpeed = 50});
    pros::delay(1500);

    // Move to collect fifth/last ring
    chassis.turnToPoint(-60, 48, 2000);
    chassis.moveToPoint(-60, 48, 2000, {.maxSpeed = 50});

    // Swing to dump the mobile stake in the corner and position to grab the other one
    chassis.turnToPoint(-72, 72, 2000, {.forwards = false});
    chassis.moveToPoint(-72, 72, 2000, {.forwards = false});
    intake_controlled(0);
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-54, 42, 1500, {.maxSpeed = 65});
    
}


void auton_skills_stage_2()
{
    // SECOND STAGE OF AUTON -----------------------------------------------
    // Move out into path of the stake
    chassis.turnToPoint(-64, -18, 1750, {.forwards = false, .maxSpeed = 60});

    // Drive backwards slowly to pick up the next stake
    chassis.moveToPoint(-64, -12, 3000, {.forwards=false, .maxSpeed = 70}, false);
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
    chassis.turnToPoint(-55, -53, 1000);
    chassis.moveToPoint(-55, -53, 2500, {.maxSpeed = 50}, false);
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
    chassis.setPose(-28, -44, 85);

    // Move to collect first ring
    chassis.moveToPoint(-9, -47, 3000, {}, false);
    // Actually collect first ring
    chassis.moveToPoint(18, -47, 3000, {.maxSpeed=50}, false);
    intake_controlled(400);
    pros::delay(1000);
    intake_controlled(0);
    pros::delay(500);

    // Move to collect second ring
    chassis.turnToPoint(28, -22, 1000, {.maxSpeed=50});
    intake_controlled(200);
    chassis.moveToPoint(28, -22, 1000, {.maxSpeed=70});
    pros::delay(1500);
    intake_controlled(0);
    pros::delay(500);

    // Grab last empty stake and put the rings onto it
    chassis.turnToPoint(54, 5, 1000, {.forwards=false, .maxSpeed=70});
    chassis.moveToPoint(54, 5, 1000, {.forwards=false, .maxSpeed=70}, false);
    pros::delay(1000);
    mobile_stake_clamp.set_value(false);
    pros::delay(750);
    intake.move_velocity(600);
    
    pros::delay(2000);
}


void auton_skills_stage_4()
{
    // FOURTH STAGE OF AUTON -----------------------------------------------
    // Turn to face the right blue stake
    chassis.turnToPoint(70, -20, 1000, {}, false);

    // Let go of stake
    intake_controlled(0);
    mobile_stake_clamp.set_value(true);

    // Drive to right blue stake
    chassis.moveToPoint(70, -30, 500);
    
    // Shove the stake into the corner at speed
    chassis.turnToPoint(78, -76, 500);
    chassis.moveToPoint(80, -78, 2000, {.minSpeed=120});

    // Back off the stake
    intake.move_velocity(-600);
    chassis.moveToPoint(56, 0, 1000, {.forwards=false});

    // Turn to face stake and push it
    chassis.turnToPoint(70, 26, 1000, {.forwards=false});
    chassis.moveToPoint(70, 26, 500, {.forwards=false, .minSpeed=40});

    // Shove it in the corner
    chassis.turnToPoint(78, 76, 500, {.forwards=false});
    chassis.moveToPoint(78, 76, 1200, {.forwards=false, .minSpeed=120});

    // Back off the stake
    chassis.moveToPoint(-50, -50, 1000);
}
