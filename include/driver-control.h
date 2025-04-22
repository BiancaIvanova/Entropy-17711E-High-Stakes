#include "main.h"
#include "lemlib/api.hpp"
#include "api.h"
#pragma once

extern std::vector<double> armPositions;
extern int currentIndex; 

extern bool prevUp;
extern bool prevDown;

void split_curvature();
void intake_control(bool in, bool out);
void stake_clamp_control(bool control);
void left_doinker_control(bool control);
void right_doinker_control(bool control);

void arm_control_new(bool up, bool down);

void arm_control(bool up, bool down);
void arm_control_logic(bool up, bool down);
void start_arm_control();