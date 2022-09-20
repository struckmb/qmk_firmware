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
 *
 * Adjusted by Björn Struckmeier.
 */
#include QMK_KEYBOARD_H
#include "struckmb.h"
#include "keymap_german.h"

#define LAYOUT_split_3x6_5_wrapper(...) LAYOUT_split_3x6_5(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_5_wrapper(
        _BL1_1_,_BL1_5_,                _BR1_5_,_BR1_1_,
        _BL2_1_,_BL2_5_,                _BR2_5_,_BR2_1_,
        _BL3_1_,_BL3_5_,xxx2xxx,xxx2xxx,_BR3_5_,_BR3_1_,
        XXXXXXX,XXXXXXX,_BL4_3_,_BR4_3_,XXXXXXX,BS_ENC0
    ),
    [_HRM_OFF] = LAYOUT_split_3x6_5_wrapper(
        _BL1_1_,_QL1_5_,                _QR1_5_,_BR1_1_,
        _BL2_1_,_QL2_5_,                _QR2_5_,_BR2_1_,
        _BL3_1_,_QL3_5_,xxx2xxx,xxx2xxx,_QR3_5_,_BR3_1_,
        XXXXXXX,XXXXXXX,_BL4_3_,_BR4_3_,XXXXXXX,BS_ENC0
    ),
#   ifdef COMBO_ENABLE
    [_ASETNIOP] = LAYOUT_split_3x6_5_wrapper(
        XXXXXXX,_AL1_5_,                _AR1_5_,XXXXXXX,
        _BL2_1_,_AL2_5_,                _AR2_5_,XXXXXXX,
        XXXXXXX,_AL3_5_,xxx2xxx,xxx2xxx,_AR3_5_,XXXXXXX,
        XXXXXXX,XXXXXXX,_AL4_3_,_AR4_3_,XXXXXXX,XXXXXXX
    ),
#   endif // COMBO_ENABLE
    [_SYM_NUM] = LAYOUT_split_3x6_5_wrapper(
        _______,_SY1_5_,                _NU1_5_,_______,
        _______,_SY2_5_,                _NU2_5_,_______,
        _______,_SY3_5_,xxx2xxx,xxx2xxx,_NU3_5_,_______,
        _______,_______,_SY4_3_,_NU4_3_,_______,_______
    ),
    [_NAV_FUN] = LAYOUT_split_3x6_5_wrapper(
        _______,_NA1_5_,                _FU1_5_,_______,
        _______,_NA2_5_,                _FU2_5_,_______,
        _______,_NA3_5_,xxx2xxx,xxx2xxx,_FU3_5_,_______,
        _______,_______,_NA4_3_,_FU4_3_,_______,_______
    ),
    [_MSE_ADJ] = LAYOUT_split_3x6_5_wrapper(
        _______,_MO1_5_,                _AD1_5_,_______,
        _______,_MO2_5_,                _AD2_5_,_______,
        _______,_MO3_5_,xxx2xxx,xxx2xxx,_AD3_5_,_______,
        _______,_______,_MO4_3_,_AD4_3_,_______,_______
    ),
};

#ifdef OLED_ENABLE

#ifdef ENCODER_ENABLE
void render_encoder(uint8_t row, uint8_t col, uint8_t index, uint8_t layer) {
    // Renders the encoder state, 14 characters
    oled_set_cursor(col, row);
    static char encoder_temp9[9] = {0};
    oled_write("E: ", false);
    switch (layer) {
        // If RGB control mode is enabled
        case _MSE_ADJ:
            // Get correct index
            switch (encoderFunState) {
                default:
#               ifdef MOUSEKEY_ENABLE
                    oled_write("MS Whl", false);
#               else // MOUSEKEY_ENABLE
                    oled_write("-N/A- ", false);
#               endif // MOUSEKEY_ENABLE
                    break;
            }
            break;
        case _NAV_FUN:
            oled_write("PgU/D ", false);
            break;
        default:
            oled_write("Vol.  ", false);
            break;
    }
}
#endif // ENCODER_ENABLE

// print logo, and allow default status printing
bool oled_task_keymap(void) {
    if (is_oled_on()) {
        if (is_keyboard_master()) {
            render_qmk_logo(0, 0);
            render_status_lite(4, 0, false);
#       ifdef ENCODER_ENABLE
            render_encoder(7, 0, 0, get_highest_layer(layer_state));
#       endif // ENCODER_ENABLE
        } else {
            // clang-format off
            static const char PROGMEM kyria_logo[] = {
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
                0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
                0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
            };
            // clang-format on
            oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
        }
    }
    return false;
}
#endif //OLED_ENABLE
