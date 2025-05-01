#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void mogo_rush_red_worlds()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    arm.resetPosition(ArmPosition::DOWN);

    chassis.setPose(-55, -48, 90);

    // Go rush middle mogo
    chassis.moveToPoint(-14, -48, 1000, {.minSpeed=60});
    intake.intake_control(600, {.jam_detection=false, .coloursort=true});
    pros::delay(200);
    left_doinker.set_value(true);

    // Fling the mogo
    chassis.turnToPoint(-14, -64,  750, {.minSpeed=50});
    intake.intake_control(0);

    // Clamp the mogo
    chassis.turnToPoint(-14, -64,  750, {.forwards=false});
    left_doinker.set_value(false);
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-14, -64,  750, {.forwards=false}, false);
    pros::delay(150);
    mobile_stake_clamp.set_value(false);

    // Score the ring
    intake.intake_control(600, {.jam_detection=false, .coloursort=true});

    // Get the preload back
    chassis.turnToPoint(-48, -36,  750);
    intake.intake_control(600, {.jam_detection=false, .coloursort=true});
    chassis.moveToPoint(-48, -36,  1000, {}, false);
    pros::delay(500);

    // Let go of mogo and grab the other one
    mobile_stake_clamp.set_value(true);
    intake.intake_control(0);
    chassis.turnToPoint(-24, -24, 750, {.forwards=false});
    chassis.moveToPoint(-24, -24, 1000, {.forwards=false}, false);
    pros::delay(250);
    mobile_stake_clamp.set_value(false);

    // Turn and get another ring from underneath the ladder
    chassis.turnToPoint(-10, -10, 750, {}, false);
    right_doinker.set_value(true);
    chassis.moveToPoint(-10, -10, 1000);
    chassis.moveToPoint(-19, -19, 1000, {.forwards=false}, false);

    // Get the ring and score it
    right_doinker.set_value(false);
    intake.intake_control(600, {.jam_detection=false, .coloursort=true});
    chassis.swingToPoint(-10, -20, DriveSide::LEFT, 500);
    chassis.moveToPoint(-10, -20, 750);
}
