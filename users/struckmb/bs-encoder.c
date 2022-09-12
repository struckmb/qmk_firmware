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

/* ROTARY ENCODER
 * This contains my general rotary encoder code
 * Encoders each have a list of different modes they can be in.
 * Each mode also have an on click action as well.
 * Modes can be cycled using either shift-click or ctrl-click
 * Modes can be reset using OS click
 * Some modes are only accessible through some keymap layers
 */

/* // Default state for the encoders */
/* void reset_encoder_state(void) { */
/*     userspace_config.e0base = 0; */
/*     userspace_config.e0point = 0; */
/*     userspace_config.e0rgb = 0; */
/*     userspace_config.e1base = 1; */
/*     userspace_config.e1point = 1; */
/*     userspace_config.e1rgb = 1; */
/* } */

// states: 0: default 1: rgb mode, 2: 
#ifdef MOUSEKEY_ENABLE
static uint8_t encoderFunState = 0;
#endif // MOUSEKEY_ENABLE

#ifndef MOUSEKEY_ENABLE
#ifdef RGB_MATRIX_ENABLE
static uint8_t encoderFunState = 1;
#else // RGB_MATRIX_ENABLE
static uint8_t encoderFunState = 0;
#endif // RGB_MATRIX_ENABLE
#endif // MOUSEKEY_ENABLE

// Encoder scroll functionality
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t this_mod = get_mods();
    // Differentiate layer roles
    switch (get_highest_layer(layer_state)) {
#       ifdef MOUSEKEY_ENABLE
        case _NAV_FUN:
            // navi layer: page up/down
            if (clockwise) {
                tap_code16(KC_PGDN);
            } else {
                tap_code16(KC_PGUP);
            }
#       endif // MOUSEKEY_ENABLE
        case _MSE_ADJ:
            switch (encoderFunState) {
#               ifdef RGB_MATRIX_ENABLE
                case 1: // Effect the RGB mode
                    if (clockwise) {
                        rgb_matrix_step_noeeprom();
                    } else {
                        rgb_matrix_step_reverse_noeeprom();
                    }
                    break;
                case 2: // Effect the RGB hue
                    if (clockwise) {
                        rgb_matrix_increase_hue_noeeprom();
                    } else {
                        rgb_matrix_decrease_hue_noeeprom();
                    }
                    break;
                case 3: // Effect the RGB saturation
                    if (clockwise) {
                        rgb_matrix_increase_sat_noeeprom();
                    } else {
                        rgb_matrix_decrease_sat_noeeprom();
                    }
                    break;
                case 4: // Effect the RGB brightness
                    if (clockwise) {
                        rgb_matrix_increase_val_noeeprom();
                    } else {
                        rgb_matrix_decrease_val_noeeprom();
                    }
                    break;
                case 5: // Effect the RGB effect speed
                    if (clockwise) {
                        rgb_matrix_increase_speed_noeeprom();
                    } else {
                        rgb_matrix_decrease_speed_noeeprom();
                    }
                    break;
#               endif // RGB_MATRIX_ENABLE
                default:
                    // mouse layer: wheel up/down or left/right with shift
                    if (this_mod & MOD_MASK_SHIFT) {
                        if (clockwise) {
                            tap_code(KC_WH_R);
                        } else {
                            tap_code(KC_WH_L);
                        }
                    } else {
                        if (clockwise) {
                            tap_code(KC_WH_D);
                        } else {
                            tap_code(KC_WH_U);
                        }
                    }
                    break;
            }
            break;
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

void encoder_click_action(void) {
    // Differentiate layer roles
    switch (get_highest_layer(layer_state)) {
#       ifdef RGB_MATRIX_ENABLE
        case _MSE_ADJ:
            // click changes rotate action
            encoderFunState = (++encoderFunState) % 6;
#       ifdef MOUSEKEY_ENABLE
            if (encoderFunState == 0) encoderFunState++;
#       endif // MOUSEKEY_ENABLE
            break;
#       endif // RGB_MATRIX_ENABLE
        default:
            // default: mute
            tap_code16(KC_MUTE);
            break;
            break;
    }
}

bool process_record_encoder(uint16_t keycode, keyrecord_t *record) {
    // Activate encoder function of button
    if (keycode == BS_ENC && (!record->event.pressed)) {
        encoder_click_action();
        /* return false; */
    }
    return true;
}

// For printing status to OLED
#ifdef OLED_ENABLE
void encoder_state_string(uint8_t index, uint8_t layer, char* buffer) {
    // Get the layer straight from the main function
    switch (layer) {
        // If RGB control mode is enabled
        case _MSE_ADJ:
            // Get correct index
            switch (encoderFunState) {
#               ifdef RGB_MATRIX_ENABLE
                case 1:
                    strcpy(buffer, "ani mode");
                    break;
                case 2:
                    strcpy(buffer, "hue     ");
                    break;
                case 3:
                    strcpy(buffer, "saturat.");
                    break;
                case 4:
                    strcpy(buffer, "bright. ");
                    break;
                case 5:
                    strcpy(buffer, "ani. spd");
                    break;
#               endif // RGB_MATRIX_ENABLE
                default:
#               ifdef MOUSEKEY_ENABLE
                    strcpy(buffer, "MS Wheel");
#               else // MOUSEKEY_ENABLE
                    strcpy(buffer, " -N/A-  ");
#               endif // MOUSEKEY_ENABLE
                    break;
            }
            break;
        case _NAV_FUN:
            strcpy(buffer, "PgUp/Dn ");
            break;
        default:
            strcpy(buffer, "Volume  ");
            break;
    }
}
#endif // OLED_ENABLE
