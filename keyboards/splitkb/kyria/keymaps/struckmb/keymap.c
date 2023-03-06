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

enum layers {
    _QWERTZ = 0,
    _SYM_NUM,
    _NAV_FUN,
    _MSE_ADJ,
    _KB_CONF,
};

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
    K01, K02, K03, K04, K05,   K06, K07, K08, K09, K0A, K0B, \
    K11, K12, K13, K14, K15,   K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25,   K26, K27, K28, K29, K2A, \
              K33, K34, K35,   K36, K37, K38 \
  ) \
  LAYOUT_wrapper( \
      KC_ESC,  K01, K02, K03, K04, K05,                                                  K06, K07, K08, K09, K0A, K0B, \
      CTL_ESC, K11, K12, GUI_T(K13), CTL_T(K14), K15,                                    K16, CTL_T(K17), GUI_T(K18), K19, K1A, CTL_T(K1B), \
      OSM_SFT, SFT_T(K21), K22, K23, ALT_T(K24), K25, KC_NO, KC_NO,      KC_CAPS, KC_NO, K26, ALT_T(K27), K28, K29, RCTL_T(K2A), OSM_SFT, \
                                   OSM_CTL, OSM_ALT, K33, K34, K35,      K36, K37, K38, OSM_GUI, KC_NO \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT_base_wrapper(
        _________________QWERTZ_L1_______________5_, _________________QWERTZ_R1_______________6_,
        _________________QWERTZ_L2_______________5_, _________________QWERTZ_R2_______________6_,
        _________________QWERTZ_L3_______________5_, _________________QWERTZ_R3_______________5_,
                               _________________THUMB_3_3_______________6_
    ),

// /*
//  * Base Layer: BoNeo
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |  Tab   |   J  |   D  |   U  |   A  |   X  |                              |   P  |   H  |   L  |   W  |   ß  |  Bksp  |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |Ctrl/Esc|   C  |   T  |   I  |   E  |   O  |                              |   B  |   N  |   R  |   S  |   G  | Ctrl/q |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * | LShift |   F  |   V  |   Ü  |   Ä  |   Ö  |      |      |  |      |      |   Y  |   Z  |   ,  |   .  |   K  | RShift |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      | LAlt/| Space| Nav  |  | Sym  | Space| AltGr|      |      |
//  *                        |      |      | Enter|      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_BONE] = LAYOUT(
//      KC_TAB , DE_J , DE_D , DE_U , DE_A , DE_Z ,                                        DE_F,   DE_G ,  DE_C ,   DE_R ,  DE_L , KC_BSPC,
//      CTL_ESC, DE_A , DE_T , DE_I , DE_E , DE_I ,                                        DE_D,   DE_H ,  DE_T ,   DE_N ,  DE_S , CTL_Q,
//      KC_LSFT, DE_F , DE_V ,DE_UE ,DE_AE ,DE_OE , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, DE_B,   DE_M ,  DE_W ,   DE_V ,  DE_Y , KC_RSFT,
//                                  ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
//     ),

///*
// * Base Layer: Colemak DH
// *
// * ,-------------------------------------------.                              ,-------------------------------------------.
// * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Z  |  ; : |  Bksp  |
// * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
// * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// * | LShift |   Y  |   X  |   C  |   D  |   V  |      |      |  |      |      |   K  |   H  |  , < |  . > |  / ? | RShift |
// * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// *                        |      |      | LAlt/| Space| Nav  |  | Sym  | Space| AltGr|      |      |
// *                        |      |      | Enter|      |      |  |      |      |      |      |      |
// *                        `----------------------------------'  `----------------------------------'
// */
//    [_COLEMAK_DH] = LAYOUT(
//     KC_TAB  , DE_Q ,  DE_W   ,  DE_F  ,   DE_P ,   DE_B ,                                        DE_J,   DE_L ,  DE_U ,   DE_Z ,KC_SCLN, KC_BSPC,
//     CTL_ESC , DE_A ,  DE_R   ,  DE_S  ,   DE_T ,   DE_G ,                                        DE_M,   DE_N ,  DE_E ,   DE_I ,  DE_O , CTL_AE,
//     KC_LSFT , DE_Y ,  DE_X   ,  DE_C  ,   DE_D ,   DE_V , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, DE_K,   DE_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
//                                 ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
//    ),


    [_SYM_NUM] = LAYOUT_wrapper(
        _______, _________________SYMBOLS_L1______________5_,             _________________SYMBOLS_R1______________6_,
        _______, _________________SYMBOLS_L2______________5_,             _________________SYMBOLS_R2______________6_,
        _______, _________________SYMBOLS_L3______________5_, X2X,   X2X, _________________SYMBOLS_R3______________6_,
                             _______, _______, _________________SYMBOLS_TB______________6_, _______, _______
    ),
    [_NAV_FUN] = LAYOUT_wrapper(
        _______, ________________NAVIGATION_L1____________5_,             _________________FUNCTION_R1_____________6_,
        _______, ________________NAVIGATION_L2____________5_,             _________________FUNCTION_R2_____________6_,
        _______, ________________NAVIGATION_L3____________5_, X2X,   X2X, _________________FUNCTION_R3_____________6_,
                             _______, _______, _________NAVIGATION_AND_FUNCTION_TB______6_, _______, _______
    ),
    [_MSE_ADJ] = LAYOUT_wrapper(
        _______, __________________MOUSE_L1_______________5_,             __________________MOUSE_R1_______________5_, KC_NO,
        _______, __________________MOUSE_L2_______________5_,             __________________MOUSE_R2_______________5_, KC_NO,
        _______, __________________MOUSE_L3_______________5_, X2X,   X2X, __________________MOUSE_R3_______________5_, _______,
                             _______, _______, __________________MOUSE_TB_______________6_, _______, _______
    ),
    [_KB_CONF] = LAYOUT_wrapper(
        _______, _________________CONFIG_L1_______________5_,             _________________CONFIG_R1_______________5_, KC_NO,
        _______, _________________CONFIG_L2_______________5_,             _________________CONFIG_R2_______________5_, KC_NO,
        _______, _________________CONFIG_L3_______________5_, X2X,   X2X, _________________CONFIG_R3_______________5_, _______,
                             _______, _______, _________________CONFIG_TB_______________6_, _______, _______
    ),

 /*
  * Layer template
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */

//     [_LAYERINDEX] = LAYOUT(
//       _______, KC_MSTP, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
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

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTZ:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
//            case _BONE:
//                oled_write_P(PSTR("BoNeo\n"), false);
//                break;
//            case _COLEMAK_DH:
//                oled_write_P(PSTR("Colemak-DH\n"), false);
//                break;
            case _SYM_NUM:
                oled_write_P(PSTR("Sym/Num\n"), false);
                break;
            case _NAV_FUN:
                oled_write_P(PSTR("Nav/Fn\n"), false);
                break;
            case _MSE_ADJ:
                oled_write_P(PSTR("Mse/Adj\n"), false);
                break;
            case _KB_CONF:
                oled_write_P(PSTR("KB Config\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
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
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
