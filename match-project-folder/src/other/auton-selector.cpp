#include "auton-selector.h"
#include <map>
#include "config.h"
#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_event.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/misc/lv_color.h"
#include "autons.h"
#include "pros/rtos.hpp"

LV_IMG_DECLARE(high_stakes_field_scaled);
LV_IMG_DECLARE(entropy_logo_scaled);

LV_FONT_DECLARE(roboto_bold_14px);
LV_FONT_DECLARE(roboto_medium_10px);
LV_FONT_DECLARE(roboto_medium_16px);
LV_FONT_DECLARE(roboto_regular_8px);
LV_FONT_DECLARE(roboto_regular_10px);
LV_FONT_DECLARE(roboto_bold_18px);
LV_FONT_DECLARE(roboto_bold_20px);

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 272;

lv_color_t background_colour = lv_color_hex(0x2e2e2e);
lv_color_t white_colour = lv_color_hex(0xfafafa);
lv_color_t black_colour = lv_color_hex(0x1c1c1c);
lv_color_t darker_white_colour = lv_color_hex(0xababab);
lv_color_t alliance_red_colour = lv_color_hex(0xc9252b);
lv_color_t alliance_blue_colour = lv_color_hex(0x0169a9);
lv_color_t alliance_neutral_grey_colour = lv_color_hex(0x5e5e5e);

lv_color_t status_green_color = lv_color_hex(0x00bf63);
lv_color_t status_yellow_color = lv_color_hex(0xedde14);
lv_color_t status_red_color = lv_color_hex(0xfd060f);

// Data labels
lv_obj_t *gps_x_label = nullptr;
lv_obj_t *gps_y_label= nullptr;
lv_obj_t *optical_r_label = nullptr;
lv_obj_t *optical_b_label = nullptr;

// Global variable tracking current button selection
lv_obj_t* current_selected_button = nullptr;

// Current selected auton, from 1 - 4 (0 is the null value)
int selected_auton_slot = 0;

// Selected button name
std::string selected_button_name = "---";

// Dictionary storing id as the key, and the value is a callable entity (ie. a function)
std::map<int, std::function<void()>> button_callbacks;

// Global variable storing the final selected auton
std::function<void()> selected_auton_callback = nullptr;

// Sensor data
double gps_x_data;
double gps_y_data;
double gps_theta_data;
double red_data;
double blue_data;
double range_data;


DetectionState current_detection_state = DetectionState::FAILED;

lv_obj_t* detection_status_text = nullptr;
lv_obj_t* detection_status_bar = nullptr;

// Metres to inches conversion
const double M_TO_IN_CONV = 39.37;


void button_event_handler(lv_event_t* e)
{
    lv_obj_t* btn = lv_event_get_target(e);

    if (lv_event_get_code(e) == LV_EVENT_CLICKED)
    {
        if (current_selected_button == btn) 
        {
            // If the clicked button is already selected, deselect it
            lv_obj_set_style_bg_color(btn, white_colour, 0);
            current_selected_button = nullptr;
            selected_auton_slot = 0; // Reset the selected auton slot to 0 (null value)

            // Reset current selected auton
            selected_auton_callback = nullptr;
            selected_button_name = "---";
        }
        else 
        {
            // If a different button is being pressed
            if (current_selected_button != nullptr) 
            {
                // Restore the previous button's original color
                lv_obj_set_style_bg_color(current_selected_button, white_colour, 0);
            }

            // Set the new button to a darker color
            lv_obj_set_style_bg_color(btn, darker_white_colour, 0);
            current_selected_button = btn;

            // Retrieve the stored ID and update the global variable
            int button_id = (int)lv_obj_get_user_data(btn); 
            selected_auton_slot = button_id;

            // Update the selected callback function
            if (button_callbacks.find(button_id) != button_callbacks.end()) {
                selected_auton_callback = button_callbacks[button_id];
            }

            // Update the global button name
            switch (button_id) {
                case 1:
                    selected_button_name = "NORTH SIDE MATCH";
                    break;
                case 2:
                    selected_button_name = "SOUTH SIDE MATCH";
                    break;
                default:
                    selected_button_name = "---";
                    break;
            }
        }
        
        // Now it's manual override
        current_detection_state = DetectionState::OVERRIDE;
        update_detection_status(current_detection_state);
    }
}


void create_button(int x, int y, int width, int height, Button button)
{
    const int WRAP_LIMIT = 20; // guess
    const int LEFT_PADDING = -3;
    const int TEXT_SPACING = 14;
    const int LARGE_TOP_PADDING = -3;
    const int SMALL_TOP_PADDING = 8;
    const lv_font_t *BUTTON_FONT = &roboto_medium_16px;

    // Create the button rectangle
    lv_obj_t* button_rect = Graphics::create_rectangle(width, height, x, y, white_colour, lv_scr_act());
    
    // Set the user data of the button to its ID
    lv_obj_set_user_data(button_rect, (void*)button.id);

    // Add event handler
    lv_obj_add_event_cb(button_rect, button_event_handler, LV_EVENT_CLICKED, NULL);

    // Put callback in the dictionary
    button_callbacks[button.id] = button.callback;

    // Wrap text as necessary
    if (int len = button.name.length(); len <= WRAP_LIMIT)
    {
        // Single line of text
        lv_obj_t* txt_1 = Graphics::create_label(button.name.c_str(), LEFT_PADDING, LARGE_TOP_PADDING, BUTTON_FONT, black_colour, Alignment::LEFT, button_rect);
    }
    else
    {
        // Two lines of text (gets truncated on the second line)
        int space_pos = button.name.rfind(' ', WRAP_LIMIT);

        std::string first_line;
        if (space_pos != std::string::npos)
        {
            first_line = button.name.substr(0, space_pos);
        }
        else
        {
            first_line = button.name.substr(0, WRAP_LIMIT);
        }

        lv_obj_t* txt_1 = Graphics::create_label(first_line.c_str(), LEFT_PADDING, SMALL_TOP_PADDING, BUTTON_FONT, black_colour, Alignment::LEFT, button_rect);
        std::string remaining_text = button.name.substr(space_pos + 1);
        if (!remaining_text.empty())
        {
            lv_obj_t* txt_2 = Graphics::create_label(remaining_text.c_str(), LEFT_PADDING, SMALL_TOP_PADDING + TEXT_SPACING, BUTTON_FONT, black_colour, Alignment::CENTRE, button_rect);
        }
    }
}


void assign_button(int x, int y, int width, int height, const std::string& name, int id, std::function<void()> callback)
{
    Button button = { name, id, callback };
    create_button(x, y, width, height, button);
}


void init_display()
{
    // Field image
    lv_obj_t *field_image = Graphics::create_image(&high_stakes_field_scaled, 12, 12);
    // Bottom status bar
    lv_obj_t *status_bar = Graphics::create_rectangle(SCREEN_WIDTH, 32, 0, 208, alliance_neutral_grey_colour);
    // Status text
    lv_obj_t *status_text = Graphics::create_label("WAITING...", 200, 214, &roboto_bold_20px, white_colour, Alignment::CENTRE);

    // Data logs
    lv_obj_t *gps_title = Graphics::create_label("GPS:", 220, 12, &roboto_bold_18px, white_colour, Alignment::LEFT);
    gps_x_label = Graphics::create_label("x: ", 220, 32, &roboto_medium_16px, white_colour, Alignment::LEFT);
    gps_y_label = Graphics::create_label("y: ", 220, 52, &roboto_medium_16px, white_colour, Alignment::LEFT);

    lv_obj_t *optical_title = Graphics::create_label("Optical:", 220, 85, &roboto_bold_18px, white_colour, Alignment::LEFT);
    optical_r_label = Graphics::create_label("r: ", 220, 105, &roboto_medium_16px, white_colour, Alignment::LEFT);
    optical_b_label = Graphics::create_label("b: ", 220, 125, &roboto_medium_16px,white_colour, Alignment::LEFT);

    // Detection Status
    detection_status_text = Graphics::create_label("AUTO", 220, 175, &roboto_bold_18px, white_colour, Alignment::LEFT);
    detection_status_bar = Graphics::create_rectangle(85, 5, 220, 195, status_yellow_color);

    // Declare radio buttons
    assign_button(325, 10, 143, 40, "North Side Match", 1, [](){north_side_match(); });
    assign_button(325, 58, 143, 40, "South Side Match", 2, [](){south_side_match(); });
    assign_button(325, 106, 143, 40, "---", 3, [](){ });
    assign_button(325, 154, 143, 40, "---", 4, [](){ });

    // Confirm button
    lv_obj_t *confirm_button_rect = Graphics::create_rectangle(100, 32, SCREEN_WIDTH - 100, 208, lv_color_hex(0xd4d4d4));

    // Create label for the confirm button
    lv_obj_t *confirm_label = Graphics::create_label("Confirm", 0, -8, &roboto_medium_16px, black_colour, Alignment::CENTRE, confirm_button_rect);

    // Confirm button event handler
    lv_obj_add_event_cb(confirm_button_rect, [](lv_event_t *e) {
        if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
            confirm_selection();
        }
    }, LV_EVENT_CLICKED, NULL);
}


void confirm_selection()
{
    ready_display();
    pros::delay(100);
}


void ready_display() 
{
    // Clear screen
    lv_obj_clean(lv_scr_act());

    // Field image
    lv_obj_t *entropy_logo = Graphics::create_image(&entropy_logo_scaled, 18, 87);

    // Selected Auton
    std::string upper_button_name = selected_button_name;
    std::transform(upper_button_name.begin(), upper_button_name.end(), upper_button_name.begin(), ::toupper);
    lv_obj_t *selected_auton_text = Graphics::create_label(upper_button_name.c_str(), 30, 202, &roboto_bold_18px, white_colour, Alignment::LEFT);

    // Vertical bar
    lv_obj_t *vertical_line = Graphics::create_rectangle(2, 210, 346, 18, white_colour);

    // Data logs
    lv_obj_t *gps_title = Graphics::create_label("GPS:", 370, 22, &roboto_bold_18px, white_colour, Alignment::LEFT);
    gps_x_label = Graphics::create_label("x: ", 370, 42, &roboto_medium_16px, white_colour, Alignment::LEFT);
    gps_y_label = Graphics::create_label("y: ", 370, 62, &roboto_medium_16px, white_colour, Alignment::LEFT);

    lv_obj_t *optical_title = Graphics::create_label("Optical:", 370, 95, &roboto_bold_18px, white_colour, Alignment::LEFT);
    optical_r_label = Graphics::create_label("r: ", 370, 115, &roboto_medium_16px, white_colour, Alignment::LEFT);
    optical_b_label = Graphics::create_label("b: ", 370, 135, &roboto_medium_16px, white_colour, Alignment::LEFT);

    // Status 'Ready'
    lv_obj_t *status_text = Graphics::create_label("READY", 370, 195, &roboto_bold_18px, white_colour, Alignment::LEFT);
    lv_obj_t *status_bar = Graphics::create_rectangle(85, 5, 370, 215, status_green_color);

    pros::Task update_task([]() {
        while (true) {
            update_display_data();
            pros::delay(1000);
        }
    });
}


void automatic_gps() {
    const double HALF_FIELD = 96;

    // Select auton based on gps coords
    if (gps_x_data < HALF_FIELD && gps_y_data < HALF_FIELD) {
        selected_auton_callback = north_side_match;
        current_detection_state = DetectionState::AUTO;
    } 
    else if (gps_x_data < HALF_FIELD && gps_y_data > HALF_FIELD) {
        selected_auton_callback = south_side_match;
        current_detection_state = DetectionState::AUTO;
    } 
    else {
        selected_auton_callback = nullptr;
        selected_button_name = "---";  // Default to no auton
        current_detection_state = DetectionState::FAILED;
    }
}


void update_display_data()
{
    gps_x_data = gps_sensor.get_position_x() * M_TO_IN_CONV;
    gps_y_data = gps_sensor.get_position_y() * M_TO_IN_CONV;
    gps_theta_data = gps_sensor.get_heading();
    red_data = optical_sensor.get_rgb().red;
    blue_data = optical_sensor.get_rgb().blue;
    range_data = optical_sensor.get_proximity();

    lv_label_set_text(gps_x_label, fmt::format("x: {:.2f}", gps_x_data).c_str());
    lv_label_set_text(gps_y_label, fmt::format("y: {:.2f}", gps_y_data).c_str());
    lv_label_set_text(optical_r_label, fmt::format("r: {:.2f}", red_data).c_str());
    lv_label_set_text(optical_b_label, fmt::format("b: {:.2f}", blue_data).c_str());
}


void update_detection_status(DetectionState state) {
    switch (state) {
        case DetectionState::AUTO:
            lv_label_set_text(detection_status_text, "AUTO");
            lv_obj_set_style_bg_color(detection_status_bar, status_yellow_color, 0);
            break;
        case DetectionState::FAILED:
            lv_label_set_text(detection_status_text, "FAILED");
            lv_obj_set_style_bg_color(detection_status_bar, status_red_color, 0);
            break;
        case DetectionState::OVERRIDE:
            lv_label_set_text(detection_status_text, "OVERRIDE");
            lv_obj_set_style_bg_color(detection_status_bar, status_green_color, 0);
            break;
    }
}

DetectionState get_detection_state() {
    return current_detection_state;
}

void set_detection_state(DetectionState state) {
    current_detection_state = state;
    update_detection_status(state);
}