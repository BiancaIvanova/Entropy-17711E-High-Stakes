#include "autons.h"
#include "config.h"
#include "subsystem-control-functions.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"

enum class SouthVariant {
    MIDDLE,
    CORNER
};


void south_side_red(SouthVariant south_variant)
{
    chassis.setPose(-50, -60, 90);

    // Move to pick up stake on the autonomous line
    chassis.moveToPoint(-20, -60, 1500, {.forwards=false});
    chassis.turnToPoint(-9.5, -53, 1500, {.forwards=false});
    chassis.moveToPoint(-9.5, -53, 1500, {.forwards=false});
    mobile_stake_clamp.set_value(true);

    // Start scoring rings
    intake_controlled(600);

    // Move to pick up second ring
    chassis.turnToPoint(-18.5, -49, 1500);
    chassis.moveToPoint(-18.5, -49, 1500);
    pros::delay(750);

    // Let go of first stake
    intake_controlled(0);
    mobile_stake_clamp.set_value(false);

    // Move to pick up second stake
    chassis.turnToPoint(-24, -43, 1500);
    chassis.moveToPoint(-24, -43, 1500);
    chassis.turnToPoint(-24, -25, 1500, {.forwards=false});
    chassis.moveToPoint(-24, -25, 1500, {.forwards=false});
    pros::delay(750);
    mobile_stake_clamp.set_value(true);

    if (south_variant == SouthVariant::MIDDLE)
    {
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
    else if (south_variant == SouthVariant::CORNER)
    {
        // Move to pick up third ring
        chassis.turnToPoint(-37, -52, 1500);
        chassis.moveToPoint(-37, -52, 1500);
        intake_controlled(600);
        chassis.turnToPoint(-59, -62, 1500);
        chassis.moveToPoint(-59, -62, 1500);
        pros::delay(750);

        // Move to touch ladder
        chassis.turnToPoint(-37, -52, 1500, {.forwards=false});
        chassis.moveToPoint(-37, -52, 1500, {.forwards=false});
        chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
        chassis.turnToPoint(-26, -7, 1500);
        chassis.moveToPoint(-26,-7, 1500);
    }
}