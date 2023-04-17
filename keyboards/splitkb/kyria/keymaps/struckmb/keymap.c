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

/*
 * The `LAYOUT_*_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */
// clang-format off
/* Re-pass though to allow templates to be used */
#define LAYOUT_kyria_hrm_wrapper(...)       LAYOUT_3x6_7_base(__VA_ARGS__)
#define LAYOUT_kyria_wrapper(...)           LAYOUT_3x6_7_layer(__VA_ARGS__)
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef QWERTZ_ENABLE
    [_QWERTZ] = LAYOUT_kyria_hrm_wrapper(
        _____________________QWERTZ_L1____________________6_, _____________________QWERTZ_R1____________________6_,
        _____________________QWERTZ_L2____________________6_, _____________________QWERTZ_R2____________________6_,
        _____________________QWERTZ_L3____________________6_, _____________________QWERTZ_R3____________________6_,
                  ________________________________________THUMB_5_5____________________________________10_),
#endif
#ifdef BONE_ENABLE
    [_BONE] = LAYOUT_kyria_hrm_wrapper(
        _______________________BONE_L1____________________6_, _______________________BONE_R1____________________6_,
        _______________________BONE_L2____________________6_, _______________________BONE_R2____________________6_,
        _______________________BONE_L3____________________6_, _______________________BONE_R3____________________6_,
                  ________________________________________THUMB_5_5____________________________________10_
    ),
#endif // BONE_ENABLE
#ifdef WORKMAN_ENABLE
    [_WORKMAN] = LAYOUT_kyria_hrm_wrapper(
        ____________________WORKMAN_L1____________________6_, ____________________WORKMAN_R1____________________6_,
        ____________________WORKMAN_L2____________________6_, ____________________WORKMAN_R2____________________6_,
        ____________________WORKMAN_L3____________________6_, ____________________WORKMAN_R3____________________6_,
                  ________________________________________THUMB_5_5____________________________________10_
    ),
#endif // WORKMAN_ENABLE
#ifdef COLEMAK_ENABLE
    [_COLMAK_DH] = LAYOUT_kyria_hrm_wrapper(
        ___________________COLEMAK_DH_L1__________________6_, ___________________COLEMAK_DH_R1__________________6_,
        ___________________COLEMAK_DH_L2__________________6_, ___________________COLEMAK_DH_R2__________________6_,
        ___________________COLEMAK_DH_L3__________________6_, ___________________COLEMAK_DH_R3__________________6_,
                  ________________________________________THUMB_5_5____________________________________10_
    ),
#endif // COLEMAK_ENABLE
#ifdef LILYPOND_ENABLE
    [_LILYPOND] = LAYOUT_kyria_hrm_wrapper(
        ____________________LILYPOND_L1___________________6_, ____________________LILYPOND_R1___________________6_,
        ____________________LILYPOND_L2___________________6_, ____________________LILYPOND_R2___________________6_,
        ____________________LILYPOND_L3___________________6_, ____________________LILYPOND_R3___________________6_,
                  ________________________________________THUMB_5_5____________________________________10_
    ),
#endif // LILYPOND_ENABLE

    [_SYM_NUM] = LAYOUT_kyria_wrapper(
        _____________________SYMBOLS_L1___________________6_, _____________________SYMBOLS_R1___________________6_,
        _____________________SYMBOLS_L2___________________6_, _____________________SYMBOLS_R2___________________6_,
        _____________________SYMBOLS_L3___________________6_, _____________________SYMBOLS_R3___________________6_,
                                 _____________________SYMBOLS_TB___________________6_
    ),
    [_NAV_FUN] = LAYOUT_kyria_wrapper(
        _______________NAVIGATION_L1______________________6_, _________________FUNCTION_R1______________________6_,
        _______________NAVIGATION_L2______________________6_, _________________FUNCTION_R2______________________6_,
        _______________NAVIGATION_L3______________________6_, _________________FUNCTION_R3______________________6_,
                                 _____________NAVIGATION_AND_FUNCTION_TB___________6_
    ),
    [_MSE_CTL] = LAYOUT_kyria_wrapper(
        ______________________MOUSE_L1____________________6_, ______________________MOUSE_R1____________________6_,
        ______________________MOUSE_L2____________________6_, ______________________MOUSE_R2____________________6_,
        ______________________MOUSE_L3____________________6_, ______________________MOUSE_R3____________________6_,
                                 ______________________MOUSE_TB____________________6_
    ),
    [_ADJUST]  = LAYOUT_kyria_wrapper(
        ____________________CONFIG_L1_____________________6_, ____________________CONFIG_R1_____________________6_,
        ____________________CONFIG_L2_____________________6_, ____________________CONFIG_R2_____________________6_,
        ____________________CONFIG_L3_____________________6_, ____________________CONFIG_R3_____________________6_,
                                 ____________________CONFIG_TB_____________________6_
    )
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

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
