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
	right_inertial_sensor.reset();
	chassis.calibrate();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	intake.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	mogo_rush_red();
}

void opcontrol()
{
	intake_controlled(0);

	while (true)
	{
		split_curvature();
	}
}