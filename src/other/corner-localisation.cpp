#include "distance-sensor-localiser.h"
#include <cmath> // For cos, M_PI

DistanceSensorLocaliser::DistanceSensorLocaliser(pros::Distance& left_sensor, pros::Distance& right_sensor, pros::Imu& imu, double angle, double x, double y) 
    : left_sensor(&left_sensor), right_sensor(&right_sensor), imu(&imu), angle(angle), x(x), y(y), 
      forward_offset_set(false), side_offset_set(false), initial_heading_offset(45) // Set to 45 degrees
{}

bool DistanceSensorLocaliser::configureOffsets(double forward_offset, double side_offset) {
    if (!forward_offset_set && !side_offset_set) {
        this->forward_offset = forward_offset;
        this->side_offset = side_offset;
        forward_offset_set = true;
        side_offset_set = true;
        return true;
    }
    return false;
}

std::optional<DistanceSensorLocaliser::Pose> DistanceSensorLocaliser::getCurrentPose() const {
    Pose current_pose;

    // Read the measurements from the distance sensors
    double d_left = left_sensor->get_distance();
    double d_right = right_sensor->get_distance();

    // If the readings of the sensors are invalid
    if (d_left == errno || d_left == 9999 || d_right == errno || d_right == 9999) {
        return std::nullopt;
    }

    // Apply the 45 degree
    double heading = imu->get_heading() + initial_heading_offset;
    if (heading >= 360) {
        heading -= 360; // Ensure heading stays within [0, 360) degrees
    }

    double alpha = (heading - 45) * M_PI / 180.0; // Convert to radians

    // Convert distances from mm to inches
    const double MM_TO_INCHES = 1.0 / 25.4; // Conversion factor

    // Calculate robot pose from measurements
    current_pose.x = d_left * cos(alpha) * MM_TO_INCHES;
    current_pose.y = d_right * cos(alpha) * MM_TO_INCHES;
    current_pose.heading = heading;

    return current_pose;
}

