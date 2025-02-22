#include "double-imu.h"

DoubleImu::DoubleImu(pros::Imu* left, pros::Imu* right)
    : pros::Imu(left->get_port()), left_imu(left), right_imu(right) {}

double DoubleImu::get_heading() {
    double left_heading = left_imu->get_heading();
    double right_heading = right_imu->get_heading();

    return (left_heading + right_heading) / 2.0;
}
