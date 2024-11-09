#include "distance-sensor-localiser.h"
#include <cmath>


// Constructor
DistanceSensorLocaliser::DistanceSensorLocaliser(
    pros::Distance& left_sensor,
    pros::Distance& right_sensor,
    pros::Imu& imu,
    double angle,
    double x,
    double y,
    double forward_offset,
    double side_offset)
    : 
    left_sensor(&left_sensor),
    right_sensor(&right_sensor),
    imu(&imu),
    angle(angle),
    x(x),
    y(y),
    FORWARD_OFFSET(FORWARD_OFFSET),
    SIDE_OFFSET(SIDE_OFFSET),
    initial_heading_offset(45)
{}

std::optional<DistanceSensorLocaliser::Pose> DistanceSensorLocaliser::getCurrentPose(std::optional<FieldCorner> corner) const {
    Pose current_pose;

    // Read the measurements from the distance sensors
    double d_left = left_sensor->get_distance();
    double d_right = right_sensor->get_distance();
    double measured_heading = imu->get_heading();

    // If the readings of the sensors are invalid
    if (d_left == errno || d_left == 9999 || d_right == errno || d_right == 9999) {
        return std::nullopt;
    }

    // Determine the heading offset based on the corner or infer it
    double heading_transformation = initial_heading_offset;

    if (corner.has_value()) {
        heading_transformation = static_cast<int>(corner.value());
    } else {
        double current_heading = imu->get_heading();
        if (current_heading >= 0 && current_heading < 90) {
            heading_transformation = static_cast<int>(FieldCorner::NORTH_EAST);
        } else if (current_heading >= 90 && current_heading < 180) {
            heading_transformation = static_cast<int>(FieldCorner::SOUTH_EAST);
        } else if (current_heading >= 180 && current_heading < 270) {
            heading_transformation = static_cast<int>(FieldCorner::SOUTH_WEST);
        } else {
            heading_transformation = static_cast<int>(FieldCorner::NORTH_WEST);
        }
    }

    // Compute the adjusted heading
    double transformed_heading = measured_heading - heading_transformation;
    if (transformed_heading >= 360) {
        transformed_heading -= 360;
    }

    // Angle for sensor calculations
    double alpha = (transformed_heading - 45) * M_PI / 180.0; // Convert to radians

    // Convert distances from mm to inches
    const double MM_TO_INCHES = 1.0 / 25.4; // Conversion factor

    // Calculate relative robot pose
    double x_temp = (d_left * cos(alpha) - FORWARD_OFFSET) * MM_TO_INCHES;
    double y_temp = (d_right * cos(alpha) - SIDE_OFFSET) * MM_TO_INCHES;

    current_pose.heading = measured_heading;

    return current_pose;
}
