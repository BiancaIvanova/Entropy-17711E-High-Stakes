#include "main.h"
#include "config.h"
#include "lemlib/api.hpp"

double x, y, heading;

void logPose() {
    while (true) {
        x = chassis.getPose().x;
        y = chassis.getPose().y;
        heading = chassis.getPose().theta;

        char json_str[128];

        snprintf(json_str, sizeof(json_str), "{\"x\": %.2f, \"y\": %.2f, \"theta\": %.2f}", x, y, heading);

        pros::delay(100);
    }
}

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

