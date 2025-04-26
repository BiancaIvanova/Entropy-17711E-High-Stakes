#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void drive_square() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 24, 2000);
    chassis.turnToPoint(24, 24, 2000);
    chassis.moveToPoint(24, 24, 2000);
    
}