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
    //chassis.setPose(-62.5, 0, 270);
    //pros::delay(1000);

    // Deal with the close left side of the field
    //auton_skills_stage_1_new();
    // Do the same with the close right side of the field
    //auton_skills_stage_2_new();
    // Move to the back of the field and fill the last empty stake
    auton_skills_stage_3_new();
    // Finish by putting the two blue ring stakes into the corners
    //auton_skills_stage_4_new();

}

void auton_skills_stage_3_new()
{
    chassis.setPose(-55.084, 0.725, 270);
    intake_controlled(600);
    chassis.turnToPoint(-55.084, 0.725, 2000);
    chassis.moveToPoint(-55.084, 0.725, 2000);

    chassis.turnToPoint(-47.157, 23.658, 2000);
    chassis.moveToPoint(-47.157, 23.658, 2000);

    chassis.turnToPoint(-21.676, 26.978, 2000);
    chassis.moveToPoint(-21.676, 26.978, 2000);

    chassis.turnToPoint(20.792, 47.08, 2000);
    chassis.moveToPoint(20.792, 47.08, 2000);

    chassis.turnToPoint(0.408, 37.737, 2000);
    chassis.moveToPoint(0.408, 37.737, 2000);

    chassis.turnToPoint(-0.159, 55.29, 2000);
    chassis.moveToPoint(-0.159, 55.29, 2000);

    chassis.turnToPoint(-0.159, 47.929, 2000);
    chassis.moveToPoint(-0.159, 47.929, 2000);

    chassis.turnToPoint(-59.048, 48.495, 2000);
    chassis.moveToPoint(-59.048, 48.495, 2000);

    chassis.turnToPoint(-57.349, 62.368, 2000);
    chassis.moveToPoint(-57.349, 62.368, 2000);

    chassis.turnToPoint(-47.723, -5.581, 2000);
    chassis.moveToPoint(-47.723, -5.581, 2000);

    chassis.turnToPoint(-47.44, -27.098, 2000);
    chassis.moveToPoint(-47.44, -27.098, 2000);

    chassis.turnToPoint(-23.658, -26.249, 2000);
    chassis.moveToPoint(-23.658, -26.249, 2000);
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
        ////arm.move_velocity(100);
    }
    ////arm.move_velocity(0);
    arm_flip.set_value(true);
    pros::delay(400);

    // Put ring on alliance stake
    ////arm.move_velocity(-100);
    pros::delay(700);

    // Move back, and grab left stake
    chassis.moveToPoint(-50, 0, 1500, {.forwards=false});
    arm_flip.set_value(false);
    chassis.turnToPoint(-50, 24, 1500, {.forwards=false});
    chassis.moveToPoint(-50, 24, 1500, {.forwards=false}, false);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);

    // Turn and grab first ring
    chassis.turnToPoint(-23, 27, 700);
    intake_controlled(600);
    chassis.moveToPoint(-23, 27, 1000);

    // Grab second ring, on the far side of the field
    chassis.turnToPoint(21, 47, 700);
    chassis.moveToPoint(21, 47, 1500);
    pros::delay(500);

    // Move back and align with wall 
    chassis.moveToPoint(0, 37, 1000, {.forwards=false});
    chassis.turnToHeading(0, 700);
    pros::delay(700);
    intake_controlled(0);

    // Move forward and intake ring for wall stake
    intake.move_velocity(400);
    chassis.moveToPoint(0, 53, 1000);

    bool ring_successful = false;
    int loop_counter = 0;
    while (loop_counter < (4000 / TASK_DELAY_MS))
    {
        if (optical_sensor.get_hue() > 5 && optical_sensor.get_hue() < 25 && optical_sensor.get_proximity() < 100)
        {
            ring_successful = true;
            break;
        }
        loop_counter++;
    }

    if (ring_successful)
    {
        // Intake slightly further, then outtake into arm
        arm_flip.set_value(false);
        intake.move_relative(600, 300);
        intake.move_relative(-2000, 600);

        // Raise arm
        while (arm_rotation_sensor.get_position() < 9000)
        {
            ////arm.move_velocity(100);
        }
        
        // Move forward
        chassis.moveToPoint(0, 58, 500);

        // Lower arm
        ////arm.move_velocity(-100);
    }

    // If it got the ring or not, move back
    chassis.moveToPoint(0, 51, 1200, {.forwards=false});

    // Turn and get that whole row of rings
    chassis.turnToHeading(260, 1500);
    intake_controlled(600);
    chassis.moveToPoint(-58, 51, 4000, {.maxSpeed=45});

    // Turn and place the stake into the corner
    chassis.turnToHeading(180, 1000);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(chassis.getPose(false).x, chassis.getPose(false).y - 10, 1500);
    mobile_stake_clamp.set_value(true);
    
    // Outtake a little to prevent getting stuck on rings
    intake_controlled(0);
    intake.move_velocity(-600);
    pros::delay(500);
    intake.move_velocity(0);

    // Move curved to in front of the other stake
    chassis.moveToPose(-48, 0, 180, 3000);
    chassis.turnToHeading(180, 1000);
    pros::delay(500);

    // Turn to face that stake and grab it
    chassis.turnToPoint(-48, -27, 1500, {.forwards=false, .maxSpeed=80});
    chassis.moveToPoint(-48, -24, 1000, {.forwards=false, .maxSpeed=45});
    mobile_stake_clamp.set_value(false);
    chassis.turnToHeading(0, 1800);
    pros::delay(700);

    // Allegedly finishes at -48, -27, 0
}

void auton_skills_stage_2_new()
{
    // Just reset pose, I'm not dealing with this
    chassis.setPose(-48, -27, 0);

    // Start intake
    intake_controlled(600);

    // Turn to grab first ring
    chassis.turnToPoint(-23, -26, 1000);
    chassis.moveToPoint(-23, -26, 1500);
}