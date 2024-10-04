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
    
    intake_control();
    arm_control();
    stake_clamp_control();
}

const double overallScaleFactor = 600.0 / 127.0;
const double mainWheelSpeedFactor = 1.0 / 1.02857;

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

void arm_control()
{
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if (controller.get_digital(DIGITAL_Y))
    {
        arm.move_velocity(ARM_VELOCITY);
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
    {
        arm.move_velocity(ARM_VELOCITY * -1);
    }
    else
    {
        arm.move_velocity(0);
    }
}

bool stakeClampOpen, stakeClampLatch;

void stake_clamp_control()
{
    if (controller.get_digital(DIGITAL_L2))
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


bool intakeOpen, intakeLatch;

void intake_lift_control()
{
    if (controller.get_digital(DIGITAL_L1))
    {

        if (!intakeLatch)
        {
            intakeOpen = !intakeOpen;

            intake_lift.set_value(intakeOpen);
            intake_lift.set_value(intakeOpen);

            intakeLatch = true;
        }
    }
    else
    {
        intakeLatch = false;
    }
}