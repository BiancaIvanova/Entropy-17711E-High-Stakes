#include "main.h"
#include "autons.h"
#include "driver-control.h"
#include "config.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystem-control-functions.h"


void initialize()
{
	chassis.calibrate();
	arm_rotation_sensor.set_position(0);
	//pros::Task logTask(logPose, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Logger thing");
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	new_red_south();
}


void opcontrol()
{
	intake_controlled(0);
	while (true)
	{
		split_curvature();
		pros::delay(TASK_DELAY_MS);
	}
}