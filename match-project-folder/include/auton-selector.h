#include <iostream>
#include "main.h"
#include "api.h"
#include "graphics.h"

void button_event_handler(lv_event_t* e);
void init_display();
void create_button(int x, int y, int width, int height, std::string text, int id_num);