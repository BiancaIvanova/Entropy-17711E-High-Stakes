#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void mogo_rush_red()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    arm.resetPosition(ArmPosition::DOWN);

    chassis.setPose(-54, -29, 115);

    // Go rush middle mogo
    chassis.moveToPoint(-22, -39, 1400, {.minSpeed=60});
    pros::delay(800);
    left_doinker.set_value(true);

    // Move it back
    chassis.moveToPoint(-38, -39, 1600, {.forwards=false}, false);
    left_doinker.set_value(false);
    pros::delay(200);

    // Turn around to grab mogo
    chassis.turnToPoint(-14.5, -48, 800, {.forwards=false});
    mobile_stake_clamp.set_value(true);

    // Move back to grab mogo
    chassis.moveToPoint(-19, -46, 800, {.forwards=false, .maxSpeed=90}, false);
    pros::delay(200);
    mobile_stake_clamp.set_value(false);
    pros::delay(150);

    // Score preload
    intake_controlled(600);
    pros::delay(1250);
    intake_controlled(0);

    // Drop mogo
    pros::delay(250);
    mobile_stake_clamp.set_value(true);

    // Move forward and turn to grab the other mogo
    chassis.moveToPoint(-30, -45, 600);
    chassis.turnToPoint(-30, -24, 700, {.forwards=false});
    chassis.moveToPoint(-30, -24, 1000, {.forwards=false, .maxSpeed=90}, false);
    pros::delay(200);
    mobile_stake_clamp.set_value(false);
    pros::delay(400);

    // Go to corner
    chassis.turnToPoint(-56, -32, 650);
    chassis.moveToPoint(-56, -32, 850);
    chassis.turnToPoint(-60, -54, 500, {}, false);
    left_doinker.set_value(true);
    chassis.moveToPoint(-60, -54, 800);

    // Turn and spin rings away
    chassis.turnToPoint(-36, 0, 1500, {.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed=60});
    
    // Turn and move forward a little to get that ring
    chassis.turnToPoint(-24, 0, 500, {}, false);
    intake_controlled(600);
    chassis.moveToPoint(-50, -50, 600);
    pros::delay(600);

    // Back into the corner
    chassis.moveToPoint(-58, -56, 1500, {.forwards=false, .maxSpeed=45});
}



void mogo_rush_blue()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    arm.resetPosition(ArmPosition::DOWN);

    chassis.setPose(54, -29, 115);

    // Go rush middle mogo
    chassis.moveToPoint(22, -39, 1400, {.minSpeed=60});
    pros::delay(800);
    left_doinker.set_value(true);

    // Move it back
    chassis.moveToPoint(38, -39, 1600, {.forwards=false}, false);
    left_doinker.set_value(false);
    pros::delay(200);

    // Turn around to grab mogo
    chassis.turnToPoint(14.5, -48, 800, {.forwards=false});
    mobile_stake_clamp.set_value(true);

    // Move back to grab mogo
    chassis.moveToPoint(19, -46, 800, {.forwards=false, .maxSpeed=90}, false);
    pros::delay(200);
    mobile_stake_clamp.set_value(false);
    pros::delay(150);

    // Score preload
    intake_controlled(600);
    pros::delay(1250);
    intake_controlled(0);

    // Drop mogo
    pros::delay(250);
    mobile_stake_clamp.set_value(true);

    // Move forward and turn to grab the other mogo
    chassis.moveToPoint(30, -45, 600);
    chassis.turnToPoint(30, -24, 700, {.forwards=false});
    chassis.moveToPoint(30, -24, 1000, {.forwards=false, .maxSpeed=90}, false);
    pros::delay(200);
    mobile_stake_clamp.set_value(false);
    pros::delay(400);

    // Go to corner
    chassis.turnToPoint(56, -32, 650);
    chassis.moveToPoint(56, -32, 850);
    chassis.turnToPoint(60, -54, 500, {}, false);
    left_doinker.set_value(true);
    chassis.moveToPoint(60, -54, 800);

    // Turn and spin rings away
    chassis.turnToPoint(36, 0, 1500, {.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed=60});
    
    // Turn and move forward a little to get that ring
    chassis.turnToPoint(24, 0, 500, {}, false);
    intake_controlled(600);
    chassis.moveToPoint(50, -50, 600);
    pros::delay(600);

    // Back into the corner
    chassis.moveToPoint(58, -56, 1500, {.forwards=false, .maxSpeed=45});
}

void elims_north_red()
{
    chassis.setPose(-53, 10, 240);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(-60.5, 6, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, true, 0.35);
    pros::delay(750);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-34, 21, 750, {.forwards=false}, false);
    left_arm.move_velocity(-600);
    right_arm.move_velocity(-600);
    chassis.moveToPoint(-24, 26, 500, {.forwards=false, .maxSpeed = 50}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(-29, 46, 750);
    chassis.moveToPoint(-29, 46, 1000);

    // Grab second ring
    chassis.turnToPoint(-20, 51, 750);
    chassis.moveToPoint(-20, 51, 900);
    chassis.moveToPoint(-26, 46, 750, {.forwards=false}, false); // back off

    // Grab third ring
    chassis.turnToPoint(-20, 47, 750);
    chassis.moveToPoint(-20, 47, 900);
    chassis.moveToPoint(-28, 46, 750, {.forwards=false}, false); // back off

    // Turn and move to corner
    chassis.turnToPoint(-50, 60, 1000, {}, false);
    intake_controlled(0);
    left_doinker.set_value(true);
    chassis.moveToPoint(-64, 58, 1500, {.maxSpeed=90});

    // Turn and doink away
    chassis.turnToPoint(-33, 25, 1500, {.maxSpeed=55}, false);

    // Grab ring and go to middle
    intake_controlled(600);
    chassis.turnToPoint(-48, 14, 800);
    chassis.moveToPoint(-48, 14, 2000);
}


void elims_north_blue()
{
    chassis.setPose(53, 10, 120);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(60.5, 6, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, true, 0.35);
    pros::delay(750);

    // Move back and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(34, 21, 750, {.forwards=false}, false);
    left_arm.move_velocity(-600);
    right_arm.move_velocity(-600);
    chassis.moveToPoint(24, 26, 500, {.forwards=false, .maxSpeed = 50}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(29, 46, 750);
    chassis.moveToPoint(29, 46, 1000);

    // Grab second ring
    chassis.turnToPoint(20, 51, 750);
    chassis.moveToPoint(20, 51, 900);
    chassis.moveToPoint(26, 46, 750, {.forwards=false}, false); // back off

    // Grab third ring
    chassis.turnToPoint(20, 47, 750);
    chassis.moveToPoint(20, 47, 900);
    chassis.moveToPoint(28, 46, 750, {.forwards=false}, false); // back off

    // Turn and move to corner
    chassis.turnToPoint(50, 60, 1000, {}, false);
    intake_controlled(0);
    left_doinker.set_value(true);
    chassis.moveToPoint(64, 58, 1500, {.maxSpeed=90});

    // Turn and doink away
    chassis.turnToPoint(33, 25, 1500, {.maxSpeed=55}, false);

    // Grab ring and go to middle
    intake_controlled(600);
    chassis.turnToPoint(48, 14, 800);
    chassis.moveToPoint(48, 14, 2000);
}


void nats_north_red()
{
    chassis.setPose(-53, 10, 240);
    arm.resetPosition(ArmPosition::LOAD);

    // Place ring on alliance stake
    chassis.moveToPoint(-60.5, 6, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, true, 0.35);
    pros::delay(750);

    // Move back                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-34, 21, 750, {.forwards=false}, false);
    left_arm.move_velocity(-600);
    right_arm.move_velocity(-600);
    chassis.moveToPoint(-24, 26, 500, {.forwards=false, .maxSpeed = 50}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(-29, 46, 750);
    chassis.moveToPoint(-29, 46, 1000);

    // Grab second ring
    chassis.turnToPoint(-20, 51, 750);
    chassis.moveToPoint(-20, 51, 1200);
    chassis.moveToPoint(-26, 46, 750, {.forwards=false}, false); // back off

    // Grab third ring
    chassis.turnToPoint(-20, 47, 750);
    chassis.moveToPoint(-20, 47, 1200);
    chassis.moveToPoint(-28, 46, 750, {.forwards=false}, false); // back off

    // Turn to go to middle
    chassis.turnToPoint(-48, 20, 750, {}, false);
    intake_controlled(0);
    chassis.moveToPoint(-48, 20, 1500);

    // Go to pos
    chassis.turnToPoint(-48, -48, 750);
    chassis.moveToPoint(-48, -48, 1500);
}


void nats_north_blue()
{
    chassis.setPose(53, 10, 120);
    arm.resetPosition(ArmPosition::LOAD);
    intake.move_velocity(300);
    pros::delay(200);
    intake.move_velocity(0);

    // Place ring on alliance stake
    chassis.moveToPoint(60.5, 6, 400);
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, true, 0.35);
    pros::delay(750);

    // Move back                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 and grab left stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(34, 21, 750, {.forwards=false}, false);
    left_arm.move_velocity(-600);
    right_arm.move_velocity(-600);
    chassis.moveToPoint(24, 26, 500, {.forwards=false, .maxSpeed = 50}, false); // slower
    pros::delay(250);
    mobile_stake_clamp.set_value(false);
    pros::delay(250);
    
    // Turn and grab first ring
    intake_controlled(600);
    chassis.turnToPoint(29, 46, 750);
    chassis.moveToPoint(29, 46, 1000);

    // Grab second ring
    chassis.turnToPoint(18.5, 53, 750);
    chassis.moveToPoint(18.5, 51, 1200);
    chassis.moveToPoint(26, 46, 750, {.forwards=false}, false); // back off

    // Grab third ring
    chassis.turnToPoint(18.5, 47, 750);
    chassis.moveToPoint(18.5, 47, 1200);
    chassis.moveToPoint(28, 46, 750, {.forwards=false}, false); // back off

    // Turn to go to middle
    chassis.turnToPoint(48, 20, 750, {}, false);
    intake_controlled(0);
    chassis.moveToPoint(48, 20, 1500);

    // Go to pos
    chassis.turnToPoint(48, -48, 750);
    chassis.moveToPoint(48, -48, 1500);
}
