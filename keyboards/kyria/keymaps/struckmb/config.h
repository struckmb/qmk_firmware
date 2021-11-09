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

/*
 * adopted by Björn Struckmeier
 */

#pragma once

// #define NO_ACTION_ONESHOT // frees 274B

/* Select hand configuration */
#define EE_HANDS

#ifdef MOUSEKEY_ENABLE
    #define MK_3_SPEED
    #define MK_MOMENTARY_ACCEL
    #define MOUSEKEY_DELAY 0
    #define MOUSEKEY_INTERVAL 16
    #define MOUSEKEY_MAX_SPEED 7
    #define MOUSEKEY_TIME_TO_MAX 60
    #define MK_C_OFFSET_0 2
    #define MK_C_INTERVAL_0 24
    #define MK_C_OFFSET_1 8
    #define MK_C_INTERVAL_1 24
    #define MK_W_INTERVAL_0 200
    #define MOUSEKEY_WHEEL_DELAY 0
#endif

/* tapping config */
#define TAPPING_TOGGLE 2
// #define TAPPING_TERM 175
// #define TAPPING_TERM_PER_KEY
// #define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
// #define TAPPING_FORCE_HOLD
// #define TAPPING_FORCE_HOLD_PER_KEY

#ifdef LEADER_ENABLE
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 250
#endif

#ifdef UNICODE_ENABLE
    // enable unicode for linux or windows
    #define UNICODE_SELECTED_MODES UC_LNX, UC_WINC
#endif

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13}
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LIMIT_VAL 150
    #define RGBLIGHT_LAYERS
    // // #define RGBLIGHT_ANIMATIONS // enable ALL animations
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD    // (636B)  Enable rainbow mood animation mode.
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // (670B)  Enable rainbow swirl animation mode.
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT // (264B)  Enable static gradient mode.
    // #define RGBLIGHT_EFFECT_TWINKLE         // (1574B) Enable twinkle animation mode.
    // #define RGBLIGHT_EFFECT_CHRISTMAS       // (922B)  Enable christmas animation mode.
    // #define RGBLIGHT_EFFECT_BREATHING       // (904B)  Enable breathing animation mode.
    // #define RGBLIGHT_EFFECT_RGB_TEST        // (596B)  Enable RGB test animation mode.
#endif
