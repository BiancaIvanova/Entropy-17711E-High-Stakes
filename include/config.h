#include "main.h"
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/api.hpp"

extern pros::Controller controller;

// Main Configuration
extern pros::MotorGroup left_drive;
extern pros::MotorGroup right_drive;
extern pros::Motor intake;
extern pros::Motor arm;
extern pros::Imu inertial_sensor;
extern pros::Optical optical_sensor;
extern pros::adi::DigitalOut mobile_stake_clamp;
extern pros::adi::DigitalOut arm_flip;

// Lemlib
extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

