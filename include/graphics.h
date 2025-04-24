#include <iostream>
#include "liblvgl/misc/lv_color.h"
#include "main.h"
#include "api.h"
#include "liblvgl/lvgl.h"

#ifndef GRAPHICS_H
#define GRAPHICS_H

enum class Alignment {
    LEFT,
    CENTRE,
    RIGHT
};

class Graphics {
public:
    /**
     * @brief Display an image on the V5 screen using LVGL.
     * @param src Pointer to the image descriptor.
     * @param x X-coordinate of the top-left corner of the image.
     * @param y Y-coordinate of the top-left corner of the image.
     * @param parent The parent object to which the image will be added.
     * @return Pointer to the created image object.
     */
    static lv_obj_t* create_image(const lv_img_dsc_t *src, lv_coord_t x, lv_coord_t y, lv_obj_t *parent = lv_scr_act());

    /**
     * @brief Display a plaintext label on the V5 screen using LVGL. 
     * @param text The text to display in the label.
     * @param x X-coordinate of the label position.
     * @param y Y-coordinate of the label position.
     * @param font Pointer to the font to use for the label text.
     * @param parent The parent object to which the label will be added.
     * @return Pointer to the created label object.
     
     */
    static lv_obj_t* create_label(const char *text, int x, int y, const lv_font_t *font, lv_color_t color, Alignment align = Alignment::LEFT, lv_obj_t *parent = lv_scr_act());

    /**
    * @brief Display a rectangle on the V5 screen using LVGL.
    * @param width Width of the rectangle.
    * @param height Height of the rectangle.
    * @param x X-coordinate of the rectangle’s top-left corner relative to the parent object.
    * @param y Y-coordinate of the rectangle’s top-left corner relative to the parent object.
    * @param color Background color of the rectangle.
    * @param parent The parent object to which the rectangle will be added. Defaults to the active screen (`lv_scr_act()`).
    * @param corner_radius The radius of the corners of the rectangle.
    * @return Pointer to the created rectangle object.
    */
    static lv_obj_t* create_rectangle(lv_coord_t width, lv_coord_t height, lv_coord_t x, lv_coord_t y, lv_color_t color, lv_obj_t *parent = lv_scr_act(), int corner_radius = 0, lv_opa_t opacity = LV_OPA_COVER);
};

#endif
