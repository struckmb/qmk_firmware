/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "struckmb.h"

//enum layers {
//    _QWERTZ = 0,
//    _SYM_NUM,
//    _NAV_FUN,
//    _MSE_CTL,
//    _ADJUST,
//};

/*
 * The `LAYOUT_kyria_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_kyria_base( \
    K00, K01, K02, K03, K04, K05,   K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,   K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,   K26, K27, K28, K29, K2A, K2B, \
         K31, K32, K33, K34, K35,   K36, K37, K38, K39, K3A \
  ) \
  LAYOUT_wrapper( \
      K01, K01,        K02, K03,        K04,        K05,                                    K06, K07,        K08,        K09, K0A,               K0B, \
      K10, K11,        K12, GUI_T(K13), CTL_T(K14), K15,                                    K16, CTL_T(K17), GUI_T(K18), K19, LT(_MSE_CTL, K1A), K1B, \
      K20, SFT_T(K21), K22, K23,        ALT_T(K24), K25, KC_NO, KC_NO,      KC_NO, CW_TOGG, K26, ALT_T(K27), K28,        K29, RSFT_T(K2A),       K2B, \
                            K31,        K32,        K33, K34,   K35,        K36,   K37,     K38, K39,        K3A \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_hrm_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT_hrm_wrapper(
        _________________QWERTZ_L1________________________6_, _________________QWERTZ_R1________________________6_,
        _________________QWERTZ_L2________________________6_, _________________QWERTZ_R2________________________6_,
        _________________QWERTZ_L3________________________6_, _________________QWERTZ_R3________________________6_,
                       ___________________________________THUMB_5_5_________________________________________10_
    ),

    [_SYM_NUM] = LAYOUT_wrapper(
        _________________SYMBOLS_L1_______________________6_,             _________________SYMBOLS_R1_______________________6_,
        _________________SYMBOLS_L2_______________________6_,             _________________SYMBOLS_R2_______________________6_,
        _________________SYMBOLS_L3_______________________6_, X2X,   X2X, _________________SYMBOLS_R3_______________________6_,
                             _______, _______, _____________________SYMBOLS_TB___________________6_, _______, _______
    ),
    [_NAV_FUN] = LAYOUT_wrapper(
        _______________NAVIGATION_L1______________________6_,             _________________FUNCTION_R1______________________6_,
        _______________NAVIGATION_L2______________________6_,             _________________FUNCTION_R2______________________6_,
        _______________NAVIGATION_L3______________________6_, X2X,   X2X, _________________FUNCTION_R3______________________6_,
                             _______, _______, _________NAVIGATION_AND_FUNCTION_TB_______________6_, _______, _______
    ),
    [_MSE_CTL] = LAYOUT_wrapper(
        __________________MOUSE_L1________________________6_,             __________________MOUSE_R1________________________6_,
        __________________MOUSE_L2________________________6_,             __________________MOUSE_R2________________________6_,
        __________________MOUSE_L3________________________6_, X2X,   X2X, __________________MOUSE_R3________________________6_,
                             _______, _______, __________________MOUSE_TB________________________6_, _______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, _________________CONFIG_L1_______________5_,             _________________CONFIG_R1_______________5_, KC_NO,
        _______, _________________CONFIG_L2_______________5_,             _________________CONFIG_R2_______________5_, KC_NO,
        _______, _________________CONFIG_L3_______________5_, X2X,   X2X, _________________CONFIG_R3_______________5_, _______,
                             _______, _______, _________________CONFIG_TB________________________6_, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,------------------------------------------------------.                              ,-------------------------------------------.
//  * |         |        |        |        |        |        |                              |      |      |      |      |      |        |
//  * |---------+--------+--------+--------+--------+--------|                              |------+------+------+------+------+--------|
//  * |         |        |        |        |        |        |                              |      |      |      |      |      |        |
//  * |---------+--------+--------+--------+--------+--------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |         |        |        |        |        |        |      |      |  |      |      |      |      |      |      |      |        |
//  * `---------------------------+--------+--------+--------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void render_logo_keyboard(uint8_t col, uint8_t row) {
    // clang-format off
    static const char PROGMEM small_kyria_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x8c, 0xc6, 0x66, 0x63, 0x33, 0x33, 0xb3,
        0x73, 0xf3, 0x73, 0xb3, 0x33, 0x33, 0x63, 0x66, 0xc6, 0x8c, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xf0, 0xfe, 0x0f, 0x01, 0xe0, 0xfc, 0x1e, 0x3f, 0xcd, 0x94, 0x94, 0xa4, 0xa4, 0xce, 0xf1,
        0xc0, 0xff, 0xc0, 0xf1, 0xce, 0xa4, 0xa4, 0x94, 0x94, 0xcd, 0x3f, 0x1e, 0xfc, 0xe0, 0x01, 0x0f,
        0xfe, 0xf0, 0x00, 0x00, 0xf0, 0x80, 0xc0, 0x40, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0,
        0x80, 0x40, 0x40, 0x80, 0x00, 0x40, 0xd0, 0x00, 0x00, 0x00, 0x40, 0x40, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x0f, 0x7f, 0xf0, 0x80, 0x07, 0x3f, 0x78, 0xfc, 0xb3, 0x29, 0x29, 0x25, 0x25, 0x73, 0x8f,
        0x03, 0xff, 0x03, 0x8f, 0x73, 0x25, 0x25, 0x29, 0x29, 0xb3, 0xfc, 0x78, 0x3f, 0x07, 0x80, 0xf0,
        0x7f, 0x0f, 0x00, 0x00, 0x07, 0x03, 0x06, 0x04, 0x00, 0x04, 0x05, 0x05, 0x03, 0x00, 0x00, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x00, 0x06, 0x05, 0x05, 0x07, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x31, 0x63, 0x66, 0xc6, 0xcc, 0xcc, 0xcd,
        0xce, 0xcf, 0xce, 0xcd, 0xcc, 0xcc, 0xc6, 0x66, 0x63, 0x31, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    // clang-format on
    oled_set_cursor(col, row);
    oled_write_raw_P(small_kyria_logo, sizeof(small_kyria_logo));
    oled_set_cursor(col + 4, row + 5);
    oled_write_P(PSTR("Kyria rev1.4"), false);
}
#endif

