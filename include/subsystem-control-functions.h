#include "main.h"
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/api.hpp"

void logPose();

void intake_async(int t, int velocity);
void intake_standard(int t, int velocity);
void intake_into_arm();
void arm_async(int t, int velocity);
void arm_standard(int t, int velocity);