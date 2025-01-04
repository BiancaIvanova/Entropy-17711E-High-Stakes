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

const int INTAKE_VELOCITY = 600;
const int ARM_VELOCITY = 100;


void split_curvature()
{
    double curveGain = 10;
    double leftY= controller.get_analog(ANALOG_LEFT_Y);
    double rightX = controller.get_analog(ANALOG_RIGHT_X);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.curvature(leftY, rightX, curveGain);
    
    intake_control(controller.get_digital(DIGITAL_R2), controller.get_digital(DIGITAL_R1));
    arm_control(controller.get_digital(DIGITAL_Y), controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
    stake_clamp_control(controller.get_digital(DIGITAL_L2));
    arm_flip_control(controller.get_digital(DIGITAL_B));
}

const double overallScaleFactor = 600.0 / 127.0;
const double mainWheelSpeedFactor = 1.0 / 1.02857;

void intake_control(bool in, bool out)
{
    if (in)
    {
        intake.move_velocity(INTAKE_VELOCITY);
    }
    else if (out)
    {
        intake.move_velocity(INTAKE_VELOCITY * -1);
    }
    else
    {
        intake.move_velocity(0);
    }
}

void arm_control(bool up, bool down)
{
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if (up)
    {
        arm.move_velocity(ARM_VELOCITY);
    }
    else if (down)
    {
        arm.move_velocity(ARM_VELOCITY * -1);
    }
    else
    {
        arm.move_velocity(0);
    }
}

bool stakeClampOpen, stakeClampLatch;

void stake_clamp_control(bool control)
{
    if (control)
    {

        if (!stakeClampLatch)
        {
            stakeClampOpen = !stakeClampOpen;

            mobile_stake_clamp.set_value(stakeClampOpen);
            mobile_stake_clamp.set_value(stakeClampOpen);

            stakeClampLatch = true;
        }
    }
    else
    {
        stakeClampLatch = false;
    }
}


bool armOpen, armLatch;


void arm_flip_control(bool control)
{
    if (control)
    {
        if (!armLatch)
        {
            armOpen = !armOpen;

            arm_flip.set_value(armOpen);
            arm_flip.set_value(armOpen);

            armLatch = true;
        }
    }
    else
    {
        armLatch = false;
    }
}