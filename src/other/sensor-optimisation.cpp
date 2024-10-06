#include "main.h"
#include "config.h"
#include "driver-control.h"
#include "lemlib/api.hpp"

struct AllianceColour
{
    int red;
    int blue;
};

void start_ring_colour_detection()
{
    const int RED_HUE_LOW_THRESHOLD = 0;
    const int RED_HUE_HIGH_THRESHOLD = 100;
    const int BLUE_HUE_LOW_THRESHOLD = 0;
    const int BLUE_HUE_HIGH_THRESHOLD = 100;

    bool ringDetected = false;

    pros::Task ring_colour_task([]()
                    {
        while (true)
        {
            int measured_hue = optical_sensor.get_hue();

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
            pros::delay(20);
        }
    });
}