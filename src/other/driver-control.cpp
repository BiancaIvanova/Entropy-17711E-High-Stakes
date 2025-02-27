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
const int ARM_VELOCITY = 150;
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
    arm_control(controller.get_digital(DIGITAL_Y), controller.get_digital(DIGITAL_RIGHT));
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


std::vector<double> armPositions = {ArmPosition::DOWN, ArmPosition::LOAD, ArmPosition::UP, ArmPosition::WALL_STAKE, ArmPosition::ALLIANCE_STAKE};
int currentIndex = 0;

bool prevUp = false;
bool prevDown = false;

void arm_control(bool up, bool down) {
    if (up && !prevUp && currentIndex < armPositions.size() - 1) {
        currentIndex++;
        arm.moveToPosition(armPositions[currentIndex]);
    }
    else if (down && !prevDown && currentIndex > 0) {
        currentIndex--;
        arm.moveToPosition(armPositions[currentIndex]);
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