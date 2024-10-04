/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font Roboto-Medium.ttf --symbols abcdefghijlkmnopqrstuvwxyzABCDEFGHIJLKMNOPQRSTUVWXYZ0123456789:.-_/(), --format lvgl -o roboto_medium_16px.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "liblvgl/lvgl.h"
#endif

#ifndef ROBOTO_MEDIUM_16PX
#define ROBOTO_MEDIUM_16PX 1
#endif

#if ROBOTO_MEDIUM_16PX

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0028 "(" */
    0x11, 0x98, 0xc4, 0x63, 0x18, 0xc6, 0x31, 0x86,
    0x30, 0x86, 0x0,

    /* U+0029 ")" */
    0x43, 0xc, 0x61, 0xc, 0x63, 0x18, 0xc6, 0x33,
    0x19, 0x88, 0x0,

    /* U+002C "," */
    0x6d, 0xe0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0xc, 0x20, 0x86, 0x10, 0x43, 0x8, 0x21, 0x84,
    0x10, 0xc0,

    /* U+0030 "0" */
    0x38, 0xdb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8d, 0xb1, 0xc0,

    /* U+0031 "1" */
    0x1b, 0xfe, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x30,

    /* U+0032 "2" */
    0x3c, 0x66, 0xc6, 0x6, 0x6, 0xe, 0x1c, 0x18,
    0x38, 0x70, 0xe0, 0xff,

    /* U+0033 "3" */
    0x7d, 0x8f, 0x18, 0x30, 0x47, 0x3, 0x3, 0x7,
    0x8f, 0xb3, 0xc0,

    /* U+0034 "4" */
    0x6, 0xe, 0x1e, 0x1e, 0x36, 0x26, 0x66, 0xc6,
    0xff, 0x6, 0x6, 0x6,

    /* U+0035 "5" */
    0x7f, 0x60, 0x60, 0x60, 0x7c, 0x66, 0x3, 0x3,
    0x3, 0x43, 0x66, 0x3c,

    /* U+0036 "6" */
    0x1c, 0x30, 0x60, 0xc0, 0xfc, 0xe6, 0xc3, 0xc3,
    0xc3, 0xc3, 0x66, 0x3c,

    /* U+0037 "7" */
    0xff, 0x3, 0x6, 0x6, 0xc, 0xc, 0xc, 0x18,
    0x18, 0x30, 0x30, 0x30,

    /* U+0038 "8" */
    0x7d, 0x9f, 0x1e, 0x34, 0x47, 0x1b, 0x63, 0xc7,
    0x8d, 0xb1, 0xe0,

    /* U+0039 "9" */
    0x38, 0xdb, 0x1e, 0x3c, 0x78, 0xdb, 0xbf, 0x6,
    0x8, 0x31, 0x80,

    /* U+003A ":" */
    0xc0, 0x0, 0xc0,

    /* U+0041 "A" */
    0xc, 0x1, 0xc0, 0x38, 0xd, 0x1, 0xb0, 0x66,
    0xc, 0x61, 0x8c, 0x7f, 0x8c, 0x19, 0x83, 0x60,
    0x60,

    /* U+0042 "B" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xc6, 0xc3,
    0xc3, 0xc3, 0xc6, 0xfc,

    /* U+0043 "C" */
    0x1e, 0x31, 0x98, 0x78, 0x3c, 0x6, 0x3, 0x1,
    0x80, 0xc1, 0xa0, 0xd8, 0xc7, 0xc0,

    /* U+0044 "D" */
    0xf8, 0xc6, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc6, 0xc6, 0xf8,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x3f, 0xe0, 0xc1,
    0x83, 0x6, 0x0,

    /* U+0047 "G" */
    0x3e, 0x31, 0x90, 0x78, 0xc, 0x6, 0x3, 0x1f,
    0x83, 0xc1, 0xb0, 0xd8, 0x63, 0xe0,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1f, 0xff, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x30,

    /* U+0049 "I" */
    0xff, 0xff, 0xff,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x7,
    0x8f, 0x33, 0xc0,

    /* U+004B "K" */
    0xc3, 0x63, 0xb3, 0x99, 0x8d, 0x87, 0xc3, 0xe1,
    0xd8, 0xce, 0x63, 0x30, 0xd8, 0x70,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x7, 0xf0,

    /* U+004D "M" */
    0xe0, 0x7e, 0x7, 0xf0, 0xff, 0xf, 0xd0, 0xbd,
    0x9b, 0xd9, 0xbc, 0x93, 0xcf, 0x3c, 0xf3, 0xc6,
    0x3c, 0x63,

    /* U+004E "N" */
    0xc1, 0xf0, 0xf8, 0x7e, 0x3d, 0x9e, 0xcf, 0x37,
    0x9b, 0xc7, 0xe1, 0xf0, 0xf8, 0x30,

    /* U+004F "O" */
    0x3e, 0x31, 0x90, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xb1, 0x98, 0xc7, 0xc0,

    /* U+0050 "P" */
    0xfe, 0x61, 0xb0, 0x78, 0x3c, 0x1e, 0x1b, 0xf9,
    0x80, 0xc0, 0x60, 0x30, 0x18, 0x0,

    /* U+0051 "Q" */
    0x3e, 0x31, 0x90, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xb1, 0x98, 0xc7, 0xc0, 0x38, 0x8,

    /* U+0052 "R" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xcc,
    0xc6, 0xc6, 0xc3, 0xc3,

    /* U+0053 "S" */
    0x3e, 0x31, 0xb0, 0x78, 0xf, 0x3, 0xf0, 0xfc,
    0xf, 0x1, 0xe0, 0xd8, 0xc7, 0xc0,

    /* U+0054 "T" */
    0xff, 0x8c, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3, 0x0,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xd8, 0xc7, 0xc0,

    /* U+0056 "V" */
    0xc0, 0xd8, 0x36, 0x19, 0x86, 0x31, 0x8c, 0xc3,
    0x30, 0x6c, 0x1e, 0x7, 0x80, 0xe0, 0x30,

    /* U+0057 "W" */
    0xc3, 0xd, 0x8c, 0x26, 0x39, 0x99, 0xe6, 0x67,
    0x98, 0x9a, 0x63, 0x49, 0xf, 0x3c, 0x3c, 0xf0,
    0xf1, 0xc1, 0x87, 0x6, 0x18,

    /* U+0058 "X" */
    0x61, 0x9c, 0x63, 0x30, 0xec, 0x1e, 0x3, 0x80,
    0xe0, 0x78, 0x3b, 0xc, 0xc6, 0x19, 0x87,

    /* U+0059 "Y" */
    0xe1, 0xd8, 0x67, 0x38, 0xcc, 0x33, 0x7, 0x81,
    0xe0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30,

    /* U+005A "Z" */
    0xff, 0x7, 0x6, 0xc, 0xc, 0x18, 0x18, 0x30,
    0x70, 0x60, 0xe0, 0xff,

    /* U+005F "_" */
    0xfe,

    /* U+0061 "a" */
    0x7d, 0xcf, 0x18, 0x37, 0xf8, 0xf1, 0xe7, 0x7e,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xec, 0xd8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x37, 0xe0,

    /* U+0063 "c" */
    0x3c, 0xcf, 0x1e, 0xc, 0x18, 0x31, 0xb3, 0x3c,

    /* U+0064 "d" */
    0x6, 0xc, 0x19, 0xf6, 0x78, 0xf1, 0xe3, 0xc7,
    0x8d, 0x9b, 0xf0,

    /* U+0065 "e" */
    0x1c, 0x66, 0x63, 0x63, 0xff, 0x40, 0x60, 0x63,
    0x3e,

    /* U+0066 "f" */
    0x3d, 0x86, 0x3e, 0x61, 0x86, 0x18, 0x61, 0x86,
    0x18,

    /* U+0067 "g" */
    0x7e, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xb3, 0x3e,
    0xd, 0x13, 0xc0,

    /* U+0068 "h" */
    0xc1, 0x83, 0x7, 0xec, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x30,

    /* U+0069 "i" */
    0xc3, 0xff, 0xff,

    /* U+006A "j" */
    0x30, 0x3, 0x33, 0x33, 0x33, 0x33, 0x33, 0xe0,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc6, 0xcc, 0xd8, 0xf0, 0xf8,
    0xf8, 0xcc, 0xce, 0xc6,

    /* U+006C "l" */
    0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xfd, 0xec, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x30,

    /* U+006E "n" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,

    /* U+006F "o" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+0070 "p" */
    0xfd, 0x9b, 0x1e, 0x3c, 0x78, 0xf1, 0xe6, 0xfd,
    0x83, 0x6, 0x0,

    /* U+0071 "q" */
    0x7e, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xb3, 0x3e,
    0xc, 0x18, 0x30,

    /* U+0072 "r" */
    0xfe, 0x31, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0073 "s" */
    0x7d, 0x8f, 0x1f, 0x87, 0xc3, 0xf1, 0xe3, 0x7c,

    /* U+0074 "t" */
    0x63, 0x3e, 0xc6, 0x31, 0x8c, 0x63, 0xe,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x7e,

    /* U+0076 "v" */
    0xc3, 0x66, 0x66, 0x66, 0x2c, 0x3c, 0x3c, 0x18,
    0x18,

    /* U+0077 "w" */
    0xc6, 0x24, 0x66, 0x66, 0x66, 0xf6, 0x6b, 0x42,
    0x94, 0x39, 0xc3, 0x9c, 0x30, 0x80,

    /* U+0078 "x" */
    0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66,
    0x67,

    /* U+0079 "y" */
    0xe3, 0x66, 0x66, 0x66, 0x34, 0x3c, 0x3c, 0x18,
    0x18, 0x18, 0x10, 0x60,

    /* U+007A "z" */
    0xfe, 0x1c, 0x70, 0xc3, 0x86, 0x18, 0x70, 0xfe
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 89, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 11, .adv_w = 90, .box_w = 5, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 22, .adv_w = 56, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 24, .adv_w = 84, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 25, .adv_w = 72, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 26, .adv_w = 101, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 36, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 146, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 68, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 170, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 162, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 167, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 145, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 141, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 174, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 182, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 72, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 161, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 139, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 224, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 182, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 177, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 164, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 177, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 372, .adv_w = 160, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 155, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 155, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 166, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 225, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 162, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 156, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 154, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 504, .adv_w = 116, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 505, .adv_w = 139, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 134, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 145, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 137, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 91, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 145, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 572, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 65, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 64, .box_w = 4, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 594, .adv_w = 134, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 65, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 223, .box_w = 12, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 623, .adv_w = 142, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 631, .adv_w = 146, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 651, .adv_w = 145, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 662, .adv_w = 90, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 132, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 85, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 683, .adv_w = 142, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 127, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 700, .adv_w = 190, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 129, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 125, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 735, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0}
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
    3, 5, 3, -31, -3, -3, -3, -3,
    -15, -2, -10, -5, -19, -6, -6, -1,
    -6, -2, -1, -6, -4, -6, 2, -3,
    -3, -7, -3, -4, -15, -15, -3, -11,
    -3, -3, -5, -3, 3, -2, -2, -2,
    -2, -2, -2, -2, -2, -3, -3, -3,
    -34, -34, -24, -26, 3, -4, -3, -3,
    -3, -3, -3, -3, -3, -3, -3, -3,
    2, -4, 2, -3, 2, -4, 2, -3,
    -3, -20, -4, -4, -4, -4, -3, -3,
    -3, -3, -3, -3, -3, -5, -8, -5,
    2, -8, -8, -8, -8, -26, -3, -26,
    -12, -35, -2, -15, -6, -15, 2, -4,
    2, -3, 2, -4, 2, -3, -15, -15,
    -3, -11, -3, -3, -5, -3, -50, -50,
    -22, -23, -6, -4, -1, -2, -2, -2,
    -2, -2, -2, 2, 2, 2, -4, -3,
    -2, -4, -6, -2, -6, -32, -34, -32,
    -15, -3, -3, -27, -3, -3, -2, 2,
    2, 2, 2, -21, -11, -11, -11, -11,
    -11, -11, -26, -11, -11, -8, -9, -8,
    -10, -6, -10, -10, -7, -3, 3, -27,
    -20, -27, -9, -2, -2, -2, -2, -6,
    -5, -5, -5, -5, -6, -5, -4, -3,
    -1, -1, 2, -18, -7, -18, -5, 2,
    -4, -4, -4, -4, -4, -4, -4, -3,
    -2, -19, -3, -3, -3, -3, 2, -3,
    -3, -3, -3, -3, -3, -3, -4, -4,
    3, -29, -19, -29, -19, -4, -4, -12,
    -4, -4, -2, 2, -12, 2, 2, 2,
    2, -8, -8, -8, -8, -3, -8, -5,
    -5, -8, -5, -8, -5, -7, -3, -5,
    -2, -3, -2, -4, 2, -3, -3, -3,
    -3, -3, -3, -3, -3, -3, -3, -2,
    -3, -3, -3, -2, -2, -1, -2, -1,
    -2, -2, -2, 3, -3, -3, -3, -3,
    -3, -2, -2, -2, -2, -2, -2, -3,
    -2, -2, -1, -2, -1, -2, -22, -22,
    -4, -2, -2, -2, 3, -2, -4, -2,
    6, 2, 2, 2, -4, -21, -21, -2,
    -2, -2, -2, 2, -2, -2, -2, -15,
    -15, -2, -2, -2, -2, -5, -2, -21,
    -21, -2, -2, -2, -2, 2, -2, -2,
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
const lv_font_t roboto_medium_16px = {
#else
lv_font_t roboto_medium_16px = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if ROBOTO_MEDIUM_16PX*/

