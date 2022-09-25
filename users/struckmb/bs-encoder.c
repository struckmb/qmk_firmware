/* Copyright 2021 Batuhan Başerdem
 * <baserdem.batuhan@gmail.com> @bbaserdem
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
#include "bs-encoder.h"

// Need this to call velocikey activation
#ifdef VELOCIKEY_ENABLE
#   include "velocikey.h"
#endif // VELOCIKEY_ENABLE
// Need memcpy and memcmp from string.h along with transfer stuff
#ifdef OLED_ENABLE
#   include <string.h>
#endif // OLED_ENABLE

// Encoder scroll functionality
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint16_t this_layer = get_highest_layer(layer_state);
    /* uint8_t this_mod = get_mods(); */
    if (index == 2) switch (this_layer) {
#       ifdef MOUSEKEY_ENABLE
        case _MSE_ADJ:
            if (clockwise) {
                tap_code(KC_WH_R);
            } else {
                tap_code(KC_WH_L);
            }
#       endif // MOUSEKEY_ENABLE
        default:
            if (clockwise) {
                tap_code16(C(KC_TAB));
            } else {
                tap_code16(C(S(KC_TAB)));
            }
    } else switch (this_layer) {
        case _NAV_FUN:
            // navi layer: page up/down
            if (clockwise) {
                tap_code16(KC_PGDN);
            } else {
                tap_code16(KC_PGUP);
            }
#       ifdef MOUSEKEY_ENABLE
        case _MSE_ADJ:
            // mouse layer: wheel up/down or left/right with shift
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
            break;
#       endif // MOUSEKEY_ENABLE
        default:
            // default: volume up/down
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
            break;
    }
    return false;
}

bool process_record_encoder(uint16_t keycode, keyrecord_t *record) {
    // Check if and which encoder was pressed
    int encoder_index = keycode == BS_ENC0 ? 0 : keycode == BS_ENC1 ? 1 : -1;
    // Activate encoder function of button
    if (encoder_index >= 0) {
        if (!record->event.pressed) {
            // Differentiate layer roles
            /* switch (get_highest_layer(layer_state)) { */
            /* #       ifdef POINTING_DEVICE_ENABLE */
            /* #       endif // POINTING_DEVICE_ENABLE */
            /* #       ifdef MOUSEKEY_ENABLE */
            /*             case _MSE_ADJ: */
            /*                 break; */
            /* #       endif // MOUSEKEY_ENABLE */
            /* default: */
            // default: mute
            tap_code16(KC_MUTE);
            /* break; */
            /* } */
        }
        return false;
    }
    return true;
}
