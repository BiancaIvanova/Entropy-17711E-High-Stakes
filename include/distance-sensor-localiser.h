#ifndef DISTANCE_SENSOR_LOCALISER_H
#define DISTANCE_SENSOR_LOCALISER_H

#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include <optional>

class DistanceSensorLocaliser {
public:
    struct Pose {
        double x;
        double y;
        double heading;
    };

    enum FieldCorner {
        SOUTH_WEST = 0,
        NORTH_WEST = 90,
        NORTH_EAST = 180,
        SOUTH_EAST = 270      
    };

    // Constructor to initialize the localiser with sensors, initial position, and sensor offsets
    DistanceSensorLocaliser (
        pros::Distance& left_sensor,
        pros::Distance& right_sensor,
        pros::Imu& imu, 
        double angle,
        double x,
        double y,
        double FORWARD_OFFSET,
        double SIDE_OFFSE
    );

    // Function to get the current pose of the robot
    // Takes an optional parameter for the expected field corner
    std::optional<Pose> getCurrentPose(std::optional<FieldCorner> corner = std::nullopt) const;

private:
    // Pointers to the distance sensors and IMU
    pros::Distance* left_sensor;
    pros::Distance* right_sensor;
    pros::Imu* imu;

    double angle;
    double x;
    double y;

    double FORWARD_OFFSET;
    double SIDE_OFFSET;

    double initial_heading_offset;
};

#endif
