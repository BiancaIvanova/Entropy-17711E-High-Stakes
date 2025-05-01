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

IntakeController::IntakeController(pros::Motor& intakeMotor) 
    : intakeMotor(intakeMotor) {}


void IntakeController::handle_intake_jam(int velocity)
{
    const int REVERSE_DISTANCE = 300;
    const int REVERSE_VELOCITY = 600;
    const int GRACE_PERIOD_MS = 100;
    
    // Stop the intake and vibrate the controller
    intake_motor.move_velocity(0);
    controller.rumble(".");

    // Reverse the intake to clear the jam
    intake_motor.move_relative(-REVERSE_DISTANCE, REVERSE_VELOCITY);
    pros::delay(600);
    intake_motor.move_velocity(velocity);

    // Grace period to prevent immediate detection of another jam
    for (int i = 0; i < floor(GRACE_PERIOD_MS / TASK_DELAY_MS); ++i)
    {
        pros::delay(TASK_DELAY_MS); 
    }
}


void IntakeController::intake_control(int velocity, IntakeParams options)
{
    static pros::Task* jamTask = nullptr;
    static pros::Task* ringTask = nullptr;

    if (velocity == 0)
    {
        if (jamTask)
        {
            jamTask->suspend();
            delete jamTask;
            jamTask = nullptr;
        }

        if (ringTask)
        {
            ringTask->suspend();
            delete ringTask;
            ringTask = nullptr;
        }

        intake_motor.move_velocity(0);
        return;
    }

    // Jam Detection Task
    if (options.jam_detection && jamTask == nullptr)
    {
        jamTask = new pros::Task([this, velocity]() {
            const int JAM_TIME_THRESHOLD = 500;
            const int MIN_VELOCITY_THRESHOLD = velocity * 0.2;

            intake_motor.move_velocity(velocity);
            int jam_time = 0;

            while (true)
            {
                int actual_velocity = intake_motor.get_actual_velocity();

                if (actual_velocity < MIN_VELOCITY_THRESHOLD && velocity != 0)
                {
                    jam_time += TASK_DELAY_MS;
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

                pros::delay(TASK_DELAY_MS);
            }
        });
    }

    // Colour Sort Task
    if (options.coloursort && ringTask == nullptr)
    {
        ringTask = new pros::Task([this, velocity]() {
            intake_colour_sort_task(velocity);
        });
    }

    // Default behavior if neither option is active
    if (!options.jam_detection && !options.coloursort)
    {
        intake_motor.move_velocity(velocity);
    }
}


void IntakeController::intake_ring_detect(int velocity)
{
    static pros::Task* colour_sort_task = nullptr;

    if (velocity == 0)
    {
        if (colour_sort_task)
        {
            colour_sort_task->suspend();
            delete colour_sort_task;
            colour_sort_task = nullptr;
        }
        intake_motor.move_velocity(0);
        return;
    }

    if (!colour_sort_task)
    {
        colour_sort_task = new pros::Task([this, velocity]()
        {
            this->intake_colour_sort_task(velocity);
        });
    }
}

void IntakeController::handle_wrong_ring(int velocity)
{
    const int FLING_DISTANCE_THRESHOLD = 542;
    int start_intake_position = intake_motor.get_position();

    while (abs(intake_motor.get_position() - start_intake_position) < FLING_DISTANCE_THRESHOLD)
    {
        pros::delay(TASK_DELAY_MS);
    }

    intake_motor.move_velocity(0);
    pros::delay(200);
    intake_motor.move_velocity(velocity);
}

void IntakeController::intake_colour_sort_task(int velocity)
{
    const int RED_LOWER_THRESHOLD = 5;
    const int RED_UPPER_THRESHOLD = 25;
    const int BLUE_LOWER_THRESHOLD = 208;
    const int BLUE_UPPER_THRESHOLD = 225;
    AllianceColour currentAllianceColour = AllianceColour::RED;

    intake_motor.move_velocity(velocity);

    while (true)
    {
        int hue = optical_sensor.get_hue();

        if (currentAllianceColour == AllianceColour::RED)
        {
            if (hue > BLUE_LOWER_THRESHOLD && hue < BLUE_UPPER_THRESHOLD)
            {
                handle_wrong_ring(velocity);
            }
        }
        else if (currentAllianceColour == AllianceColour::BLUE)
        {
            if (hue > RED_LOWER_THRESHOLD && hue < RED_UPPER_THRESHOLD)
            {
                handle_wrong_ring(velocity);
            }
        }

        pros::delay(TASK_DELAY_MS);
    }
}
