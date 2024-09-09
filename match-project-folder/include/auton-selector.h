#ifndef AUTON_SELECTOR_H
#define AUTON_SELECTOR_H

#include "graphics.h"
#include <string>
#include <functional>

// Button struct
struct Button {
    std::string name;
    int id;
    std::function<void()> callback;
};

// This is whether the autmatic gps detection worked
enum class DetectionState {
    AUTO,
    FAILED,
    OVERRIDE
};

extern DetectionState current_detection_state;

extern std::function<void()> selected_auton_callback;

void assign_button(int x, int y, int width, int height, const std::string& name, int id, std::function<void()> callback);
void button_event_handler(lv_event_t* e);
void init_display();
void confirm_selection();
void ready_display();
void create_button(int x, int y, int width, int height, Button button);
void update_display_data();
void update_detection_status(DetectionState state);
void automatic_gps();

#endif
