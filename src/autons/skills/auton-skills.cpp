#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void auton_skills()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    arm.resetPosition(ArmPosition::LOAD);
    
    //Robot starts with the front facing alliance wall stake
    chassis.setPose(-60, 0, 90);

    // Deal with the close left side of the field
    auton_skills_stage_1();
    // Do the same with the close right side of the field
    auton_skills_stage_2();
    // Move to the back of the field and fill the last empty stake
    //auton_skills_stage_3_new();
    // Finish by putting the two blue ring stakes into the corners
    //auton_skills_stage_4_new();

}

void auton_skills_stage_1()
{
    // Score alliance stake
    intake_controlled(600);
    pros::delay(750);
    intake_controlled(0);
    chassis.moveToPoint(-50, 0, 500);

    // Turn and grab left stake
    chassis.turnToPoint(-48, 24, 750, {.forwards=false});
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-48, 20, 1000, {.forwards=false}, false);
    pros::delay(350);
    chassis.moveToPoint(-48, 25, 500, {.forwards=false, .maxSpeed=50}, false);
    pros::delay(350);
    mobile_stake_clamp.set_value(false);
    pros::delay(400);

    // Get the first ring
    intake_controlled(500); //fix
    chassis.turnToPoint(-24, 21, 500);
    chassis.moveToPoint(-24, 21, 1000);
    
    // Get the second ring
    chassis.turnToPoint(-4.5, 48, 750);
    chassis.moveToPoint(-4.5, 48, 1200);

    // Get the third ring
    chassis.turnToPoint(-21, 46, 750);
    chassis.moveToPoint(-21, 46, 1200);

    // Get the fourth/fifth rings
    chassis.turnToPoint(-55, 46, 750);
    chassis.moveToPoint(-55, 48, 1500, {.maxSpeed=85});
    pros::delay(350);

    // Get the sixth ring
    chassis.turnToPoint(-53, 58, 500);
    chassis.moveToPoint(-53, 58, 500);

    // Leave mogo in the left corner
    chassis.turnToPoint(0, 24, 500, {}, false);
    pros::delay(1500);
    mobile_stake_clamp.set_value(true);
    intake_controlled(-600);
    pros::delay(250);
    intake_controlled(0);

    // Push it into the corner
    chassis.moveToPoint(-75, 75, 1000, {.forwards=false});
}

void auton_skills_stage_2()
{
    chassis.setPose(-52, 58, 120);
    // Drive forwards to the right mogo
    chassis.moveToPoint(-48, 53, 1500, {.maxSpeed=70});

    // Move and grab mogo
    chassis.turnToPoint(-48, -28, 800, {.forwards=false, .maxSpeed=65}, false);
    chassis.moveToPoint(-48, -28, 1750, {.forwards=false, .maxSpeed=85, .earlyExitRange=10}, false);
    pros::delay(300);
    chassis.moveToPoint(-48, -28, 1200, {.forwards=false, .maxSpeed=45}, false); // slower
    pros::delay(750);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);
    
    // Get the first ring
    intake_controlled(500); // fix
    chassis.turnToPoint(-28, -20, 750);
    chassis.moveToPoint(-28, -20, 1000);

    // Get the second ring
    chassis.turnToPoint(-11, -45, 750);
    chassis.moveToPoint(-11, -45, 1250);
    
    // Get the third ring
    chassis.turnToPoint(-26, -42, 750);
    chassis.moveToPoint(-26, -42, 1000);

    // Get the fourth/fifth rings
    chassis.turnToPoint(-61, -43, 750);
    chassis.moveToPoint(-61, -43, 2000, {.maxSpeed=85});

    // Get the sixth ring
    chassis.turnToPoint(-58, -48, 500);
    chassis.moveToPoint(-58, -48, 750);
    /*
    
    // Leave mogo in the right corner
    chassis.turnToPoint(0, 24, 500);
    
    mobile_stake_clamp.set_value(true);
    intake_controlled(0);
    */
}