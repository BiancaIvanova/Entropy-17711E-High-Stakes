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
#include "double-imu.h"
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

const int TASK_DELAY_MS = 20;

const float TRACKWIDTH = 12.8;
const float MOTOR_GEAR_TEETH = 36.0;
const float MOTOR_RPM = 600.0;
const float WHEEL_GEAR_TEETH = 60.0;
const float WHEEL_RPM = MOTOR_RPM / (WHEEL_GEAR_TEETH / MOTOR_GEAR_TEETH);
const float WHEEL_DIAMETER = lemlib::Omniwheel::NEW_325;

pros::Controller controller(pros::E_CONTROLLER_MASTER);


// -----------------------------------------------------------------------------
// Ports Configuration

using MotorGearset = pros::MotorGearset;
using MotorUnits = pros::v5::MotorUnits;

pros::MotorGroup left_drive({-12, -13, -20}, MotorGearset::blue);
pros::MotorGroup right_drive({14, 15, 19}, MotorGearset::blue);

pros::Motor intake(16, MotorGearset::blue, MotorUnits::degrees);

pros::Motor left_arm(17, MotorGearset::green, MotorUnits::degrees);
pros::Motor right_arm(-18, MotorGearset::green, MotorUnits::degrees);

pros::Imu left_inertial_sensor(9);
pros::Imu right_inertial_sensor(10);

pros::GPS gps_sensor(20);
pros::Optical optical_sensor(7);
pros::Rotation arm_rotation_sensor(8);
pros::Rotation vertical_odom(5);
pros::Rotation horizontal_odom(6);

pros::adi::DigitalOut mobile_stake_clamp('A');
pros::adi::DigitalOut doinker('B');

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
    &right_inertial_sensor,
};

// Forward/Backward PID
lemlib::ControllerSettings lateralController {
    12.5,
    0,
    1,
    3,
    1,
    100,
    3,
    500,
    30
};
 
// Turning PID
lemlib::ControllerSettings angularController {
    2.8,
    0,
    1.5,
    3,
    1,
    100,
    3,
    500,
    0
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
