#include "main.h"
#include "autons.h"
#include "driver-control.h"
#include "config.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystem-control-functions.h"
#include "data-logger.h"
#include "errno.h"

void initialize()
{
	optical_sensor.set_led_pwm(100);
	chassis.calibrate();
	arm_rotation_sensor.set_position(0);
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	auton_skills();
}


void opcontrol()
{
	intake_controlled(0);

	while (true)
	{
		split_curvature();
	}
}