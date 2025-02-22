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
	////arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	arm_test();
}


void opcontrol()
{
	intake_controlled(0);
	start_arm_control();

	while (true)
	{
		split_curvature();
	}
}