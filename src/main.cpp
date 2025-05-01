#include "main.h"
#include "autons.h"
#include "driver-control.h"
#include "config.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystem-control-functions.h"
#include "data-logger.h"
#include "auton-selector.h"
#include "errno.h"

void initialize()
{
	currentAutonName = "Standard North Red - Worlds";
	currentAllianceColour = AllianceColour::RED;
	ready_display(currentAutonName);

	optical_sensor.set_led_pwm(50);
	optical_sensor.set_integration_time(TASK_DELAY_MS);
	chassis.calibrate();
	
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	left_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake_motor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
}


void disabled() {}


void competition_initialize() {}


void autonomous()
{
	north_side_red_worlds();
}

void opcontrol()
{
	intake.intake_control(0);
	arm.resetPosition(ArmPosition::DOWN);

	while (true)
	{
		split_curvature();
	}
}