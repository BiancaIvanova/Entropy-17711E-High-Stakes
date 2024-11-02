#ifndef DISTANCE_SENSOR_LOCALISER_H
#define DISTANCE_SENSOR_LOCALISER_H

#include "pros/distance.hpp" // Include the PROS distance sensor library
#include "pros/imu.hpp"      // Include the PROS IMU library
#include <optional>          // For std::optional

class DistanceSensorLocaliser {
public:
    struct Pose {
        double x;        // X-coordinate of the robot's position
        double y;        // Y-coordinate of the robot's position
        double heading;  // Robot's heading in degrees
    };

    // Constructor
    DistanceSensorLocaliser(pros::Distance& left_sensor, pros::Distance& right_sensor, pros::Imu& imu, 
                            double angle = 0, double x = 0, double y = 0);

    // Configure offsets for the sensors (forward and side offsets)
    bool configureOffsets(double forward_offset, double side_offset);

    // Get the current pose of the robot
    std::optional<Pose> getCurrentPose() const;

private:
    pros::Distance* left_sensor;  // Pointer to the left distance sensor
    pros::Distance* right_sensor; // Pointer to the right distance sensor
    pros::Imu* imu;               // Pointer to the IMU sensor

    double angle;                 // Robot's current angle (optional for future use)
    double x, y;                  // Robot's initial position

    // Sensor offsets (distances between sensors and robot's center)
    double forward_offset; 
    double side_offset;
    
    // Flags to track if offsets are configured
    bool forward_offset_set;
    bool side_offset_set;

    // Initial heading offset to account for the robot's starting orientation
    double initial_heading_offset;
};

#endif // DISTANCE_SENSOR_LOCALISER_H
