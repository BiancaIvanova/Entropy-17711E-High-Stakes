#include "main.h"
#include "autons.h"
#include "driver-control.h"
#include "config.h"
#include "liblvgl/llemu.hpp"
#include "pros/rtos.hpp"
#include "subsystem-control-functions.h"
#include "distance-sensor-localiser.h"



void initialize()
{
	chassis.calibrate();
	pros::Task logTask(logPose, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Logger thing");
	pros::lcd::initialize();
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	intake_controlled(600);
}


void opcontrol()
{
    DistanceSensorLocaliser localiser(left_distance_sensor, right_distance_sensor, inertial_sensor, 8.0, 6.8, 45);
    //localiser.configureOffsets(0, 0);
    
    while (true)
    {
        auto pose_opt = localiser.getCurrentPose(DistanceSensorLocaliser::FieldCorner::NORTH_WEST);
        
        if (pose_opt) {
            auto pose = pose_opt.value();
            pros::lcd::print(0, "x: %f\n", pose.x);
            pros::lcd::print(1, "y: %f\n", pose.y);
            pros::lcd::print(2, "theta: %f\n", pose.heading);
        } else {
            pros::lcd::print(0, "Pose unavailable\n");
        }

        pros::delay(20);
    }
}