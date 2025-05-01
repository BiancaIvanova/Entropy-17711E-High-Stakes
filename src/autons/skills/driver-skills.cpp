#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void driver_skills_auton()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    arm.resetPosition(ArmPosition::LOAD);
    currentAllianceColour = AllianceColour::RED;
    
    //  Robot starts with the front facing alliance wall stake
    chassis.setPose(-55.5, 0, 270);

    // Score alliance stake
    arm.moveToPosition(ArmPosition::ALLIANCE_STAKE, 800, false);

    // Turn and grab left stake
    chassis.moveToPoint(-48, 0, 350, {.forwards=false}, false);
    arm.moveToPosition(ArmPosition::DOWN, false);
    chassis.turnToPoint(-48, 24, 500, {.forwards=false, .maxSpeed=70});
    
    // Clamp the stake
    mobile_stake_clamp.set_value(true);
    chassis.moveToPoint(-48, 19, 500, {.forwards=false}, true);
    chassis.moveToPoint(-48, 28.5, 500, {.forwards=false, .maxSpeed=50}, false);
    mobile_stake_clamp.set_value(false);
}