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
    _DEF = 0,
    _BRA, // braces
    _SYM, // symbols
    _NUM, // key pad
    _FNC, // function keys
    _NAV, // navigation
    _MOUSE,  // mouse adjustment
//    _MFN, // media and function keys
//    _ADJ  // kb adjustment
};

enum custom_keycodes {
    NUM_X = SAFE_RANGE,
    NUM_Y,
};

// Aliases for base layers
#define L_B_A  LT(_BRA, DE_A)
#define L_S_E  LT(_SYM, DE_E)
#define L_N_S  LT(_NUM, DE_S)
#define T_SYM  OSL(_SYM)
#define L_DEF  TO(_DEF)
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)
#define KC_DN  KC_DOWN

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT(
     KC_NO,  L_N_S,   DE_T,    DE_R,    L_B_A,   DE_SS,                                   DE_SS,  L_B_A,   DE_R,    DE_T,    L_N_S,   KC_NO,
     KC_NO,  DE_O,    DE_I,    DE_Y,    L_S_E,   OS_SFT,                                  OS_SFT, L_S_E,   DE_Y,    DE_I,    DE_O,    KC_NO,
     KC_NO,  OS_CTL,  DE_AT,   KC_DEL,  DE_EQL,  KC_TAB,  KC_NO, KC_NO,     KC_NO, KC_NO, KC_TAB, DE_EQL,  KC_DEL,  DE_AT,   OS_CTL,  KC_NO,
                         KC_NO,   KC_NO,     T_SYM,     KC_ENT, KC_SPC,     KC_SPC, KC_ENT,     T_SYM,     KC_NO, KC_NO//ENC
    ),
    [_BRA] = LAYOUT(
     KC_NO,  DE_LCBR, DE_LPRN, DE_RPRN, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, DE_RPRN, DE_LPRN, DE_LCBR, KC_NO,
     KC_NO,  DE_RCBR, DE_LBRC, DE_RBRC, KC_NO,   KC_TRNS,                                 KC_TRNS, KC_NO,   DE_RBRC, DE_LBRC, DE_RCBR, KC_NO,
     KC_NO,  DE_SLSH, DE_LABK, DE_RABK, KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   DE_RABK, DE_LABK, DE_SLSH, KC_NO,
                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
    ),
    [_SYM] = LAYOUT(
     KC_NO,  DE_GRV,  DE_SCLN, DE_BSLS, DE_EXLM, KC_HASH,                                 KC_HASH, DE_EXLM, DE_BSLS, DE_SCLN, DE_GRV,  KC_NO,
     KC_NO,  DE_EQL,  DE_MINS, DE_QUES, KC_TRNS, DE_DQUO,                                 DE_DQUO, KC_TRNS, DE_QUES, DE_MINS, DE_EQL,  KC_NO,
     KC_NO,  DE_SLSH, DE_PLUS, DE_PIPE, KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   DE_PIPE, DE_PLUS, DE_SLSH, KC_NO,
                         KC_TRNS, KC_TRNS,    KC_TRNS,    TO(0), TO(0),     TO(0), TO(0),    KC_TRNS,    KC_TRNS, KC_NO//ENC
    )
    [_NUM] = LAYOUT(
     QK_RBT, NUM_X,   DE_3,    DE_2,    DE_1,    KC_TRNS,                                 KC_TRNS, DE_1,    DE_2,    DE_3,    NUM_X,  QK_RBT,
     KC_NO,  NUM_Y,   DE_7,    DE_6,    DE_5,    KC_TRNS,                                 KC_TRNS, DE_5,    DE_6,    DE_7,    NUM_Y,   KC_NO,
     KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
    ),
    [_FNC] = LAYOUT(
     KC_NO,  KC_F11,  KC_F3,   KC_F2,   KC_F1,   KC_TRNS,                                 KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F11,  KC_NO,
     KC_NO,  KC_F12,  KC_F7,   KC_F6,   KC_F5,   KC_TRNS,                                 KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F12,  KC_NO,
     KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                         KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
    ),
    [_NAV] = LAYOUT(
     KC_NO,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS,                                 KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO,
     KC_NO,  KC_PGDN, KC_LEFT, KC_DN,   KC_RGHT, KC_TRNS,                                 KC_TRNS, KC_LEFT, KC_DN,   KC_RGHT, KC_PGDN, KC_NO,
     KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                         KC_TRNS, KC_TRNS,    KC_TRNS,    TO(0), TO(0),     TO(0), TO(0),    KC_TRNS,    KC_TRNS, KC_NO//ENC
    ),
    [_MOUSE] = LAYOUT(
     KC_NO,  KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, KC_TRNS,                                 KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO,
     KC_NO,  KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO,
     KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                         KC_TRNS, KC_TRNS,    KC_TRNS,    TO(0), TO(0),     TO(0), TO(0),    KC_TRNS,    KC_TRNS, KC_NO//ENC
    ),
};

// combos definitions
// global combos
const uint16_t PROGMEM combo_DEF_space[] = {L_S_E, DE_Y, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_DEF_enter[] = {L_B_A, L_S_E, COMBO_END};
const uint16_t PROGMEM combo_DEF_tab[] = {L_B_A, DE_R, DE_T, DE_O, COMBO_END};
const uint16_t PROGMEM combo_DEF_bspc[] = {DE_R, L_S_E, COMBO_END};
const uint16_t PROGMEM combo_DEF_del[] = {DE_R, DE_I, COMBO_END};
const uint16_t PROGMEM combo_DEF_shift[] = {DE_R, DE_T, L_N_S, L_S_E, COMBO_END};
const uint16_t PROGMEM combo_DEF_ctrl[] = {L_N_S, L_S_E, COMBO_END};
const uint16_t PROGMEM combo_DEF_alt[] = {L_N_S, DE_I, COMBO_END};
const uint16_t PROGMEM combo_DEF_gui[] = {L_N_S, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_DEF_esc[] = {L_B_A, DE_R, DE_O, COMBO_END};

const uint16_t PROGMEM combo_NUM_enter[] = {DE_1, DE_5, COMBO_END};
const uint16_t PROGMEM combo_NUM_bspc[] = {DE_2, DE_5, COMBO_END};
const uint16_t PROGMEM combo_NUM_del[] = {DE_2, DE_7, COMBO_END};
const uint16_t PROGMEM combo_NUM_shift[] = {NUM_X, DE_3, DE_2, DE_5, COMBO_END};
const uint16_t PROGMEM combo_NUM_ctrl[] = {NUM_X, DE_5, COMBO_END};
const uint16_t PROGMEM combo_NUM_alt[] = {NUM_X, DE_7, COMBO_END};
const uint16_t PROGMEM combo_NUM_gui[] = {NUM_X, DE_6, COMBO_END};
const uint16_t PROGMEM combo_NUM_esc[] = {NUM_Y, DE_3, DE_2, COMBO_END};

const uint16_t PROGMEM combo_FNC_shift[] = {NUM_X, KC_F2, KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_FNC_ctrl[] = {NUM_X, KC_F1, COMBO_END};
const uint16_t PROGMEM combo_FNC_gui[] = {NUM_X, KC_F2, COMBO_END};
const uint16_t PROGMEM combo_FNC_alt[] = {NUM_X, KC_F3, COMBO_END};
const uint16_t PROGMEM combo_FNC_esc[] = {NUM_Y, KC_F2, KC_F3, COMBO_END};

const uint16_t PROGMEM combo_NAV_enter[] = {KC_END, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_NAV_bspc[] = {KC_UP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_NAV_del[] = {KC_UP, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_NAV_shiftL[] = {KC_PGUP, KC_HOME, KC_UP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_NAV_shiftR[] = {KC_PGUP, KC_END, KC_UP, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_NAV_ctrlL[] = {KC_PGUP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_NAV_ctrlR[] = {KC_PGUP, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_NAV_alt[] = {KC_PGUP, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_NAV_gui[] = {KC_PGUP, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo_NAV_esc[] = {KC_PGDN, KC_HOME, KC_UP, COMBO_END};

const uint16_t PROGMEM combo_MSE_enter[] = {KC_BTN1, KC_MS_R, COMBO_END};
const uint16_t PROGMEM combo_MSE_shift[] = {KC_WH_U, KC_BTN2, KC_MS_U, KC_MS_R, COMBO_END};
const uint16_t PROGMEM combo_MSE_ctrl[] = {KC_WH_U, KC_MS_R, COMBO_END};
const uint16_t PROGMEM combo_MSE_alt[] = {KC_WH_U, KC_MS_L, COMBO_END};
const uint16_t PROGMEM combo_MSE_gui[] = {KC_WH_U, KC_MS_D, COMBO_END};
const uint16_t PROGMEM combo_MSE_esc[] = {KC_WH_D, KC_MS_U, KC_BTN1, COMBO_END};
// character combos
const uint16_t PROGMEM combo_b[] = {L_S_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_c[] = {L_S_E, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_d[] = {L_B_A, DE_R, DE_T, COMBO_END};
const uint16_t PROGMEM combo_f[] = {L_B_A, DE_R,  COMBO_END};
const uint16_t PROGMEM combo_g[] = {DE_R, DE_T, COMBO_END};
const uint16_t PROGMEM combo_h[] = {L_S_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_j[] = {DE_T, L_N_S, COMBO_END};
const uint16_t PROGMEM combo_k[] = {DE_Y, DE_O, COMBO_END};
const uint16_t PROGMEM combo_l[] = {L_S_E, DE_Y, DE_I, COMBO_END};
const uint16_t PROGMEM combo_m[] = {DE_Y, DE_I,DE_O, COMBO_END};
const uint16_t PROGMEM combo_n[] = {DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_p[] = {L_S_E, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_q[] = {L_B_A, DE_T, L_N_S, COMBO_END};
const uint16_t PROGMEM combo_u[] = {DE_Y, DE_I, COMBO_END};
const uint16_t PROGMEM combo_v[] = {DE_R, L_N_S, COMBO_END};
const uint16_t PROGMEM combo_w[] = {L_B_A, L_N_S, COMBO_END};
const uint16_t PROGMEM combo_x[] = {DE_R, DE_T, L_N_S, COMBO_END};
const uint16_t PROGMEM combo_z[] = {L_B_A, DE_R, DE_T, L_N_S, COMBO_END};
const uint16_t PROGMEM combo_four[] = {DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_eight[] = {DE_5, DE_6, COMBO_END};
const uint16_t PROGMEM combo_nine[] = {DE_6, DE_7, COMBO_END};
const uint16_t PROGMEM combo_zero[] = {DE_2, DE_3, COMBO_END};
const uint16_t PROGMEM combo_F4[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM combo_F8[] = {KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM combo_F9[] = {KC_F6, KC_F7, COMBO_END};
const uint16_t PROGMEM combo_F0[] = {KC_F2, KC_F3, COMBO_END};
// special char combos
const uint16_t PROGMEM combo_quot[] = {L_B_A, DE_Y, DE_I, COMBO_END};
const uint16_t PROGMEM combo_dot[] = {L_B_A, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_comma[] = {L_B_A, DE_I, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {L_B_A, DE_O, COMBO_END};
const uint16_t PROGMEM combo_exclam[] = {DE_T, DE_I, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {L_B_A, DE_Y, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_adia[] = {L_B_A, KC_ENT, COMBO_END};
const uint16_t PROGMEM combo_odia[] = {DE_O, KC_ENT, COMBO_END};
const uint16_t PROGMEM combo_udia[] = {DE_Y, DE_I,  KC_ENT, COMBO_END};
const uint16_t PROGMEM combo_szett[] = {L_N_S, KC_ENT, COMBO_END};
// layer combos
const uint16_t PROGMEM combo_nav1[] = {DE_R, L_S_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_nav0[] = {KC_LEFT, KC_UP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_mouse1[] = {L_B_A, DE_T, DE_Y, COMBO_END};
const uint16_t PROGMEM combo_mouse0[] = {KC_BTN2, KC_MS_D, KC_BTN1, COMBO_END};
const uint16_t PROGMEM combo_fnc1[] = {OS_SFT, KC_TAB, COMBO_END};

/* const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END}; */
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_four, DE_4),
    COMBO(combo_eight, DE_8),
    COMBO(combo_nine, DE_9),
    COMBO(combo_zero, DE_0),
    COMBO(combo_adia, DE_ADIA),
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
    COMBO(combo_odia, DE_ODIA),
    COMBO(combo_p, DE_P),
    COMBO(combo_q, DE_Q),
    COMBO(combo_szett, DE_SS),
    COMBO(combo_u, DE_U),
    COMBO(combo_udia, DE_UDIA),
    COMBO(combo_v, DE_V),
    COMBO(combo_w, DE_W),
    COMBO(combo_x, DE_X),
    COMBO(combo_z, DE_Z),
    COMBO(combo_F4, KC_F4),
    COMBO(combo_F8, KC_F8),
    COMBO(combo_F9, KC_F9),
    COMBO(combo_F0, KC_F10),
    COMBO(combo_quot, DE_QUOT),
    COMBO(combo_dot, DE_DOT),
    COMBO(combo_comma, DE_COMM),
    COMBO(combo_slash, DE_SLSH),
    COMBO(combo_exclam, DE_EXLM),
    COMBO(combo_caps, KC_CAPS),
    COMBO(combo_nav1, TO(_NAV)),
    COMBO(combo_nav0, TO(_DEF)),
    COMBO(combo_mouse1, TO(_MOUSE)),
    COMBO(combo_mouse0, TO(_DEF)),
    COMBO(combo_fnc1, OSL(_FNC)),
    COMBO(combo_DEF_space, KC_SPC),
    COMBO(combo_DEF_enter, KC_ENT),
    COMBO(combo_DEF_tab, KC_TAB),
    COMBO(combo_DEF_bspc, KC_BSPC),
    COMBO(combo_DEF_del, KC_DEL),
    COMBO(combo_DEF_shift, OS_SFT),
    COMBO(combo_DEF_ctrl, OS_CTL),
    COMBO(combo_DEF_alt, OS_ALT),
    COMBO(combo_DEF_gui, OS_GUI),
    COMBO(combo_DEF_esc, KC_ESC),
    COMBO(combo_NUM_enter, KC_ENT),
    COMBO(combo_NUM_bspc, KC_BSPC),
    COMBO(combo_NUM_del, KC_DEL),
    COMBO(combo_NUM_shift, OS_SFT),
    COMBO(combo_NUM_ctrl, OS_CTL),
    COMBO(combo_NUM_alt, OS_ALT),
    COMBO(combo_NUM_gui, OS_GUI),
    COMBO(combo_NUM_esc, KC_ESC),
    COMBO(combo_FNC_shift, OS_SFT),
    COMBO(combo_FNC_ctrl, OS_CTL),
    COMBO(combo_FNC_alt, OS_ALT),
    COMBO(combo_FNC_gui, OS_GUI),
    COMBO(combo_FNC_esc, KC_ESC),
    COMBO(combo_NAV_enter, KC_ENT),
    COMBO(combo_NAV_bspc, KC_BSPC),
    COMBO(combo_NAV_del, KC_DEL),
    COMBO(combo_NAV_shiftL, OS_SFT),
    COMBO(combo_NAV_shiftR, OS_SFT),
    COMBO(combo_NAV_ctrlL, OS_CTL),
    COMBO(combo_NAV_ctrlR, OS_CTL),
    COMBO(combo_NAV_alt, OS_ALT),
    COMBO(combo_NAV_gui, OS_GUI),
    COMBO(combo_NAV_esc, KC_ESC),
    COMBO(combo_MSE_enter, KC_ENT),
    COMBO(combo_MSE_shift, OS_SFT),
    COMBO(combo_MSE_ctrl, OS_CTL),
    COMBO(combo_MSE_alt, OS_ALT),
    COMBO(combo_MSE_gui, OS_GUI),
    COMBO(combo_MSE_esc, KC_ESC),
};

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
        oled_write_P(PSTR("\nARTSEYIO: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _DEF:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case _BRA:
                oled_write_P(PSTR("Braces\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbols\n"), false);
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
        uint8_t osm_mod = mod_config(get_oneshot_mods());
        oled_write_P(PSTR("\nOSMs: "), false);
        if (osm_mod > 0) {
            oled_write_P(PSTR("^"), true);
            if (osm_mod & MOD_MASK_SHIFT) { // if shift is held, flash rather than compile
                oled_write_P(PSTR("S"), true);
            }
            if (osm_mod & MOD_MASK_CTRL) { // if shift is held, flash rather than compile
                oled_write_P(PSTR("C"), true);
            }
            if (osm_mod & MOD_MASK_ALT) { // if shift is held, flash rather than compile
                oled_write_P(PSTR("A"), true);
            }
            if (osm_mod & MOD_MASK_GUI) { // if shift is held, flash rather than compile
                oled_write_P(PSTR("G"), true);
            }
            oled_write_P(PSTR("   "), false);
        }
        else {
                oled_write_P(PSTR("     "), false);
        }
        oled_write_P(PSTR("\n     "), false);
        if (led_usb_state.caps_lock)
            oled_write_P(PSTR(" CAPS-LOCK "), true);
        else
            oled_write_P(PSTR("           "), false);
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
