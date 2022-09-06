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
    // Default layers
    _BASE = 0,
    _A,
    _S,
    _E,
    _T,
    _N,
    _I,
    _O,
    _P,
    _NUM,
    _1,
    _2,
    _3,
    _4,
    _7,
    _8,
    _9,
    _0,
};

#define OSM_SFT OSM(MOD_LSFT)
#define KEY_DIA S(ALGR(DE_UDIA))
#define KEY_A   LT(_A, DE_A)
#define KEY_S   LT(_S, DE_S)
#define KEY_E   LT(_E, DE_E)
#define KEY_T   LT(_T, DE_T)
#define KEY_N   LT(_N, DE_N)
#define KEY_I   LT(_I, DE_I)
#define KEY_O   LT(_O, DE_O)
#define KEY_P   LT(_P, DE_P)
#define KEY_1   LT(_1, DE_1)
#define KEY_2   LT(_2, DE_2)
#define KEY_3   LT(_3, DE_3)
#define KEY_4   LT(_4, DE_4)
#define KEY_7   LT(_7, DE_7)
#define KEY_8   LT(_8, DE_8)
#define KEY_9   LT(_9, DE_9)
#define KEY_0   LT(_0, DE_0)

#define KEY_FN  KC_NO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   KEY_A,   KEY_S,   KEY_E,   KEY_T,   KC_NO,                                 KC_NO,   KEY_N,   KEY_I,   KEY_O,   KEY_P,   KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,  KEY_DIA,    OSM_SFT,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_SPC,    KC_NO,   KC_NO//ENC
            ),
    [_A] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   XXXXXXX, DE_W,    DE_X,    DE_F,    KC_NO,                                 KC_NO,   DE_Q,    DE_Z,    DE_LPRN, DE_QUES, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_S] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_W,    XXXXXXX, DE_D,    DE_C,    KC_NO,                                 KC_NO,   DE_J,   DE_K,   DE_DOT,   DE_RPRN,   KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_E] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_X,    DE_D,    XXXXXXX, DE_R,    KC_NO,                                 KC_NO,   DE_Y,   DE_COMM,   DE_MINS,   DE_QUOT,   KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_T] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_F,    DE_C,    DE_R,    XXXXXXX, KC_NO,                                 KC_NO,   DE_B,   DE_V,   DE_G,   KC_BSPC,   KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_N] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_Q,    DE_J,    DE_Y,    DE_B,    KC_NO,                                 KC_NO,   XXXXXXX, DE_H,    DE_U,    DE_M,    KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_I] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_Z,    DE_K,    DE_COMM, DE_V,    KC_NO,                                 KC_NO,   DE_H,    XXXXXXX, DE_L,    DE_EXLM, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_O] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_LPRN, DE_DOT,  DE_MINS, DE_G,    KC_NO,                                 KC_NO,   DE_U,    DE_L,    XXXXXXX, DE_SCLN, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_P] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_QUES, DE_RPRN, DE_QUOT, KC_BSPC, KC_NO,                                 KC_NO,   DE_M,    DE_EXLM, DE_SCLN, XXXXXXX, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),

    [_NUM] = LAYOUT(
            RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   KEY_1,   KEY_2,   KEY_3,   KEY_4,   KC_NO,                                 KC_NO,   KEY_7,   KEY_8,   KEY_9,   KEY_0,   KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,  KEY_DIA,    OSM_SFT,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_SPC,    KC_NO,   KC_NO//ENC
            ),
    [_1] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   XXXXXXX, KC_NO,   DE_GRV,  DE_LBRC, KC_NO,                                 KC_NO,   KC_NO,   DE_EXLM, DE_LPRN, DE_QUES, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_2] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   KC_NO,   XXXXXXX, DE_MINS, KEY_FN,  KC_NO,                                 KC_NO,   KC_END,  DE_EQL,  DE_DOT,  DE_RPRN, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_3] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_GRV,  DE_MINS, XXXXXXX, DE_5,    KC_NO,                                 KC_NO,   KC_HOME, DE_COMM, DE_MINS, DE_QUOT, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_4] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_LBRC, KEY_FN,  DE_5,    XXXXXXX, KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_7] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   KC_NO,   KC_END,  KC_HOME, KC_NO,   KC_NO,                                 KC_NO,   XXXXXXX, DE_6,    KEY_FN,  DE_RBRC, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_8] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_EXLM, DE_EQL,  DE_COMM, KC_NO,   KC_NO,                                 KC_NO,   DE_6,    XXXXXXX, DE_EQL,  KC_NO,   KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_9] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_LPRN, DE_DOT,  DE_MINS, KC_NO,   KC_NO,                                 KC_NO,   KEY_FN,  DE_MINS, XXXXXXX, DE_SCLN, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
    [_0] = LAYOUT(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            KC_NO,   DE_QUES, DE_RPRN, DE_QUOT, KC_BSPC, KC_NO,                                 KC_NO,   DE_RBRC, KC_NO,   DE_SCLN, XXXXXXX, KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO ,KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_TRNS,   KC_NO, KC_NO,     KC_NO, KC_NO,     KC_TRNS,   KC_NO,   KC_NO//ENC
            ),
};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*     } */
/*     return true; */
/* } */

const uint16_t PROGMEM combo_alpha_enter[] = {KEY_N, KEY_I, KEY_O, KEY_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_tab[] = {KEY_A, KEY_S, KEY_E, KEY_T, COMBO_END};
const uint16_t PROGMEM combo_alpha_to_num[] = {KEY_A, KEY_T, KEY_N, KEY_P, COMBO_END};
const uint16_t PROGMEM combo_num_enter[] = {KEY_7, KEY_8, KEY_9, KEY_0, COMBO_END};
const uint16_t PROGMEM combo_num_tab[] = {KEY_1, KEY_2, KEY_3, KEY_4, COMBO_END};
const uint16_t PROGMEM combo_num_to_alpha[] = {KEY_1, KEY_4, KEY_7, KEY_0, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_alpha_tab, KC_TAB),
    COMBO(combo_alpha_enter, KC_ENT),
    COMBO(combo_alpha_to_num, DF(_NUM)),
    COMBO(combo_num_tab, KC_TAB),
    COMBO(combo_num_enter, KC_ENT),
    COMBO(combo_num_to_alpha, DF(_BASE)),
};

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
            case _BASE: oled_write_P(PSTR("ASETNIOP"), false); break;
            case _A: oled_write_P(PSTR("*SETNIOP"), false); break;
            case _S: oled_write_P(PSTR("A*ETNIOP"), false); break;
            case _E: oled_write_P(PSTR("AS*TNIOP"), false); break;
            case _T: oled_write_P(PSTR("ASE*NIOP"), false); break;
            case _N: oled_write_P(PSTR("ASET*IOP"), false); break;
            case _I: oled_write_P(PSTR("ASETN*OP"), false); break;
            case _O: oled_write_P(PSTR("ASETNI*P"), false); break;
            case _P: oled_write_P(PSTR("ASETNIO*"), false); break;
            case _NUM: oled_write_P(PSTR("12347890"), false); break;
            case _1: oled_write_P(PSTR("*2347890"), false); break;
            case _2: oled_write_P(PSTR("1*347890"), false); break;
            case _3: oled_write_P(PSTR("12*47890"), false); break;
            case _4: oled_write_P(PSTR("123*7890"), false); break;
            case _7: oled_write_P(PSTR("1234*890"), false); break;
            case _8: oled_write_P(PSTR("12347*90"), false); break;
            case _9: oled_write_P(PSTR("123478*0"), false); break;
            case _0: oled_write_P(PSTR("1234789*"), false); break;
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
