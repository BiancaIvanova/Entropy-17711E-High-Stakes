#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void drive_square() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 24, 0, 2000);
    chassis.turnToPoint(24, 24, 2000);
    chassis.moveToPose(24, 24, 90, 2000);
    chassis.turnToPoint(24, 0, 2000);
    chassis.moveToPose(24, 0, 180, 2000);
    chassis.turnToPoint(0, 0, 2000);
    chassis.moveToPose(0, 0, 270, 2000);
    chassis.turnToPoint(0, 24, 2000);
}