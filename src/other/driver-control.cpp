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
const int ARM_VELOCITY = 200;
double const POSITION_TOLERANCE = 5.0;

bool doinkerOpen, doinkerLatch;
bool stakeClampOpen, stakeClampLatch;

const double overallScaleFactor = 600.0 / 127.0;
const double mainWheelSpeedFactor = 1.0 / 1.02857;


void split_curvature()
{
    double curveGain = 10;
    double leftY= controller.get_analog(ANALOG_LEFT_Y);
    double rightX = controller.get_analog(ANALOG_RIGHT_X);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.curvature(leftY, rightX, curveGain);
    
    intake_control(controller.get_digital(DIGITAL_R2), controller.get_digital(DIGITAL_R1));
    //arm_control(controller.get_digital(DIGITAL_Y), controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
    stake_clamp_control(controller.get_digital(DIGITAL_L2));
    doinker_control(controller.get_digital(DIGITAL_B));
}

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

void start_arm_control()
{
    pros::Task arm_task([&](){
        while (true)
        {
            arm_control_logic(controller.get_digital(DIGITAL_Y), controller.get_digital(DIGITAL_RIGHT));
            pros::delay(TASK_DELAY_MS);
        }
    }); 
}

void arm_control_logic(bool up, bool down)
{
    left_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if (currentIndex == 0)
    {
        if (up && !prevUp)
        {
            currentIndex = 1;
            arm.moveToPosition(ArmPosition::LOAD);
        }
    } 
    else if (currentIndex == 1)
    {
        if (down && !prevDown)
        {
            currentIndex = 0;
            arm.moveToPosition(ArmPosition::DOWN);
        }
        else if (up)
        {
            currentIndex = 2;
        }
    } 

    if (currentIndex > 1)
    {
        if (up)
        {
            left_arm.move_velocity(ARM_VELOCITY);
            right_arm.move_velocity(ARM_VELOCITY);
        }
        else if (down)
        {
            left_arm.move_velocity(-ARM_VELOCITY);
            right_arm.move_velocity(-ARM_VELOCITY);
        }
        else
        {
            left_arm.move_velocity(0);
            right_arm.move_velocity(0);
        }

        if (currentIndex == 2 && arm.getPosition() <= (ArmPosition::LOAD + POSITION_TOLERANCE))
        {
            left_arm.move_velocity(0);
            right_arm.move_velocity(0);
            currentIndex = 1;
        }
    }

    prevUp = up;
    prevDown = down;
}


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

void doinker_control(bool control)
{
    if (control)
    {
        if (!doinkerLatch)
        {
            doinkerOpen = !doinkerOpen;

            doinker.set_value(doinkerOpen);
            doinker.set_value(doinkerOpen);

            doinkerLatch = true;
        }
    }
    else
    {
        doinkerLatch = false;
    }
}