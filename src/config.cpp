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
#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

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

pros::MotorGroup left_drive({-11, -12, 13}, MotorGearset::blue);
pros::MotorGroup right_drive({16, 15, -14}, MotorGearset::blue);

pros::Motor intake(18, MotorGearset::blue, MotorUnits::rotations);
pros::Motor arm(19, MotorGearset::green, MotorUnits::rotations);
pros::Imu inertial_sensor(17);
pros::GPS gps_sensor(20);
pros::Optical optical_sensor(8);
pros::adi::DigitalOut mobile_stake_clamp('A');
pros::adi::DigitalOut intake_lift('B');


// -----------------------------------------------------------------------------
// Lemlib configuration

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
    &inertial_sensor
};

// Forward/Backward PID
lemlib::ControllerSettings lateralController {
    10,
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
    1.95,
    0,
    10,
    3,
    1,
    100,
    3,
    500,
    0
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
