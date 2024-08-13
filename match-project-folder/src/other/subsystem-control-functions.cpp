#include "main.h"
#include "config.h"
#include "lemlib/api.hpp"


void intake_async(int t, int velocity)
{
    pros::Task task([&]()
                    {
    intake.move_velocity(velocity);
    pros::delay(t);
    intake.move_velocity(0); });
}

void intake_standard(int t, int velocity)
{
    intake.move_velocity(velocity);
    pros::delay(t);
    intake.move_velocity(0);
}

void intake_into_arm()
{
    pros::Task task([&]()
                    {
    intake.move_velocity(200);
    while (optical_sensor.get_proximity() > 120) {}
    intake.move_velocity(0);
    intake.move_relative(3, -120);
    });
}

void arm_async(int t, int velocity)
{
    pros::Task task([&]()
                    {
    arm.move_velocity(velocity);
    pros::delay(t);
    arm.move_velocity(0); });
}

void arm_standard(int t, int velocity)
{
    arm.move_velocity(velocity);
    pros::delay(t);
    arm.move_velocity(0);
}