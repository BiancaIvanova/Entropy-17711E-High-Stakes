/*
   ____ ___  _   _ _____ ___ ____ 
  / ___/ _ \| \ | |  ___|_ _/ ___|
 | |__| |_| | |\  |  _|  | | |_| |
  \____\___/|_| \_|_|   |___\____|
                                  
*/
// FINAL COMPETITION ROBOT PORTS DONE

#include "fmt/format.h"
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/pose.hpp"
#include "main.h"
#include "config.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"
#include "arm-controller.h"
#include "subsystem-control-functions.h"
#include "double-imu.h"
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

const int TASK_DELAY_MS = 20;

const float TRACKWIDTH = 18;
const float MOTOR_GEAR_TEETH = 36.0;
const float MOTOR_RPM = 600.0;
const float WHEEL_GEAR_TEETH = 48.0;
const float WHEEL_RPM = MOTOR_RPM / (WHEEL_GEAR_TEETH / MOTOR_GEAR_TEETH);
const float WHEEL_DIAMETER = lemlib::Omniwheel::NEW_275;

pros::Controller controller(pros::E_CONTROLLER_MASTER);

AllianceColour currentAllianceColour = RED;
std::string currentAutonName = "";

// -----------------------------------------------------------------------------
// Ports Configuration

using MotorGearset = pros::MotorGearset;
using MotorUnits = pros::v5::MotorUnits;

pros::MotorGroup left_drive({-14, -17, -19}, MotorGearset::blue);
pros::MotorGroup right_drive({18, 20, 3}, MotorGearset::blue);

pros::Motor intake_motor(-4, MotorGearset::blue, MotorUnits::degrees);

pros::Motor left_arm(-2, MotorGearset::green, MotorUnits::degrees);
pros::Motor right_arm(1, MotorGearset::green, MotorUnits::degrees);

pros::Imu left_inertial_sensor(10);
pros::Imu right_inertial_sensor(15);

pros::GPS gps_sensor(20);
pros::Optical optical_sensor(13);
pros::Rotation arm_rotation_sensor(5);
pros::Rotation vertical_odom(5);
pros::Rotation horizontal_odom(6);

pros::adi::DigitalOut mobile_stake_clamp('A');
pros::adi::DigitalOut left_doinker('C');
pros::adi::DigitalOut right_doinker('B');

DoubleImu double_imu(&left_inertial_sensor, &right_inertial_sensor);

// -----------------------------------------------------------------------------
// PID configuration
ArmController arm (
    0.2,
    0.0,
    0.8,
    left_arm,
    right_arm,
    arm_rotation_sensor
);

IntakeController intake
{
    intake_motor
};

// -----------------------------------------------------------------------------
// Lemlib configuration

lemlib::TrackingWheel vertical(&vertical_odom, lemlib::Omniwheel::NEW_2, 1);
lemlib::TrackingWheel horizontal(&horizontal_odom, lemlib::Omniwheel::NEW_2, 0);

lemlib::Drivetrain drivetrain {
    &left_drive,
    &right_drive,
    TRACKWIDTH,
    WHEEL_DIAMETER,
    WHEEL_RPM,
    8 // This is because we have traction wheels
};

lemlib::OdomSensors sensors {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &left_inertial_sensor,
};

// Forward/Backward PID
lemlib::ControllerSettings lateralController {
    13,
    0,
    3,
    3,
    1,
    100,
    3,
    500,
    20
};
 
// Turning PID
lemlib::ControllerSettings angularController {
    1.7,
    0,
    10.0,
    0,
    1,
    100,
    3,
    500,
    0
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
