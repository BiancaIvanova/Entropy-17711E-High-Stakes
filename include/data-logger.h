#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include "pros/misc.h"
#include <vector>
#include <iostream>

struct ControllerState {
    int timestamp;
    int leftX, leftY, rightX, rightY;
    bool RIGHT, DOWN, Y, B;
    bool L1, L2, R1, R2;
};

extern std::vector<ControllerState> controllerLogs;
extern int log_timestamp;

void log_controller();
void save_logs_to_file();
void read_logs_from_file();
void replay_logs();

#endif