#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void drive_square() {
    chassis.setPose(0, 0, 0);
    printf("X: %.2f\n \t Y:%.2f\n \t theta: %.2f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    chassis.moveToPoint(0, 24, 15000, {.maxSpeed=50});
    printf("X: %.2f\n \t Y:%.2f\n \t theta: %.2f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToPoint(24, 24, 2000);
    printf("X: %.2f\n \t Y:%.2f\n \t theta: %.2f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
    chassis.moveToPoint(24, 24, 15000, {.maxSpeed=50});   
    printf("X: %.2f\n \t Y:%.2f\n \t theta: %.2f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
}