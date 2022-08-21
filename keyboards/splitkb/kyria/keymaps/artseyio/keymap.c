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
#include "sendstring_german.h"

enum layers {
    _DEFAULT = 0,
//    _SYM, // symbols (neo based)
    _BRA, // braces
    _PCT, // punctuation
    _NUM, // key pad
    _FNC, // function keys
    _NAV, // navigation
    _MOUSE,  // mouse adjustment
//    _MFN, // media and function keys
//    _ADJ  // kb adjustment
};

enum custom_keycodes {
    SY_HELL = SAFE_RANGE, // horizontal ellipsis
    SY_CIRC, // caret (non dead)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
    L_NUM,
    L_FNC,
};

// Aliases for base layers
#define L_BRA  OSL(_BRA)
#define L_PCT  OSL(_PCT)
#define L_DEF  TO(_DEFAULT)
#define KC_DN KC_DOWN

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
     KC_NO, DE_S,  DE_T,  DE_R,  DE_A,  L_BRA,                                  L_BRA, DE_A,  DE_R,  DE_T,  DE_S, KC_NO,
     KC_NO, DE_O,  DE_I,  DE_Y,  DE_E,  L_PCT,                                  L_PCT, DE_E,  DE_Y,  DE_I,  DE_O, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      KC_NO, KC_NO,   KC_NO,   L_NUM, L_FNC,      L_FNC, L_NUM,   KC_NO,   KC_NO, KC_NO//ENC
    ),
    [_BRA] = LAYOUT(
     KC_NO, DE_LCBR, DE_LBRC, DE_LPRN, DE_LABK, KC_NO,                                KC_NO, DE_LABK, DE_LPRN, DE_LBRC, DE_LCBR, KC_NO,
     KC_NO, DE_RCBR, DE_RBRC, DE_RPRN, DE_RABK, KC_NO,                                KC_NO, DE_RABK, DE_RPRN, DE_RBRC, DE_RCBR, KC_NO,
     KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                            KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO//ENC
    ),
    [_PCT] = LAYOUT(
     KC_NO, DE_GRV, DE_SCLN, DE_BSLS, DE_EXLM, KC_NO,                                KC_NO, DE_EXLM, DE_BSLS, DE_SCLN, DE_GRV, KC_NO,
     KC_NO, DE_EQL, DE_MINS, DE_QUES, XXXXXXX, KC_NO,                                KC_NO, XXXXXXX, DE_QUES, DE_MINS, DE_EQL,  KC_NO,
     KC_NO, KC_NO,  KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,
                            KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO//ENC
    ),
    [_NUM] = LAYOUT(
     KC_NO, DE_8,  DE_7,  DE_6,  DE_5,  KC_NO,                                  KC_NO, DE_5,  DE_6,  DE_7,  DE_8,  KC_NO,
     KC_NO, DE_4,  DE_3,  DE_2,  DE_1,  KC_NO,                                  KC_NO, DE_1,  DE_2,  DE_3,  DE_4,  KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                     KC_NO, KC_NO,   KC_NO,  KC_TRNS, KC_NO,      KC_NO, KC_TRNS,  KC_NO,   KC_NO, KC_NO//ENC
    ),
    [_FNC] = LAYOUT(
     KC_NO, KC_F8, KC_F7, KC_F6, KC_F5, KC_NO,                                  KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,
     KC_NO, KC_F4, KC_F3, KC_F2, KC_F1, KC_NO,                                  KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                     KC_NO, KC_NO,   KC_NO,  KC_TRNS, KC_NO,      KC_NO, KC_TRNS,  KC_NO,   KC_NO, KC_NO//ENC
    ),
    [_NAV] = LAYOUT(
     KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END,  KC_NO,                                  KC_NO, KC_HOME, KC_UP, KC_END,  KC_PGUP, KC_NO,
     KC_NO, KC_PGDN, KC_LEFT, KC_DN, KC_RGHT, KC_NO,                                  KC_NO, KC_LEFT, KC_DN, KC_RGHT, KC_PGUP, KC_NO,
     KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,
                            KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO//ENC
    ),
    [_MOUSE] = LAYOUT(
     KC_NO, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, KC_NO,                                KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO,
     KC_NO, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,                                KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO,
     KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,
                            KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO//ENC
    ),
};

// combos definitions
// character combos
const uint16_t PROGMEM combo_nine[] = {DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_zero[] = {DE_2, DE_3, COMBO_END};
const uint16_t PROGMEM combo_b[] = {DE_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_c[] = {DE_E, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_d[] = {DE_A, DE_R, DE_T, COMBO_END};
const uint16_t PROGMEM combo_f[] = {DE_A, DE_R,  COMBO_END};
const uint16_t PROGMEM combo_g[] = {DE_R, DE_T, COMBO_END};
const uint16_t PROGMEM combo_h[] = {DE_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_j[] = {DE_T, DE_S, COMBO_END};
const uint16_t PROGMEM combo_k[] = {DE_Y, DE_O, COMBO_END};
const uint16_t PROGMEM combo_l[] = {DE_E, DE_Y, DE_I, COMBO_END};
const uint16_t PROGMEM combo_m[] = {DE_Y, DE_I,DE_O, COMBO_END};
const uint16_t PROGMEM combo_n[] = {DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_p[] = {DE_E, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_q[] = {DE_A, DE_T, DE_S, COMBO_END};
const uint16_t PROGMEM combo_u[] = {DE_Y, DE_I, COMBO_END};
const uint16_t PROGMEM combo_v[] = {DE_R, DE_S, COMBO_END};
const uint16_t PROGMEM combo_w[] = {DE_A, DE_S, COMBO_END};
const uint16_t PROGMEM combo_x[] = {DE_R, DE_T, DE_S, COMBO_END};
const uint16_t PROGMEM combo_z[] = {DE_A, DE_R, DE_T, DE_S, COMBO_END};
const uint16_t PROGMEM combo_F9[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM combo_F10[] = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM combo_F11[] = {KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM combo_F12[] = {KC_F6, KC_F7, COMBO_END};
// special char combos
const uint16_t PROGMEM combo_quot[] = {DE_A, DE_Y, DE_I, COMBO_END};
const uint16_t PROGMEM combo_dot[] = {DE_A, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_comma[] = {DE_A, DE_I, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {DE_A, DE_O, COMBO_END};
const uint16_t PROGMEM combo_exclam[] = {DE_T, DE_I, COMBO_END};
const uint16_t PROGMEM combo_space[] = {DE_E, DE_Y, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {DE_A, DE_E, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {DE_A, DE_R, DE_T, DE_O, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {DE_R, DE_E, COMBO_END};
const uint16_t PROGMEM combo_del[] = {DE_R, DE_I, COMBO_END};
const uint16_t PROGMEM combo_shift[] = {DE_R, DE_T, DE_S, DE_E, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {DE_A, DE_Y, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_ctrl[] = {DE_S, DE_E, COMBO_END};
const uint16_t PROGMEM combo_alt[] = {DE_S, DE_I, COMBO_END};
const uint16_t PROGMEM combo_gui[] = {DE_S, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {DE_A, DE_R, DE_O, COMBO_END};
// layer combos
const uint16_t PROGMEM combo_nav1[] = {DE_R, DE_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_nav0[] = {KC_LEFT, KC_UP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_mouse1[] = {DE_A, DE_T, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_mouse0[] = {KC_BTN2, KC_MS_D, KC_BTN1, COMBO_END};

/* const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END}; */
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_nine, DE_9),
    COMBO(combo_zero, DE_0),
    COMBO(combo_b, DE_B),
    COMBO(combo_c, DE_C),
    COMBO(combo_d, DE_D),
    COMBO(combo_f, DE_F),
    COMBO(combo_g, DE_G),
    COMBO(combo_h, DE_H),
    COMBO(combo_j, DE_J),
    COMBO(combo_k, DE_K),
    COMBO(combo_l, DE_L),
    COMBO(combo_m, DE_M),
    COMBO(combo_n, DE_N),
    COMBO(combo_p, DE_P),
    COMBO(combo_q, DE_Q),
    COMBO(combo_u, DE_U),
    COMBO(combo_v, DE_V),
    COMBO(combo_w, DE_W),
    COMBO(combo_x, DE_X),
    COMBO(combo_z, DE_Z),
    COMBO(combo_F9, KC_F9),
    COMBO(combo_F10, KC_F10),
    COMBO(combo_F11, KC_F11),
    COMBO(combo_F12, KC_F12),
    COMBO(combo_quot, DE_QUOT),
    COMBO(combo_dot, DE_DOT),
    COMBO(combo_comma, DE_COMM),
    COMBO(combo_slash, DE_SLSH),
    COMBO(combo_exclam, DE_EXLM),
    COMBO(combo_space, KC_SPC),
    COMBO(combo_enter, KC_ENT),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_shift, OSM(MOD_LSFT)),
    COMBO(combo_caps, KC_CAPS),
    COMBO(combo_ctrl, OSM(MOD_LCTL)),
    COMBO(combo_alt, OSM(MOD_LALT)),
    COMBO(combo_gui, OSM(MOD_LGUI)),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_nav1, TG(_NAV)),
    COMBO(combo_nav0, TG(_NAV)),
    COMBO(combo_mouse1, TG(_MOUSE)),
    COMBO(combo_mouse0, TG(_MOUSE)),
};

// alternative TT implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_NUM:
        case L_FNC:
            static bool isToggeled = 0;
            static uint32_t toggle_timer = 0;
            static bool isNum = false;
            if (keycode == L_NUM) isNum = true;
            if (record->event.pressed) {
                toggle_timer = timer_read32();
                layer_off(isNum ? _FNC : _NUM);
                layer_on(!isNum ? _FNC : _NUM);
            } else {
                if (timer_elapsed32(toggle_timer) < TAPPING_TERM) {
                    isToggeled = !isToggeled;
                }
                if (!isToggeled) {
                layer_off(isNum ? _NUM : _FNC );
                }
            }
            return false;
    }
    return true;
}

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
        // Host Keyboard Layer Status
        oled_write_P(PSTR("\nLayer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _DEFAULT:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case _BRA:
                oled_write_P(PSTR("Braces\n"), false);
                break;
            case _PCT:
                oled_write_P(PSTR("Punctuation\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Numbers\n"), false);
                break;
            case _FNC:
                oled_write_P(PSTR("Fn-Keys\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Navigation\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("Mouse\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(PSTR("\nLOCK: "), false);
        oled_write_P(PSTR("NUM"), led_usb_state.num_lock);
        oled_write_P(PSTR("  "), false);
        oled_write_P(PSTR("CAPS"), led_usb_state.caps_lock);
        oled_write_P(PSTR("  "), false);
        oled_write_P(PSTR("SCR"), led_usb_state.scroll_lock);
    } else {
        // clang-format off
        // 'Kyria_OLED_mini_display', 128x32px
        static const char PROGMEM kyria_logo[] = {
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
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
        oled_set_cursor(4,5);
        oled_write_P(PSTR("Kyria rev1.4"), false);
    }
    return false;
}
#endif
