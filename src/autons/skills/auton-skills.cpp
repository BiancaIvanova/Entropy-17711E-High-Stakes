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
    currentAllianceColour = AllianceColour::RED;
    
    //  Robot starts with the front facing alliance wall stake
    chassis.setPose(-55.5, 0, 270);

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
    // Score alliance stake
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, 1000, false);
    // Turn and grab left stake
    chassis.moveToPoint(-48, 0, 500, {.forwards=false}, false);
    arm.moveToPosition(ArmPosition::DOWN, false);
    chassis.turnToPoint(-48, 24, 800, {.forwards=false, .maxSpeed=70});
    
    // Clamp the stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-48, 19, 800, {.forwards=false}, true);
    chassis.moveToPoint(-48, 28.5, 800, {.forwards=false, .maxSpeed=50}, false);
    mobile_stake_clamp.set_value(false);
    pros::delay(400);

    // Get the first ring
    intake.intake_control(600, {.jam_detection=false, .coloursort=false});
    chassis.turnToPoint(-20, 24, 500);
    chassis.moveToPoint(-20, 24, 1000);
    
    // Get the second ring into lady brown
    chassis.turnToPoint(0, 52, 750, {}, false);
    chassis.moveToPoint(23, 44, 1200, {}, false); // Get that ring
    intake.intake_control(600, {.jam_detection=false, .coloursort=false});
    arm.moveToPosition(33, 1500, true, 1.0);
    pros::delay(500);

    // Lady brown score
    chassis.moveToPoint(3.5, 42, 400, {.forwards=false}); 
    chassis.moveToPoint(3.5, 42, 800, {.forwards=false}); //move back
    chassis.turnToPoint(3.5, 66, 500); // turn to wall stake
    chassis.moveToPoint(3.5, 66, 1000, {}, false);
    intake.intake_control(0);
    arm.moveToPosition(ArmPosition::WALL_STAKE, 1500, true);
    pros::delay(500);
    intake.intake_control(600, {.jam_detection=false, .coloursort=false});
    chassis.moveToPoint(3.5, 69, 1000, {}, false);
    
    // Move back
    intake.intake_control(600, {.jam_detection=false, .coloursort=false});
    chassis.moveToPoint(3.5, 52, 750, {.forwards=false, .maxSpeed=60});
    intake.intake_control(600, {.jam_detection=false, .coloursort=false});
    chassis.turnToPoint(-60, 52, 500, {}, false);
    arm.moveToPosition(ArmPosition::DOWN, 750, true);
    intake.intake_control(600, {.jam_detection=true, .coloursort=false});

    // Get that line of rings
    chassis.moveToPoint(-60, 52, 3000, {.maxSpeed=51}, false);
    intake.intake_control(600, {.jam_detection=true, .coloursort=false});
    pros::delay(500);

    // Turn and get last ring
    chassis.swingToPoint(-48, 55, DriveSide::LEFT, 750);
    chassis.moveToPoint(-48, 55, 750, {}, false);
    pros::delay(750);

    // Place mogo in corner
    chassis.turnToPoint(-65, 65, 750, {.forwards=false}, false);
    chassis.moveToPoint(-60, 60, 500, {.forwards=false}, false);
    mobile_stake_clamp.set_value(true);
    pros::delay(750);
    intake.intake_control(0);
}

void auton_skills_stage_2()
{
    chassis.moveToPoint(-52, 52, 750);
    chassis.turnToPoint(-52, -14, 750, {.forwards=false}); // turn to face second mogo
    chassis.moveToPoint(-52, -14, 1500, {.forwards=false});
    chassis.moveToPoint(-52, -22, 750, {.forwards=false, .maxSpeed=55}, false);
    chassis.moveToPoint(-52, -24, 750, {.forwards=false, .maxSpeed=42}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);

    // Drive to get first ring
    chassis.turnToPoint(-32, -23.5, 500);
    intake.intake_control(600, {.jam_detection=false, .coloursort=false});
    chassis.moveToPoint(-32, -23.5, 750);

    // Get the second ring into lady brown
    chassis.turnToPoint(-4, -55, 750, {}, false);
    chassis.moveToPoint(12, -48, 1200, {}, false); // get that ring
    intake.intake_control(600, {.jam_detection=false, .coloursort=false});
    arm.moveToPosition(33, 1500, true, 1.0);
    pros::delay(500);

    // Lady brown score
    chassis.moveToPoint(-8, -44, 400, {.forwards=false});
    chassis.moveToPoint(-8, -44, 800, {.forwards=false}); // move back
    chassis.turnToPoint(-8, 66, 500); // turn to wall stake
}

void auton_skills_stage_3()
{
    // Get first ring
    chassis.moveToPoint(20, -48, 1000, {.maxSpeed=85});
    intake.intake_controlled(200);
    pros::delay(750);
    intake.intake_controlled(0);

    // Get second ring
    chassis.turnToPoint(24, -19, 750);
    chassis.moveToPoint(24, -19, 1000);
    pros::delay(500);
    intake.intake_controlled(200);
    pros::delay(750);
    intake.intake_controlled(0);

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
    intake.intake_controlled(500);

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
    intake.intake_controlled(0);

    // Turn around to place mogo in corner
    chassis.turnToPoint(60, 58, 1000, {.forwards=false, .direction=AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    
    // Bash into the wall with the mogo
    chassis.moveToPoint(60, 58, 800, {.forwards=false}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(true);
    intake.intake_controlled(-600);
    pros::delay(250);
    intake.intake_controlled(0);

    // Turn a bit
    chassis.turnToPoint(50, 50, 500);

    // Grab that ring
    intake.intake_controlled(300);
    chassis.moveToPoint(50, 50, 500, {}, false);
    intake.intake_controlled(0);
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
    intake.intake_controlled(600);
    pros::delay(1500);
    intake.intake_controlled(0);

    // Turn and push last mogo in corner
    chassis.turnToPoint(60, -60, 750);
    chassis.moveToPoint(60, -60, 1000, {.minSpeed=60, .earlyExitRange=12});
    chassis.moveToPoint(80, -75, 1000);
    
    // Back off
    chassis.moveToPoint(24, -24, 1500, {.forwards=false});
}