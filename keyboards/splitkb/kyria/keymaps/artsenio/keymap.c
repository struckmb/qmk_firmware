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
    _MINI = 0,
    _BIG,
    _QWER,
    _BONE,
    _COLE,
    _MAX_DFL,
    // Additional mini and big layers
    _APAR, // braces
    _ASYM, // symbols
    _ANUM, // key pad
    _AFNC, // function keys
    _ACUS, // custom keys
    _ANAV, // navigation
    _AMSE,  // mouse adjustment
    // Additional 40p layers
    _CSYM, // symbols (neo based)
    _CNAV, // navigation and key pad
    _CMFN, // media and function keys
    _CADJ  // kb adjustment
};

// Aliases for 40p default layers
#define BONE     DF(_BONE)
#define COLE     DF(_COLE)
#define QWER     DF(_QWER)

// Aliases for base layers
#define ALCU_S   LT(_ACUS, DE_S)
#define ALNU_O   LT(_ANUM, DE_O)
#define ALPA_A   LT(_APAR, DE_A)
#define ALSY_E   LT(_ASYM, DE_E)
#define AOS_SY   OSL(_ASYM)
#define CL_ADJ   MO(_CADJ)
#define CL_MFN   MO(_CMFN)
#define CL_NAV   MO(_CNAV)

// mod aliases
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define OS_ALT   OSM(MOD_LALT)
#define OS_CTL   OSM(MOD_LCTL)
#define OS_GUI   OSM(MOD_LGUI)
#define OS_SFT   OSM(MOD_LSFT)
#define SFT_BSP  MT(MOD_LSFT, KC_BSPC)
#define SFT_DEL  MT(MOD_RSFT, KC_DEL)

//#define CL_SYM   MO(_CSYM)
#define MFN_SPC  LT(_CMFN, KC_SPC)
#define NUM_SPC  LT(_ANUM, KC_SPC)
#define SYM_ENT  LT(_CSYM, KC_ENT)
#define SYM_SPC  LT(_CSYM, KC_SPC)

// Aliases for some specials
#define SY_COPY  C(KC_INS)
#define SY_CUT   S(KC_DEL)
#define SY_CENT  ALGR(KC_C)
#define SY_HELL  ALGR(KC_DOT)
#define SY_PASTE S(KC_INS)
#define SY_REDO  RCS(DE_Z)
#define SY_UNDO  C(DE_Z)

enum custom_keycodes {
    TO_DFL = SAFE_RANGE,
    WR_DFL,
    INC_DFL,
    DEC_DFL,
    OS_KILL,
    SY_CIRC, // caret (non dead)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MINI] = LAYOUT(
            OS_KILL, ALCU_S,  DE_T,    DE_R,    ALPA_A,  KC_NO,                                   KC_NO,   ALPA_A,  DE_R,    DE_T,    ALCU_S,  OS_KILL,
            KC_NO,   ALNU_O,  DE_I,    DE_N,    ALSY_E,  KC_NO,                                   KC_NO,   ALSY_E,  DE_N,    DE_I,    ALNU_O,  KC_NO,
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   CL_ADJ,KC_NO,     KC_NO,CL_ADJ, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                 KC_NO,   KC_NO,     KC_NO,       KC_NO, KC_NO,     KC_NO, KC_NO,     KC_NO,     KC_NO,   KC_NO//ENC
            ),
    [_BIG] = LAYOUT(
            OS_KILL, ALCU_S,  DE_T,    DE_R,    ALPA_A,  DE_SS,                                   DE_SS,   ALPA_A,  DE_R,    DE_T,    ALCU_S,  OS_KILL,
            CTL_ESC, ALNU_O,  DE_I,    DE_N,    ALSY_E,  OS_SFT,                                  OS_SFT,  ALSY_E,  DE_N,    DE_I,    ALNU_O,  CTL_ESC,
            OS_SFT,  OS_CTL,  KC_BSPC, KC_DEL,  DE_EQL,  KC_TAB,  CL_ADJ,KC_NO,     KC_NO,CL_ADJ, KC_TAB,  DE_EQL,  KC_DEL,  KC_BSPC, OS_CTL,  OS_SFT,
                                KC_NO,   KC_NO,   AOS_SY,    KC_ENT,   NUM_SPC,     NUM_SPC, KC_ENT,   AOS_SY,   KC_NO,   KC_NO//ENC
            ),
    [_QWER] = LAYOUT(
            KC_TAB,  DE_Q,   DE_W,    DE_E,    DE_R,    DE_T,                                     DE_Z,   DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
            CTL_ESC, DE_A,   DE_S,    DE_D,    DE_F,    DE_G,                                     DE_H,   DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
            SFT_BSP, DE_Y,   DE_X,    DE_C,    DE_V,    DE_B,  CL_ADJ,KC_CAPS,     CL_MFN,CL_ADJ, DE_N,   DE_M, DE_COMM , DE_DOT,    DE_SS,   SFT_DEL,
                                SY_COPY, SY_PASTE,  CL_NAV,   SYM_ENT,MFN_SPC,     CL_ADJ, SYM_SPC,  CL_NAV,  KC_APP, KC_PSCR//ENC
            ),
    [_BONE] = LAYOUT(
            KC_TAB,  DE_J,   DE_D,    DE_U,    DE_A,    DE_X,                                     DE_P,   DE_H,    DE_L,    DE_M,    DE_W,    DE_SS,
            CTL_ESC, DE_C,   DE_T,    DE_I,    DE_E,    DE_O,                                     DE_B,   DE_N,    DE_R,    DE_S,    DE_G,    DE_Q,
            SFT_BSP, DE_F,   DE_V, DE_UDIA, DE_ADIA, DE_ODIA,  CL_ADJ,KC_CAPS,     CL_MFN,CL_ADJ, DE_Y,   DE_Z, DE_COMM,    DE_DOT,  DE_K,    SFT_DEL,
                                SY_COPY, SY_PASTE,  CL_NAV,   SYM_ENT,MFN_SPC,     CL_ADJ,SYM_SPC,   CL_NAV,  KC_APP, KC_PSCR//ENC
    ),
    [_COLE] = LAYOUT(
            KC_TAB,  DE_Q,   DE_W,    DE_F,    DE_P,    DE_B,                                     DE_J,   DE_L,    DE_U,    DE_Y,    DE_ODIA, DE_UDIA,
            CTL_ESC, DE_A,   DE_R,    DE_S,    DE_T,    DE_G,                                     DE_M,   DE_N,    DE_E,    DE_I,    DE_O,    DE_ADIA,
            SFT_BSP, DE_Z,   DE_X,    DE_C,    DE_D,    DE_V,  CL_ADJ,KC_CAPS,     CL_MFN,CL_ADJ, DE_K,   DE_H,    DE_COMM, DE_DOT,  DE_SS,   SFT_DEL,
                                SY_COPY, SY_PASTE,  CL_NAV,   SYM_ENT,MFN_SPC,     CL_ADJ,SYM_SPC,  CL_NAV,  KC_APP, KC_PSCR//ENC
    ),
    [_APAR] = LAYOUT(
            KC_TRNS,DE_LCBR, DE_LBRC, DE_LPRN, KC_NO,   KC_TRNS,                                 KC_TRNS, KC_TRNS, DE_LPRN, DE_LBRC, DE_LCBR, KC_NO,
            KC_TRNS,DE_RCBR, DE_RBRC, DE_RPRN, KC_NO,   KC_TRNS,                                 KC_TRNS, KC_NO,   DE_RPRN, DE_RBRC, DE_RCBR, KC_TRNS,
            KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
            ),
    [_ASYM] = LAYOUT(
            KC_TRNS,DE_BSLS, DE_HASH, DE_AMPR, DE_EXLM, KC_NO,                                   KC_NO,   DE_EXLM, DE_AMPR, DE_HASH, DE_BSLS, KC_NO,
            KC_TRNS,DE_PLUS, DE_MINS, DE_QUES, KC_TRNS, DE_DQUO,                                 DE_DQUO, KC_TRNS, DE_QUES, DE_MINS, DE_PLUS, KC_TRNS,
            KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,   KC_TRNS,   TO_DFL, TO_DFL,     TO_DFL, TO_DFL,   KC_TRNS,   KC_TRNS, KC_NO//ENC
            ),
    [_ANUM] = LAYOUT(
            QK_RBT, KC_BSPC, DE_1,    DE_2,    DE_3,    DE_PLUS,                                 DE_PLUS, DE_1,    DE_2,    DE_3,    KC_BSPC, QK_RBT,
            KC_TRNS,TO_DFL,  DE_4,    DE_5,    DE_6,    DE_MINS,                                 DE_MINS, DE_4,    DE_5,    DE_6,    TO_DFL,  KC_TRNS,
            KC_TRNS,KC_TRNS, DE_7,    DE_8,    DE_9,    KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, DE_7,    DE_8,    DE_9,    KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
            ),
    [_AFNC] = LAYOUT(
            KC_NO,  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F10,                                  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_NO,
            KC_TRNS,KC_F12,  KC_F4,   KC_F5,   KC_F6,   KC_F11,                                  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F12,  KC_TRNS,
            KC_TRNS,KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_NO, KC_NO,     KC_NO, KC_NO, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_TRNS ,KC_TRNS,
                                KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
            ),
    [_ACUS] = LAYOUT(
            KC_NO,  KC_NO,   KC_NO,   KC_PWR,  KC_APP,  KC_NO,                                   KC_NO,   KC_APP,  KC_PWR,  KC_NO,   KC_NO,   KC_NO,
            KC_TRNS,KC_NO,   KC_NO,   KC_INS,  KC_PSCR, KC_NO,                                   KC_NO,   KC_PSCR, KC_INS,  KC_NO,   KC_NO,   KC_TRNS,
            KC_TRNS,KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS ,KC_TRNS,
                                KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
            ),
    [_ANAV] = LAYOUT(
            KC_NO,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS,                                 KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO,
            KC_TRNS,KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,                                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
            KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
            ),
    [_AMSE] = LAYOUT(
            KC_NO,  KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, KC_TRNS,                                 KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO,
            KC_TRNS,KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS,
            KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC
            ),
    [_CSYM] = LAYOUT(
            OS_KILL, SY_HELL, DE_UNDS, DE_LBRC, DE_RBRC, SY_CIRC,                                            DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_EURO,
            OS_CTL,  DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                            DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
            OS_GUI,  DE_HASH, DE_DLR , DE_PIPE, SY_TILD, SY_BKTK, _______, _______,        _______, _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______,
                               SY_CUT, DE_CIRC,      DE_TILD,     KC_TRNS, _______,        _______, KC_TRNS,     DE_GRV,       DE_ACUT, _______
    ),
    [_CNAV] = LAYOUT(
            OS_KILL, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_INS,                                             DE_ASTR, DE_7,    DE_8,    DE_9,    DE_SLSH, DE_SCLN,
            OS_ALT,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                                             DE_0,    DE_4,    DE_5,    DE_6,    DE_DOT,  DE_COLN,
            OS_SFT,  KC_ESC,  SY_UNDO, SY_REDO, KC_ENT,  KC_PGDN, KC_WHOM, KC_NUM,         _______, _______, DE_PLUS, DE_1,    DE_2,    DE_3,    DE_COMM, DE_MINS,
                               SY_CUT, _______,     KC_TRNS,      KC_WBAK, KC_WFWD,        _______, _______,     KC_TRNS,      _______, _______
    ),
    [_CMFN] = LAYOUT(
            _______, XXXXXXX, XXXXXXX, KC_VOLU, KC_MUTE, XXXXXXX,                                            XXXXXXX, KC_F7 , KC_F8, KC_F9, KC_F10, XXXXXXX,
            _______, XXXXXXX, KC_MPRV, KC_VOLD, KC_MPLY, KC_MNXT,                                            XXXXXXX, KC_F4 , KC_F5, KC_F6, KC_F11, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES, XXXXXXX, _______, KC_PAUS,        KC_TRNS, _______, XXXXXXX, KC_F1 , KC_F2, KC_F3, KC_F12, _______,
                               _______, _______,     _______,      _______, KC_TRNS,        _______, _______,    _______,     KC_PWR, KC_MUTE
    ),
    [_CADJ] = LAYOUT(
            RGB_VAI, KC_WH_U, KC_WBAK, KC_MS_U, KC_WFWD, RGB_HUI,                                            RGB_TOG,  RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, XXXXXXX,
            RGB_TOG, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,                                            RGB_M_P, RGB_RMOD, RGB_HUD, RGB_VAD, RGB_SAD, XXXXXXX,
            RGB_VAD, WR_DFL,  XXXXXXX, DEC_DFL, INC_DFL, KC_WH_D, KC_TRNS, KC_SCRL,        _______, KC_TRNS, XXXXXXX,   INC_DFL, DEC_DFL, XXXXXXX, WR_DFL,  _______,
                               RGB_M_P, RGB_MOD,    KC_BTN3,       KC_BTN1, KC_BTN2,        KC_TRNS, KC_BTN4,     KC_BTN5,    UC_MOD, KC_BTN1
    ),
};

// combo definitions
// character combos
const uint16_t PROGMEM combo_b[] = {ALSY_E, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_c[] = {ALSY_E, DE_N, COMBO_END};
const uint16_t PROGMEM combo_d[] = {ALPA_A, DE_R, DE_T, COMBO_END};
const uint16_t PROGMEM combo_f[] = {ALPA_A, DE_R,  COMBO_END};
const uint16_t PROGMEM combo_g[] = {DE_R, DE_T, COMBO_END};
const uint16_t PROGMEM combo_h[] = {ALSY_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_j[] = {DE_T, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_k[] = {DE_N, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_l[] = {ALSY_E, DE_N, DE_I, COMBO_END};
const uint16_t PROGMEM combo_m[] = {DE_N, DE_I,ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_p[] = {ALSY_E, DE_I, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_q[] = {ALPA_A, DE_T, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_u[] = {DE_N, DE_I, COMBO_END};
const uint16_t PROGMEM combo_v[] = {DE_R, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_w[] = {ALPA_A, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_x[] = {DE_R, DE_T, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_y[] = {DE_T, ALPA_A, COMBO_END};
const uint16_t PROGMEM combo_z[] = {ALPA_A, DE_R, DE_T, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_adia[] = {ALPA_A, DE_R, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_udia[] = {ALSY_E, DE_R, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_odia[] = {ALSY_E, DE_N, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_szett[] = {ALSY_E, DE_N, ALCU_S, COMBO_END};
const uint16_t PROGMEM combo_seven[] = {DE_1, DE_4, COMBO_END};
const uint16_t PROGMEM combo_eight[] = {DE_2, DE_5, COMBO_END};
const uint16_t PROGMEM combo_nine[] = {DE_3, DE_6, COMBO_END};
const uint16_t PROGMEM combo_zero[] = {DE_4, DE_6, COMBO_END};
const uint16_t PROGMEM combo_F7[] = {KC_F1, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_F8[] = {KC_F2, KC_F5, COMBO_END};
const uint16_t PROGMEM combo_F9[] = {KC_F3, KC_F6, COMBO_END};
const uint16_t PROGMEM combo_F11[] = {KC_F10, KC_F12, COMBO_END};
// command combos
const uint16_t PROGMEM combo_alt[] = {ALCU_S, DE_I, COMBO_END};
const uint16_t PROGMEM combo_alt_big[] = {KC_ENT, OS_CTL, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {DE_R, ALSY_E, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {ALPA_A, DE_N, DE_I, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_ctrl[] = {ALCU_S, ALSY_E, COMBO_END};
const uint16_t PROGMEM combo_del[] = {DE_R, DE_I, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {ALPA_A, ALSY_E, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {ALPA_A, DE_R, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_gui[] = {ALCU_S, DE_N, COMBO_END};
const uint16_t PROGMEM combo_gui_big[] = {KC_ENT, OS_SFT, COMBO_END};
const uint16_t PROGMEM combo_shift[] = {DE_R, DE_T, ALCU_S, ALSY_E, COMBO_END};
const uint16_t PROGMEM combo_space[] = {ALSY_E, DE_N, DE_I, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {ALPA_A, DE_R, DE_T, ALNU_O, COMBO_END};
// special char combos
const uint16_t PROGMEM combo_at[] = {DE_PLUS, DE_AMPR, COMBO_END};
const uint16_t PROGMEM combo_caret[] = {DE_BSLS, DE_AMPR, COMBO_END};
const uint16_t PROGMEM combo_cent[] = {DE_BSLS, DE_HASH, DE_AMPR, COMBO_END};
const uint16_t PROGMEM combo_comma[] = {ALPA_A, DE_I, COMBO_END};
const uint16_t PROGMEM combo_dollar[] = {DE_MINS, DE_QUES, COMBO_END};
const uint16_t PROGMEM combo_dot[] = {ALPA_A, DE_N, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {DE_PLUS, DE_MINS, COMBO_END};
const uint16_t PROGMEM combo_euro[] = {DE_PLUS, DE_MINS, DE_QUES, COMBO_END};
const uint16_t PROGMEM combo_exclam1[] = {DE_I, DE_T, COMBO_END};
const uint16_t PROGMEM combo_exclam2[] = {DE_MINS, DE_AMPR, COMBO_END};
const uint16_t PROGMEM combo_gt[] = {DE_RCBR, DE_RPRN, COMBO_END};
const uint16_t PROGMEM combo_lt[] = {DE_LCBR, DE_LPRN, COMBO_END};
const uint16_t PROGMEM combo_percent[] = {DE_PLUS, DE_HASH, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {DE_HASH, DE_AMPR, COMBO_END};
const uint16_t PROGMEM combo_slash[] = {ALPA_A, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_tick[] = {DE_BSLS, DE_HASH, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {DE_PLUS, DE_QUES, COMBO_END};
// layer combos
const uint16_t PROGMEM combo_nav1[] = {DE_R, ALSY_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_nav0[] = {KC_LEFT, KC_UP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_navosl[] = {DE_R, DE_N, COMBO_END};
const uint16_t PROGMEM combo_navmse[] = {KC_HOME, KC_DOWN, KC_END, COMBO_END};
const uint16_t PROGMEM combo_mse1[] = {ALPA_A, DE_T, DE_N, COMBO_END};
const uint16_t PROGMEM combo_mse0[] = {KC_BTN2, KC_MS_D, KC_BTN1, COMBO_END};
const uint16_t PROGMEM combo_mseButton3[] = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM combo_mseButton4[] = {KC_WH_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM combo_mseButton5[] = {KC_WH_D, KC_MS_D, COMBO_END};
const uint16_t PROGMEM combo_msenav[] = {KC_MS_L, KC_MS_U, KC_MS_R, COMBO_END};
const uint16_t PROGMEM combo_fnc1[] = {ALNU_O, DE_I, COMBO_END};
const uint16_t PROGMEM combo_fncnav[] = {KC_F2, KC_F4, KC_F6, COMBO_END};
const uint16_t PROGMEM combo_fncmse[] = {KC_F1, KC_F3, KC_F5, COMBO_END};
const uint16_t PROGMEM combo_fncLock[] = {DE_R, DE_I, ALNU_O, COMBO_END};
const uint16_t PROGMEM combo_fncRelease[] = {KC_F2, KC_F12, COMBO_END};
const uint16_t PROGMEM combo_numLock[] = {DE_R, ALNU_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
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
    COMBO(combo_odia, DE_ODIA),
    COMBO(combo_p, DE_P),
    COMBO(combo_q, DE_Q),
    COMBO(combo_szett, DE_SS),
    COMBO(combo_u, DE_U),
    COMBO(combo_udia, DE_UDIA),
    COMBO(combo_v, DE_V),
    COMBO(combo_w, DE_W),
    COMBO(combo_x, DE_X),
    COMBO(combo_y, DE_Y),
    COMBO(combo_z, DE_Z),
    COMBO(combo_seven, DE_7),
    COMBO(combo_eight, DE_8),
    COMBO(combo_nine, DE_9),
    COMBO(combo_zero, DE_0),
    COMBO(combo_F7, KC_F7),
    COMBO(combo_F8, KC_F8),
    COMBO(combo_F9, KC_F9),
    COMBO(combo_F11, KC_F11),
    COMBO(combo_space, NUM_SPC),
    COMBO(combo_enter, KC_ENT),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_shift, OS_SFT),
    COMBO(combo_caps, KC_CAPS),
    COMBO(combo_ctrl, OS_CTL),
    COMBO(combo_alt, OS_ALT),
    COMBO(combo_gui, OS_GUI),
    COMBO(combo_alt_big, OS_ALT),
    COMBO(combo_gui_big, OS_GUI),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_at, DE_AT),
    COMBO(combo_caret, DE_CIRC),
    COMBO(combo_cent, SY_CENT),
    COMBO(combo_comma, DE_COMM),
    COMBO(combo_dollar, DE_DLR),
    COMBO(combo_dot, DE_DOT),
    COMBO(combo_equal, DE_EQL),
    COMBO(combo_euro, DE_EURO),
    COMBO(combo_exclam1, DE_EXLM),
    COMBO(combo_exclam2, DE_EXLM),
    COMBO(combo_gt, DE_RABK),
    COMBO(combo_lt, DE_LABK),
    COMBO(combo_percent, DE_PERC),
    COMBO(combo_pipe, DE_PIPE),
    COMBO(combo_slash, DE_SLSH),
    COMBO(combo_tick, DE_ACUT),
    COMBO(combo_tilde, DE_TILD),
    COMBO(combo_fnc1, OSL(_AFNC)),
    COMBO(combo_fncLock, TO(_AFNC)),
    COMBO(combo_fncRelease, TO_DFL),
    COMBO(combo_fncmse, TO(_AMSE)),
    COMBO(combo_fncnav, TO(_ANAV)),
    COMBO(combo_mse0, TO_DFL),
    COMBO(combo_mse1, TO(_AMSE)),
    COMBO(combo_mseButton3, KC_BTN3),
    COMBO(combo_mseButton4, KC_BTN4),
    COMBO(combo_mseButton5, KC_BTN5),
    COMBO(combo_msenav, TO(_ANAV)),
    COMBO(combo_nav0, TO_DFL),
    COMBO(combo_nav1, TO(_ANAV)),
    COMBO(combo_navmse, TO(_AMSE)),
    COMBO(combo_navosl, OSL(_ANAV)),
    COMBO(combo_numLock, TO(_ANUM)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_KILL:
            if (record->event.pressed) clear_oneshot_mods();
            return false;
        case DEC_DFL:
            if (record->event.pressed) {
                default_layer_set(1UL<<((get_highest_layer(default_layer_state) + 1) % _MAX_DFL));
                clear_oneshot_mods();
            }
            return false;
        case INC_DFL:
            if (record->event.pressed) {
                default_layer_set(1UL<<((get_highest_layer(default_layer_state) + _MAX_DFL - 1) % _MAX_DFL));
                clear_oneshot_mods();
            }
            return false;
        case TO_DFL:
            if (record->event.pressed) layer_clear();
            return false;
        case WR_DFL:
            if (record->event.pressed) set_single_persistent_default_layer(get_highest_layer(default_layer_state));
            return false;
        case SY_CIRC:
            if (record->event.pressed) send_string("^");
            return false;
        case SY_TILD:
            if (record->event.pressed) send_string("~");
            return false;
        case SY_BKTK:
            if (record->event.pressed) send_string("`");
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("       ARTSENIO      "), true);
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
            case _APAR:
                oled_write_P(PSTR("Parens"), false);
                break;
            case _ASYM:
            case _CSYM:
                oled_write_P(PSTR("Symbols"), false);
                break;
            case _ANUM:
                oled_write_P(PSTR("Numbers"), false);
                break;
            case _AFNC:
                oled_write_P(PSTR("Fn-Keys"), false);
                break;
            case _ACUS:
                oled_write_P(PSTR("Custom"), false);
                break;
            case _ANAV:
                oled_write_P(PSTR("Navigation"), false);
                break;
            case _AMSE:
                oled_write_P(PSTR("Mouse"), false);
                break;
            case _CNAV:
                oled_write_P(PSTR("Nav/Num  "), false);
                break;
            case _CMFN:
                oled_write_P(PSTR("Media/Fn "), false);
                break;
            case _CADJ:
                oled_write_P(PSTR("Adjust   "), false);
                break;
            default:
                if (activeLayer > 0) oled_write_P(PSTR("Undefined"), true);
                break;
        }
        oled_write_P(activeLayer < _CSYM ? PSTR("\n") : PSTR("(40p)"), false);

        // Write Status to OLEDs
        oled_write_P(PSTR("WPM: "), false);
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
        oled_write_P(PSTR("\nBase:  "), false);
        switch (get_highest_layer(default_layer_state)) {
            case _MINI:
                oled_write_P(PSTR("Mini    "), false);
                break;
            case _BIG:
                oled_write_P(PSTR("Big     "), false);
                break;
            case _QWER:
                oled_write_P(PSTR("QWERTZ  "), false);
                break;
            case _BONE:
                oled_write_P(PSTR("BONE    "), false);
                break;
            case _COLE:
                oled_write_P(PSTR("Colemak "), false);
                break;
            default:
                oled_write_P(PSTR("Undefined"), true);
        }
        if (host_keyboard_led_state().caps_lock)
            oled_write_P(PSTR("CAPS"), true);
        else
            oled_write_P(PSTR("    "), false);
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
