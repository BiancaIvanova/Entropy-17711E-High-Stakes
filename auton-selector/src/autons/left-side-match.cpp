#include "autons.h"
#include "config.h"

void left_side_match()
{
    chassis.setPose(-60, 14, 180);
    // Outtaking as we move so robot doesn't accidentally get blue ring
    intake_async(1000, -100);
    chassis.moveToPose(-60, 0, 180, 3000, {.forwards = true});

    // Turn so back of robot is facing alliance wall stake
    chassis.turnToPoint(-72, 0, 1000, {.forwards = false, .maxSpeed = 85});
    // Grab red ring, outtake both the preload and new ring onto alliance wall stake
    intake_async(1000, 100);
}