#include "liblvgl/extra/widgets/span/lv_span.h"
#include "main.h"
#include "config.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "driver-control.h"

/*
Ensure that when these functions are used in a competition function, eg. autonomous(), that there
is a minimum 10 millisecond delay using pros::delay();
*/

const int INTAKE_VELOCITY = 200;


void split_curvature()
{
    double curveGain = 10;
    double leftY= controller.get_analog(ANALOG_LEFT_Y);
    double rightX = controller.get_analog(ANALOG_RIGHT_X);
    //chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    //chassis.curvature(leftY, rightX, curveGain);
}

const double overallScaleFactor = 600.0 / 127.0;
const double mainWheelSpeedFactor = 1.0 / 1.02857;

void x_drive_control()
{
    double turning = controller.get_analog(ANALOG_RIGHT_X) * overallScaleFactor;
    double movementX = controller.get_analog(ANALOG_LEFT_X) * overallScaleFactor;
    double movementY = controller.get_analog(ANALOG_LEFT_Y) * overallScaleFactor;

    int frontLeftVel = movementY + movementX + turning; 
    int backLeftVel = movementY - movementX + turning;
    int frontRightVel = movementY - movementX - turning;
    int backRightVel = movementY + movementX - turning;

    int centreLeftVel = (movementY + turning) * mainWheelSpeedFactor;
    int centreRightVel = (movementY - turning) * mainWheelSpeedFactor;

    front_left.move_velocity(frontLeftVel);
    back_left.move_velocity(backLeftVel);
    front_right.move_velocity(frontRightVel);
    back_right.move_velocity(backRightVel);

    middle_left.move_velocity(centreLeftVel);
    middle_right.move_velocity(centreRightVel);
}

void intake_control()
{
    if (controller.get_digital(DIGITAL_R2))
    {
        //intake.move_velocity(INTAKE_VELOCITY);
    }
    else if (controller.get_digital(DIGITAL_R1))
    {
        //intake.move_velocity(INTAKE_VELOCITY * -1);
    }
    else
    {
        //intake.move_velocity(0);
    }
}
