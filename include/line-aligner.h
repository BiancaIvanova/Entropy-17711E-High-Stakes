#pragma once

#include "lemlib/api.hpp"
#include "pros/adi.hpp"

class LineAligner {
private:
    pros::ADIAnalogIn leftSensor;
    pros::ADIAnalogIn rightSensor;
    lemlib::Chassis* chassis;

    int threshold = 2500; // Sensors return 0 (lightest) to 4095 (darkest)

public:
    /**
     * Constructor for the LineAligner class.
     * @param leftPort ADI port for the left line sensor (e.g. 'A')
     * @param rightPort ADI port for the right line sensor (e.g. 'B')
     * @param chassisPtr Pointer to LemLib chassis object
     */
    LineAligner(pros::adi::AnalogIn leftSensor, pros::adi::AnalogIn rightSensor, lemlib::Chassis* chassisPtr);

    /**
     * Set the threshold above which the surface is considered white tape.
     * @param newThreshold Light intensity threshold (0–4095)
     */
    void setThreshold(int newThreshold);

    /**
     * Drive forward until both sensors detect the line.
     * @param velocity Tank drive velocity (0–127)
     * @param maxDistance Max distance in inches before aborting
     */
    void driveToLine(int velocity, double maxDistance = 24.0);
};
