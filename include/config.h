#include "main.h"
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/api.hpp"

extern pros::Controller controller;

extern const int TASK_DELAY_MS;

enum AllianceColour
{
    RED,
    BLUE
};

// Global variable defining our alliance colour
extern AllianceColour currentAllianceColour;

// Main Configuration
extern pros::MotorGroup left_drive;
extern pros::MotorGroup right_drive;
extern pros::Motor intake;
extern pros::Motor arm;
extern pros::Imu inertial_sensor;
extern pros::Optical optical_sensor;
extern pros::Rotation arm_rotation_sensor;
extern pros::adi::DigitalOut mobile_stake_clamp;
extern pros::adi::DigitalOut arm_flip;

// Lemlib
extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

