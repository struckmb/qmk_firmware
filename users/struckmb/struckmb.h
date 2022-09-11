/* Copyright 2021 Batuhan Başerdem
 * <baserdem.batuhan@gmail.com> @bbaserdem
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
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keymap_german.h"

/* Besides loading libraries and definitions, this file has my layout defs
 * LAYOUTS:
 *  This file has a couple layouts I use; so that the general changes can be
 *  propagated by only editing this file.
 */

// Rotary encoder
#ifdef ENCODER_ENABLE
#include "bs-encoder.h"
#endif // ENCODER_ENABLE

// Oled screen
#ifdef OLED_ENABLE
#include "bs-oled.h"
#endif // OLED_ENABLE

// Function definitions that can be accessed through specific keymaps
// These will be delegated to keymap specific stuff (weak definition)
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Make it so that keymaps can use KEYMAP_SAFE_RANGE for custom keycodes
#ifdef KEYMAP_SAFE_RANGE
#define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

// Custom macro keycode ranges
enum userspace_custom_keycodes {
    // Safe stuff
    BS_SAFE = PLACEHOLDER_SAFE_RANGE,
    // Encoder button
#   ifdef ENCODER_ENABLE
    BS_ENC,
#   endif // ENCODER_ENABLE
    //use for keymap specific codes
    KEYMAP_SAFE_RANGE
};
#ifndef ENCODER_ENABLE
#define BS_ENC KC_NO
#endif // ENCODER_ENABLE

/// Enumeration of layers
enum userspace_layers {
    _DEFAULT = 0, // Base layer
    _SYM_NUM,     // L: Symbols layer,    R: Numbers layer
    _NAV_FUN,     // L: Navigation layer, R: Function keys layer
    _MSE_ADJ,     // L: Mouse keys layer, R: Keyboard adjustments
    _CUSTOMS,     // OSMs and special keys
    /* _GAME,     // Game layer */
    /* _MEDI,     // R3: Media layer */
};

// some german and combining characters
#define DE_AE   KC_QUOT          // Ä
#define DE_OE   KC_SCLN          // Ö
#define DE_UE   KC_LBRC          // Ü
#define DE_SZ   KC_MINS          // ß

// linux extended chars (as not in keymap_german)
#define DE_F1_2 ALGR(DE_5)       // ½
#define DE_F1_4 ALGR(DE_4)       // ¼
#define DE_NOT  ALGR(DE_5)       // ¬
#define DE_CED  ALGR(DE_ACUT)    // ¸ cedilla (dead)
#define DE_EURO ALGR(DE_E)       // €
#define DE_ARRL ALGR(DE_Z)       // ← left arrow
#define DE_ARRD ALGR(DE_U)       // ↓ down arrow
#define DE_ARRR ALGR(DE_I)       // → right arrow
#define DE_DIA  ALGR(DE_UE)      // ¨ diaresis (dead)
#define DE_LDOT ALGR(DE_J)       // ̣  dot below (dead)
#define DE_HATS ALGR(DE_AE)      // ˇ hatschek (dead)
#define DE_FDQL ALGR(DE_Y)       // » double guillemets left
#define DE_FDQR ALGR(DE_X)       // « double guillemets right
#define DE_CENT ALGR(DE_C)       // ¢
#define DE_DQUL ALGR(DE_V)       // „ double quote left
#define DE_DQUR ALGR(DE_B)       // “ double quote right
#define DE_DQUE ALGR(DE_N)       // “ double quote right (en)
#define DE_CDOT ALGR(DE_COMM)    // · center dot
#define DE_HELL ALGR(DE_DOT)     // … horizontal ellipsis
#define DE_EN   ALGR(DE_MINS)    // – en dash

#define DE_IEXC S(ALGR(DE_1))    // ̣¡ inverted question mark
#define DE_F1_8 S(ALGR(DE_2))    // ⅛
#define DE_F3_8 S(ALGR(DE_5))    // ⅜
#define DE_F5_8 S(ALGR(DE_6))    // ⅝
#define DE_F7_8 S(ALGR(DE_7))    // ⅞
#define DE_TM   S(ALGR(DE_8))    // ™
#define DE_IQUE S(ALGR(DE_SZ))   // ̣¿ inverted question mark
#define DE_OGNK S(ALGR(DE_ACUT)) // ˛ ogonek (dead)
#define DE_REG  S(ALGR(DE_R))    // ®
#define DE_ARRU S(ALGR(DE_U))    // ↑ up arrow
#define DE_RING S(ALGR(DE_UE))   // ° ring (dead)
#define DE_MCRN S(ALGR(DE_PLUS)) // ¨ macron
#define DE_HDOT S(ALGR(DE_J))    // ˙ dot above (dead)
#define DE_BRV  S(ALGR(DE_HASH)) // ˘ breve (dead)
#define DE_FSQL S(ALGR(DE_Y))    // › single guillemets left
#define DE_FSQR S(ALGR(DE_X))    // ‹ single guillemets right
#define DE_COPY S(ALGR(DE_C))    // ©
#define DE_SQUL S(ALGR(DE_V))    // ‚ single quote left
#define DE_SQUR S(ALGR(DE_B))    // ‘ single quote right
#define DE_SQUE S(ALGR(DE_N))    // ‘ single quote right (en)
#define DE_MULT S(ALGR(DE_COMM)) // × multiplication operator
#define DE_DIV  S(ALGR(DE_DOT))  // ÷ division operator
#define DE_EM   S(ALGR(DE_MINS)) // — em dash

// These defines allow multiple multi-parameter definitions to expand
// for these boards
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

// Masks
#define ___1___ _______
#define ___2___ _______,_______
#define ___3___ _______,_______,_______
#define ___4___ _______,_______,_______,_______
#define ___5___ _______,_______,_______,_______,_______
#define ___6___ _______,_______,_______,_______,_______,_______
#define xxx1xxx KC_NO
#define xxx2xxx KC_NO,  KC_NO
#define xxx3xxx KC_NO,  KC_NO,  KC_NO
#define xxx4xxx KC_NO,  KC_NO,  KC_NO,  KC_NO
#define xxx5xxx KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
#define xxx6xxx KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO

// Quick macros: in dvorak
#define BS_UNDO    C(DE_Z)
#define BS_REST    RCS(DE_Z)
#define BS_REDO    C(DE_Y)
#define BS_COPY    C(KC_INS)
#define BS_CUT     S(KC_DEL)
#define BS_PSTE    S(KC_INS)

// MOD-tap definitions
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_F   MT(MOD_LCTL, DE_F)
#define CTL_J   MT(MOD_LCTL, DE_J)
#define ALT_S   MT(MOD_LALT, DE_S)
#define ALT_L   MT(MOD_LALT, DE_L)
#define GUI_D   MT(MOD_LGUI, DE_D)
#define GUI_K   MT(MOD_RGUI, DE_K)
#define SFT_Y   MT(MOD_LSFT, DE_Y)
#define SFT_SZ  MT(MOD_LSFT, DE_SZ)

#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)

// Layer switches
#define ADJ_CTL LT(_MSE_ADJ, KC_LCTL )
#define NUM_ENT LT(_SYM_NUM, KC_ENT )
#define FUN_TAB LT(_NAV_FUN, KC_TAB )
#define MSE_BSP LT(_MSE_ADJ, KC_BSPC )
#define SYM_SPC LT(_SYM_NUM, KC_SPC )
#define NAV_ESC LT(_NAV_FUN, KC_ESC )

/* Base layout
 * QWERT
 *      ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 *  Tab │  q  │  w  │  e  │  r  │  t  │             │  z  │  u  │  i  │  o  │  p  │  ü
 *      ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 *  E/C │  a  │  s  │  d  │  f  │  g  │             │  h  │  j  │  k  │  l  │  ö  │  ä
 *      ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 *  Sft │  y  │  x  │  c  │  v  │  b  │             │  n  │  m  │ , ; │ . : │ ß ? │ Sft
 *      └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
 *                        │ Ctr │Enter│ Tab │ │BkSpc│Space│ Esc │
 *                        └─Adj─┴─Num─┴─Fun─┘ └─Mou─┴─Sym─┴─Nav─┘
 * The thing about this layout is that these will fit most boards I have.
 */
#define _BL1_5_ DE_Q, DE_W, DE_E, DE_R, DE_T
#define _BR1_5_ DE_Z, DE_U, DE_I, DE_O, DE_P
#define _BL2_5_ DE_A, DE_S, DE_D, DE_F, DE_G
#define _BR2_5_ DE_H, DE_J, DE_K, DE_L, DE_OE
#define _BL3_5_ DE_Y, DE_X, DE_C, DE_V, DE_B
#define _BR3_5_ DE_N, DE_M, DE_COMM, DE_DOT, DE_SZ

#define _BL4_3_ ADJ_CTL,NUM_ENT,FUN_TAB
#define _BR4_3_ MSE_BSP,SYM_SPC,NAV_ESC

// The extra line for the 6th (or 0th) row
#define _BL1_1_ KC_TAB
#define _BR1_1_ DE_UE
#define _BL2_1_ CTL_ESC
#define _BR2_1_ DE_AE
#define _BL3_1_ OSM_SFT
#define _BR3_1_ OSM_SFT

/* Symbols layer
 * _SYM_NUM
 * ┌─────┬─────┬─────┬─────┬─────┐
 * │  €  │  _  │  [  │  ]  │  ^  │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │  \  │  /  │  {  │  }  │  @  │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │ # ' │  $  │  |  │  ~  │  `  │
 * └─────┴─────┴─────┼─────┼─────┼─────┐
 *                   │  ¢  │     │     │
 *                   └─────┴─────┴─────┘
 */
#define _SY1_5_ DE_EURO,DE_UNDS,DE_LBRC,DE_RBRC,DE_CIRC
#define _SY2_5_ DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_AT
#define _SY3_5_ KC_NUHS,DE_DLR,DE_PIPE,DE_TILD,DE_GRV
#define _SY4_3_ DE_CENT, KC_TRNS, KC_TRNS

/* Numbers layer
 * _SYM_NUM
 *  This layer contains numbers and the associated symbols.
 *       ┌─────┬─────┬─────┬─────┬─────┐
 *       │ < > │ 7 / │ 8 ( │ 9 ) │  :  │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │ - _ │ 4 $ │ 5 % │ 6 & │ + * │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │ 0 = │ 1 ! │ 2 " │ 3 § │  .  │
 * ┌─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │  ,  │
 * └─────┴─────┴─────┘
 */
#define _NU1_5_           DE_LABK, KC_7,   KC_8,   KC_9,   DE_COLN
#define _NU2_5_           DE_MINS, KC_4,   KC_5,   KC_6,   DE_PLUS
#define _NU3_5_     DE_0,    KC_1, KC_2,   KC_3,   DE_DOT
#define _NU4_3_  KC_TRNS, KC_TRNS, DE_COMM

/* Navigation layer
 * _NAV_FUN
 * ┌─────┬─────┬─────┬─────┬─────┐
 * │PgUp │ BSp │  ^  │ Del │PgDn │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │Home │  <  │  v  │  >  │ End │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │ Ins │ Cut │Copy │Paste│PrScr│
 * └─────┴─────┴─────┼─────┼─────┼─────┐
 *                   │     │     │     │
 *                   └─────┴─────┴─────┘
 */
#define _NA1_5_ KC_PGUP,KC_BSPC,KC_UP  ,KC_DEL,KC_PGDN
#define _NA2_5_ KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END
#define _NA3_5_ KC_INS, BS_CUT,BS_COPY,BS_PSTE,KC_PSCR
#define _NA4_3_ KC_TRNS,KC_TRNS,KC_TRNS

/* Function layer
 *       ┌─────┬─────┬─────┬─────┬─────┐
 *       │OsAlt│ F07 │ F08 │ F09 │ F10 │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │OsSft│ F04 │ F05 │ F06 │ F11 │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │OsCtl│ F01 │ F02 │ F03 │ F12 │
 * ┌─────┼─────┼─────┼─────┴─────┴─────┘
 * │CAPSL│ App │     │
 * └─────┴─────┴─────┘
 */
#define _FU1_5_           OSM_ALT, KC_F7, KC_F8, KC_F9, KC_F10
#define _FU2_5_           OSM_CTL, KC_F4, KC_F5, KC_F6, KC_F11
#define _FU3_5_           OSM_GUI, KC_F1, KC_F2, KC_F3, KC_F12
#define _FU4_3_  KC_CAPS, KC_APP,  KC_TRNS

/* Mouse layer
 * ┌─────┬─────┬─────┬─────┬─────┐
 * │ <<< │ vvv │ |^| │ ^^^ │ >>> │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │ Slo │ |<| │ |v| │ |>| │ CTL │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │ Fst │ Bt4 │     │ Bt5 │ SFT │
 * └─────┴─────┴─────┼─────┼─────┼─────┐
 *                   │ Bt3 │ Bt1 │ Bt2 │
 *                   └─────┴─────┴─────┘
 */
#define _MO1_5_    KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R
#define _MO2_5_    KC_ACL0, KC_MS_L, KC_MS_D, KC_MS_R, KC_LCTL
#define _MO3_5_    KC_ACL2, KC_BTN4, XXXXXXX, KC_BTN5, KC_LSFT
#define _MO4_3_                               KC_BTN3, KC_BTN1, KC_BTN2

/* Adjustment layer
 *       ┌─────┬─────┬─────┬─────┬─────┐
 *       │     │     │     │EECLR│RESET│
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │     │     │     │     │     │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │     │     │     │     │     │
 * ┌─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │     │
 * └─────┴─────┴─────┘
 */
#define _AD1_5_           KC_NO, KC_NO, KC_NO, EE_CLR, RESET
#define _AD2_5_           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define _AD3_5_           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define _AD4_3_  KC_TRNS, KC_TRNS, KC_TRNS

/* Game layer
 * This layer turns off the tap-hold keys for the left half.
 *      ┌─────┬─────┬─────┬─────┬─────┐
 *      │  Q  │  W  │  E  │  R  │  T  │
 *      ├─────┼─────┼─────┼─────┼─────┤
 *  Tab │  A  │  S  │  D  │  F  │  G  │
 *      ├─────┼─────┼─────┼─────┼─────┤
 * Shift│  Z  │  X  │  C  │  V  │  B  │
 *      └─────┴─────┴─────┼─────┼─────┼─────┐
 *                        │ Esc │Enter│Space│
 *                        └─────┴─────┴─────┘
 */
/* #define _GA1_5_ KC_Q,   KC_W,   KC_E,   KC_R,   KC_T */
/* #define _GA1_1_ _______ */
/* #define _GA2_5_ KC_A,   KC_S,   KC_D,   KC_F,   KC_G */
/* #define _GA2_1_ KC_TAB */
/* #define _GA3_5_ KC_Z,   KC_X,   KC_C,   KC_V,   KC_B */
/* #define _GA3_1_ KC_LSFT */
/* #define _GA4_3_ KC_ESC, KC_ENT, KC_SPC */

/* Media layer
 *       ┌─────┬─────┬─────┬─────┬─────┐
 *       │Speed│ Mod │ Hue │ Sat │ Bri │ RGB light control
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │Togg.│Prev.│MuTog│MuStp│Next │ Media control
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │Sink │Vol -│ Mut │Eject│Vol +│ Volume control
 * ┌─────┼─────┼─────┼─────┴─────┴─────┘
 * │OledL│Veloc│Music│                   Feature control on keyboard
 * └─────┴─────┴─────┘
 */
/* #define _ME1_5_ RGB_SPI,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI */
/* #define _ME2_5_ RGB_TOG,KC_MPRV,KC_MPLY,KC_MSTP,KC_MNXT */
/* #define _ME3_5_ KC_F13, KC_VOLD,KC_MUTE,KC_EJCT,KC_VOLU */
/* #define _ME4_3_ BS_OLED,VLK_TOG,MU_TOG */

