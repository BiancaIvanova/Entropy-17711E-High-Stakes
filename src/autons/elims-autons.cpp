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
    doinker.set_value(true);

    // Move it back
    chassis.moveToPoint(-38, -39, 1600, {.forwards=false}, false);
    doinker.set_value(false);
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
    doinker.set_value(true);
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