/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --no-compress --font Roboto-Bold.ttf --symbols abcdefghijlkmnopqrstuvwxyzABCDEFGHIJLKMNOPQRSTUVWXYZ0123456789:.-_/(), --format lvgl -o roboto_bold_20px.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "liblvgl/lvgl.h"
#endif

#ifndef ROBOTO_BOLD_20PX
#define ROBOTO_BOLD_20PX 1
#endif

#if ROBOTO_BOLD_20PX

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0028 "(" */
    0xc, 0x73, 0x8c, 0x71, 0xce, 0x38, 0xe3, 0x8e,
    0x38, 0xe3, 0x86, 0x1c, 0x70, 0xe1, 0x83, 0x4,

    /* U+0029 ")" */
    0xc3, 0x87, 0xc, 0x38, 0xe1, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x71, 0x8e, 0x39, 0xc6, 0x30, 0x0,

    /* U+002C "," */
    0x77, 0x77, 0xec,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x6, 0xc, 0x30, 0x60, 0xc3, 0x6, 0xc, 0x30,
    0x60, 0xc3, 0x6, 0xc, 0x30, 0x60,

    /* U+0030 "0" */
    0x1e, 0x1f, 0xe7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0x73,
    0x9f, 0xe1, 0xe0,

    /* U+0031 "1" */
    0x6, 0x7f, 0xff, 0xf8, 0xe1, 0xc3, 0x87, 0xe,
    0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x80,

    /* U+0032 "2" */
    0x1f, 0x1f, 0xe7, 0x3f, 0x87, 0xe1, 0xc0, 0x70,
    0x38, 0x1e, 0xf, 0x7, 0x81, 0xc0, 0xf0, 0x78,
    0x3f, 0xff, 0xfc,

    /* U+0033 "3" */
    0x3f, 0x1f, 0xef, 0x3f, 0x87, 0x1, 0xc0, 0xf1,
    0xf8, 0x7e, 0x3, 0xc0, 0x70, 0x1f, 0x87, 0xf3,
    0xdf, 0xe3, 0xf0,

    /* U+0034 "4" */
    0x3, 0x80, 0xf0, 0x3e, 0x7, 0xc1, 0xf8, 0x37,
    0xe, 0xe1, 0x9c, 0x73, 0x9c, 0x73, 0xff, 0xff,
    0xf0, 0x38, 0x7, 0x0, 0xe0,

    /* U+0035 "5" */
    0x7f, 0xdf, 0xf7, 0x1, 0x80, 0x60, 0x1f, 0xcf,
    0xf9, 0x8f, 0x1, 0xc0, 0x70, 0x1f, 0x87, 0xf3,
    0x9f, 0xe1, 0xe0,

    /* U+0036 "6" */
    0xf, 0x7, 0xc3, 0x81, 0xc0, 0x60, 0x3b, 0xcf,
    0xfb, 0xcf, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0x73,
    0x9f, 0xe1, 0xe0,

    /* U+0037 "7" */
    0xff, 0xff, 0xf0, 0x1c, 0xe, 0x3, 0x80, 0xc0,
    0x70, 0x1c, 0xe, 0x3, 0x81, 0xc0, 0x70, 0x1c,
    0xe, 0x3, 0x80,

    /* U+0038 "8" */
    0x3e, 0x1f, 0xce, 0x3b, 0x8e, 0xe3, 0xb8, 0xe7,
    0xf1, 0xfc, 0x73, 0xb8, 0x7e, 0x1f, 0x87, 0xf3,
    0xdf, 0xe3, 0xf0,

    /* U+0039 "9" */
    0x1e, 0x1f, 0xc7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0xcf, 0x7f, 0xcf, 0x70, 0x18, 0xe, 0x7,
    0xf, 0xc3, 0xc0,

    /* U+003A ":" */
    0xff, 0x80, 0x0, 0xff, 0x80,

    /* U+0041 "A" */
    0x7, 0x0, 0x3c, 0x3, 0xe0, 0x1f, 0x0, 0xfc,
    0xe, 0xe0, 0x77, 0x3, 0x9c, 0x38, 0xe1, 0xc7,
    0xf, 0xfc, 0xff, 0xe7, 0x7, 0xb8, 0x1f, 0x80,
    0xe0,

    /* U+0042 "B" */
    0xff, 0x1f, 0xf3, 0x8f, 0x70, 0xee, 0x1d, 0xc3,
    0xb8, 0xf7, 0xfc, 0xff, 0xdc, 0x3f, 0x83, 0xf0,
    0x7e, 0x1f, 0xff, 0xbf, 0xe0,

    /* U+0043 "C" */
    0x1f, 0x83, 0xfc, 0x70, 0xe7, 0xe, 0xe0, 0x7e,
    0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xe0,
    0x77, 0xe, 0x70, 0xe3, 0xfc, 0x1f, 0x80,

    /* U+0044 "D" */
    0xfe, 0x1f, 0xf3, 0x8f, 0x70, 0xee, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0xee, 0x3d, 0xff, 0x3f, 0x80,

    /* U+0045 "E" */
    0xff, 0xff, 0xfe, 0x3, 0x80, 0xe0, 0x38, 0xe,
    0x3, 0xfe, 0xff, 0xb8, 0xe, 0x3, 0x80, 0xe0,
    0x3f, 0xff, 0xfc,

    /* U+0046 "F" */
    0xff, 0xff, 0xfe, 0x3, 0x80, 0xe0, 0x38, 0xe,
    0x3, 0xfe, 0xff, 0xb8, 0xe, 0x3, 0x80, 0xe0,
    0x38, 0xe, 0x0,

    /* U+0047 "G" */
    0xf, 0x83, 0xfe, 0x78, 0xe7, 0x7, 0xe0, 0x7e,
    0x0, 0xe0, 0xe, 0x3f, 0xe3, 0xfe, 0x7, 0xe0,
    0x77, 0x7, 0x78, 0x73, 0xff, 0xf, 0xc0,

    /* U+0048 "H" */
    0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7f, 0xff, 0xff, 0xfe, 0x7, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x70,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,

    /* U+004A "J" */
    0x1, 0xc0, 0x70, 0x1c, 0x7, 0x1, 0xc0, 0x70,
    0x1c, 0x7, 0x1, 0xc0, 0x70, 0x1f, 0x87, 0xf3,
    0x9f, 0xe3, 0xe0,

    /* U+004B "K" */
    0xe0, 0xee, 0x1c, 0xe3, 0xce, 0x78, 0xe7, 0xe,
    0xe0, 0xfe, 0xf, 0xe0, 0xff, 0xf, 0x70, 0xe7,
    0x8e, 0x38, 0xe1, 0xce, 0x1e, 0xe0, 0xe0,

    /* U+004C "L" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0x3, 0x81,
    0xc0, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x7, 0xff,
    0xfe,

    /* U+004D "M" */
    0xf0, 0x1f, 0xe0, 0x7f, 0xe0, 0xff, 0xc1, 0xff,
    0x83, 0xfd, 0x8d, 0xfb, 0x1b, 0xf6, 0x37, 0xee,
    0xef, 0xcd, 0x9f, 0x9b, 0x3f, 0x3e, 0x7e, 0x38,
    0xfc, 0x71, 0xf8, 0xe3, 0x80,

    /* U+004E "N" */
    0xe0, 0x7f, 0x7, 0xf8, 0x7f, 0x87, 0xfc, 0x7f,
    0xc7, 0xee, 0x7e, 0xf7, 0xe7, 0x7e, 0x3f, 0xe3,
    0xfe, 0x1f, 0xe1, 0xfe, 0xf, 0xe0, 0x70,

    /* U+004F "O" */
    0xf, 0x3, 0xfc, 0x71, 0xe7, 0xe, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x77, 0xe, 0x78, 0xe3, 0xfc, 0xf, 0x0,

    /* U+0050 "P" */
    0xff, 0x1f, 0xfb, 0x87, 0x70, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0xe, 0xff, 0xdf, 0xe3, 0x80, 0x70,
    0xe, 0x1, 0xc0, 0x38, 0x0,

    /* U+0051 "Q" */
    0xf, 0x3, 0xfc, 0x71, 0xe7, 0xe, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x77, 0xe, 0x78, 0xe3, 0xfc, 0x1f, 0xc0, 0xf,
    0x0, 0x60,

    /* U+0052 "R" */
    0xff, 0xf, 0xfc, 0xe1, 0xee, 0xe, 0xe0, 0xee,
    0xe, 0xe1, 0xef, 0xfc, 0xff, 0xe, 0x38, 0xe3,
    0x8e, 0x1c, 0xe1, 0xce, 0xe, 0xe0, 0xe0,

    /* U+0053 "S" */
    0x1f, 0xf, 0xfb, 0xc7, 0xf0, 0x7e, 0x1, 0xf0,
    0x1f, 0xc1, 0xfc, 0xf, 0xc0, 0x3f, 0x83, 0xf0,
    0x77, 0x1e, 0xff, 0x87, 0xc0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xe, 0x0, 0xe0, 0xe, 0x0,
    0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe,
    0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0,

    /* U+0055 "U" */
    0xe0, 0xfc, 0x1f, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x83, 0xf0,
    0x77, 0x1c, 0xff, 0x87, 0xc0,

    /* U+0056 "V" */
    0xe0, 0x3b, 0x83, 0xdc, 0x1c, 0xe0, 0xe3, 0x8f,
    0x1c, 0x70, 0xe3, 0x83, 0x9c, 0x1d, 0xc0, 0xee,
    0x3, 0x70, 0x1f, 0x0, 0xf8, 0x7, 0xc0, 0x1c,
    0x0,

    /* U+0057 "W" */
    0xe1, 0xc3, 0xb8, 0xe1, 0xdc, 0x78, 0xee, 0x3c,
    0x67, 0x1e, 0x73, 0x9f, 0x38, 0xcd, 0x9c, 0x76,
    0xee, 0x3b, 0x36, 0x1f, 0x9f, 0x7, 0xcf, 0x83,
    0xc7, 0xc1, 0xe1, 0xe0, 0xf0, 0xe0, 0x78, 0x70,

    /* U+0058 "X" */
    0x70, 0x73, 0x87, 0x8e, 0x38, 0x7b, 0x81, 0xdc,
    0xf, 0xc0, 0x3e, 0x1, 0xe0, 0xf, 0x80, 0xfc,
    0x7, 0x70, 0x73, 0xc3, 0x8e, 0x38, 0x7b, 0xc1,
    0xc0,

    /* U+0059 "Y" */
    0x70, 0x73, 0x83, 0x8e, 0x38, 0x71, 0xc1, 0xdc,
    0xe, 0xe0, 0x3f, 0x1, 0xf0, 0xf, 0x80, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80, 0x1c,
    0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xfc, 0x7, 0x1, 0xe0, 0x38, 0xe,
    0x3, 0xc0, 0x70, 0x1e, 0x7, 0x80, 0xe0, 0x3c,
    0x7, 0x1, 0xff, 0xff, 0xf8,

    /* U+005F "_" */
    0xff, 0xff, 0xc0,

    /* U+0061 "a" */
    0x3e, 0x3f, 0xb8, 0xe0, 0x73, 0xfb, 0xff, 0x8f,
    0xc7, 0xe3, 0xbf, 0xcf, 0xe0,

    /* U+0062 "b" */
    0xe0, 0x38, 0xe, 0x3, 0x80, 0xef, 0x3f, 0xef,
    0x3b, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xf3,
    0xbf, 0xee, 0xf0,

    /* U+0063 "c" */
    0x1e, 0x3f, 0x9c, 0xfc, 0x7e, 0x7, 0x3, 0x81,
    0xc7, 0x73, 0xbf, 0x87, 0x80,

    /* U+0064 "d" */
    0x1, 0xc0, 0x70, 0x1c, 0x7, 0x3d, 0xdf, 0xf7,
    0x3f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0x73,
    0xdf, 0xf3, 0xdc,

    /* U+0065 "e" */
    0x1f, 0x1f, 0xe7, 0x1f, 0x87, 0xff, 0xff, 0xfe,
    0x3, 0x80, 0x71, 0x9f, 0xf1, 0xf0,

    /* U+0066 "f" */
    0x1e, 0xfd, 0xc3, 0x8f, 0xff, 0xdc, 0x38, 0x70,
    0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x0,

    /* U+0067 "g" */
    0x3d, 0xdf, 0xf7, 0x1f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0x71, 0xdf, 0xf3, 0xdc, 0x7, 0x63,
    0xdf, 0xe3, 0xe0,

    /* U+0068 "h" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0xf7, 0xfb, 0x8f,
    0xc7, 0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f,
    0x8e,

    /* U+0069 "i" */
    0xff, 0x8f, 0xff, 0xff, 0xff, 0xf8,

    /* U+006A "j" */
    0x39, 0xce, 0x3, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0x3f, 0xb8,

    /* U+006B "k" */
    0xe0, 0x38, 0xe, 0x3, 0x80, 0xe3, 0xb9, 0xce,
    0xf3, 0xf8, 0xfc, 0x3f, 0xf, 0xe3, 0x9c, 0xe7,
    0x38, 0xee, 0x3c,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,

    /* U+006D "m" */
    0xef, 0x3d, 0xff, 0xfb, 0x8e, 0x3f, 0x1c, 0x7e,
    0x38, 0xfc, 0x71, 0xf8, 0xe3, 0xf1, 0xc7, 0xe3,
    0x8f, 0xc7, 0x1f, 0x8e, 0x38,

    /* U+006E "n" */
    0xef, 0x7f, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf1, 0xf8, 0xe0,

    /* U+006F "o" */
    0x1e, 0x1f, 0xe7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0x73, 0x9f, 0xe1, 0xe0,

    /* U+0070 "p" */
    0xef, 0x3f, 0xee, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe3, 0xbf, 0xee, 0xf3, 0x80, 0xe0,
    0x38, 0xe, 0x0,

    /* U+0071 "q" */
    0x3d, 0xdf, 0xf7, 0x1f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0x71, 0xdf, 0xf3, 0xdc, 0x7, 0x1,
    0xc0, 0x70, 0x1c,

    /* U+0072 "r" */
    0xff, 0xff, 0x38, 0xe3, 0x8e, 0x38, 0xe3, 0x8e,
    0x0,

    /* U+0073 "s" */
    0x3e, 0x3f, 0xb8, 0xfc, 0xf, 0x83, 0xf8, 0x3f,
    0xc7, 0xe3, 0xbf, 0x8f, 0x80,

    /* U+0074 "t" */
    0x71, 0xc7, 0x3f, 0xfd, 0xc7, 0x1c, 0x71, 0xc7,
    0x1c, 0x7c, 0xf0,

    /* U+0075 "u" */
    0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xff, 0xde, 0xe0,

    /* U+0076 "v" */
    0xe1, 0xd8, 0x67, 0x39, 0xce, 0x33, 0x8e, 0xc3,
    0xf0, 0x7c, 0x1e, 0x7, 0x80, 0xe0,

    /* U+0077 "w" */
    0xe3, 0xd, 0x8e, 0x76, 0x39, 0xdd, 0xe7, 0x77,
    0xd8, 0xdb, 0x63, 0x6f, 0x8f, 0x3e, 0x3c, 0x70,
    0x71, 0xc1, 0x87, 0x0,

    /* U+0078 "x" */
    0x71, 0xdc, 0xe3, 0xf8, 0xfc, 0x1e, 0x7, 0x81,
    0xf0, 0xfc, 0x3b, 0x9c, 0xef, 0x1c,

    /* U+0079 "y" */
    0xe1, 0xf8, 0xe7, 0x39, 0xce, 0x73, 0xf, 0xc3,
    0xf0, 0xf8, 0x1e, 0x7, 0x81, 0xc0, 0x70, 0x1c,
    0x1e, 0x7, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xc1, 0xc1, 0xe1, 0xe0, 0xe0, 0xe0,
    0xf0, 0x70, 0x7f, 0xff, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 112, .box_w = 6, .box_h = 21, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 16, .adv_w = 113, .box_w = 6, .box_h = 21, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 32, .adv_w = 78, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 35, .adv_w = 124, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 37, .adv_w = 93, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 120, .box_w = 7, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 53, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 184, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 184, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 184, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 90, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 215, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 204, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 209, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 208, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 180, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 175, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 218, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 226, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 93, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 179, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 203, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 173, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 280, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 226, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 221, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 559, .adv_w = 206, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 580, .adv_w = 221, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 606, .adv_w = 204, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 629, .adv_w = 197, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 198, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 211, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 209, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 280, .box_w = 17, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 751, .adv_w = 203, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 776, .adv_w = 198, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 194, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 143, .box_w = 9, .box_h = 2, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 825, .adv_w = 172, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 838, .adv_w = 180, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 167, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 870, .adv_w = 180, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 173, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 903, .adv_w = 115, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 917, .adv_w = 183, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 936, .adv_w = 179, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 953, .adv_w = 85, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 959, .adv_w = 83, .box_w = 5, .box_h = 19, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 971, .adv_w = 171, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 990, .adv_w = 85, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 996, .adv_w = 277, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1017, .adv_w = 179, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 181, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1044, .adv_w = 180, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1063, .adv_w = 181, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1082, .adv_w = 117, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1091, .adv_w = 165, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1104, .adv_w = 108, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1115, .adv_w = 179, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1128, .adv_w = 162, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1142, .adv_w = 235, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1162, .adv_w = 163, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1176, .adv_w = 161, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1195, .adv_w = 163, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 40, .range_length = 2, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 44, .range_length = 15, .glyph_id_start = 3,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 18,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 1, .glyph_id_start = 44,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 45,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    1, 39,
    1, 40,
    1, 42,
    6, 6,
    18, 20,
    18, 24,
    18, 32,
    18, 34,
    18, 37,
    18, 38,
    18, 39,
    18, 40,
    18, 42,
    18, 57,
    18, 58,
    18, 59,
    18, 60,
    18, 64,
    18, 65,
    18, 66,
    18, 67,
    18, 69,
    18, 70,
    19, 37,
    19, 39,
    19, 42,
    20, 2,
    20, 37,
    21, 3,
    21, 5,
    21, 18,
    21, 37,
    21, 39,
    21, 41,
    21, 42,
    21, 43,
    22, 37,
    22, 47,
    22, 48,
    22, 49,
    22, 50,
    22, 51,
    22, 59,
    22, 61,
    22, 65,
    22, 66,
    22, 67,
    22, 69,
    23, 3,
    23, 5,
    23, 18,
    23, 27,
    23, 37,
    23, 45,
    23, 47,
    23, 48,
    23, 49,
    23, 51,
    23, 59,
    23, 61,
    23, 62,
    23, 65,
    23, 66,
    23, 69,
    25, 18,
    25, 37,
    25, 41,
    25, 42,
    26, 18,
    26, 37,
    26, 41,
    26, 42,
    27, 18,
    28, 4,
    28, 20,
    28, 24,
    28, 32,
    28, 34,
    28, 47,
    28, 48,
    28, 49,
    28, 51,
    28, 59,
    28, 61,
    28, 65,
    28, 66,
    28, 67,
    28, 69,
    29, 18,
    29, 20,
    29, 24,
    29, 32,
    29, 34,
    29, 37,
    29, 38,
    29, 39,
    29, 40,
    29, 42,
    29, 65,
    29, 66,
    29, 67,
    29, 69,
    30, 18,
    30, 37,
    30, 41,
    30, 42,
    31, 18,
    31, 37,
    31, 41,
    31, 42,
    32, 3,
    32, 5,
    32, 18,
    32, 37,
    32, 39,
    32, 41,
    32, 42,
    32, 43,
    33, 3,
    33, 5,
    33, 18,
    33, 27,
    33, 41,
    33, 43,
    33, 45,
    33, 47,
    33, 48,
    33, 49,
    33, 51,
    33, 59,
    33, 61,
    33, 64,
    33, 66,
    33, 69,
    34, 37,
    34, 39,
    34, 40,
    34, 42,
    35, 37,
    35, 39,
    35, 42,
    37, 3,
    37, 4,
    37, 5,
    37, 18,
    37, 20,
    37, 24,
    37, 27,
    37, 32,
    37, 34,
    37, 36,
    37, 37,
    37, 39,
    37, 40,
    37, 42,
    37, 45,
    37, 47,
    37, 48,
    37, 49,
    37, 51,
    37, 57,
    37, 58,
    37, 59,
    37, 60,
    37, 61,
    37, 62,
    37, 63,
    37, 65,
    37, 66,
    37, 67,
    37, 68,
    37, 69,
    37, 70,
    38, 18,
    39, 2,
    39, 3,
    39, 4,
    39, 5,
    39, 18,
    39, 20,
    39, 24,
    39, 32,
    39, 34,
    39, 45,
    39, 47,
    39, 48,
    39, 49,
    39, 51,
    39, 59,
    39, 61,
    39, 62,
    39, 65,
    39, 66,
    39, 69,
    40, 2,
    40, 3,
    40, 4,
    40, 5,
    40, 18,
    40, 37,
    40, 45,
    40, 47,
    40, 48,
    40, 49,
    40, 51,
    40, 59,
    40, 61,
    40, 62,
    40, 65,
    41, 4,
    41, 20,
    41, 24,
    41, 32,
    41, 34,
    41, 39,
    41, 47,
    41, 48,
    41, 49,
    41, 51,
    41, 59,
    41, 61,
    41, 65,
    41, 66,
    41, 69,
    42, 2,
    42, 3,
    42, 4,
    42, 5,
    42, 18,
    42, 20,
    42, 24,
    42, 27,
    42, 32,
    42, 34,
    42, 36,
    42, 37,
    42, 38,
    42, 39,
    42, 40,
    42, 41,
    42, 42,
    42, 45,
    42, 47,
    42, 48,
    42, 49,
    42, 50,
    42, 51,
    42, 57,
    42, 58,
    42, 59,
    42, 60,
    42, 61,
    42, 62,
    42, 63,
    42, 64,
    42, 65,
    42, 66,
    42, 68,
    42, 69,
    42, 70,
    43, 18,
    43, 20,
    43, 24,
    43, 32,
    43, 34,
    43, 47,
    43, 48,
    43, 49,
    43, 51,
    43, 59,
    43, 61,
    43, 65,
    43, 66,
    43, 67,
    43, 69,
    45, 66,
    45, 69,
    46, 66,
    46, 68,
    46, 69,
    46, 70,
    49, 66,
    49, 69,
    50, 2,
    50, 47,
    50, 48,
    50, 49,
    50, 51,
    50, 61,
    55, 47,
    55, 48,
    55, 49,
    55, 51,
    55, 61,
    59, 66,
    59, 68,
    59, 69,
    59, 70,
    60, 66,
    60, 68,
    60, 69,
    60, 70,
    62, 3,
    62, 5,
    62, 45,
    62, 47,
    62, 48,
    62, 49,
    62, 50,
    62, 51,
    62, 59,
    62, 61,
    62, 64,
    62, 66,
    62, 67,
    62, 69,
    64, 59,
    66, 3,
    66, 5,
    66, 45,
    66, 47,
    66, 48,
    66, 49,
    66, 50,
    66, 51,
    66, 59,
    66, 61,
    67, 3,
    67, 5,
    68, 47,
    68, 48,
    68, 49,
    68, 51,
    68, 59,
    68, 61,
    69, 3,
    69, 5,
    69, 45,
    69, 47,
    69, 48,
    69, 49,
    69, 50,
    69, 51,
    69, 59,
    69, 61,
    70, 47,
    70, 48,
    70, 49,
    70, 51,
    70, 59,
    70, 61
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    3, 6, 3, -39, -3, -3, -3, -3,
    -19, -3, -12, -6, -23, -7, -7, -2,
    -7, -3, -2, -8, -5, -8, 2, -4,
    -4, -9, -4, -5, -19, -19, -3, -13,
    -3, -3, -7, -4, 3, -3, -3, -3,
    -3, -3, -3, -3, -3, -4, -3, -4,
    -43, -43, -30, -32, 3, -5, -3, -3,
    -3, -3, -3, -3, -4, -3, -4, -4,
    3, -5, 3, -4, 3, -5, 3, -4,
    -3, -26, -5, -5, -5, -5, -4, -4,
    -4, -4, -4, -4, -4, -6, -10, -6,
    3, -10, -10, -10, -10, -32, -4, -32,
    -15, -44, -2, -19, -8, -19, 3, -5,
    3, -4, 3, -5, 3, -4, -19, -19,
    -3, -13, -3, -3, -7, -4, -63, -63,
    -28, -29, -8, -6, -2, -2, -2, -2,
    -2, -2, -2, 2, 2, 2, -5, -4,
    -3, -5, -8, -3, -7, -40, -42, -40,
    -19, -4, -4, -34, -4, -4, -2, 3,
    3, 2, 3, -26, -14, -14, -14, -14,
    -14, -14, -32, -14, -14, -10, -12, -10,
    -13, -7, -12, -13, -9, -3, 3, -34,
    -25, -34, -12, -2, -2, -2, -2, -7,
    -7, -7, -7, -7, -7, -7, -5, -4,
    -2, -2, 2, -22, -9, -22, -7, 2,
    -5, -5, -5, -5, -5, -5, -5, -3,
    -3, -24, -4, -4, -4, -4, 2, -4,
    -4, -4, -4, -3, -4, -3, -5, -5,
    3, -36, -24, -36, -23, -5, -5, -15,
    -5, -5, -2, 3, -15, 3, 3, 2,
    3, -10, -10, -10, -10, -3, -10, -6,
    -6, -10, -6, -10, -6, -9, -3, -6,
    -3, -4, -3, -5, 2, -4, -4, -4,
    -4, -3, -3, -3, -3, -3, -3, -3,
    -4, -4, -4, -2, -2, -2, -2, -2,
    -2, -2, -2, 3, -4, -4, -4, -4,
    -4, -3, -3, -3, -3, -3, -2, -3,
    -2, -2, -2, -2, -2, -2, -27, -27,
    -5, -3, -3, -3, 3, -3, -6, -3,
    8, 3, 3, 3, -5, -26, -26, -2,
    -2, -2, -2, 2, -2, -2, -2, -19,
    -19, -3, -3, -3, -3, -6, -3, -26,
    -26, -2, -2, -2, -2, 2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 351,
    .glyph_ids_size = 0
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
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 5,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_18;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t roboto_bold_20px = {
#else
lv_font_t roboto_bold_20px = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_18,
#endif
    .user_data = NULL,
};



#endif /*#if ROBOTO_BOLD_20PX*/

