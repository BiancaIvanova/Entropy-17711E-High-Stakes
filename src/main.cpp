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
	auton_skills();
}


void opcontrol()
{
	mobile_stake_clamp.set_value(true);
	while (true)
	{
		split_curvature();
		pros::delay(TASK_DELAY_MS);
	}
}