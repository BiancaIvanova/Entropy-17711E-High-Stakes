#ifndef SUBSYSTEM_CONTROL_FUNCTIONS_H
#define SUBSYSTEM_CONTROL_FUNCTIONS_H

#include "main.h"
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/api.hpp"

void logPose();

struct IntakeParams
{
    bool jam_detection = true;
    bool coloursort = false;
};


class IntakeController
{
    pros::Motor& intakeMotor;

    void handle_intake_jam(int velocity);
    void intake_colour_sort_task(int velocity);
    void handle_wrong_ring(int velocity);

    public:
        IntakeController(pros::Motor& intakeMotor);

        void intake_controlled(int velocity);
        void intake_ring_detect(int velocity);
        void intake_control(int velocity, IntakeParams options = {});
};

#endif