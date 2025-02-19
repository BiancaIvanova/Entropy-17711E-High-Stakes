#include "main.h"
#include "config.h"
#include "lemlib/api.hpp"
#include "subsystem-control-functions.h"

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
    
    // Stop the intake and vibrate the controller
    intake.move_velocity(0);
    controller.rumble(".");

    // Reverse the intake to clear the jam
    intake.move_relative(-REVERSE_DISTANCE, REVERSE_VELOCITY);
    pros::delay(600);
    intake.move_velocity(velocity);

    // Grace period to prevent immediate detection of another jam
    for (int i = 0; i < floor(GRACE_PERIOD_MS / TASK_DELAY_MS); ++i)
    {
        pros::delay(TASK_DELAY_MS); 
    }
}


void intake_controlled(int velocity)
{
    static pros::Task* intake_task = nullptr; 

    if (velocity == 0)
    {
        // If the velocity has been set to 0, stop the intake
        if (intake_task)
        {
            intake_task->suspend();
            delete intake_task;
            intake_task = nullptr;
        }
        intake.move_velocity(0);
        return;
    }

    // Create new thread for intake control
    if (!intake_task) 
    {
        intake_task = new pros::Task([velocity]()
        {
            const int JAM_TIME_THRESHOLD = 1200;
            const int MIN_VELOCITY_THRESHOLD = velocity * 0.2;

            // Start moving intake at input velocity
            intake.move_velocity(velocity);
            int jam_time = 0;
            
            while (true)
            {
                int actual_velocity = intake.get_actual_velocity();

                // If velocity drops below threshold, start a timer
                if (actual_velocity < MIN_VELOCITY_THRESHOLD && velocity != 0)
                {
                    jam_time += TASK_DELAY_MS;
                }
                else
                {
                    jam_time = 0;
                }

                // Handle jam if it has been stuck for longer than the threshold time
                if (jam_time >= JAM_TIME_THRESHOLD)
                {
                    handle_intake_jam(velocity);
                    jam_time = 0;
                }

                pros::delay(TASK_DELAY_MS);
            }
        });
    }
}

void intake_ring_detect(int velocity)
{
    const int RED_LOWER_THRESHOLD = 5;
    const int RED_UPPER_THRESHOLD = 25;
    const int BLUE_LOWER_THRESHOLD = 208;
    const int BLUE_UPPER_THRESHOLD = 215;

    AllianceColour currentAllianceColour = AllianceColour::RED;

    if (currentAllianceColour == AllianceColour::RED)
    {
        if (optical_sensor.get_hue() > BLUE_LOWER_THRESHOLD && optical_sensor.get_hue() < BLUE_UPPER_THRESHOLD)
        {
            handle_wrong_ring(velocity);
        }
    }
    else if (currentAllianceColour == AllianceColour::BLUE)
    {
        if (optical_sensor.get_hue() > RED_LOWER_THRESHOLD && optical_sensor.get_hue() < RED_UPPER_THRESHOLD)
        {
            handle_wrong_ring(velocity);
        }
    }
}

void handle_wrong_ring(int velocity)
{
    const int FLING_DISTANCE_THRESHOLD = 500;
    int start_intake_position = intake.get_position();

    while (abs(intake.get_position() - start_intake_position) < FLING_DISTANCE_THRESHOLD)
    {
        pros::delay(TASK_DELAY_MS);
    }

    intake.move_velocity(0);
    pros::delay(200);
    intake.move_velocity(velocity);
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
    //arm.move_velocity(velocity);
    pros::delay(t);
    //arm.move_velocity(0);
    });
}

void arm_standard(int t, int velocity)
{
    //arm.move_velocity(velocity);
    pros::delay(t);
    //arm.move_velocity(0);
}

void move_arm_absolute(int position)
{
    while (arm_rotation_sensor.get_position())
    {
        //arm.move_velocity(100);
    }
}