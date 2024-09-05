#include "main.h"
#include "auton-selector.h"
#include "driver-control.h"
#include "config.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"


void initialize() {
	init_display();

	controller.clear();

	pros::delay(200);
	controller.print(0, 0, "Time Left: %ds");
	pros::delay(200);
	controller.print(1, 0, "Auton 1");
	pros::delay(200);
	controller.print(2, 0, "Battery: %i%%", pros::c::battery_get_capacity());
	
	pros::Task task([&]()
    {
		update_display_data();
		pros::delay(1000);
	});
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