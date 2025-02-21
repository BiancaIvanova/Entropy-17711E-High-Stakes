#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void double_side_red()
{
    currentAllianceColour = AllianceColour::RED;
    AllianceColour currentAllianceColour = AllianceColour::RED;
    ////arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-55, 11, 180);

    // Open mogo clamp
    mobile_stake_clamp.set_value(true);

    // Open arm mech
    arm_rotation_sensor.set_position(0);
    while (arm_rotation_sensor.get_position() < 5500)
    {
        ////arm.move_velocity(100);
    }
    ////arm.move_velocity(0);
    doinker.set_value(true);

    // Turn to alliance stake
    chassis.swingToHeading(245, DriveSide::RIGHT, 1000, {.maxSpeed=60}, false);
    ////arm.move_velocity(-100);
    pros::delay(650);

    // Move back to stake
    chassis.moveToPoint(-20, 26, 1750, {.forwards=false, .maxSpeed=70});
    //chassis.moveToPoint(-12, 29, 1000, {.forwards=false, .maxSpeed=60});

    // Fold arm back
    doinker.set_value(false);

    // Clamp on stake
    chassis.waitUntilDone();
    pros::delay(200);
    mobile_stake_clamp.set_value(false);
    ////arm.move_velocity(0);
    pros::delay(500);

    // Score first ring
    intake.move_velocity(600);
    chassis.turnToPoint(-24, 40, 1000, {.maxSpeed=80}, false);
    chassis.moveToPoint(-24, 40, 1500, {.maxSpeed=100}, false);

    // Score second ring
    chassis.turnToPoint(-12, 43, 1000, {.maxSpeed=80}, false);
    chassis.moveToPoint(-12, 43, 1000, {.maxSpeed=100}, false);
    pros::delay(500);

    // Move back
    chassis.moveToPoint(-21, 43, 1500, {.forwards=false, .maxSpeed=127}, false);

    // Move out to the middle of the field and let go of stake
    chassis.turnToPoint(-43, -2, 1000, {.minSpeed=60}, false);
    mobile_stake_clamp.set_value(true);
    intake.move_velocity(0);
    chassis.moveToPoint(-10, -2, 1000, {.minSpeed=60}, false);
    
    // Turn and grab other mobile stake
    chassis.turnToPoint(-23, -23, 1000, {.forwards=false, .maxSpeed=80}, false);
    chassis.moveToPoint(-23, -23, 1000, {.forwards=false, .maxSpeed=80}, false);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);

    // Turn and score last ring
    intake.move_velocity(600);
    chassis.turnToPoint(-23, -39, 1000, {.maxSpeed=127}, false);
    chassis.moveToPoint(-23, -39, 1000, {.maxSpeed=110}, false);

    // Turn and touch ladder
    chassis.turnToPoint(-23, -7, 1000, {.maxSpeed=127}, false);
    chassis.moveToPoint(-23, -7, 1000, {.maxSpeed=110}, false);
}


void double_side_blue()
{
    currentAllianceColour = AllianceColour::BLUE;
    ////arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(55, 11, -180);

    // Open mogo clamp
    mobile_stake_clamp.set_value(true);

    // Open arm mech
    arm_rotation_sensor.set_position(0);
    while (arm_rotation_sensor.get_position() < 5500)
    {
        /////arm.move_velocity(100);
    }
    ////arm.move_velocity(0);
    doinker.set_value(true);

    // Turn to alliance stake
    chassis.swingToHeading(-245, DriveSide::LEFT, 1000, {.maxSpeed=60}, false);
    ////arm.move_velocity(-100);
    pros::delay(1000);

    // Move back to stake
    chassis.moveToPoint(20, 26, 1750, {.forwards=false, .maxSpeed=70});
    //chassis.moveToPoint(-12, 29, 1000, {.forwards=false, .maxSpeed=60});

    // Fold arm back
    doinker.set_value(false);

    // Clamp on stake
    chassis.waitUntilDone();
    pros::delay(500);
    mobile_stake_clamp.set_value(false);
    ////arm.move_velocity(0);
    pros::delay(500);

    // Score first ring
    intake.move_velocity(600);
    chassis.turnToPoint(20, 40, 1000, {.maxSpeed=70}, false);
    chassis.moveToPoint(20, 40, 1500, {.maxSpeed=80}, false);

    // Score second ring
    chassis.turnToPoint(8, 43, 1000, {.maxSpeed=70}, false);
    chassis.moveToPoint(8, 43, 1000, {.maxSpeed=80}, false);
    pros::delay(500);

    // Move back
    chassis.moveToPoint(17, 43, 1500, {.forwards=false, .maxSpeed=50}, false);

    // Move out to the middle of the field and let go of stake
    chassis.turnToPoint(43, -2, 1000, {.minSpeed=60}, false);
    mobile_stake_clamp.set_value(true);
    intake.move_velocity(0);
    chassis.moveToPoint(10, -2, 1000, {.minSpeed=60}, false);
    
    // Turn and grab other mobile stake
    chassis.turnToPoint(23, -23, 1000, {.forwards=false, .maxSpeed=80}, false);
    chassis.moveToPoint(23, -23, 1000, {.forwards=false, .maxSpeed=80}, false);
    mobile_stake_clamp.set_value(false);
    pros::delay(500);

    // Turn and score last ring
    intake.move_velocity(600);
    chassis.turnToPoint(23, -39, 1000, {.maxSpeed=127}, false);
    chassis.moveToPoint(23, -39, 1000, {.maxSpeed=110}, false);

    // Turn and touch ladder
    chassis.turnToPoint(23, -7, 1000, {.maxSpeed=127}, false);
    chassis.moveToPoint(23, -7, 1000, {.maxSpeed=110}, false);
}


void elims_red()
{
    chassis.setPose(-51, 30, 72);
    intake_controlled(600);
    
    // rush ring stacks
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-9, 42.5, 1500, {.minSpeed=85});
    pros::delay(1500);
    chassis.moveToPoint(-16, 40, 750, {.forwards=false}, false);

    // turn to grab stake
    chassis.turnToPoint(-23, 24.5, 1000, {.forwards=false});
    intake_controlled(0);
    chassis.moveToPoint(-22, 26, 1000, {.forwards=false}, false);
    chassis.moveToPoint(-23, 25.5, 750, {.forwards=false}, false);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    intake_controlled(600);

    // turn to grab ring
    chassis.turnToPoint(-23, 50, 1500);
    chassis.moveToPoint(-23, 50, 1500);
    pros::delay(750);

    // alliance stake
    chassis.turnToPoint(-52, -5.5, 1500);
    chassis.moveToPoint(-52, -10, 2000); // forward
    pros::delay(250);
    ////arm.move_velocity(100);
    chassis.moveToPoint(-52, -5.5, 1000, {.forwards=false}); // back
    intake_controlled(0);
    chassis.turnToHeading(270, 1000);

    // go forward
    chassis.moveToPoint(-57, -5.5, 1500);
    pros::delay(750);

    // put wall stake
    doinker.set_value(true);
    ////arm.move_velocity(-100);
    pros::delay(1250);

    // back off
    chassis.moveToPoint(-50, -5.5, 1500, {.forwards=false, .minSpeed=60});

    // positive corner
    chassis.moveToPoint(-60, -53, 2000, {.minSpeed=85});
}


void elims_blue()
{
    chassis.setPose(51, 30, 288);
    intake_controlled(600);
    
    // rush ring stacks
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(9, 42.5, 1500, {.minSpeed=85});
    pros::delay(1500);
    chassis.moveToPoint(16, 40, 750, {.forwards=false}, false);

    // turn to grab stake
    chassis.turnToPoint(23, 24.5, 1000, {.forwards=false});
    intake_controlled(0);
    chassis.moveToPoint(22, 26, 1000, {.forwards=false}, false);
    chassis.moveToPoint(23, 25.5, 750, {.forwards=false}, false);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    intake_controlled(600);

    // turn to grab ring
    chassis.turnToPoint(23, 50, 1500);
    chassis.moveToPoint(23, 50, 1500);
    pros::delay(750);

    // alliance stake
    chassis.turnToPoint(52, -5.5, 1500);
    chassis.moveToPoint(52, -10, 2000); // forward
    pros::delay(250);
    ////arm.move_velocity(100);
    chassis.moveToPoint(52, -5.5, 1000, {.forwards=false}); // back
    intake_controlled(0);
    chassis.turnToHeading(90, 1000);

    // go forward
    chassis.moveToPoint(57, -5.5, 1500);
    pros::delay(750);

    // put wall stake
    doinker.set_value(true);
    ////arm.move_velocity(-100);
    pros::delay(1250);

    // back off
    chassis.moveToPoint(50, -5.5, 1500, {.forwards=false, .minSpeed=60});

    // positive corner
    chassis.moveToPoint(60, -53, 2000, {.minSpeed=85});
}