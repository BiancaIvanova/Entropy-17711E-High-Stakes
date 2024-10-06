#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void south_side_red()
{
    chassis.setPose(-50, -60, 90);

    // Move to pick up stake on the autonomous line
    chassis.moveToPoint(-20, -60, 1500, {.forwards=false});
    chassis.turnToPoint(-9.5, -53, 1500, {.forwards=false});
    chassis.moveToPoint(-9.5, -53, 1500, {.forwards=false});
}