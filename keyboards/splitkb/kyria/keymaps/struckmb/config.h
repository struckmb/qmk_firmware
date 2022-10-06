/* Copyright 2023 Thomas Baart <thomas@splitkb.com>
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

/* #define TAPPING_TERM 200 */

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X64
#endif

#define QWERTZ_ENABLE
#ifdef COMBO_ENABLE
#    define SPLIT_USB_DETECT
// use ARTSENIO on left half, because
// it makes no use of the right side
/* #    define ARTSENIO_ENABLE */
/* #    define ASETNIOP_ENABLE */
#endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
/* #    define RGBLIGHT_EFFECT_RAINBOW_MOOD */
#endif
