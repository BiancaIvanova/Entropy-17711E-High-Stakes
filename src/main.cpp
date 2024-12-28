#include "main.h"
#include "autons.h"
#include "driver-control.h"
#include "config.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystem-control-functions.h"
#include "data-logger.h"

void initialize()
{
	chassis.calibrate();
	arm_rotation_sensor.set_position(0);
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	north_side_blue();
}


void opcontrol()
{
	intake_controlled(0);

	read_logs_from_file();
	replay_logs();
}