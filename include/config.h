#include "main.h"
#include "arm-controller.h"
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
extern pros::Motor left_arm;
extern pros::Motor right_arm;
extern pros::Imu left_inertial_sensor;
extern pros::Imu right_inertial_sensor;
extern pros::Optical optical_sensor;
extern pros::Rotation arm_rotation_sensor;
extern pros::adi::DigitalOut mobile_stake_clamp;
extern pros::adi::DigitalOut doinker;

// PID Configuration
extern ArmController arm;

// Lemlib
extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

