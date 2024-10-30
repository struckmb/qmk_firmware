/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include QMK_KEYBOARD_H

// #ifdef MAC_SIDE
// #    include "keymap_german_mac_iso.h"
// #else
// #    include "keymap_german_linux.h"
// #endif /* ifdef MAC_SIDE */
#include "keymap_german_linux.h"

enum charybdis_keymap_layers {
    LAYER_BASE00 = 0, //
#ifdef BONE_ENABLE
    LAYER_BASE01,
#endif /* ifdef BONE_ENABLE */
    LAYER_BASE10,
#ifdef BONE_ENABLE
    LAYER_BASE11,
#endif /* ifdef BONE_ENABLE */
    LAYER_SYMB0,
    LAYER_SYMB1,
    LAYER_LOWER0,
    LAYER_LOWER1,
    LAYER_RAISE0,
    LAYER_RAISE1,
    LAYER_ATTIC0,
    LAYER_ATTIC1,
    LAYER_POINTER,
};
// #ifndef BONE_ENABLE
// #define LAYER_BASE01 LAYER_BASE00
// #define LAYER_BASE11 LAYER_BASE10
// #endif /* ifdef BONE_ENABLE */

/** \brief Automatically enable sniping-mode on the pointer layer. */
// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define L0_TAB LT(LAYER_LOWER0, KC_TAB)
#define L1_TAB LT(LAYER_LOWER1, KC_TAB)
#define RAISE0 MO(LAYER_RAISE0)
#define RAISE1 MO(LAYER_RAISE1)
#define ATTIC0 MO(LAYER_ATTIC0)
#define ATTIC1 MO(LAYER_ATTIC1)
#define SYM_A0 LT(LAYER_SYMB0, DE_A)
#define SYM_A1 LT(LAYER_SYMB1, DE_A)
#define SYM_O0 LT(LAYER_SYMB0, DE_ODIA)
#define SYM_O1 LT(LAYER_SYMB1, DE_ODIA)
#define SYM_C0 LT(LAYER_SYMB0, DE_C)
#define SYM_C1 LT(LAYER_SYMB1, DE_C)
#define SYM_G0 LT(LAYER_SYMB0, DE_G)
#define SYM_G1 LT(LAYER_SYMB1, DE_G)
#define PT_Y LT(LAYER_POINTER, DE_Y)
#define PT_SZ LT(LAYER_POINTER, DE_SS)
#define PT_K LT(LAYER_POINTER, DE_K)
#define PT_F LT(LAYER_POINTER, DE_F)
#define DF_BSE00 DF(LAYER_BASE00)
#define DF_BSE10 DF(LAYER_BASE10)
#ifdef BONE_ENABLE
#    define DF_BSE01 DF(LAYER_BASE01)
#    define DF_BSE11 DF(LAYER_BASE11)
#else
#    define DF_BSE01 DF(LAYER_BASE00)
#    define DF_BSE11 DF(LAYER_BASE10)
#endif /* ifdef BONE_ENABLE */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE00] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       ALT_BSP, DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,       DE_Z,    DE_U,    DE_I,    DE_O,    DE_P, ALT_UE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CTL_ESC, SYM_A0,  DE_S,    DE_D,    DE_F,    DE_G,       DE_H,    DE_J,    DE_K,    DE_L,  SYM_O0, CTL_AE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       GUI_LT,  PT_Y,    DE_X,    DE_C,    DE_V,    DE_B,       DE_N,    DE_M, DE_COMM,  DE_DOT,   PT_SZ, GUI_ENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  QK_REP,  SC_SENT, L0_TAB,   RAISE0,RSFT_T(KC_SPC)
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

#ifdef BONE_ENABLE
  [LAYER_BASE01] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        ALT_BSP, DE_J,   DE_D,    DE_U,    DE_A,    DE_X,       DE_P,    DE_H,    DE_L,    DE_M,    DE_W,  ALT_SZ,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        CTL_ESC, SYM_C1, DE_T,    DE_I,    DE_E,    DE_O,       DE_B,    DE_N,    DE_R,    DE_S,   SYM_G0,   CTL_Q,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        GUI_LT,  PT_F,   DE_V,    DE_UDIA, DE_ADIA, DE_ODIA,    DE_Y,    DE_Z, DE_COMM,  DE_DOT,    PT_K, GUI_ENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  QK_REP,  SC_SENT, L0_TAB,   RAISE0,RSFT_T(KC_SPC)
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
   ),
#endif /* ifdef BONE_ENABLE */

  [LAYER_BASE10] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       ALT_BSP, DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,       DE_Z,    DE_U,    DE_I,    DE_O,    DE_P, ALT_UE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CTL_ESC, SYM_A1,  DE_S,    DE_D,    DE_F,    DE_G,       DE_H,    DE_J,    DE_K,    DE_L,  SYM_O1, CTL_AE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       GUI_LT,  PT_Y,    DE_X,    DE_C,    DE_V,    DE_B,       DE_N,    DE_M, DE_COMM,  DE_DOT,   PT_SZ, GUI_ENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                QK_REP, SC_SENT,  L1_TAB,     RAISE1,RSFT_T(KC_SPC)
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

#ifdef BONE_ENABLE
  [LAYER_BASE11] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       ALT_BSP, DE_J,    DE_D,    DE_U,    DE_A,    DE_X,       DE_P,    DE_H,    DE_L,    DE_M,    DE_W,  ALT_SZ,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CTL_ESC, SYM_C1,  DE_T,    DE_I,    DE_E,    DE_O,       DE_B,    DE_N,    DE_R,    DE_S,   SYM_G1,   CTL_Q,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       GUI_LT,  PT_F,    DE_V,    DE_UDIA, DE_ADIA, DE_ODIA,    DE_Y,    DE_Z, DE_COMM,  DE_DOT,    PT_K, GUI_ENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  QK_REP,  SC_SENT, L1_TAB,   RAISE1,RSFT_T(KC_SPC)
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

#endif /* ifdef BONE_ENABLE */

  [LAYER_SYMB0] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       OSM_LA,  DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,    DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, LALT_T(DE_CIRC),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       OSM_LC,  DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,    DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, LCTL_T(DE_PLUS),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       OSM_LG,  DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT,    DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, RGUI_T(DE_MINS),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  QK_REP,  KC_APP,   KC_NO,       KC_NO, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_SYMB1] = LAYOUT( // mac symbols
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       OSM_LA,  A(DE_L), DE_UNDS, A(DE_5), A(DE_6), DE_CIRC,    DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, LALT_T(DE_CIRC),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       OSM_LC,S(A(DE_7)),DE_SLSH, A(DE_8), A(DE_9), DE_ASTR,    DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, LCTL_T(DE_PLUS),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       OSM_LG,  DE_HASH, DE_DLR,  A(DE_7), A(DE_N), DE_ACUT,    DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, RGUI_T(DE_MINS),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  QK_REP,  KC_APP,   KC_NO,       KC_NO, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_LOWER0] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_LALT, XXXXXXX, OSM_RA,  DE_RSAQ, DE_LSAQ, DE_RSAQ,    KC_EJCT, KC_MNXT, KC_MPLY, KC_MPRV, KC_MUTE, DE_ACUT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, OSM_LG,  OSM_LA,  OSM_LC,  OSM_LS,  OSM_MEH,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PSCR, DE_GRV,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LGUI, XXXXXXX, CP_CUT,  CP_COPY, CP_PSTE, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_INS,  CW_TOGG,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_VOLD, KC_VOLU, _______,     ATTIC0, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_LOWER1] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      KC_LALT,KC_NO,OSM_RA,S(A(DE_N)),S(A(DE_B)),S(A(DE_N)),    KC_EJCT, KC_MNXT, KC_MPLY, KC_MPRV, KC_MUTE, DE_ACUT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, OSM_LG,  OSM_LA,  OSM_LC,  OSM_LS,  OSM_MEH,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PSCR, DE_GRV,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LGUI, XXXXXXX, G(KC_X), G(KC_C), G(KC_V), XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_INS,  CW_TOGG,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_VOLD, KC_VOLU, _______,     ATTIC1, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_RAISE0] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       ALT_DEL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, LALT_T(KC_F11),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CTL_DOT, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,         DE_6,    DE_7,    DE_8,    DE_9,    DE_0, LCTL_T(KC_F12),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       GUI_COM, DE_PND, DE_DLR,  DE_CENT, DE_EURO, KC_F11,      KC_F12, DE_PERC, DE_COMM,  DE_DOT, DE_SECT, RGUI_T(DE_MINS),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                 XXXXXXX, KC_TRNS, ATTIC0,      ATTIC0, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_RAISE1] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       ALT_DEL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, LALT_T(KC_F11),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       CTL_DOT, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,         DE_6,    DE_7,    DE_8,    DE_9,    DE_0, LCTL_T(KC_F12),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       GUI_COM,S(A(DE_4)),DE_DLR, A(DE_4), A(DE_E), KC_F11,     KC_F12, DE_PERC, DE_COMM,  DE_DOT, DE_SECT, RGUI_T(DE_MINS),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                 XXXXXXX, KC_TRNS, ATTIC1,      ATTIC1, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_ATTIC0] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       DF_BSE00, KC_NO,   KC_NO,   DE_RDAQ, DE_LDAQ, DE_RDAQ,    DE_IEXL, XXXXXXX, DE_SLQU, DE_LSQU, DE_SQUE, DF_BSE10,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DF_BSE01, OSM_LG,  OSM_LA,  OSM_LC,  OSM_LS,  OSM_MEH,    DE_IQUE, XXXXXXX, DE_MDOT, DE_ELLP, XXXXXXX, DF_BSE11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO,   DE_DIV,  DE_MULT, EE_CLR,  QK_BOOT, XXXXXXX,    DE_NDSH, DE_MDSH, DE_DLQU, DE_LDQU, DE_RDQU,   KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  BRI_DN,  BRI_UP,  _______,    _______, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_ATTIC1] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       DF_BSE00, KC_NO, KC_NO, S(A(DE_Q)),DE_LDAQ,S(A(DE_Q)),   A(DE_1),XXXXXXX,A(DE_S),A(DE_HASH),  DE_QUOT, DF_BSE10,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DF_BSE01, OSM_LG,  OSM_LA,  OSM_LC,  OSM_LS,  OSM_MEH,   A(DE_SS),XXXXXXX,S(A(DE_9)),DE_ELLP, XXXXXXX, DF_BSE11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, S(A(DE_DOT)),DE_ASTR,EE_CLR, QK_BOOT, XXXXXXX,    DE_NDSH,DE_MDSH,A(DE_CIRC),A(DE_2),S(A(DE_2)), KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  BRI_DN,  BRI_UP,  _______,    _______, KC_LSFT
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_LALT, KC_NO, S_D_RMOD, DPI_RMOD, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD,DPI_RMOD,S_D_RMOD,  KC_NO,  KC_LALT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,      KC_NO, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, KC_LCTL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LGUI, _______, DRG_TOG, DRGSCRL, SNIPING, SNP_TOG,   SNP_TOG, SNIPING, DRGSCRL,  DRG_TOG, _______, KC_LGUI,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN3, KC_BTN1, KC_BTN2,    KC_BTN4, KC_BTN5
  //                          ╰─────────────────────────────╯ ╰───────────────────╯
  ),
};
// clang-format on

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    // adapt caps word to german layout
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DE_ADIA:
        case DE_ODIA:
        case DE_UDIA:
        case DE_SS:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DE_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}
#endif /* ifdef CAPS_WORD_ENABLE */

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
            // #        ifdef RGB_MATRIX_ENABLE
            //             rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            //             rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            // #        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
        // #        ifdef RGB_MATRIX_ENABLE
        //         rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
        // #        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

// #ifdef RGB_MATRIX_ENABLE
// // Forward-declare this helper function since it is defined in rgb_matrix.c.
// void rgb_matrix_update_pwm_buffers(void);
// #endif // RGB_MATRIX_ENABLE
