#include "main.h"
#include "auton-selector.h"
#include "driver-control.h"


void initialize() {
	init_display();
}


void disabled() {}


void competition_initialize() {
	
}


void autonomous() {}


void opcontrol()
{
	while (true)
	{
		split_curvature();
		pros::delay(20);
	}
}