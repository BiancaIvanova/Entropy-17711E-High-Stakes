#ifndef DOUBLE_IMU_HPP
#define DOUBLE_IMU_HPP

#include "pros/imu.hpp"

class DoubleImu : public pros::Imu {
public:
    pros::Imu* left_imu;
    pros::Imu* right_imu;

    DoubleImu(pros::Imu* left, pros::Imu* right);

    double get_heading();
};

#endif
