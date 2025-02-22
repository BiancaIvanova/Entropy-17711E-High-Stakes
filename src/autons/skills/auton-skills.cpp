#include "autons.h"
#include "config.h"
#include "lemlib/chassis/chassis.hpp"
#include "subsystem-control-functions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void auton_skills()
{
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    
    // Robot starts with the back directly facing alliance wall stake
    chassis.setPose(-62.5, 0, 270);
    pros::delay(1000);

    // Deal with the close left side of the field
    auton_skills_stage_1();
    // Do the same with the close right side of the field
    auton_skills_stage_2();
    // Move to the back of the field and fill the last empty stake
    auton_skills_stage_3();
    // Finish by putting the two blue ring stakes into the corners
    auton_skills_stage_4();

}


void auton_skills_stage_1()
{
    // NOT PROGRAMMED   
}

void auton_skills_stage_2()
{
    // NOT PROGRAMMED
}

void auton_skills_stage_3()
{
    // NOT PROGRAMMED
}

void auton_skills_stage_4()
{
    // NOT PROGRAMMED
}