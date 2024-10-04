/*******************************************************************************
 * Size: 10 px
 * Bpp: 2
 * Opts: --bpp 2 --size 10 --no-compress --font Roboto-Medium.ttf --symbols ACDBEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_0123456789 --format lvgl -o roboto_medium_10px.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "liblvgl/lvgl.h"
#endif

#ifndef ROBOTO_MEDIUM_10PX
#define ROBOTO_MEDIUM_10PX 1
#endif

#if ROBOTO_MEDIUM_10PX

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0xbc, 0x0,

    /* U+0030 "0" */
    0x2f, 0x3, 0x1c, 0x60, 0xc6, 0xc, 0x60, 0xc6,
    0xc, 0x31, 0xc1, 0xf4,

    /* U+0031 "1" */
    0xa, 0x3f, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,

    /* U+0032 "2" */
    0x2f, 0x47, 0x1c, 0x50, 0xc0, 0x28, 0x7, 0x0,
    0xc0, 0x34, 0x7, 0xfd,

    /* U+0033 "3" */
    0x2f, 0x47, 0x1c, 0x1, 0xc0, 0xf4, 0x2, 0xc0,
    0xc, 0x71, 0xc2, 0xf4,

    /* U+0034 "4" */
    0x3, 0x80, 0xb8, 0xe, 0x82, 0x68, 0x72, 0x8b,
    0xfd, 0x2, 0x80, 0x28,

    /* U+0035 "5" */
    0x3f, 0xc3, 0x40, 0x30, 0x3, 0xf4, 0x11, 0xc0,
    0xc, 0x31, 0xc1, 0xf4,

    /* U+0036 "6" */
    0xb, 0x2, 0xc0, 0x30, 0x7, 0xb4, 0x75, 0xc7,
    0xc, 0x31, 0xc1, 0xf4,

    /* U+0037 "7" */
    0xbf, 0xd0, 0xc, 0x2, 0x80, 0x30, 0x7, 0x0,
    0xd0, 0xc, 0x2, 0x80,

    /* U+0038 "8" */
    0x2f, 0x43, 0x1c, 0x31, 0xc2, 0xf4, 0x31, 0xc6,
    0xc, 0x71, 0xc2, 0xf4,

    /* U+0039 "9" */
    0x2f, 0x7, 0x28, 0xa0, 0xc7, 0x1c, 0x3f, 0xc0,
    0x1c, 0x7, 0x42, 0xd0,

    /* U+0041 "A" */
    0x7, 0x0, 0x2d, 0x0, 0xe8, 0x7, 0x30, 0x24,
    0xd0, 0xff, 0x87, 0x7, 0x28, 0xd,

    /* U+0042 "B" */
    0x7f, 0x87, 0xe, 0x70, 0xe7, 0xfc, 0x70, 0xe7,
    0x7, 0x70, 0xe7, 0xf8,

    /* U+0043 "C" */
    0xf, 0xc0, 0xe2, 0xc7, 0x2, 0x1c, 0x0, 0x70,
    0x1, 0xc0, 0x83, 0x4b, 0x3, 0xf0,

    /* U+0044 "D" */
    0x7f, 0x41, 0xc7, 0x47, 0x7, 0x1c, 0x1c, 0x70,
    0x71, 0xc1, 0xc7, 0x1d, 0x1f, 0xd0,

    /* U+0045 "E" */
    0x7f, 0xd7, 0x0, 0x70, 0x7, 0xfc, 0x70, 0x7,
    0x0, 0x70, 0x7, 0xfd,

    /* U+0046 "F" */
    0x7f, 0xc7, 0x0, 0x70, 0x7, 0xfc, 0x70, 0x7,
    0x0, 0x70, 0x7, 0x0,

    /* U+0047 "G" */
    0xf, 0xc0, 0xe2, 0xc7, 0x2, 0x1c, 0x0, 0x71,
    0xf1, 0xc0, 0xc3, 0x87, 0x3, 0xf4,

    /* U+0048 "H" */
    0x70, 0x35, 0xc0, 0xd7, 0x3, 0x5f, 0xfd, 0x70,
    0x35, 0xc0, 0xd7, 0x3, 0x5c, 0xd,

    /* U+0049 "I" */
    0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,

    /* U+004A "J" */
    0x1, 0xc0, 0x70, 0x1c, 0x7, 0x1, 0xd0, 0x7a,
    0x28, 0xfc,

    /* U+004B "K" */
    0x70, 0xb1, 0xc7, 0x7, 0x34, 0x1f, 0xc0, 0x7f,
    0x1, 0xcb, 0x7, 0xd, 0x1c, 0x1c,

    /* U+004C "L" */
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7,
    0x0, 0x70, 0x7, 0xfc,

    /* U+004D "M" */
    0x74, 0xb, 0x1f, 0x3, 0xc7, 0xc1, 0xf1, 0xe4,
    0xdc, 0x77, 0x33, 0x1c, 0xe8, 0xc7, 0x2d, 0x31,
    0xc7, 0xc,

    /* U+004E "N" */
    0x70, 0x35, 0xf0, 0xd7, 0xd3, 0x5d, 0xcd, 0x73,
    0x75, 0xc7, 0xd7, 0xb, 0x5c, 0xd,

    /* U+004F "O" */
    0xf, 0xc0, 0xe2, 0xc7, 0x3, 0x1c, 0xd, 0x70,
    0x35, 0xc0, 0xc3, 0x8b, 0x3, 0xf0,

    /* U+0050 "P" */
    0x7f, 0xc1, 0xc2, 0xc7, 0x3, 0x1c, 0x2c, 0x7f,
    0xd1, 0xc0, 0x7, 0x0, 0x1c, 0x0,

    /* U+0051 "Q" */
    0xf, 0x80, 0xe2, 0xc7, 0x3, 0x28, 0xd, 0xa0,
    0x35, 0xc0, 0xc3, 0x8b, 0x3, 0xf4, 0x0, 0x70,
    0x0, 0x0,

    /* U+0052 "R" */
    0x7f, 0x81, 0xc3, 0x87, 0x7, 0x1c, 0x28, 0x7f,
    0xc1, 0xcb, 0x7, 0xd, 0x1c, 0x1c,

    /* U+0053 "S" */
    0x1f, 0x87, 0x4d, 0x70, 0x13, 0xe0, 0x7, 0xc5,
    0xa, 0x70, 0xe2, 0xf8,

    /* U+0054 "T" */
    0xff, 0xf0, 0xa0, 0xa, 0x0, 0xa0, 0xa, 0x0,
    0xa0, 0xa, 0x0, 0xa0,

    /* U+0055 "U" */
    0x70, 0x77, 0x7, 0x70, 0x77, 0x7, 0x70, 0x77,
    0x7, 0x34, 0xa1, 0xf8,

    /* U+0056 "V" */
    0xe0, 0x31, 0xc1, 0xc3, 0xa, 0xd, 0x34, 0x19,
    0xc0, 0x3a, 0x0, 0xf4, 0x2, 0xc0,

    /* U+0057 "W" */
    0xa0, 0xc2, 0x98, 0x74, 0xd7, 0x2e, 0x30, 0xcd,
    0x9c, 0x37, 0x36, 0xb, 0x8f, 0x41, 0xd2, 0xd0,
    0x30, 0x70,

    /* U+0058 "X" */
    0x70, 0xb0, 0xd3, 0x41, 0xe8, 0x3, 0xc0, 0xf,
    0x0, 0x7b, 0x3, 0x4d, 0x2c, 0x2c,

    /* U+0059 "Y" */
    0xa0, 0xb1, 0xc3, 0x43, 0x5c, 0x7, 0xd0, 0xf,
    0x0, 0x28, 0x0, 0xa0, 0x2, 0x80,

    /* U+005A "Z" */
    0xbf, 0xe0, 0x1c, 0x3, 0x80, 0x70, 0xd, 0x2,
    0x80, 0x34, 0xb, 0xfe,

    /* U+005F "_" */
    0xff, 0x40, 0x0,

    /* U+0061 "a" */
    0x2f, 0x8, 0xa2, 0xfd, 0xc7, 0x72, 0xcf, 0xb0,

    /* U+0062 "b" */
    0x70, 0x7, 0x0, 0x7f, 0x47, 0x1c, 0x70, 0xc7,
    0xc, 0x71, 0xc7, 0xf4,

    /* U+0063 "c" */
    0x2f, 0x1c, 0x7a, 0x2, 0x80, 0x71, 0xcb, 0xc0,

    /* U+0064 "d" */
    0x0, 0xc0, 0xc, 0x2e, 0xc7, 0x1c, 0xa0, 0xca,
    0xc, 0x71, 0xc2, 0xec,

    /* U+0065 "e" */
    0x2f, 0x47, 0x1c, 0xbf, 0xca, 0x0, 0x74, 0x81,
    0xf4,

    /* U+0066 "f" */
    0x1e, 0x34, 0xfd, 0x30, 0x30, 0x30, 0x30, 0x30,

    /* U+0067 "g" */
    0x2e, 0xc7, 0x1c, 0xa0, 0xca, 0xc, 0x71, 0xc2,
    0xec, 0x11, 0xc2, 0xf0,

    /* U+0068 "h" */
    0x70, 0x1c, 0x7, 0xf5, 0xc7, 0x70, 0xdc, 0x37,
    0xd, 0xc3,

    /* U+0069 "i" */
    0x71, 0x77, 0x77, 0x77,

    /* U+006A "j" */
    0x18, 0x1, 0xc7, 0x1c, 0x71, 0xc7, 0x2d, 0xd0,

    /* U+006B "k" */
    0x70, 0x7, 0x0, 0x73, 0x87, 0xb0, 0x7d, 0x7,
    0xe0, 0x73, 0x47, 0x1c,

    /* U+006C "l" */
    0x77, 0x77, 0x77, 0x77,

    /* U+006D "m" */
    0x7f, 0x6e, 0x1c, 0x75, 0xc7, 0x1c, 0x31, 0xc7,
    0xc, 0x71, 0xc3, 0x1c, 0x70, 0xc0,

    /* U+006E "n" */
    0x7f, 0x5c, 0x77, 0xd, 0xc3, 0x70, 0xdc, 0x30,

    /* U+006F "o" */
    0x2f, 0x47, 0x1c, 0xa0, 0xca, 0xd, 0x71, 0xc2,
    0xf4,

    /* U+0070 "p" */
    0x7f, 0x47, 0x1c, 0x70, 0xc7, 0xc, 0x71, 0xc7,
    0xf4, 0x70, 0x7, 0x0,

    /* U+0071 "q" */
    0x2e, 0xc7, 0x1c, 0xa0, 0xca, 0xc, 0x71, 0xc2,
    0xec, 0x0, 0xc0, 0xc,

    /* U+0072 "r" */
    0x0, 0x7d, 0x74, 0x70, 0x70, 0x70, 0x70,

    /* U+0073 "s" */
    0x2f, 0x1c, 0xa3, 0x90, 0x1d, 0xa2, 0x8b, 0xc0,

    /* U+0074 "t" */
    0x20, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x34, 0x2c,

    /* U+0075 "u" */
    0x70, 0xdc, 0x37, 0xd, 0xc3, 0x72, 0xcf, 0xb0,

    /* U+0076 "v" */
    0x92, 0x98, 0xd3, 0x30, 0xe8, 0x2d, 0x3, 0x0,

    /* U+0077 "w" */
    0x93, 0x4c, 0x63, 0x8c, 0x36, 0xd8, 0x39, 0xe4,
    0x3c, 0xb0, 0x28, 0x70,

    /* U+0078 "x" */
    0xb2, 0x8e, 0xc1, 0xd0, 0x78, 0x37, 0x28, 0xa0,

    /* U+0079 "y" */
    0xd2, 0x9c, 0xd3, 0x30, 0xe8, 0x1d, 0x3, 0x2,
    0x81, 0xc0,

    /* U+007A "z" */
    0xbf, 0x81, 0xc0, 0xd0, 0xb0, 0x30, 0x2f, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 53, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 2, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 91, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 106, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 101, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 104, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 105, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 88, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 109, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 114, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 45, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 89, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 101, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 140, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 114, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 110, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 102, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 110, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 344, .adv_w = 100, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 97, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 97, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 104, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 104, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 408, .adv_w = 141, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 101, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 98, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 72, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 469, .adv_w = 87, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 84, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 86, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 57, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 538, .adv_w = 89, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 41, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 40, .box_w = 3, .box_h = 10, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 560, .adv_w = 84, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 41, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 139, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 89, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 91, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 607, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 619, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 631, .adv_w = 56, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 83, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 646, .adv_w = 53, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 89, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 662, .adv_w = 79, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 670, .adv_w = 119, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 682, .adv_w = 80, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 690, .adv_w = 78, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 700, .adv_w = 80, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 0, 0, 1, 2, 3, 4, 5,
    6, 7, 8, 9, 10
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 45, .range_length = 13, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 13, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 12,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 1, .glyph_id_start = 38,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 39,
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
    0, 0, 0, 0, 1, 2, 3, 4,
    5, 6, 0, 7, 7, 8, 9, 10,
    7, 7, 4, 11, 12, 13, 0, 14,
    8, 15, 16, 17, 18, 19, 0, 20,
    21, 0, 0, 22, 23, 0, 0, 0,
    0, 24, 0, 0, 0, 25, 21, 0,
    26, 0, 27, 0, 28, 0, 29, 28,
    30
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 3, 0,
    0, 0, 3, 0, 0, 4, 0, 0,
    0, 0, 3, 0, 3, 0, 5, 6,
    7, 8, 9, 10, 11, 12, 0, 13,
    0, 14, 14, 14, 15, 14, 0, 0,
    0, 0, 0, 16, 16, 17, 16, 14,
    18, 19, 20, 21, 22, 23, 24, 22,
    25
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, -2, 0, 0, -9, -1, -6,
    -3, 0, -12, 0, 0, 0, 0, -4,
    -1, 0, 0, -1, -1, -4, -3, 0,
    1, 0, 0, 0, 0, 0, -2, 0,
    -2, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    -7, 0, -2, 0, -2, -3, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, -1, -1, 0, -1, 0, 0, 0,
    -1, -2, -2, 0, 0, 0, -15, 0,
    -16, 0, 2, 0, 0, 0, 0, 0,
    0, -3, -2, 0, 0, -2, -2, 0,
    0, -2, -2, 0, 0, 0, 0, 1,
    0, 0, 0, -2, 0, 0, 0, 1,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -13, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    -2, 0, 0, 0, -2, -3, -5, 0,
    0, 0, 1, -5, 0, 0, -16, -2,
    -16, -7, 0, -22, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, -10, -4,
    0, 0, 0, -14, 0, -14, 0, 0,
    0, 0, 0, -4, 0, -3, -1, -1,
    0, 0, -1, 0, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, -2, -2, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, -1, 0, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -21, -9, -2,
    -17, -1, 1, 0, 1, 1, 0, 1,
    0, -13, -7, 0, -7, -16, -5, -6,
    0, -5, -6, -4, -6, -5, -12, -6,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -3, 0, 0, -4, -2,
    0, 0, -2, -1, 0, 0, 0, -5,
    -3, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, -3, -2, 0, 0, -2,
    -2, 0, 0, -1, 0, 0, 0, 0,
    -12, 0, -2, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, -2, 0, 0,
    -2, 0, 0, 0, -2, -2, 0, 0,
    0, -12, -12, -2, -7, -1, 1, -7,
    1, 1, 1, 1, 0, -5, -5, -2,
    -3, -5, -3, -5, -2, -3, -2, 0,
    -2, -2, 0, 1, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, -2, 0, 0, 0, -1, -2,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -1, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, -2,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -1, 2,
    0, -3, 0, 0, 4, 0, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    -1, 1, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, -3, 0, 0, 0,
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
    .left_class_cnt      = 30,
    .right_class_cnt     = 25,
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
const lv_font_t roboto_medium_10px = {
#else
lv_font_t roboto_medium_10px = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if ROBOTO_MEDIUM_10PX*/

