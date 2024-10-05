#include "main.h"
#include "autons.h"
#include "driver-control.h"
#include "config.h"
#include "pros/rtos.hpp"
#include "subsystem-control-functions.h"


void initialize()
{
	chassis.calibrate();
	pros::Task logTask(logPose, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Logger thing");
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	intake_controlled(600);
	pros::delay(5000);
	intake_controlled(0);
}


void opcontrol()
{
	while (true)
	{
		split_curvature();
		pros::delay(20);
	}
}