/*******************************************************************************
 * Size: 8 px
 * Bpp: 2
 * Opts: --bpp 2 --size 8 --no-compress --font Roboto-Regular.ttf --symbols ACDBEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_0123456789.: --format lvgl -o roboto_regular_8px.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "liblvgl/lvgl.h"
#endif

#ifndef ROBOTO_REGULAR_8PX
#define ROBOTO_REGULAR_8PX 1
#endif

#if ROBOTO_REGULAR_8PX

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0x60,

    /* U+002E "." */
    0x50,

    /* U+0030 "0" */
    0x29, 0x10, 0x88, 0x21, 0x48, 0x29, 0x0,

    /* U+0031 "1" */
    0x28, 0x20, 0x82, 0x8,

    /* U+0032 "2" */
    0x2a, 0x10, 0x80, 0x50, 0x50, 0x7a, 0x0,

    /* U+0033 "3" */
    0x29, 0x2, 0x1d, 0x2, 0x29,

    /* U+0034 "4" */
    0xa, 0x6, 0x82, 0x22, 0xac, 0x2, 0x0,

    /* U+0035 "5" */
    0x3a, 0xe, 0x40, 0x20, 0x8, 0x2a, 0x0,

    /* U+0036 "6" */
    0x18, 0xa, 0x45, 0x21, 0x48, 0x29, 0x0,

    /* U+0037 "7" */
    0x6b, 0x0, 0x80, 0x80, 0x20, 0x20, 0x0,

    /* U+0038 "8" */
    0x29, 0x14, 0x83, 0x91, 0x8, 0x2a, 0x0,

    /* U+0039 "9" */
    0x29, 0x82, 0x2b, 0x2, 0x18,

    /* U+003A ":" */
    0x40, 0x4,

    /* U+0041 "A" */
    0xc, 0x1, 0x60, 0x22, 0x3, 0xa4, 0x80, 0x80,

    /* U+0042 "B" */
    0x6a, 0x14, 0x56, 0xb1, 0x45, 0x6a, 0x0,

    /* U+0043 "C" */
    0x2a, 0x54, 0x18, 0x1, 0x41, 0x2a, 0x0,

    /* U+0044 "D" */
    0x6a, 0x14, 0x25, 0xd, 0x42, 0x6a, 0x0,

    /* U+0045 "E" */
    0x6a, 0x14, 0x6, 0x91, 0x40, 0x6a, 0x0,

    /* U+0046 "F" */
    0x6a, 0x14, 0x6, 0x91, 0x40, 0x50, 0x0,

    /* U+0047 "G" */
    0x2a, 0x54, 0x18, 0x29, 0x43, 0x2a, 0x40,

    /* U+0048 "H" */
    0x50, 0x85, 0x8, 0x6a, 0xc5, 0x8, 0x50, 0x80,

    /* U+0049 "I" */
    0x55, 0x55, 0x50,

    /* U+004A "J" */
    0x3, 0x3, 0x3, 0x42, 0x69,

    /* U+004B "K" */
    0x52, 0x45, 0x90, 0x7c, 0x5, 0x20, 0x51, 0x80,

    /* U+004C "L" */
    0x50, 0x14, 0x5, 0x1, 0x40, 0x6a, 0x0,

    /* U+004D "M" */
    0x70, 0x35, 0xd1, 0xd5, 0x89, 0x55, 0x55, 0x53,
    0x14,

    /* U+004E "N" */
    0x70, 0x86, 0x88, 0x59, 0x85, 0x2c, 0x50, 0xc0,

    /* U+004F "O" */
    0x2a, 0x5, 0xc, 0x80, 0x85, 0xc, 0x2a, 0x0,

    /* U+0050 "P" */
    0x6a, 0x54, 0x26, 0xa1, 0x40, 0x50, 0x0,

    /* U+0051 "Q" */
    0x2a, 0x5, 0xc, 0x80, 0xc5, 0xc, 0x2b, 0x40,
    0x8,

    /* U+0052 "R" */
    0x6a, 0x14, 0x56, 0xa1, 0x48, 0x51, 0x40,

    /* U+0053 "S" */
    0x2a, 0x14, 0x1, 0x91, 0x5, 0x2a, 0x0,

    /* U+0054 "T" */
    0x6e, 0x43, 0x0, 0xc0, 0x30, 0xc, 0x0,

    /* U+0055 "U" */
    0x50, 0x94, 0x25, 0x9, 0x42, 0x2a, 0x0,

    /* U+0056 "V" */
    0x80, 0x94, 0x52, 0x20, 0x58, 0xc, 0x0,

    /* U+0057 "W" */
    0x83, 0x9, 0x49, 0x22, 0x89, 0xa, 0x28, 0x24,
    0x60,

    /* U+0058 "X" */
    0x51, 0x49, 0x80, 0xc0, 0x98, 0x51, 0x40,

    /* U+0059 "Y" */
    0x81, 0x48, 0x81, 0x80, 0x30, 0xc, 0x0,

    /* U+005A "Z" */
    0x6b, 0x41, 0x80, 0x80, 0x80, 0xaa, 0x40,

    /* U+005F "_" */
    0xa9,

    /* U+0061 "a" */
    0x29, 0x26, 0x82, 0x6a,

    /* U+0062 "b" */
    0x50, 0x1a, 0x85, 0x21, 0x48, 0x6a, 0x0,

    /* U+0063 "c" */
    0x29, 0x81, 0x80, 0x29,

    /* U+0064 "d" */
    0x2, 0x2b, 0x82, 0x82, 0x2b,

    /* U+0065 "e" */
    0x29, 0xaa, 0x90, 0x29,

    /* U+0066 "f" */
    0x24, 0x87, 0x48, 0x20, 0x80,

    /* U+0067 "g" */
    0x2b, 0x82, 0x82, 0x2b, 0x29,

    /* U+0068 "h" */
    0x50, 0x6a, 0x52, 0x52, 0x52,

    /* U+0069 "i" */
    0x45, 0x55, 0x50,

    /* U+006A "j" */
    0x10, 0x51, 0x45, 0x14, 0x80,

    /* U+006B "k" */
    0x50, 0x16, 0x46, 0x41, 0xa0, 0x52, 0x0,

    /* U+006C "l" */
    0x55, 0x55, 0x50,

    /* U+006D "m" */
    0x6a, 0xa1, 0x4c, 0x55, 0x21, 0x54, 0x85,

    /* U+006E "n" */
    0x6a, 0x52, 0x52, 0x52,

    /* U+006F "o" */
    0x2a, 0x20, 0x88, 0x20, 0xa4,

    /* U+0070 "p" */
    0x6a, 0x14, 0x85, 0x21, 0xa8, 0x50, 0x0,

    /* U+0071 "q" */
    0x2b, 0x82, 0x82, 0x2b, 0x2,

    /* U+0072 "r" */
    0x1, 0x95, 0x14, 0x50,

    /* U+0073 "s" */
    0x29, 0x60, 0x6, 0x29,

    /* U+0074 "t" */
    0x22, 0xc2, 0x8, 0x30,

    /* U+0075 "u" */
    0x52, 0x52, 0x52, 0x2b,

    /* U+0076 "v" */
    0x82, 0x58, 0x28, 0x24,

    /* U+0077 "w" */
    0x85, 0x25, 0xa5, 0x25, 0x83, 0x8,

    /* U+0078 "x" */
    0x55, 0x28, 0x28, 0x55,

    /* U+0079 "y" */
    0x81, 0x58, 0x28, 0x20, 0x60,

    /* U+007A "z" */
    0x6d, 0x8, 0x20, 0xa9
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 35, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1, .adv_w = 34, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 72, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 72, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 72, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 31, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 84, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 83, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 84, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 73, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 71, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 87, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 91, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 35, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 71, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 80, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 69, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 112, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 91, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 88, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 81, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 88, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 189, .adv_w = 79, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 76, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 76, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 83, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 81, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 114, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 58, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 255, .adv_w = 70, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 67, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 72, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 68, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 44, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 72, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 289, .adv_w = 71, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 31, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 31, .box_w = 3, .box_h = 6, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 302, .adv_w = 65, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 31, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 112, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 71, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 73, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 72, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 335, .adv_w = 73, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 340, .adv_w = 43, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 66, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 42, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 71, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 62, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 63, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 61, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 375, .adv_w = 63, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 0, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 45, .range_length = 14, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 14, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 14,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 1, .glyph_id_start = 40,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 41,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 2,
    3, 4, 5, 6, 0, 7, 7, 8,
    9, 10, 7, 7, 4, 11, 12, 13,
    0, 14, 8, 15, 16, 17, 18, 19,
    0, 20, 21, 0, 0, 22, 23, 0,
    0, 0, 0, 24, 0, 0, 0, 25,
    21, 0, 26, 0, 27, 0, 28, 29,
    30, 28, 31
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 3, 0,
    4, 0, 0, 0, 4, 0, 0, 5,
    0, 0, 0, 0, 4, 0, 4, 0,
    6, 7, 8, 9, 10, 11, 12, 13,
    0, 14, 0, 15, 15, 15, 16, 15,
    0, 0, 0, 0, 0, 17, 17, 18,
    17, 15, 19, 20, 21, 22, 23, 24,
    25, 23, 26
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, -1, 0, 0, -8, -1,
    -5, -4, 0, -6, 0, 0, 0, 0,
    0, -1, 0, 0, -1, -1, -3, -2,
    0, 1, 0, 0, 0, 0, 0, 0,
    -2, 0, -1, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    -1, 0, 0, 0, -2, 0, -1, 0,
    -1, -3, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, -1, -1,
    0, -1, 0, 0, 0, -1, -2, -1,
    0, 0, 0, -15, -11, 0, -16, 0,
    1, 0, 0, 0, 0, 0, 0, -2,
    -1, 0, 0, -1, -2, 0, 0, -1,
    -1, 0, 0, 0, 0, 0, 1, 0,
    0, 0, -2, 0, 0, 0, 1, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    -1, -2, 0, 0, 0, -1, -2, -4,
    0, 0, 0, 0, 1, -4, 0, 0,
    -17, -3, -11, -9, 0, -15, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -8, -6, 0, 0, 0, -20, -9, 0,
    -12, 0, 0, 0, 0, 0, -2, 0,
    -2, -1, -1, 0, 0, -1, 0, 0,
    1, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, -2, -1,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, 0,
    -1, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -14, -14, -5, -2, -15, -1,
    1, 0, 1, 1, 0, 1, 0, -7,
    -6, 0, -7, -6, -5, -7, 0, -6,
    -4, -4, -5, -4, -2, -14, -5, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, -3, 0, 0, -3, -2, 0,
    0, -2, -1, 0, 0, 0, -4, -8,
    -3, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, -2, -2, 0, 0, -2,
    -1, 0, 0, -1, 0, 0, 0, 0,
    -3, 0, 0, -2, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, -2, 0,
    0, -1, 0, 0, 0, -1, -2, 0,
    0, 0, -3, -13, -6, -2, -6, -1,
    1, -6, 1, 1, 1, 1, 0, -5,
    -4, -1, -2, -4, -2, -4, -1, -2,
    -1, 0, -1, -2, 0, 0, 1, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, -1, 0, 0,
    0, -1, -2, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -1, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -1, -1, 0, -8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -1, 1, 0, -1, 0, 0, 3, 0,
    1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -7,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, -1, 1, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 31,
    .right_class_cnt     = 26,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 4,
    .bpp = 2,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_24;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t roboto_regular_8px = {
#else
lv_font_t roboto_regular_8px = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 7,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_24,
#endif
    .user_data = NULL,
};



#endif /*#if ROBOTO_REGULAR_8PX*/

