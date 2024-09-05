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

void assign_button(int x, int y, int width, int height, const std::string& name, int id, std::function<void()> callback);
void button_event_handler(lv_event_t* e);
void init_display();
void ready_display();
void create_button(int x, int y, int width, int height, Button button);
void update_display_data();

#endif
