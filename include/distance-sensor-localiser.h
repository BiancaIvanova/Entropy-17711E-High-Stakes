#ifndef DISTANCE_SENSOR_LOCALISER_H
#define DISTANCE_SENSOR_LOCALISER_H

#include "pros/distance.hpp"

class DistanceSensorLocaliser
{
    public:
        struct Pose {
            double x;
            double y;
            double heading;
        };

        DistanceSensorLocaliser(pros::Distance& left_sensor, pros::Distance& right_sensor, double angle, double x, double y);

        double getX();
        double getY();
        Pose getCurrentPose();
        void configure(pros::Distance& left_sensor, pros::Distance& right_sensor, double forward_offset, double side_offset);
        void updatePose(double new_x, double new_y, double new_angle);

    private:
        pros::Distance* left_sensor;
        pros::Distance* right_sensor;
        double angle;
        double x;
        double y;
        double forward_offset;
        double side_offset;
};

#endif