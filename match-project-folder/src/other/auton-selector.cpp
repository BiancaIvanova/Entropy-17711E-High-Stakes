#include "auton-selector.h"
#include "liblvgl/core/lv_event.h"
#include "liblvgl/core/lv_obj.h"

LV_IMG_DECLARE(high_stakes_field_scaled_map);
LV_FONT_DECLARE(roboto_bold_14px);
LV_FONT_DECLARE(roboto_medium_10px);
LV_FONT_DECLARE(roboto_regular_8px);
LV_FONT_DECLARE(roboto_regular_10px);

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 272;

lv_color_t background_colour = lv_color_hex(0x2e2e2e);
lv_color_t white_colour = lv_color_hex(0xfafafa);
lv_color_t darker_white_colour = lv_color_hex(0xd0d0d0);
lv_color_t alliance_red_colour = lv_color_hex(0xc9252b);
lv_color_t alliance_blue_colour = lv_color_hex(0x0169a9);
lv_color_t alliance_neutral_grey_colour = lv_color_hex(0x5e5e5e);

// Global variable tracking current button selection
lv_obj_t* current_selected_button = nullptr;

// Current selected auton, from 1 - 4 (0 is the null value)
int selected_auton_slot = 0;


void button_event_handler(lv_event_t* e)
{
    lv_obj_t* btn = lv_event_get_target(e);

    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        if (current_selected_button != btn && current_selected_button != nullptr) // If a different button is being pressed
        {
            // Restore to original colour
            lv_obj_set_style_bg_color(current_selected_button, white_colour, 0);   
        }

        // Set current button to darker colour
        lv_obj_set_style_bg_color(btn, darker_white_colour, 0);
        current_selected_button = btn;


        // Retrieve the stored ID
        int button_id = (int) lv_obj_get_user_data(btn); 
        // Update the global variable
        selected_auton_slot = button_id; 
    }
}


void init_display()
{
    // Field image
    lv_obj_t *field_image = Graphics::create_image(&high_stakes_field_scaled_map, 12, 20);
    // Bottom status bar
    lv_obj_t *status_bar = Graphics::create_rectangle(SCREEN_WIDTH, 35, 0, 237, alliance_neutral_grey_colour);
    // Status text
    lv_obj_t *status_text = Graphics::create_label("Waiting...", 50, 150, &roboto_bold_14px, Alignment::CENTRE);

    // Radio buttons
    create_button(50, 50, 100, 40, "Button 1", 1);
    create_button(50, 100, 100, 40, "Button 2", 2);
    create_button(50, 150, 100, 40, "Button 3", 3);
    create_button(50, 200, 100, 40, "Button 4", 4);
}


void create_button(int x, int y, int width, int height, std::string text, int id_num)
{
    const int WRAP_LIMIT = 14; // guess
    const int LEFT_PADDING = 7;
    const int TEXT_SPACING = 14;
    const int LARGE_TOP_PADDING = 13;
    const int SMALL_TOP_PADDING = 8;
    const lv_font_t *BUTTON_FONT = &roboto_medium_10px;

    // Create the button rectangle
    lv_obj_t* button_rect = Graphics::create_rectangle(width, height, x, y, white_colour);

    // Set the user data of the button to its ID
    lv_obj_set_user_data(button_rect, (void*)id_num);

    // Add event handler
    lv_obj_add_event_cb(button_rect, button_event_handler, LV_EVENT_CLICKED, NULL);

    // Wrap text as necessary
    if (int len = text.length(); len <= WRAP_LIMIT)
    {
        // Single line of text
        lv_obj_t* txt_1 = Graphics::create_label(text.c_str(), x + LEFT_PADDING, y + LARGE_TOP_PADDING, BUTTON_FONT, Alignment::LEFT, button_rect);
    }
    else
    {
        // Two lines of text (gets truncated on the second line)
        int space_pos = text.rfind(' ', WRAP_LIMIT);

        std::string first_line;
        if (space_pos != std::string::npos)
        {
            first_line = text.substr(0, space_pos);
        }
        else
        {
            first_line = text.substr(0, WRAP_LIMIT);
        }

        lv_obj_t* txt_1 = Graphics::create_label(first_line.c_str(), x, y + SMALL_TOP_PADDING, BUTTON_FONT, Alignment::LEFT, button_rect);
        std::string remaining_text = text.substr(first_line.length());
        if (!remaining_text.empty())
        {
            lv_obj_t* txt_2 = Graphics::create_label(remaining_text.c_str(), x, y + SMALL_TOP_PADDING + TEXT_SPACING, BUTTON_FONT, Alignment::CENTRE, button_rect);
        }
    }
}