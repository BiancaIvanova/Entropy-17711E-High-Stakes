#include "main.h"
#include "config.h"
#include "driver-control.h"

/*
Ensure that when these functions are used in a competition function, eg. autonomous(), that there
is a minimum 10 millisecond delay using pros::delay();
*/

const int INTAKE_VELOCITY = 200;


void split_curvature()
{
    double curveGain = 4;
    double leftY= controller.get_analog(ANALOG_LEFT_Y);
    double rightX = controller.get_analog(ANALOG_RIGHT_X);
    chassis.curvature(leftY, rightX, curveGain);
}


void intake_control()
{
    if (controller.get_digital(DIGITAL_R2))
    {
        intake.move_velocity(INTAKE_VELOCITY);
    }
    else if (controller.get_digital(DIGITAL_R1))
    {
        intake.move_velocity(INTAKE_VELOCITY * -1);
    }
    else
    {
        intake.move_velocity(0);
    }
}
