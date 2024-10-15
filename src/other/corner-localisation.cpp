#include "main.h"
#include "config.h"
#include "lemlib/api.hpp"
#include "pros/distance.h"
#include <optional>

class DistanceSensorLocaliser
{
    public:
        struct Pose {
            double x;
            double y;
            double heading;
        };

        DistanceSensorLocaliser(pros::Distance& left_sensor, pros::Distance& right_sensor, double angle, double x, double y)
        : left_sensor(&left_sensor), right_sensor(&right_sensor), angle(angle), x(x), y(y), forward_offset_set(false), side_offset_set(false) {}

        bool configureOffsets(double forward_offset, double side_offset) {
            if (!forward_offset_set && !side_offset_set) {
                this->forward_offset = forward_offset;
                this->side_offset = side_offset;
                forward_offset_set = true;
                side_offset_set = true;
                return true;
            }
            return false;
        }

        std::optional<Pose> getCurrentPose() const {
            // assumes bottom left corner (temporarily)
            // uses the corner as the origin of the graph (temprarily)
            Pose current_pose;

            double d_left = left_sensor->get_distance(); // in mm
            double d_right = right_sensor->get_distance(); // in mm

            // If the readings of the distance sensors are way off
            if (d_left == PROS_ERR || d_left == 9999 || d_right == PROS_ERR || d_right == 9999) {
                return std::nullopt;
            }

            double heading = imu->get_heading();

            double alpha = heading - 45;
            current_pose.x = cos(alpha) * d_left;
            current_pose.y = cos(alpha) * d_right;
            current_pose.heading = heading;

            return current_pose;
        }

    private:
        pros::Distance* left_sensor;
        pros::Distance* right_sensor;
        pros::Imu* imu;
        double angle;
        double x;
        double y;
        double forward_offset;
        double side_offset;

        bool forward_offset_set;
        bool side_offset_set;
};
