#include "autons.h"
#include "config.h"
#include "subsystem-control-functions.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void south_side_red()
{
    //currentAllianceColour = AllianceColour::RED;
    chassis.setPose(-50.5, -60, 270);
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    mobile_stake_clamp.set_value(true);

    // Move to pick up stake on the autonomous line
    chassis.moveToPoint(-24, -60, 1000, {.forwards=false});
    chassis.turnToPoint(-8, -53, 1000, {.forwards=false, .maxSpeed=100});
    chassis.moveToPoint(-8, -53, 1000, {.forwards=false, .maxSpeed=80});
    //chassis.moveToPose(-6, -53.5, 240, 1500, {.forwards=false});
    pros::delay(1000);
    mobile_stake_clamp.set_value(false);
    pros::delay(1000);

    // Start scoring rings
    intake_controlled(600);

    // Move to pick up second ring
    chassis.turnToPoint(-22, -49, 1500);
    chassis.moveToPoint(-22, -49, 1500);

    // Let go of first stake
    pros::delay(2000);
    mobile_stake_clamp.set_value(true);
    intake_controlled(0);

    // Move to pick up second stake
    chassis.turnToPoint(-22, -25, 1000, {.forwards=false});
    chassis.moveToPoint(-22, -25, 1500, {.forwards=false, .maxSpeed=70});
    chassis.moveToPoint(-22, -23.5, 1500, {.forwards=false, .minSpeed=80}, false);

    pros::delay(750);
    mobile_stake_clamp.set_value(false);
    pros::delay(750);

    // Turn to corner
    chassis.turnToPoint(-46.5, -1.5, 1000, {}, false);
    intake.move_velocity(600);
    chassis.moveToPoint(-46.5, -5.5, 1000, {.maxSpeed=60}, false);

    // Move to intake both red and blue ring
    chassis.moveToPoint(-58, 11, 1000);
    //pros::delay(1000);
    //intake.move_velocity(0);
    //pros::delay(500);
    //intake.move_velocity(0);

    // Score ring
    //intake_controlled(600);

    // Move to touch ladder
    //chassis.moveToPoint(-24, -22, 1000, {.forwards=false, .minSpeed = 60}, false);
    chassis.turnToPoint(0, 0, 1000, {}, false);
    chassis.moveToPoint(0, 0, 1000, {.minSpeed = 60});
    //intake_controlled(0);

    // Open arm
    /*
    arm_rotation_sensor.set_position(0);
    int timer = 0;
    while (arm_rotation_sensor.get_position() < 400 && timer * 20 < 1000)
    {
        arm.move_velocity(100);
        pros::delay(20);
        timer++;
    }
    arm.move_velocity(0);
    
    chassis.waitUntilDone();

    // Drive to corner
    //arm_flip.set_value(true);
    intake.move_velocity(-600);
    chassis.moveToPoint(-75, -75, 2000, {.maxSpeed=100}, false);
    intake_controlled(0);

    // Reset position
    chassis.setPose(-56, -56, 215);

    // Back off
    chassis.moveToPoint(-42, -33, 1000, {.forwards=false}, false);    
    /*
    int timer = 0;
    while (arm_rotation_sensor.get_position() < 5500 && timer * 20 < 1000)
    {
        arm.move_velocity(100);
        pros::delay(20);
        timer++;
    }
    arm.move_velocity(0);
    

    // Alliance stake
    chassis.turnToPoint(-61, -11, 1000, {}, false);
    chassis.moveToPoint(-61, -11, 1500, {}, false);
    pros::delay(250);
    //arm.move_velocity(-100);

    // Turn and touch ladder
    chassis.turnToPoint(-29, -2, 1000, {}, false);
    //arm_flip.set_value(false);
    chassis.moveToPoint(-29, -2, 1000, {}, false);
    //south_side_red_corner();
    */
    
}


void south_side_blue()
{
    //currentAllianceColour = AllianceColour::BLUE;
    chassis.setPose(50.5, -60, 90);
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    mobile_stake_clamp.set_value(true);

    // Move to pick up stake on the autonomous line
    chassis.moveToPoint(24, -60, 1000, {.forwards=false});
    chassis.turnToPoint(8, -53, 1000, {.forwards=false, .maxSpeed=100});
    chassis.moveToPoint(8, -53, 1000, {.forwards=false, .maxSpeed=80});
    //chassis.moveToPose(-6, -53.5, 240, 1500, {.forwards=false});
    pros::delay(1000);
    mobile_stake_clamp.set_value(false);
    pros::delay(1000);

    // Start scoring rings
    intake_controlled(600);

    // Move to pick up second ring
    chassis.turnToPoint(22, -49, 1500);
    chassis.moveToPoint(22, -49, 1500);

    // Let go of first stake
    pros::delay(2000);
    mobile_stake_clamp.set_value(true);
    intake_controlled(0);

    // Move to pick up second stake
    chassis.turnToPoint(20, -22, 1000, {.forwards=false});
    chassis.moveToPoint(20, -22, 1500, {.forwards=false});

    pros::delay(750);
    mobile_stake_clamp.set_value(false);

    // Start scoring
    intake_controlled(600);

    /*

    // Turn to corner
    chassis.turnToPoint(75, -75, 1000);

    // Open arm
    /*
    arm_rotation_sensor.set_position(0);
    int timer = 0;
    while (arm_rotation_sensor.get_position() < 400 && timer * 20 < 1000)
    {
        arm.move_velocity(100);
        pros::delay(20);
        timer++;
    }
    arm.move_velocity(0);
    */
    chassis.waitUntilDone();

    // Drive to corner
    //arm_flip.set_value(true);
    intake.move_velocity(-600);
    chassis.moveToPoint(75, -75, 2000, {.maxSpeed=100}, false);
    intake_controlled(0);

    // Reset position
    chassis.setPose(56, -56, 145);

    // Back off
    chassis.moveToPoint(42, -33, 1000, {.forwards=false}, false);    
    /*
    int timer = 0;
    while (arm_rotation_sensor.get_position() < 5500 && timer * 20 < 1000)
    {
        arm.move_velocity(100);
        pros::delay(20);
        timer++;
    }
    arm.move_velocity(0);
    */

    // Alliance stake
    chassis.turnToPoint(61, -11, 1000, {}, false);
    chassis.moveToPoint(61, -11, 1500, {}, false);
    pros::delay(250);
    //arm.move_velocity(-100);

    // Turn and touch ladder
    chassis.turnToPoint(29, -2, 1000, {}, false);
    //arm_flip.set_value(false);
    chassis.moveToPoint(29, -2, 1000, {}, false);
    //south_side_red_corner();
    
}

/*
void south_side_blue()
{
    chassis.setPose(50.5, -60, 90);
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    mobile_stake_clamp.set_value(true);

    // Move to pick up stake on the autonomous line
    chassis.moveToPoint(24, -60, 1000, {.forwards=false});
    chassis.turnToPoint(8, -53, 1000, {.forwards=false, .maxSpeed=100});
    chassis.moveToPoint(8, -53, 1000, {.forwards=false, .maxSpeed=80});
    //chassis.moveToPose(-6, -53.5, 240, 1500, {.forwards=false});
    pros::delay(1000);
    mobile_stake_clamp.set_value(false);
    pros::delay(1000);

    // Start scoring rings
    intake_controlled(600);

    // Move to pick up second ring
    chassis.turnToPoint(22, -49, 1500);
    chassis.moveToPoint(22, -49, 1500);

    // Let go of first stake
    pros::delay(2000);
    mobile_stake_clamp.set_value(true);
    intake_controlled(0);

    // Move to pick up second stake
    chassis.turnToPoint(20, -22, 1000, {.forwards=false});
    chassis.moveToPoint(20, -22, 1500, {.forwards=false});

    pros::delay(750);
    mobile_stake_clamp.set_value(false);

    // Start scoring
    intake_controlled(600);

    // Turn to corner
    chassis.turnToPoint(58, -56, 1000);

    // Open arm
    arm_rotation_sensor.set_position(0);
    int timer = 0;
    while (arm_rotation_sensor.get_position() < 500 || timer * 20 < 1000)
    {
        arm.move_velocity(100);
        pros::delay(20);
        timer++;
    }
    arm.move_velocity(0);
    chassis.waitUntilDone();

    // Drive to corner
    chassis.moveToPoint(75, -75, 2000, {.maxSpeed=100});
    intake_controlled(0);
    arm_flip.set_value(true);
    
    // Back off
    chassis.moveToPoint(42, -33, 1000, {.forwards=false});

    // Reset position
    chassis.setPose(42, -33, 215);

    while (arm_rotation_sensor.get_position() < 5500)
    {
        arm.move_velocity(100);
    }
    arm.move_velocity(0);
    

    // Alliance stake
    chassis.turnToPoint(61, -11, 1000);
    chassis.moveToPoint(61, -11, 1500, {}, false);
    pros::delay(250);
    arm.move_velocity(-100);

    // Turn and touch ladder
    chassis.turnToPoint(29, -2, 1000);
    arm_flip.set_value(false);
    chassis.moveToPoint(29, -2, 1000);
    //south_side_red_corner();
    
}
*/




void south_side_red_middle()
{
    intake.move_velocity(-600);
    
    // Move to pick up third ring beside the ladder
    chassis.turnToPoint(-44, -3, 1500);
    chassis.moveToPoint(-44, -3, 1500);
    // intake until reaches sensor
    chassis.turnToPoint(-35, 7, 1500);
    // outtake ring fully
    chassis.turnToPoint(-48.5, 2, 1500);
    intake_controlled(600);
    chassis.moveToPoint(-48.5, 2, 1500, {.maxSpeed = 60});

    // Turn and touch ladder
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.turnToPoint(-26.5, 0, 1500);
    chassis.moveToPoint(-26.5, 0, 1500);
}


void south_side_red_corner()
{
    // Move to pick up third ring
    chassis.turnToPoint(-30, -56, 1500);
    chassis.moveToPoint(-30, -56, 1500);
    chassis.turnToPoint(-69, -67, 1500, {.minSpeed=60});
    chassis.moveToPoint(-69, -67, 1500);
    intake.move_velocity(600);
    pros::delay(750);

    // Move to touch ladder
    chassis.turnToPoint(-37, -52, 1500, {.forwards=false});
    chassis.moveToPoint(-37, -52, 1500, {.forwards=false});
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.turnToPoint(-26, -7, 1500);
    chassis.moveToPoint(-26,-7, 1500);
    intake.move_velocity(0);
}