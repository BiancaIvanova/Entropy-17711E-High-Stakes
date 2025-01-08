#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void auton_skills_new()
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


void auton_skills_stage_1_new()
{
    // FIRST STAGE OF AUTON -------------------------------------
    // Open clamp
    mobile_stake_clamp.set_value(true);

    // Lift up arm
    arm_rotation_sensor.set_position(0);
    while (arm_rotation_sensor.get_position() < 6500)
    {
        arm.move_velocity(100);
    }
    arm.move_velocity(0);
    arm_flip.set_value(true);
    pros::delay(400);

    // Put ring on alliance stake
    arm.move_velocity(-100);
    pros::delay(700);

    // Move back curved, and grab left stake
    chassis.moveToPose(-47.157, 23.658, 180, 1000, {.forwards=false});
    mobile_stake_clamp.set_value(false);

    // Turn and grab first ring
    chassis.turnToPoint(-23, 25, 700);
    intake_controlled(600);
    chassis.moveToPoint(-23, 25, 1000);

    // Grab second ring, on the far side of the field
    chassis.turnToPoint(21, 47, 700);
    chassis.moveToPoint(21, 47, 1500);
    pros::delay(500);

    // Move back and align with wall 
    chassis.moveToPoint(0, 37, 1000, {.forwards=false});
    chassis.turnToHeading(0, 700);
    intake_controlled(0);

    // Move forward and intake ring for wall stake
    intake.move_velocity(600);
    chassis.moveToPoint(0, 53, 5000);
    



    chassis.moveTo(-0.159, 47.929, 5000);
    chassis.moveTo(-56.217, 47.08, 5000);
    chassis.moveTo(-48.289, 57.555, 5000);
    chassis.moveTo(-57.915, 58.971, 5000);


}