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
        std::cout << "x: " << x << "y: " << y << "theta: " << heading;
        pros::delay(100);
    }
}


void handle_intake_jam(int velocity)
{
    const int REVERSE_DISTANCE = 600;
    const int REVERSE_VELOCITY = 300;
    const int GRACE_PERIOD_MS = 100;
    
    intake.move_velocity(0);
    controller.rumble(".");

    intake.move_relative(-REVERSE_DISTANCE, REVERSE_VELOCITY);
    pros::delay(600);
    intake.move_velocity(velocity);

    for (int i = 0; i < floor(GRACE_PERIOD_MS / 20); ++i)
    {
        pros::delay(20); 
    }
}


void intake_controlled(int velocity)
{
    static pros::Task* intake_task = nullptr; 

    if (velocity == 0)
    {
        if (intake_task)
        {
            intake_task->suspend();
            delete intake_task;
            intake_task = nullptr;
        }
        intake.move_velocity(0);
        return;
    }

    if (!intake_task) 
    {
        intake_task = new pros::Task([velocity]()
        {
            const int JAM_TIME_THRESHOLD = 750;
            const int MIN_VELOCITY_THRESHOLD = velocity * 0.2;

            intake.move_velocity(velocity);
            int jam_time = 0;
            
            while (true)
            {
                int actual_velocity = intake.get_actual_velocity();

                if (actual_velocity < MIN_VELOCITY_THRESHOLD && velocity != 0)
                {
                    jam_time += 10;
                }
                else
                {
                    jam_time = 0;
                }

                if (jam_time >= JAM_TIME_THRESHOLD)
                {
                    handle_intake_jam(velocity);
                    jam_time = 0;
                }

                pros::delay(20);
            }
        });
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

