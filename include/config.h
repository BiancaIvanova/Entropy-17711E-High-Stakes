#include "main.h"
#include "arm-controller.h"
#include "subsystem-control-functions.h"
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
extern std::string currentAutonName;

// Main Configuration
extern pros::MotorGroup left_drive;
extern pros::MotorGroup right_drive;
extern pros::Motor intake_motor;
extern pros::Motor left_arm;
extern pros::Motor right_arm;
extern pros::Imu left_inertial_sensor;
extern pros::Imu right_inertial_sensor;
extern pros::Optical optical_sensor;
extern pros::Rotation arm_rotation_sensor;
extern pros::Rotation vertical_odom;
extern pros::Rotation horizontal_odom;
extern pros::adi::DigitalOut mobile_stake_clamp;
extern pros::adi::DigitalOut left_doinker;
extern pros::adi::DigitalOut right_doinker;

// PID Configuration
extern ArmController arm;
extern IntakeController intake;

// Lemlib
extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

