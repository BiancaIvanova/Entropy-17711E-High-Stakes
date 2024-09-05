#include "liblvgl/core/lv_obj.h"
#include "main.h"
#include "liblvgl/lvgl.h"
#include "auton-selector.h"
#include "graphics.h"

lv_obj_t* Graphics::create_image(const lv_img_dsc_t *src, lv_coord_t x, lv_coord_t y, lv_obj_t *parent)
{
    lv_obj_t *img = lv_img_create(parent);
    lv_img_set_src(img, src);
    lv_obj_set_pos(img, x, y);
    return img;
}

lv_obj_t* Graphics::create_label(const char *text, int x, int y, const lv_font_t *font, lv_color_t color, Alignment align, lv_obj_t *parent)
{
    lv_obj_t *temp_label = lv_label_create(parent);
    lv_label_set_text(temp_label, text);
    lv_obj_set_style_text_font(temp_label, font, 0);

    lv_coord_t text_width = lv_obj_get_width(temp_label);
    lv_coord_t text_height = lv_obj_get_height(temp_label);

    lv_obj_del(temp_label);

    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, font, 0);
    lv_obj_set_style_text_color(label, color, 0);

    switch (align) {
        case Alignment::LEFT:
            lv_obj_set_pos(label, x, y);
            break;
        case Alignment::CENTRE:
            lv_obj_set_pos(label, x - text_width / 2, y);
            break;
        case Alignment::RIGHT:
            lv_obj_set_pos(label, x - text_width, y);
            break;
    }

    return label;
}

lv_obj_t* Graphics::create_rectangle(lv_coord_t width, lv_coord_t height, lv_coord_t x, lv_coord_t y, lv_color_t color, lv_obj_t *parent, int corner_radius)
{
    lv_obj_t *rect = lv_obj_create(parent);
    lv_obj_set_size(rect, width, height);
    lv_obj_set_pos(rect, x, y);

    // Dynamically allocate the style
    lv_style_t *rect_style = new lv_style_t;
    lv_style_init(rect_style);
    lv_style_set_bg_color(rect_style, color);
    lv_style_set_border_width(rect_style, 0);
    
    lv_obj_add_style(rect, rect_style, 0);
    lv_obj_set_scrollbar_mode(rect, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_radius(rect, corner_radius, LV_PART_MAIN);

    // Save or manage rect_style pointer if needed for future use or deletion
    return rect;
}