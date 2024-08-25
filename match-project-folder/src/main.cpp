#include "main.h"
#include "auton-selector.h"
#include "driver-control.h"
#include "config.h"
#include "pros/misc.h"


void initialize() {
	ready_display();
	controller.clear();

	pros::delay(200);
	controller.print(0, 0, "Time Left: %ds");
	pros::delay(200);
	controller.print(1, 0, "Auton 1");
	pros::delay(200);
	controller.print(2, 0, "Battery: %i%%", pros::c::battery_get_capacity());
	
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol()
{
	while (true)
	{
		split_curvature();
		pros::delay(20);
	}
}