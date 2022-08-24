/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

/* Select hand configuration */
#define EE_HANDS

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
// additions
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // (670B)  Enable rainbow swirl animation mode.
#endif

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#ifdef MOUSEKEY_ENABLE
    #define MOUSEKEY_MAX_SPEED 4
    #define MOUSEKEY_TIME_TO_MAX 45
    #define MOUSEKEY_WHEEL_MAX_SPEED 20
    #define MOUSEKEY_WHEEL_TIME_TO_MAX 60
#endif

#ifdef UNICODE_ENABLE
    // enable unicode for linux or windows
    #define UNICODE_SELECTED_MODES UC_LNX
#endif
