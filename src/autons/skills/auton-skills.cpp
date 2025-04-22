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
    
    //  Robot starts with the front facing alliance wall stake
    chassis.setPose(-60, 0, 90);

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
    chassis.turnToPoint(-24, 23, 500);
    chassis.moveToPoint(-24, 23, 1000);
    
    // Get the second ring
    chassis.turnToPoint(-4.5, 51, 750);
    chassis.moveToPoint(-4.5, 51, 1200);

    // Get the third ring
    chassis.turnToPoint(-21, 46, 750);
    chassis.moveToPoint(-21, 46, 1200);

    // Get the fourth/fifth rings
    chassis.turnToPoint(-55, 44, 750);
    chassis.moveToPoint(-55, 44, 1500, {.maxSpeed=85});
    pros::delay(350);

    // Get the sixth ring
    chassis.turnToPoint(-50, 53, 1000);
    chassis.moveToPoint(-50, 53, 1200);

    // Move a bit back before turning
    chassis.moveToPoint(-49, 49, 1000, {.forwards=false});

    // Leave mogo in the left corner
    chassis.turnToPoint(0, 30, 500, {}, false);
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
    chassis.turnToHeading(130, 500);
    chassis.setPose(-54, 54, 130);
    
    // Drive forwards to the right mogo
    chassis.moveToPoint(-48, 50, 1500, {.maxSpeed=70});

    // Bash into the wall
    chassis.turnToPoint(-48, 75, 1000);
    chassis.moveToPoint(-48, 75, 1000, {}, false);
    pros::delay(500);
    chassis.setPose(-48, 60, 0);

    // Move and grab mogo
    chassis.turnToPoint(-48, -26, 2000, {.forwards=false, .maxSpeed=45}, false);
    chassis.moveToPoint(-48, -26, 1750, {.forwards=false, .maxSpeed=85, .earlyExitRange=10}, false);
    pros::delay(300);
    chassis.moveToPoint(-48, -28, 1200, {.forwards=false, .maxSpeed=45}, false); // slower
    pros::delay(750);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);
    
    // Get the first ring
    intake_controlled(500); // fix
    chassis.turnToPoint(-28, -22, 750);
    chassis.moveToPoint(-28, -22, 1000);

    // Get the second ring
    chassis.turnToPoint(-6, -48, 750);
    chassis.moveToPoint(-6, -48, 1200);
    
    // Get the third ring
    chassis.turnToPoint(-21, -46, 1000);
    chassis.moveToPoint(-21, -46, 1000);

    // Get the fourth/fifth rings
    chassis.turnToPoint(-53, -44, 750);
    chassis.moveToPoint(-53, -44, 2000, {.maxSpeed=85});

    // Get the sixth ring
    chassis.turnToPoint(-48, -53, 1000);
    chassis.moveToPoint(-48, -53, 1200);

    // Move a bit back before turning
    chassis.moveToPoint(-49, -49, 1000, {.forwards=false});
    
    // Leave mogo in the right corner
    chassis.turnToPoint(0, -30, 500, {}, false);
    pros::delay(1500);
    mobile_stake_clamp.set_value(true);
    intake_controlled(-600);
    pros::delay(250);
    intake_controlled(0);

    // Push it into the corner
    chassis.moveToPoint(-75, -75, 1000, {.forwards=false});

    // Reset pose there
    chassis.setPose(-58, -57, 50);

    // Drive forwards
    chassis.moveToPoint(-55, -56, 1500, {.maxSpeed=70});

    // Bash into the wall
    chassis.turnToPoint(-75, -56, 1000, {.forwards=false});
    chassis.moveToPoint(-75, -56, 1000, {.forwards=false}, false);
    pros::delay(500);
    chassis.setPose(-60, -48, 90);

    // Drive to other side of field
    chassis.moveToPoint(8, -48, 2000, {.maxSpeed=85});
}

void auton_skills_stage_3()
{
    // Get first ring
    chassis.moveToPoint(20, -48, 1000, {.maxSpeed=85});
    intake_controlled(200);
    pros::delay(750);
    intake_controlled(0);

    // Get second ring
    chassis.turnToPoint(24, -19, 750);
    chassis.moveToPoint(24, -19, 1000);
    pros::delay(500);
    intake_controlled(200);
    pros::delay(750);
    intake_controlled(0);

    // Turn and grab back mobile goal
    mobile_stake_clamp.set_value(true);
    chassis.turnToPoint(48, 0, 1250, {.forwards=false, .maxSpeed=80});
    chassis.moveToPoint(48, 0, 1500, {.forwards=false, .maxSpeed=80, .earlyExitRange=8}, false);
    pros::delay(40);
    chassis.moveToPoint(48, 0, 1000, {.forwards=false, .maxSpeed=35});
    pros::delay(500);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);

    // Score the two rings
    intake_controlled(500);

    // Score the third ring
    chassis.turnToPoint(24, 24, 750);
    chassis.moveToPoint(24, 24, 1000);
    
    // Score the fourth ring
    chassis.turnToPoint(24, 58, 750);
    chassis.moveToPoint(24, 58, 1000);

    // Score the fifth and last ring
    chassis.turnToPoint(41, 58, 1000);
    chassis.moveToPoint(41, 58, 1500, {.maxSpeed=85});

    // Move back
    chassis.moveToPoint(37, 58, 500, {.forwards=false});
    intake_controlled(0);

    // Turn around to place mogo in corner
    chassis.turnToPoint(60, 58, 1000, {.forwards=false, .direction=AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    
    // Bash into the wall with the mogo
    chassis.moveToPoint(60, 58, 800, {.forwards=false}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(true);
    intake_controlled(-600);
    pros::delay(250);
    intake_controlled(0);

    // Turn a bit
    chassis.turnToPoint(50, 50, 500);

    // Grab that ring
    intake_controlled(300);
    chassis.moveToPoint(50, 50, 500, {}, false);
    intake_controlled(0);
}

void auton_skills_stage_4()
{
    //chassis.setPose(50, 50, 225);

    // Drive out of corner
    chassis.moveToPoint(45, 45, 1000, {.maxSpeed=70});

    // Turn and drive to alliance stake
    chassis.turnToPoint(45, 0, 1000, {.forwards=false, .maxSpeed=95}, false);
    chassis.moveToPoint(45, 0, 1750, {.forwards=false, .maxSpeed=95}, false);

    // Align with and back into stake
    chassis.turnToPoint(66, -2.5, 1500, {.forwards=false, .maxSpeed=35}, false);
    chassis.moveToPoint(66, -2.5, 2000, {.forwards=false, .maxSpeed=45}, false);

    // Go a bit forward
    chassis.setPose(66, 0, 270);
    chassis.moveToPoint(62, 0, 1000, {.maxSpeed=70});

    // Score whatever ring is being held
    intake_controlled(600);
    pros::delay(1500);
    intake_controlled(0);

    // Turn and push last mogo in corner
    chassis.turnToPoint(60, -60, 750);
    chassis.moveToPoint(60, -60, 1000, {.minSpeed=60, .earlyExitRange=12});
    chassis.moveToPoint(80, -75, 1000);
    
    // Back off
    chassis.moveToPoint(24, -24, 1500, {.forwards=false});
}