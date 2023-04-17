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

#define QWERTZ_ENABLE
#define BONE_ENABLE
#define WORKMAN_ENABLE
#define COLEMAK_ENABLE
#define LILYPOND_ENABLE

// deactivated some effects for size reasons
#ifdef RGBLIGHT_ENABLE
/* #    define RGBLIGHT_EFFECT_BREATHING */
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
/* #    define RGBLIGHT_EFFECT_KNIGHT */
/* #    define RGBLIGHT_EFFECT_CHRISTMAS */
/* #    define RGBLIGHT_EFFECT_STATIC_GRADIENT */
/* #    define RGBLIGHT_EFFECT_RGB_TEST */
/* #    define RGBLIGHT_EFFECT_ALTERNATING */
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_DEFAULT_HUE 85
#    define RGBLIGHT_DEFAULT_VAL 75
#    define RGBLIGHT_SLEEP
#    undef RGBLIGHT_LIMIT_VAL
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_SPLIT
#    define RGBLIGHT_LAYERS
#endif
