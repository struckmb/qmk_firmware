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
    _BASE = 0,
    _NUM,
    _FN,
    _NAV,
    _CMD,
};

#define KEY_ALT OSM(MOD_LALT)
#define KEY_CTL OSM(MOD_LCTL)
#define KEY_DIA S(ALGR(DE_UDIA))
#define KEY_GUI OSM(MOD_LGUI)
#define SHIFT OSM(MOD_LSFT)
/* #define KEY_FN  KC_NO */

enum custom_keycodes {
    OS_KILL = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
            RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
            OS_KILL, DE_A,    DE_S,    DE_E,    DE_T,    KC_NO,                                 KC_NO,   DE_N,    DE_I,    DE_O,    DE_P,  OS_KILL,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,  KEY_DIA,    KEY_DIA,   SHIFT, KC_NO,     KC_NO, KC_NO,     KC_SPC,    KC_NO,   KC_NO//ENC
            ),
    [_NUM] = LAYOUT(
            RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_1,    DE_2,    DE_3,    DE_4,    KC_NO,                                 KC_NO,   DE_7,    DE_8,    DE_9,    DE_0,    KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,  KEY_DIA,    KC_NO,     SHIFT, KC_NO,     KC_NO, KC_NO,     KC_SPC,    KC_NO,   KC_NO//ENC
            ),
    [_FN] = LAYOUT(
            RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,                                 KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,  KEY_DIA,    KC_NO,     SHIFT, KC_NO,     KC_NO, KC_NO,     KC_SPC,    KC_NO,   KC_NO//ENC
            ),
    [_NAV] = LAYOUT(
            RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   KC_HOME, KC_NO,   KC_NO,   KC_END,  KC_NO,                                 KC_NO,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,  KEY_DIA,    KC_NO,     SHIFT, KC_NO,     KC_NO, KC_NO,     KC_SPC,    KC_NO,   KC_NO//ENC
            ),
    [_CMD] = LAYOUT(
            RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   KC_ESC,  KEY_ALT, KEY_GUI, KEY_CTL, KC_NO,                                 KC_NO,   KC_HOME, KC_PSCR, KC_MENU, KC_END,  KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,  KEY_DIA,    KC_NO,     SHIFT, KC_NO,     KC_NO, KC_NO,     KC_SPC,    KC_NO,   KC_NO//ENC
            ),
};

const uint16_t PROGMEM combo_alpha_b[] = {DE_T, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_c[] = {DE_S, DE_T, COMBO_END};
const uint16_t PROGMEM combo_alpha_d[] = {DE_S, DE_E, COMBO_END};
const uint16_t PROGMEM combo_alpha_f[] = {DE_A, DE_T, COMBO_END};
const uint16_t PROGMEM combo_alpha_g[] = {DE_T, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_h[] = {DE_N, DE_I, COMBO_END};
const uint16_t PROGMEM combo_alpha_j[] = {DE_S, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_k[] = {DE_S, DE_I, COMBO_END};
const uint16_t PROGMEM combo_alpha_l[] = {DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_m[] = {DE_N, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_q[] = {DE_A, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_r[] = {DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_alpha_u[] = {DE_N, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_v[] = {DE_T, DE_I, COMBO_END};
const uint16_t PROGMEM combo_alpha_w[] = {DE_A, DE_S, COMBO_END};
const uint16_t PROGMEM combo_alpha_x[] = {DE_A, DE_E, COMBO_END};
const uint16_t PROGMEM combo_alpha_y[] = {DE_E, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_z[] = {DE_A, DE_I, COMBO_END};

const uint16_t PROGMEM combo_alpha_at[] = {DE_I, DE_P, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_colon[] = {DE_O, DE_P, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_comma[] = {DE_E, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_dblquot[] = {DE_E, DE_P, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_dot[] = {DE_S, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_exclamation[] = {DE_I, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_gt[] = {DE_S, DE_O, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_leftbrace[] = {DE_A, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_leftbracket[] = {DE_A, DE_O, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_lt[] = {DE_E, DE_P, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_minus[] = {DE_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_question[] = {DE_A, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_rightbrace[] = {DE_S, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_rightbracket[] = {DE_S, DE_P, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_semicolon[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_slash[] = {DE_A, DE_P, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_alpha_underscore[] = {DE_E, DE_O, SHIFT, COMBO_END};

const uint16_t PROGMEM combo_alpha_bspc[] = {DE_T, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_enter[] = {DE_N, DE_I, DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_tab[] = {DE_A, DE_S, DE_E, DE_T, COMBO_END};

const uint16_t PROGMEM combo_fn_f5[] = {KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f6[] = {KC_F7, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f11[] = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM combo_fn_f12[] = {KC_F8, KC_F9, COMBO_END};

const uint16_t PROGMEM combo_num_5[] = {DE_3, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_6[] = {DE_7, DE_8, COMBO_END};
const uint16_t PROGMEM combo_num_hash[] = {DE_3, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_dollar[] = {DE_4, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_percent[] = {DE_3, DE_4, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_caret[] = {DE_7, DE_8, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_ampersand[] = {DE_7, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_asterisk[] = {DE_8, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_lparen[] = {DE_9, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_rparen[] = {DE_0, SHIFT, COMBO_END};

const uint16_t PROGMEM combo_num_grave[] = {DE_1, DE_7, COMBO_END};
const uint16_t PROGMEM combo_num_tilde[] = {DE_1, DE_7, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_exclam[] = {DE_8, DE_0, COMBO_END};
const uint16_t PROGMEM combo_num_at[] = {DE_8, DE_0, SHIFT, COMBO_END};
const uint16_t PROGMEM combo_num_euro[] = {DE_2, DE_3, COMBO_END};
const uint16_t PROGMEM combo_num_cent[] = {DE_2, DE_3, SHIFT, COMBO_END};

const uint16_t PROGMEM combo_num_enter[] = {DE_7, DE_8, DE_9, DE_0, COMBO_END};
const uint16_t PROGMEM combo_num_tab[] = {DE_1, DE_2, DE_3, DE_4, COMBO_END};

const uint16_t PROGMEM combo_cmd_altctl[] = {KEY_ALT, KEY_CTL, COMBO_END};
const uint16_t PROGMEM combo_cmd_altctlgui[] = {KEY_ALT, KEY_CTL, KEY_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_altgui[] = {KEY_ALT, KEY_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_ctlgui[] = {KEY_CTL, KEY_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_salt[] = {SHIFT, KEY_ALT, COMBO_END};
const uint16_t PROGMEM combo_cmd_saltctl[] = {SHIFT, KEY_ALT, KEY_CTL, COMBO_END};
const uint16_t PROGMEM combo_cmd_saltctlgui[] = {SHIFT, KEY_ALT, KEY_CTL, KEY_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_saltgui[] = {SHIFT, KEY_ALT, KEY_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_sctl[] = {SHIFT, KEY_CTL, COMBO_END};
const uint16_t PROGMEM combo_cmd_sctlgui[] = {SHIFT, KEY_CTL, KEY_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_sgui[] = {SHIFT, KEY_GUI, COMBO_END};

const uint16_t PROGMEM combo_nav_pageup[] = {KC_LEFT, KC_UP, COMBO_END};
const uint16_t PROGMEM combo_nav_pagedown[] = {KC_DOWN, KC_RGHT, COMBO_END};

const uint16_t PROGMEM combo_alpha_to_num[] = {DE_A, DE_T, DE_N, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_to_numosl[] = {DE_N, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_to_cmd[] = {DE_S, DE_E, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_to_fn[] = {DE_A, DE_E, DE_I, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_to_nav[] = {DE_S, DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_num_to_alpha[] = {DE_1, DE_4, DE_7, DE_0, COMBO_END};
const uint16_t PROGMEM combo_fn_to_alpha[] = {DE_1, DE_4, DE_7, DE_0, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_alpha_b, DE_B),
    COMBO(combo_alpha_c, DE_C),
    COMBO(combo_alpha_d, DE_D),
    COMBO(combo_alpha_f, DE_F),
    COMBO(combo_alpha_g, DE_G),
    COMBO(combo_alpha_h, DE_H),
    COMBO(combo_alpha_j, DE_J),
    COMBO(combo_alpha_k, DE_K),
    COMBO(combo_alpha_l, DE_L),
    COMBO(combo_alpha_m, DE_M),
    COMBO(combo_alpha_q, DE_Q),
    COMBO(combo_alpha_r, DE_R),
    COMBO(combo_alpha_u, DE_U),
    COMBO(combo_alpha_v, DE_V),
    COMBO(combo_alpha_w, DE_W),
    COMBO(combo_alpha_x, DE_X),
    COMBO(combo_alpha_y, DE_Y),
    COMBO(combo_alpha_z, DE_Z),
    COMBO(combo_alpha_at, DE_AT),
    COMBO(combo_alpha_colon, DE_COLN),
    COMBO(combo_alpha_comma, DE_COMM),
    COMBO(combo_alpha_dblquot, DE_DQUO),
    COMBO(combo_alpha_dot, DE_DOT),
    COMBO(combo_alpha_exclamation, DE_EXLM),
    COMBO(combo_alpha_gt, DE_RABK),
    COMBO(combo_alpha_leftbrace, DE_LCBR),
    COMBO(combo_alpha_leftbracket, DE_LBRC),
    COMBO(combo_alpha_lt, DE_LABK),
    COMBO(combo_alpha_minus, DE_MINS),
    COMBO(combo_alpha_question, DE_QUES),
    COMBO(combo_alpha_rightbrace, DE_RCBR),
    COMBO(combo_alpha_rightbracket, DE_RBRC),
    COMBO(combo_alpha_semicolon, DE_SCLN),
    COMBO(combo_alpha_slash, DE_SLSH),
    COMBO(combo_alpha_underscore, DE_UNDS),
    COMBO(combo_alpha_bspc, KC_BSPC),
    COMBO(combo_alpha_enter, KC_ENT),
    COMBO(combo_alpha_tab, KC_TAB),
    COMBO(combo_cmd_altctl,     OSM(MOD_LALT|MOD_LCTL)),
    COMBO(combo_cmd_altctlgui,  OSM(MOD_LALT|MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_altgui,     OSM(MOD_LALT|MOD_LGUI)),
    COMBO(combo_cmd_ctlgui,     OSM(MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_salt,       OSM(MOD_LSFT|MOD_LALT)),
    COMBO(combo_cmd_saltctl,    OSM(MOD_LSFT|MOD_LALT|MOD_LCTL)),
    COMBO(combo_cmd_saltctlgui, OSM(MOD_LSFT|MOD_LALT|MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_saltgui,    OSM(MOD_LSFT|MOD_LALT|MOD_LGUI)),
    COMBO(combo_cmd_sctl,       OSM(MOD_LSFT|MOD_LCTL)),
    COMBO(combo_cmd_sctlgui,    OSM(MOD_LSFT|MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_sgui,       OSM(MOD_LSFT|MOD_LGUI)),
    COMBO(combo_num_5, DE_5),
    COMBO(combo_num_6, DE_6),
    COMBO(combo_num_ampersand, DE_AMPR),
    COMBO(combo_num_asterisk, DE_ASTR),
    COMBO(combo_num_at, DE_AT),
    COMBO(combo_num_caret, DE_CIRC),
    COMBO(combo_num_dollar, DE_DLR),
    COMBO(combo_num_exclam, DE_EXLM),
    COMBO(combo_num_hash, DE_HASH),
    COMBO(combo_num_lparen, DE_LPRN),
    COMBO(combo_num_percent, DE_PERC),
    COMBO(combo_num_rparen, DE_RPRN),
    COMBO(combo_num_enter, KC_ENT),
    COMBO(combo_num_tab, KC_TAB),
    COMBO(combo_nav_pageup, KC_PGUP),
    COMBO(combo_nav_pagedown, KC_PGDN),
    COMBO(combo_alpha_to_cmd, OSL(_CMD)),
    COMBO(combo_alpha_to_fn, OSL(_FN)),
    COMBO(combo_alpha_to_nav, OSL(_NAV)),
    COMBO(combo_alpha_to_num, TO(_NUM)),
    COMBO(combo_alpha_to_numosl, OSL(_NUM)),
    COMBO(combo_num_to_alpha, TO(_BASE)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_KILL:
            if (record->event.pressed) clear_oneshot_mods();
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    default_layer_set(1UL);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("  small   ASETNIOP   "), true);
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
        uint8_t activeLayer = get_highest_layer(layer_state);
        switch (activeLayer) {
            case _BASE: oled_write_P(PSTR("Alpha"), false); break;
            case _NUM: oled_write_P(PSTR("Numbers"), false); break;
            case _FN:  oled_write_P(PSTR("Fn-Keys"), false); break;
            case _NAV: oled_write_P(PSTR("Navigation"), false); break;
            case _CMD: oled_write_P(PSTR("Command"), false); break;
            default:
                oled_write_P(PSTR("Undefined"), true);
                break;
        }

        // Write Status to OLEDs
        oled_write_P(PSTR("\nWPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
        uint8_t osm_mod = mod_config(get_oneshot_mods());
        uint8_t all_mod = mod_config(get_mods()|get_oneshot_mods());
        oled_write_P(PSTR(" MODs: "), false);
        if (all_mod & MOD_MASK_SHIFT)
            oled_write_P(PSTR("S"), osm_mod & MOD_MASK_SHIFT);
        else oled_write_P(PSTR("_"), false);
        if (all_mod & MOD_MASK_CTRL)
            oled_write_P(PSTR("C"), osm_mod & MOD_MASK_CTRL);
        else oled_write_P(PSTR("_"), false);
        if (all_mod & MOD_MASK_ALT)
            oled_write_P(PSTR("A"), osm_mod & MOD_MASK_ALT);
        else oled_write_P(PSTR("_"), false);
        if (all_mod & MOD_MASK_GUI)
            oled_write_P(PSTR("M"), osm_mod & MOD_MASK_GUI);
        else oled_write_P(PSTR("_"), false);

        if (host_keyboard_led_state().caps_lock)
            oled_write_P(PSTR("\n CAPS "), true);
        else
            oled_write_P(PSTR("\n      "), false);
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
