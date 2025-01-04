#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void auton_skills()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    
    // Robot starts with the back directly facing alliance wall stake
    chassis.setPose(-62.5, 0, 270);
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
    // Lift up arm
    arm_rotation_sensor.set_position(0);
    while (arm_rotation_sensor.get_position() < 6500)
    {
        arm.move_velocity(100);
    }
    arm.move_velocity(0);
    arm_flip.set_value(true);
    pros::delay(500);

    // Put ring on alliance stake
    arm.move_velocity(-100);
    pros::delay(1000);

    // Move back
    chassis.moveToPoint(-50, 0, 1500, {.forwards=false});
    arm_flip.set_value(false);
    chassis.turnToPoint(-50, 24, 1500, {.forwards=false});

    // Move to pick up stake
    mobile_stake_clamp.set_value(true);
    pros::delay(500);
    chassis.moveToPoint(-50, 24, 1500, {.forwards=false});
    pros::delay(750);
    mobile_stake_clamp.set_value(false);
    pros::delay(750);

    // Move to pick up stake
    intake_controlled(600);
    
    // Move to collect first ring
    chassis.turnToPoint(-29, 23, 2000);
    chassis.moveToPoint(-29, 24, 2000);

    // Move to collect second ring
    chassis.turnToPoint(-24, 50, 2000);
    chassis.moveToPoint(-24, 50, 2000);

    // Move to collect third and fourth rings
    chassis.turnToPoint(-60, 52, 2000);
    chassis.moveToPoint(-60, 52, 2000);
    pros::delay(1500);

    // Move to collect fifth/last ring
    chassis.turnToPoint(-60, 48, 1000);
    chassis.moveToPoint(-60, 48, 1000);

    // Swing to dump the mobile stake in the corner and position to grab the other one
    chassis.turnToPoint(-72, 72, 1000, {.forwards = false});
    chassis.moveToPoint(-72, 72, 1000, {.forwards = false});
    intake_controlled(0);
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-54, 42, 1200, {.maxSpeed = 65});
    
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
    chassis.turnToPoint(-20, -21, 1000);
    chassis.moveToPoint(-20, -21, 1000);

    // Move to collect second ring
    chassis.turnToPoint(-18, -48, 1000);
    chassis.moveToPoint(-18, -48, 1000);

    // Move to collect third and fourth rings
    chassis.turnToPoint(-68, -53, 1000);
    chassis.moveToPoint(-68, -53, 2500, {.maxSpeed = 60}, false);
    pros::delay(350);

    // Swing to dump the mobile stake in the corner
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
    chassis.turnToPoint(-9, -44, 1000, {}, false);

    // Move to collect first ring
    chassis.moveToPoint(-9, -44, 3000, {}, false);
    // Actually collect first ring
    intake_controlled(400);
    chassis.moveToPoint(18, -44, 3000, {.maxSpeed=50}, false);
    pros::delay(500);
    intake_controlled(0);
    pros::delay(500);

    // Grab last empty stake and put the rings onto it
    chassis.turnToPoint(38, -3, 1000, {.forwards=false, .maxSpeed=70});
    chassis.moveToPoint(35, -3, 2000, {.forwards=false, .maxSpeed=70}, false);
    chassis.moveToPoint(35, 4, 2000, {.forwards=false, .minSpeed=80}, false);
    pros::delay(500);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);
    intake.move_velocity(600);
    
    pros::delay(1000);
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
    chassis.turnToPoint(68, 76, 500, {.forwards=false});
    chassis.moveToPoint(68, 76, 1200, {.forwards=false, .minSpeed=120});

    // Back off the stake
    chassis.moveToPoint(50, 50, 1000, {.forwards=false});

    // Turn to ladder rung
    arm.move_velocity(100);
    chassis.turnToPoint(9, -22, 1000, {}, false);
    chassis.moveToPoint(9, -22, 2000, {.minSpeed=100});
    chassis.tank(-127, -127, false);
}

