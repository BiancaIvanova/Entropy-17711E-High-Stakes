#include "main.h"
#include "autons.h"
#include "driver-control.h"
#include "config.h"
#include "subsystem-control-functions.h"


void initialize()
{
	chassis.calibrate();
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	left_side_match_red();
}


void opcontrol()
{
	while (true)
	{
		split_curvature();
		pros::delay(20);
	}
}