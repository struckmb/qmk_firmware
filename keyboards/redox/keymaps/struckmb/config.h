/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
#define EE_HANDS

#ifdef MOUSEKEY_ENABLE
    #define MOUSEKEY_MAX_SPEED 4
    #define MOUSEKEY_TIME_TO_MAX 45
    #define MOUSEKEY_WHEEL_MAX_SPEED 20
    #define MOUSEKEY_WHEEL_TIME_TO_MAX 60
#endif

/* tapping config */
#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#ifdef LEADER_ENABLE
    // leader key cofiguration
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 250
#endif

#ifdef UNICODE_ENABLE
    // enable unicode for linux or windows
    #define UNICODE_SELECTED_MODES UC_LNX, UC_WINC
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 14
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_ANIMATIONS // enable ALL animations
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD    // (636k)  Enable rainbow mood animation mode.
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // (670k)  Enable rainbow swirl animation mode.
    // #define RGBLIGHT_EFFECT_STATIC_GRADIENT // (264k)  Enable static gradient mode.
    // #define RGBLIGHT_EFFECT_TWINKLE         // (1574k) Enable twinkle animation mode.
    // #define RGBLIGHT_EFFECT_CHRISTMAS       // (922k)  Enable christmas animation mode.
    // #define RGBLIGHT_EFFECT_BREATHING       // (904k)  Enable breathing animation mode.
    // #define RGBLIGHT_EFFECT_RGB_TEST        // (596k)  Enable RGB test animation mode.
#endif

