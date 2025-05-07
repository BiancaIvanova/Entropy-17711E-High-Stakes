#include "lemlib/api.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"
#include "autons.h"
#include "config.h"
#include "subsystem-control-functions.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"


LineAligner::LineAligner(pros::adi::AnalogIn leftSensor, pros::adi::AnalogIn rightSensor, lemlib::Chassis* chassisPtr)
    : leftSensor(leftSensor),
    rightSensor(rightSensor),
    chassis(chassisPtr) {}

void LineAligner::setThreshold(int newThreshold) {
    threshold = newThreshold;
}

void LineAligner::driveToLine(int velocity, double maxDistance) {
    double startX = chassis->getPose().x;
    double startY = chassis->getPose().y;

    chassis->tank(velocity, velocity);

    while (true) {
        bool leftOnLine = leftSensor.get_value() < threshold;
        bool rightOnLine = rightSensor.get_value() < threshold;

        if (leftOnLine && rightOnLine) break;

        // If one side touches the line early, align
        if (leftOnLine) {
            chassis->tank(0, velocity);
        } else if (rightOnLine) {
            chassis->tank(velocity, 0);
        } else {
            chassis->tank(velocity, velocity);
        }

        // Stop if robot goes too far
        double dx = chassis->getPose().x - startX;
        double dy = chassis->getPose().y - startY;
        if (sqrt(dx * dx + dy * dy) > maxDistance) {
            break;
        }

        pros::delay(TASK_DELAY_MS);
    }

    chassis->tank(0, 0); // Stop motors
}