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
#include "struckmb.h"

#define LAYOUT_split_3x6_5_wrapper(...) LAYOUT_split_3x6_5(__VA_ARGS__)

/* enum layers { */
/*     // Default layers */
/*     _BIG, */
/*     _QWER, */
/*     _MINI, */
/*     _MAX_DFL, */
/*     // Additional mini and big layers */
/*     _APAR, // braces */
/*     _ASYM, // symbols */
/*     _ANUM, // key pad */
/*     _AFNC, // function keys */
/*     _ACUS, // custom keys */
/*     _ANAV, // navigation */
/*     _AMSE,  // mouse adjustment */
/*     // Additional 40p layers */
/*     _CSYM, // symbols (neo based) */
/*     _CNAV, // navigation and key pad */
/*     _CADJ  // kb adjustment */
/* }; */

/* // Aliases for base layers */
/* #define ALCU_S   LT(_ACUS, DE_S) */
/* #define ALNU_O   LT(_ANUM, DE_O) */
/* #define ALPA_A   LT(_APAR, DE_A) */
/* #define ALSY_E   LT(_ASYM, DE_E) */
/* #define AOS_SY   OSL(_ASYM) */
/* #define CL_ADJ   MO(_CADJ) */
/* #define CL_NAV   MO(_CNAV) */

/* // mod aliases */
/* #define CTL_ESC  MT(MOD_LCTL, KC_ESC) */
/* #define OS_ALT   OSM(MOD_LALT) */
/* #define OS_CTL   OSM(MOD_LCTL) */
/* #define OS_GUI   OSM(MOD_LGUI) */
/* #define OS_SFT   OSM(MOD_LSFT) */
/* #define SFT_BSP  MT(MOD_LSFT, KC_BSPC) */
/* #define SFT_DEL  MT(MOD_RSFT, KC_DEL) */

/* //#define CL_SYM   MO(_CSYM) */
/* #define MFN_SPC  LT(_CADJ, KC_SPC) */
/* #define NUM_SPC  LT(_ANUM, KC_SPC) */
/* #define SYM_ENT  LT(_CSYM, KC_ENT) */
/* #define SYM_SPC  LT(_CSYM, KC_SPC) */

/* // Aliases for some specials */
/* #define SY_COPY  C(KC_INS) */
/* #define SY_CUT   S(KC_DEL) */
/* #define SY_CENT  ALGR(KC_C) */
/* #define SY_HELL  ALGR(KC_DOT) */
/* #define SY_PASTE S(KC_INS) */
/* #define SY_REDO  RCS(DE_Z) */
/* #define SY_UNDO  C(DE_Z) */

/* // HRM */
/* #define HQ_Y  DE_Y */
/* #define HQ_S  DE_S */
/* #define HQ_D  DE_D */
/* #define HQ_F  DE_F */
/* #define HQ_J  DE_J */
/* #define HQ_K  DE_K */
/* #define HQ_L  DE_L */
/* #define HQ_SS DE_SS */

/* enum custom_keycodes { */
/*     TO_DFL = SAFE_RANGE, */
/*     INC_DFL, */
/*     DEC_DFL, */
/*     OS_KILL, */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_5_wrapper(
        _BL1_1_,_BL1_5_,                _BR1_5_,_BR1_1_,
        _BL2_1_,_BL2_5_,                _BR2_5_,_BR2_1_,
        _BL3_1_,_BL3_5_,xxx2xxx,xxx2xxx,_BR3_5_,_BR3_1_,
        XXXXXXX,XXXXXXX,_BL4_3_,_BR4_3_,XXXXXXX,BS_ENC
    ),
    [_SYM_NUM] = LAYOUT_split_3x6_5_wrapper(
        _BL1_1_,_SY1_5_,                _NU1_5_,_BR1_1_,
        _BL2_1_,_SY2_5_,                _NU2_5_,_BR2_1_,
        _BL3_1_,_SY3_5_,xxx2xxx,xxx2xxx,_NU3_5_,_BR3_1_,
        _______,_______,_SY4_3_,_NU4_3_,_______,_______
    ),
    [_NAV_FUN] = LAYOUT_split_3x6_5_wrapper(
        _BL1_1_,_NA1_5_,                _FU1_5_,_BR1_1_,
        _BL2_1_,_NA2_5_,                _FU2_5_,_BR2_1_,
        _BL3_1_,_NA3_5_,xxx2xxx,xxx2xxx,_FU3_5_,_BR3_1_,
        _______,_______,_NA4_3_,_FU4_3_,_______,_______
    ),
    [_MSE_ADJ] = LAYOUT_split_3x6_5_wrapper(
        _BL1_1_,_MO1_5_,                _AD1_5_,_BR1_1_,
        _BL2_1_,_MO2_5_,                _AD2_5_,_BR2_1_,
        _BL3_1_,_MO3_5_,xxx2xxx,xxx2xxx,_AD3_5_,_BR3_1_,
        _______,_______,_MO4_3_,_AD4_3_,_______,_______
    ),
};

#ifdef KEYBOARD_splitkb_kyria_rev1      // Kyria specific code
#ifdef OLED_ENABLE                          // Kyria's oled screen
// For kyria; print logo, and allow default status printing
bool oled_task_keymap(void) {
    if (is_keyboard_master()) {
        render_qmk_logo(0, 0);
        render_status_lite(4, 0);
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
#endif //OLED_ENABLE
#endif //KEYBOARD_splitkb_kyria_rev1

/* // clang-format off */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [_BIG] = LAYOUT( */
/*             OS_KILL, ALCU_S,  DE_T,    DE_R,    ALPA_A,  DE_SS,                                   DE_SS,   ALPA_A,  DE_R,    DE_T,    ALCU_S,  OS_KILL, */
/*             CTL_ESC, ALNU_O,  DE_I,    DE_N,    ALSY_E,  OS_SFT,                                  OS_SFT,  ALSY_E,  DE_N,    DE_I,    ALNU_O,  CTL_ESC, */
/*             OS_SFT,  OS_CTL,  KC_BSPC, KC_DEL,  DE_EQL,  KC_TAB,  CL_ADJ,KC_NO,     KC_NO,CL_ADJ, KC_TAB,  DE_EQL,  KC_DEL,  KC_BSPC, OS_CTL,  OS_SFT, */
/*                                 KC_NO,   KC_NO,   AOS_SY,    KC_ENT,   NUM_SPC,     NUM_SPC, KC_ENT,   AOS_SY,   KC_NO,   KC_NO//ENC */
/*             ), */
/*     [_QWER] = LAYOUT( */
/*             KC_TAB,  DE_Q,   DE_W,    DE_E,    DE_R,    DE_T,                                     DE_Z,   DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, */
/*             CTL_ESC, DE_A,   HQ_S,    HQ_D,    HQ_F,    DE_G,                                     DE_H,   HQ_J,    HQ_K,    HQ_L,    DE_ODIA, DE_ADIA, */
/*             SFT_BSP, HQ_Y,   DE_X,    DE_C,    DE_V,    DE_B,  CL_ADJ,KC_CAPS,     CL_ADJ,CL_ADJ, DE_N,   DE_M, DE_COMM , DE_DOT,    HQ_SS,   SFT_DEL, */
/*                                 SY_COPY, SY_PASTE,  CL_NAV,   SYM_ENT,MFN_SPC,     CL_ADJ, SYM_SPC,  CL_NAV,  KC_APP, KC_PSCR//ENC */
/*             ), */
/*     [_MINI] = LAYOUT( */
/*             OS_KILL, ALCU_S,  DE_T,    DE_R,    ALPA_A,  KC_NO,                                   KC_NO,   ALPA_A,  DE_R,    DE_T,    ALCU_S,  OS_KILL, */
/*             KC_NO,   ALNU_O,  DE_I,    DE_N,    ALSY_E,  KC_NO,                                   KC_NO,   ALSY_E,  DE_N,    DE_I,    ALNU_O,  KC_NO, */
/*             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   CL_ADJ,KC_NO,     KC_NO,CL_ADJ, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, */
/*                                  KC_NO,   KC_NO,     KC_NO,       KC_NO, KC_NO,     KC_NO, KC_NO,     KC_NO,     KC_NO,   KC_NO//ENC */
/*             ), */
/*     [_APAR] = LAYOUT( */
/*             KC_TRNS,DE_LCBR, DE_LBRC, DE_LPRN, KC_NO,   KC_TRNS,                                 KC_TRNS, KC_TRNS, DE_LPRN, DE_LBRC, DE_LCBR, KC_NO, */
/*             KC_TRNS,DE_RCBR, DE_RBRC, DE_RPRN, KC_NO,   KC_TRNS,                                 KC_TRNS, KC_NO,   DE_RPRN, DE_RBRC, DE_RCBR, KC_TRNS, */
/*             KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*                                 KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC */
/*             ), */
/*     [_ASYM] = LAYOUT( */
/*             KC_TRNS,DE_BSLS, DE_HASH, DE_AMPR, DE_EXLM, KC_NO,                                   KC_NO,   DE_EXLM, DE_AMPR, DE_HASH, DE_BSLS, KC_NO, */
/*             KC_TRNS,DE_PLUS, DE_MINS, DE_QUES, KC_TRNS, DE_DQUO,                                 DE_DQUO, KC_TRNS, DE_QUES, DE_MINS, DE_PLUS, KC_TRNS, */
/*             KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*                                 KC_TRNS, KC_TRNS,   KC_TRNS,   TO_DFL, TO_DFL,     TO_DFL, TO_DFL,   KC_TRNS,   KC_TRNS, KC_NO//ENC */
/*             ), */
/*     [_ANUM] = LAYOUT( */
/*             QK_RBT, KC_BSPC, DE_1,    DE_2,    DE_3,    DE_PLUS,                                 DE_PLUS, DE_1,    DE_2,    DE_3,    KC_BSPC, QK_RBT, */
/*             KC_TRNS,TO_DFL,  DE_4,    DE_5,    DE_6,    DE_MINS,                                 DE_MINS, DE_4,    DE_5,    DE_6,    TO_DFL,  KC_TRNS, */
/*             KC_TRNS,KC_TRNS, DE_7,    DE_8,    DE_9,    KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, DE_7,    DE_8,    DE_9,    KC_TRNS, KC_TRNS, */
/*                                 KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC */
/*             ), */
/*     [_AFNC] = LAYOUT( */
/*             KC_NO,  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F10,                                  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_NO, */
/*             KC_TRNS,KC_F12,  KC_F4,   KC_F5,   KC_F6,   KC_F11,                                  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F12,  KC_TRNS, */
/*             KC_TRNS,KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_NO, KC_NO,     KC_NO, KC_NO, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_TRNS ,KC_TRNS, */
/*                                 KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC */
/*             ), */
/*     [_ACUS] = LAYOUT( */
/*             KC_NO,  KC_NO,   KC_NO,   KC_PWR,  KC_APP,  KC_NO,                                   KC_NO,   KC_APP,  KC_PWR,  KC_NO,   KC_NO,   KC_NO, */
/*             KC_TRNS,KC_NO,   RESET,   KC_INS,  KC_PSCR, KC_NO,                                   KC_NO,   KC_PSCR, KC_INS,  RESET,   KC_NO,   KC_TRNS, */
/*             KC_TRNS,KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS ,KC_TRNS, */
/*                                 KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC */
/*             ), */
/*     [_ANAV] = LAYOUT( */
/*             KC_NO,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS,                                 KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO, */
/*             KC_TRNS,KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,                                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS, */
/*             KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*                                 KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC */
/*             ), */
/*     [_AMSE] = LAYOUT( */
/*             KC_NO,  KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, KC_TRNS,                                 KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO, */
/*             KC_TRNS,KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, */
/*             KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,     KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*                                 KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_NO//ENC */
/*             ), */
/*     [_CSYM] = LAYOUT( */
/*             OS_KILL, SY_HELL, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                                            DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_EURO, */
/*             OS_CTL,  DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                            DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT, */
/*             OS_GUI,  DE_HASH, DE_DLR , DE_PIPE, DE_TILD, DE_GRV,  _______, _______,        _______, _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______, */
/*                                SY_CUT, _______,      _______,     KC_TRNS, _______,        _______, KC_TRNS,     DE_GRV,       DE_ACUT, _______ */
/*     ), */
/*     [_CNAV] = LAYOUT( */
/*             OS_KILL, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_INS,                                             DE_LPRN, DE_7,    DE_8,    DE_9,    DE_RPRN, DE_SCLN, */
/*             OS_ALT,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                                             DE_MINS, DE_4,    DE_5,    DE_6,    DE_PLUS, DE_COLN, */
/*             OS_SFT,  KC_ESC,  SY_UNDO, SY_REDO, KC_ENT,  KC_PGDN, KC_WHOM, KC_NUM,         _______, _______, DE_0,    DE_1,    DE_2,    DE_3,    DE_DOT,  _______, */
/*                                SY_CUT, _______,     KC_TRNS,      KC_WBAK, KC_WFWD,        _______, _______,     KC_TRNS,      DE_COMM, _______ */
/*     ), */
/*     [_CADJ] = LAYOUT( */
/*             RGB_VAI, KC_WH_U, KC_WBAK, KC_MS_U, KC_WFWD, RGB_HUI,                                            RGB_TOG, KC_F7 , KC_F8, KC_F9, KC_F10, RGB_HUI, */
/*             RGB_TOG, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,                                            RGB_MOD, KC_F4 , KC_F5, KC_F6, KC_F11, RGB_SAI, */
/*             RGB_VAD, RESET,   EE_CLR,  DEC_DFL, INC_DFL, KC_WH_D, KC_TRNS, KC_SCRL,        _______, KC_TRNS, XXXXXXX, KC_F1 , KC_F2, KC_F3, KC_F12, RGB_VAI, */
/*                                RGB_M_P, RGB_MOD,    KC_BTN3,      KC_BTN1, KC_BTN2,        KC_TRNS, KC_BTN4,    KC_BTN5,     KC_PWR, KC_BTN1 */
/*     ), */
/* }; */

/* // combo definitions */
/* // character combos */
/* const uint16_t PROGMEM combo_b[] = {ALSY_E, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_c[] = {ALSY_E, DE_N, COMBO_END}; */
/* const uint16_t PROGMEM combo_d[] = {ALPA_A, DE_R, DE_T, COMBO_END}; */
/* const uint16_t PROGMEM combo_f[] = {ALPA_A, DE_R,  COMBO_END}; */
/* const uint16_t PROGMEM combo_g[] = {DE_R, DE_T, COMBO_END}; */
/* const uint16_t PROGMEM combo_h[] = {ALSY_E, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_j[] = {DE_T, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_k[] = {DE_N, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_l[] = {ALSY_E, DE_N, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_m[] = {DE_N, DE_I, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_p[] = {ALSY_E, DE_I, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_q[] = {ALPA_A, DE_T, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_u[] = {DE_N, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_v[] = {DE_R, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_w[] = {ALPA_A, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_x[] = {DE_R, DE_T, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_y[] = {DE_T, ALPA_A, COMBO_END}; */
/* const uint16_t PROGMEM combo_z[] = {ALPA_A, DE_R, DE_T, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_adia[] = {ALPA_A, DE_R, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_udia[] = {ALSY_E, DE_R, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_odia[] = {ALSY_E, DE_N, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_szett[] = {ALSY_E, DE_N, ALCU_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_seven[] = {DE_1, DE_4, COMBO_END}; */
/* const uint16_t PROGMEM combo_eight[] = {DE_2, DE_5, COMBO_END}; */
/* const uint16_t PROGMEM combo_nine[] = {DE_3, DE_6, COMBO_END}; */
/* const uint16_t PROGMEM combo_zero[] = {DE_4, DE_6, COMBO_END}; */
/* const uint16_t PROGMEM combo_F7[] = {KC_F1, KC_F4, COMBO_END}; */
/* const uint16_t PROGMEM combo_F8[] = {KC_F2, KC_F5, COMBO_END}; */
/* const uint16_t PROGMEM combo_F9[] = {KC_F3, KC_F6, COMBO_END}; */
/* const uint16_t PROGMEM combo_F11[] = {KC_F10, KC_F12, COMBO_END}; */
/* // command combos */
/* const uint16_t PROGMEM combo_alt[] = {ALCU_S, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_alt_big[] = {KC_ENT, OS_CTL, COMBO_END}; */
/* const uint16_t PROGMEM combo_bspc[] = {DE_R, ALSY_E, COMBO_END}; */
/* const uint16_t PROGMEM combo_caps[] = {ALPA_A, DE_N, DE_I, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_ctrl[] = {ALCU_S, ALSY_E, COMBO_END}; */
/* const uint16_t PROGMEM combo_del[] = {DE_R, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_enter[] = {ALPA_A, ALSY_E, COMBO_END}; */
/* const uint16_t PROGMEM combo_esc[] = {ALPA_A, DE_R, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_gui[] = {ALCU_S, DE_N, COMBO_END}; */
/* const uint16_t PROGMEM combo_gui_big[] = {KC_ENT, OS_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_shift[] = {DE_R, DE_T, ALCU_S, ALSY_E, COMBO_END}; */
/* const uint16_t PROGMEM combo_space[] = {ALSY_E, DE_N, DE_I, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_tab[] = {ALPA_A, DE_R, DE_T, ALNU_O, COMBO_END}; */
/* // special char combos */
/* const uint16_t PROGMEM combo_at[] = {DE_PLUS, DE_AMPR, COMBO_END}; */
/* const uint16_t PROGMEM combo_caret[] = {DE_BSLS, DE_AMPR, COMBO_END}; */
/* const uint16_t PROGMEM combo_cent[] = {DE_BSLS, DE_HASH, DE_AMPR, COMBO_END}; */
/* const uint16_t PROGMEM combo_comma[] = {ALPA_A, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_dollar[] = {DE_MINS, DE_QUES, COMBO_END}; */
/* const uint16_t PROGMEM combo_dot[] = {ALPA_A, DE_N, COMBO_END}; */
/* const uint16_t PROGMEM combo_equal[] = {DE_PLUS, DE_MINS, COMBO_END}; */
/* const uint16_t PROGMEM combo_euro[] = {DE_PLUS, DE_MINS, DE_QUES, COMBO_END}; */
/* const uint16_t PROGMEM combo_exclam1[] = {DE_I, DE_T, COMBO_END}; */
/* const uint16_t PROGMEM combo_exclam2[] = {DE_MINS, DE_AMPR, COMBO_END}; */
/* const uint16_t PROGMEM combo_gt[] = {DE_RCBR, DE_RPRN, COMBO_END}; */
/* const uint16_t PROGMEM combo_lt[] = {DE_LCBR, DE_LPRN, COMBO_END}; */
/* const uint16_t PROGMEM combo_percent[] = {DE_PLUS, DE_HASH, COMBO_END}; */
/* const uint16_t PROGMEM combo_pipe[] = {DE_HASH, DE_AMPR, COMBO_END}; */
/* const uint16_t PROGMEM combo_slash[] = {ALPA_A, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_tick[] = {DE_BSLS, DE_HASH, COMBO_END}; */
/* const uint16_t PROGMEM combo_tilde[] = {DE_PLUS, DE_QUES, COMBO_END}; */
/* // layer combos */
/* const uint16_t PROGMEM combo_nav1[] = {DE_R, ALSY_E, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_nav0[] = {KC_LEFT, KC_UP, KC_RGHT, COMBO_END}; */
/* const uint16_t PROGMEM combo_navosl[] = {DE_R, DE_N, COMBO_END}; */
/* const uint16_t PROGMEM combo_nav_tabnext[] = {KC_PGDN, KC_RGHT, COMBO_END}; */
/* const uint16_t PROGMEM combo_nav_tabprev[] = {KC_PGDN, KC_LEFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_navmse[] = {KC_HOME, KC_DOWN, KC_END, COMBO_END}; */
/* const uint16_t PROGMEM combo_mse1[] = {ALPA_A, DE_T, DE_N, COMBO_END}; */
/* const uint16_t PROGMEM combo_mse0[] = {KC_BTN2, KC_MS_D, KC_BTN1, COMBO_END}; */
/* const uint16_t PROGMEM combo_mseButton3[] = {KC_BTN1, KC_BTN2, COMBO_END}; */
/* const uint16_t PROGMEM combo_mseButton4[] = {KC_WH_D, KC_MS_U, COMBO_END}; */
/* const uint16_t PROGMEM combo_mseButton5[] = {KC_WH_D, KC_MS_D, COMBO_END}; */
/* const uint16_t PROGMEM combo_msenav[] = {KC_MS_L, KC_MS_U, KC_MS_R, COMBO_END}; */
/* const uint16_t PROGMEM combo_fnc1[] = {ALNU_O, DE_I, COMBO_END}; */
/* const uint16_t PROGMEM combo_fncnav[] = {KC_F2, KC_F4, KC_F6, COMBO_END}; */
/* const uint16_t PROGMEM combo_fncmse[] = {KC_F1, KC_F3, KC_F5, COMBO_END}; */
/* const uint16_t PROGMEM combo_fncLock[] = {DE_R, DE_I, ALNU_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_fncRelease[] = {KC_F2, KC_F12, COMBO_END}; */
/* const uint16_t PROGMEM combo_numLock[] = {DE_R, ALNU_O, COMBO_END}; */
/* // hrm combos */
/* const uint16_t PROGMEM combo_hrm_lalt[] = {DE_Q, HQ_S, COMBO_END}; */
/* const uint16_t PROGMEM combo_hrm_lgui[] = {DE_Q, HQ_D, COMBO_END}; */
/* const uint16_t PROGMEM combo_hrm_lctl[] = {DE_Q, HQ_F, COMBO_END}; */
/* const uint16_t PROGMEM combo_hrm_lsft[] = {HQ_F, HQ_D, COMBO_END}; */
/* const uint16_t PROGMEM combo_hrm_rsft[] = {HQ_J, HQ_K, COMBO_END}; */
/* const uint16_t PROGMEM combo_hrm_rctl[] = {DE_P, HQ_J, COMBO_END}; */
/* const uint16_t PROGMEM combo_hrm_rgui[] = {DE_P, HQ_K, COMBO_END}; */
/* const uint16_t PROGMEM combo_hrm_ralt[] = {DE_P, HQ_L, COMBO_END}; */

/* combo_t key_combos[COMBO_COUNT] = { */
/*     COMBO(combo_adia, DE_ADIA), */
/*     COMBO(combo_b, DE_B), */
/*     COMBO(combo_c, DE_C), */
/*     COMBO(combo_d, DE_D), */
/*     COMBO(combo_f, DE_F), */
/*     COMBO(combo_g, DE_G), */
/*     COMBO(combo_h, DE_H), */
/*     COMBO(combo_j, DE_J), */
/*     COMBO(combo_k, DE_K), */
/*     COMBO(combo_l, DE_L), */
/*     COMBO(combo_m, DE_M), */
/*     COMBO(combo_odia, DE_ODIA), */
/*     COMBO(combo_p, DE_P), */
/*     COMBO(combo_q, DE_Q), */
/*     COMBO(combo_szett, DE_SS), */
/*     COMBO(combo_u, DE_U), */
/*     COMBO(combo_udia, DE_UDIA), */
/*     COMBO(combo_v, DE_V), */
/*     COMBO(combo_w, DE_W), */
/*     COMBO(combo_x, DE_X), */
/*     COMBO(combo_y, DE_Y), */
/*     COMBO(combo_z, DE_Z), */
/*     COMBO(combo_seven, DE_7), */
/*     COMBO(combo_eight, DE_8), */
/*     COMBO(combo_nine, DE_9), */
/*     COMBO(combo_zero, DE_0), */
/*     COMBO(combo_F7, KC_F7), */
/*     COMBO(combo_F8, KC_F8), */
/*     COMBO(combo_F9, KC_F9), */
/*     COMBO(combo_F11, KC_F11), */
/*     COMBO(combo_space, NUM_SPC), */
/*     COMBO(combo_enter, KC_ENT), */
/*     COMBO(combo_tab, KC_TAB), */
/*     COMBO(combo_bspc, KC_BSPC), */
/*     COMBO(combo_del, KC_DEL), */
/*     COMBO(combo_shift, OS_SFT), */
/*     COMBO(combo_caps, KC_CAPS), */
/*     COMBO(combo_ctrl, OS_CTL), */
/*     COMBO(combo_alt, OS_ALT), */
/*     COMBO(combo_gui, OS_GUI), */
/*     COMBO(combo_alt_big, OS_ALT), */
/*     COMBO(combo_gui_big, OS_GUI), */
/*     COMBO(combo_esc, KC_ESC), */
/*     COMBO(combo_at, DE_AT), */
/*     COMBO(combo_caret, DE_CIRC), */
/*     COMBO(combo_cent, SY_CENT), */
/*     COMBO(combo_comma, DE_COMM), */
/*     COMBO(combo_dollar, DE_DLR), */
/*     COMBO(combo_dot, DE_DOT), */
/*     COMBO(combo_equal, DE_EQL), */
/*     COMBO(combo_euro, DE_EURO), */
/*     COMBO(combo_exclam1, DE_EXLM), */
/*     COMBO(combo_exclam2, DE_EXLM), */
/*     COMBO(combo_gt, DE_RABK), */
/*     COMBO(combo_lt, DE_LABK), */
/*     COMBO(combo_percent, DE_PERC), */
/*     COMBO(combo_pipe, DE_PIPE), */
/*     COMBO(combo_slash, DE_SLSH), */
/*     COMBO(combo_tick, DE_ACUT), */
/*     COMBO(combo_tilde, DE_TILD), */
/*     COMBO(combo_fnc1, OSL(_AFNC)), */
/*     COMBO(combo_fncLock, TO(_AFNC)), */
/*     COMBO(combo_fncRelease, TO_DFL), */
/*     COMBO(combo_fncmse, TO(_AMSE)), */
/*     COMBO(combo_fncnav, TO(_ANAV)), */
/*     COMBO(combo_mse0, TO_DFL), */
/*     COMBO(combo_mse1, TO(_AMSE)), */
/*     COMBO(combo_mseButton3, KC_BTN3), */
/*     COMBO(combo_mseButton4, KC_BTN4), */
/*     COMBO(combo_mseButton5, KC_BTN5), */
/*     COMBO(combo_msenav, TO(_ANAV)), */
/*     COMBO(combo_nav0, TO_DFL), */
/*     COMBO(combo_nav1, TO(_ANAV)), */
/*     COMBO(combo_navmse, TO(_AMSE)), */
/*     COMBO(combo_navosl, OSL(_ANAV)), */
/*     COMBO(combo_nav_tabnext, C(KC_TAB)), */
/*     COMBO(combo_nav_tabprev, S(C(KC_TAB))), */
/*     COMBO(combo_numLock, TO(_ANUM)), */
/*     COMBO(combo_hrm_lsft, OS_SFT), */
/*     COMBO(combo_hrm_lalt, OS_ALT), */
/*     COMBO(combo_hrm_lctl, OS_CTL), */
/*     COMBO(combo_hrm_lgui, OS_GUI), */
/*     COMBO(combo_hrm_rgui, OS_GUI), */
/*     COMBO(combo_hrm_rctl, OS_CTL), */
/*     COMBO(combo_hrm_ralt, OS_ALT), */
/*     COMBO(combo_hrm_rsft, OS_SFT), */
/* }; */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case OS_KILL: */
/*             if (record->event.pressed) clear_oneshot_mods(); */
/*             return false; */
/*         case INC_DFL: */
/*             if (record->event.pressed) { */
/*                 default_layer_set(1UL<<((get_highest_layer(default_layer_state) + 1) % _MAX_DFL)); */
/*                 clear_oneshot_mods(); */
/*             } */
/*             return false; */
/*         case DEC_DFL: */
/*             if (record->event.pressed) { */
/*                 default_layer_set(1UL<<((get_highest_layer(default_layer_state) + _MAX_DFL - 1) % _MAX_DFL)); */
/*                 clear_oneshot_mods(); */
/*             } */
/*             return false; */
/*         case TO_DFL: */
/*             if (record->event.pressed) layer_clear(); */
/*             return false; */
/*     } */
/*     return true; */
/* } */

/* #ifdef OLED_ENABLE */
/* void printLayers(void) { */
/*     // Host Keyboard Layer Status */
/*     oled_write_P(PSTR("\nLayer: "), false); */
/*     switch (get_highest_layer(default_layer_state)) { */
/*         case _MINI: */
/*             oled_write_P(PSTR("Def"), false); */
/*             break; */
/*         case _BIG: */
/*             oled_write_P(PSTR("Big"), false); */
/*             break; */
/*         case _QWER: */
/*             oled_write_P(PSTR("QWER"), false); */
/*             break; */
/*     } */
/*     uint8_t activeLayer = get_highest_layer(layer_state); */
/*     switch (activeLayer) { */
/*         case _APAR: */
/*             oled_write_P(PSTR(" P"), false); */
/*             break; */
/*         case _ASYM: */
/*         case _CSYM: */
/*             oled_write_P(PSTR(" S"), false); */
/*             break; */
/*         case _ANUM: */
/*             oled_write_P(PSTR(" 1"), false); */
/*             break; */
/*         case _AFNC: */
/*             oled_write_P(PSTR(" Fn"), false); */
/*             break; */
/*         case _ACUS: */
/*             oled_write_P(PSTR(" C"), false); */
/*             break; */
/*         case _ANAV: */
/*             oled_write_P(PSTR(" N"), false); */
/*             break; */
/*         case _AMSE: */
/*             oled_write_P(PSTR(" M"), false); */
/*             break; */
/*         case _CNAV: */
/*             oled_write_P(PSTR(" N1"), false); */
/*             break; */
/*         case _CADJ: */
/*             oled_write_P(PSTR(" MFA"), false); */
/*             break; */
/*     } */
/*     oled_write_P(PSTR("\n"), false); */
/* } */
/* void printModsState(void) { */
/*     // Write mods state to OLEDs */
/*     uint8_t osm_mod = mod_config(get_oneshot_mods()); */
/*     uint8_t all_mod = mod_config(get_mods()|get_oneshot_mods()); */
/*     oled_write_P(PSTR("\nMODs : "), false); */
/*     oled_write_P(all_mod & MOD_MASK_SHIFT ? PSTR("S") : PSTR("_"), osm_mod & MOD_MASK_SHIFT); */
/*     oled_write_P(all_mod & MOD_MASK_CTRL ?  PSTR("C") : PSTR("_"), osm_mod & MOD_MASK_CTRL); */
/*     oled_write_P(all_mod & MOD_MASK_ALT ?   PSTR("A") : PSTR("_"), osm_mod & MOD_MASK_ALT); */
/*     oled_write_P(all_mod & MOD_MASK_GUI ?   PSTR("M") : PSTR("_"), osm_mod & MOD_MASK_GUI); */
/*     // Write host Keyboard LED Status to OLEDs */
/*     if (host_keyboard_led_state().caps_lock) { */
/*         oled_write_P(PSTR("  "), false); */
/*         oled_write_P(PSTR(" CAPS "), true); */
/*     } else { */
/*         oled_write_P(PSTR("        "), false); */
/*     } */
/* } */
/* void printClaim(void) { */
/*         oled_write_P(PSTR("         STRUCKMB    "), true); */
/* } */
/* bool oled_task_user(void) { */
/*     if (is_keyboard_master()) { */
/*         printClaim(); */
/*         // QMK Logo and version information */
/*         // clang-format off */
/*         static const char PROGMEM qmk_logo[] = { */
/*             0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
/*             0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
/*             0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0}; */
/*         // clang-format on */
/*         oled_write_P(qmk_logo, false); */
/*         printLayers(); */
/*         printModsState(); */
/*     } else { */
/*         // clang-format off */
/*         static const char PROGMEM kyria_logo[] = { */
/*             0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0, */
/*             0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 */
/*         }; */
/*         // clang-format on */
/*         oled_write_raw_P(kyria_logo, sizeof(kyria_logo)); */
/*         oled_set_cursor(13,6); */
/*         oled_write_P(PSTR("rev1.4"), false); */
/*     } */
/*     return false; */
/* } */
/* #endif */
