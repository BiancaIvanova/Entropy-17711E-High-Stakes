#include "main.h"
#include "config.h"
#include "driver-control.h"
#include "lemlib/api.hpp"


void start_ring_colour_detection(AllianceColour alliance)
{
    optical_sensor.set_led_pwm(75);

    pros::Task ring_colour_task([]()
    {
        const int RED_HUE_LOW_THRESHOLD = 0;
        const int RED_HUE_HIGH_THRESHOLD = 100;
        const int BLUE_HUE_LOW_THRESHOLD = 0;
        const int BLUE_HUE_HIGH_THRESHOLD = 100;
        const int PROXIMITY_THRESHOLD = 100;

        bool ringDetected = false;

        while ((pros::competition::get_status() & COMPETITION_CONNECTED) == true)
        {
            int measured_hue = optical_sensor.get_hue();

            if (optical_sensor.get_proximity() < 100)
            {
                controller.rumble(".");
            }


            if (!ringDetected && optical_sensor.get_proximity() > 100)
            {
                /*
                if (measured_hue >= RED_HUE_LOW_THRESHOLD && measured_hue <= RED_HUE_HIGH_THRESHOLD)
                {
                    controller.rumble(".");
                    ringDetected = true;
                }
                else if (measured_hue >= BLUE_HUE_LOW_THRESHOLD && measured_hue <= BLUE_HUE_HIGH_THRESHOLD)
                {
                    controller.rumble(".");
                    ringDetected = true;
                }
                else
                {
                    ringDetected = false;
                }
                */
            }
        }

        pros::delay(20);
    });
}