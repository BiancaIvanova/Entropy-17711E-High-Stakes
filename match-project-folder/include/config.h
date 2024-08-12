#include <iostream>
#include "main.h"
#include "lemlib/api.hpp"
#include "api.h"
#pragma once
using namespace std;

extern pros::Controller controller;

// Main Configuration
extern pros::MotorGroup left_drive;
extern pros::MotorGroup right_drive;
extern pros::Motor intake;
extern pros::Motor outtake;
extern pros::Imu inertial_sensor;
extern pros::adi::DigitalOut mobile_stake_clamp;

// Lemlib
extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

// Other functions
void intake_async(int t, int velocity);
void intake_standard(int t, int velocity);
void deposit_async(int t, int velocity);
void deposit_standard(int t, int velocity);