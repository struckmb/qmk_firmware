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
    NO_MOD,
    // Encoder button
#   ifdef ENCODER_ENABLE
    BS_ENC0,
    BS_ENC1,
#   endif // ENCODER_ENABLE
    //use for keymap specific codes
    KEYMAP_SAFE_RANGE
};
#ifndef ENCODER_ENABLE
#define BS_ENC0 KC_NO
#define BS_ENC1 KC_NO
#endif // ENCODER_ENABLE

/// Enumeration of layers
enum userspace_layers {
    _DEFAULT = 0, // Base layer
    _HRM_OFF,     // Base layer w/o home row mod
#   ifdef COMBO_ENABLE
    _ASETNIOP,    // ASETNIOP layer
#   endif // COMBO_ENABLE
    _SYM_NUM,     // L: Symbols layer,    R: Numbers layer
    _NAV_FUN,     // L: Navigation layer, R: Function keys layer
    _MSE_ADJ      // L: Mouse keys layer, R: Keyboard adjustments
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
#define LAYOUT_split_3x5_4_wrapper(...) LAYOUT_split_3x5_4(__VA_ARGS__)

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

// MOD definitions
#define SFT_Y   MT(MOD_LSFT, DE_Y)
#define ALT_S   MT(MOD_LALT, DE_S)
#define GUI_D   MT(MOD_LGUI, DE_D)
#define CTL_F   MT(MOD_LCTL, DE_F)
#define CTL_J   MT(MOD_LCTL, DE_J)
#define GUI_K   MT(MOD_RGUI, DE_K)
#define ALT_L   MT(MOD_LALT, DE_L)
#define SFT_SZ  MT(MOD_LSFT, DE_SZ)

#define ALT_AE  MT(MOD_LALT, DE_AE)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define OS_ALT  OSM(MOD_LALT)
#define OS_ALG  OSM(MOD_RALT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_SFT  OSM(MOD_LSFT)

// Layer switches
#define ADJ_HOE LT(_MSE_ADJ, DE_OE )
#define ADJ_ESC LT(_MSE_ADJ, KC_ESC )
#define NUM_ENT LT(_SYM_NUM, KC_ENT )
#define FUN_TAB LT(_NAV_FUN, KC_TAB )
#define MSE_BSP LT(_MSE_ADJ, KC_BSPC )
#define SYM_SPC LT(_SYM_NUM, KC_SPC )
#define NAV_DEL LT(_NAV_FUN, KC_DEL )
#define TO_DP   DF(_DEFAULT)
#define TO_DM   DF(_HRM_OFF)
#ifdef COMBO_ENABLE
#   define TO_AS   DF(_ASETNIOP)
#else
#   define TO_AS   DF(_DEFAULT)
#endif // COMBO_ENABLE
#define TO_MA   OSL(_MSE_ADJ)
#define TO_NF   OSL(_NAV_FUN)

// The extra side rows and thumbs
#define _BL1_1_ KC_TAB
#define _BL2_1_ CTL_ESC
#define _BL3_1_ OS_SFT
#define _BR1_1_ DE_UE
#define _BR2_1_ ALT_AE
#define _BR3_1_ OS_SFT
#define _BL4_3_ ADJ_ESC,NUM_ENT,FUN_TAB
#define _BR4_3_ MSE_BSP,SYM_SPC,NAV_DEL

/* QWERTY layout + HRM
 * 
 *      ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 *  Tab │  q  │  w  │  e  │  r  │  t  │             │  z  │  u  │  i  │  o  │  p  │  ü
 *      ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 *  C/E │  a  │  s  │  d  │  f  │  g  │             │  h  │  j  │  k  │  l  │  ö  │ A/ä
 *      ├─────┼─Alt─┼─Gui─┼─Ctl─┼─────┤             ├─────┼─Ctl─┼─Gui─┼─Alt─┼─Adj─┤
 *  Sft │  y  │  x  │  c  │  v  │  b  │             │  n  │  m  │ , ; │ . : │ ß ? │ Sft
 *      └─Sft─┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─Sft─┘
 *                        │ Esc │Enter│ Tab │ │BkSpc│Space│ Del │
 *                        └─Adj─┴─Num─┴─Fun─┘ └─Mou─┴─Sym─┴─Nav─┘
 */
#define _BL1_5_ DE_Q,  DE_W,  DE_E,  DE_R,    DE_T
#define _BL2_5_ DE_A,  ALT_S, GUI_D, CTL_F,   DE_G
#define _BL3_5_ SFT_Y, DE_X,  DE_C,  DE_V,    DE_B
#define _BR1_5_ DE_Z,  DE_U,  DE_I,  DE_O,    DE_P
#define _BR2_5_ DE_H,  CTL_J, GUI_K, ALT_L,   ADJ_HOE
#define _BR3_5_ DE_N,  DE_M,  DE_COMM, DE_DOT, SFT_SZ

/* QWERTY layout
 *      ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 *  Tab │  q  │  w  │  e  │  r  │  t  │             │  z  │  u  │  i  │  o  │  p  │  ü
 *      ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 *  C/E │  a  │  s  │  d  │  f  │  g  │             │  h  │  j  │  k  │  l  │  ö  │  ä
 *      ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 *  Sft │  y  │  x  │  c  │  v  │  b  │             │  n  │  m  │ , ; │ . : │ ß ? │ Sft
 *      └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
 *                        │ Esc │Enter│ Tab │ │BkSpc│Space│ Del │
 *                        └─Adj─┴─Num─┴─Fun─┘ └─Mou─┴─Sym─┴─Nav─┘
 */
#define _QL1_5_ DE_Q, DE_W, DE_E, DE_R, DE_T
#define _QL2_5_ DE_A, DE_S, DE_D, DE_F, DE_G
#define _QL3_5_ DE_Y, DE_X, DE_C, DE_V, DE_B
#define _QR1_5_ DE_Z, DE_U, DE_I, DE_O, DE_P
#define _QR2_5_ DE_H, DE_J, DE_K, DE_L, DE_OE
#define _QR3_5_ DE_N, DE_M, DE_COMM, DE_DOT, DE_SZ

/* ASETNIOP+ layout
 * ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 * │  <  │  v  │  ^  │  >  │     │             │     │  1  │  2  │  4  │  8  │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │  a  │  s  │  e  │  t  │     │             │     │  n  │  i  │  o  │  p  │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │ Esc │ Alt │ Gui │ Ctl │     │             │     │ F1  │ F2  │ F4  │ F8  │
 * └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │ Ctl │ Sft │NoMod│ │     │Space│     │
 *                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
#define _AL1_5_ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
#define _AL2_5_ DE_A,    DE_S,    DE_E,    DE_T,    XXXXXXX
#define _AL3_5_ KC_ESC,  OS_ALT,  OS_GUI,  OS_CTL,  XXXXXXX
#define _AL4_3_ OS_CTL,  OS_SFT,  XXXXXXX

#define _AR1_5_ XXXXXXX, DE_1,    DE_2,    DE_4,    DE_8
#define _AR2_5_ XXXXXXX, DE_N,    DE_I,    DE_O,    DE_P
#define _AR3_5_ XXXXXXX, KC_F1,   KC_F2,   KC_F4,   KC_F8
#define _AR4_3_ TO_MA,   SYM_SPC, XXXXXXX

/* Symbols layer
 * _SYM_NUM
 * ┌─────┬─────┬─────┬─────┬─────┐
 * │  €  │  _  │  [  │  ]  │  ^  │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │  \  │  /  │  {  │  }  │  @  │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │ # ' │  $  │  |  │  ~  │  ´  │
 * └─────┴─────┴─────┼─────┼─────┼─────┐
 *                   │     │     │     │
 *                   └─────┴─────┴─────┘
 */
#define _SY1_5_ DE_AT,  DE_UNDS,DE_LBRC,DE_RBRC,DE_CIRC
#define _SY2_5_ DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR
#define _SY3_5_ KC_NUHS,DE_DLR, DE_PIPE,DE_TILD,DE_ACUT
#define _SY4_3_ KC_TRNS, KC_TRNS, KC_TRNS

/* Numbers layer
 * _SYM_NUM
 *  This layer contains numbers and the associated symbols.
 *       ┌─────┬─────┬─────┬─────┬─────┐
 *       │ < > │ 1 ! │ 2 " │ 4 $ │ 8 ( │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │  =  │  (  │  )  │ - _ │  &  │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │ + * │  %  │  "  │  '  │  €  │
 * ┌─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │  ¢  │
 * └─────┴─────┴─────┘
 */
#define _NU1_5_           DE_LABK, KC_1,    KC_2,    KC_4,    KC_8
#define _NU2_5_           DE_EQL,  DE_LPRN, DE_RPRN, DE_MINS,  DE_AMPR
#define _NU3_5_           DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO
#define _NU4_3_  KC_TRNS, KC_TRNS, DE_CENT

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
 *       │     │ F01 │ F02 │ F04 │ F08 │
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │     │OsCtl│OsGui│OsAlt│OsAGr│
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │     │NoMod│     │     │OsSft│
 * ┌─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │ App │CapsW│
 * └─────┴─────┴─────┘
 */
#define _FU1_5_         KC_NO,  KC_F1,  KC_F2,  KC_F4,  KC_F8
#define _FU2_5_         NO_MOD, OS_CTL, OS_GUI, OS_ALT, OS_ALG
#define _FU3_5_         KC_NO,  NO_MOD, KC_NO,  KC_NO,  OS_SFT
#define _FU4_3_  KC_NO, KC_APP, CAPSWRD

/* Mouse layer
 * ┌─────┬─────┬─────┬─────┬─────┐
 * │ vvv │ <<< │ |^| │ >>> │ ^^^ │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │ Slo │ |<| │ |v| │ |>| │ CTL │
 * ├─────┼─────┼─────┼─────┼─────┤
 * │ Fst │ Bt4 │     │ Bt5 │ SFT │
 * └─────┴─────┴─────┼─────┼─────┼─────┐
 *                   │ Bt3 │ Bt1 │ Bt2 │
 *                   └─────┴─────┴─────┘
 */
#define _MO1_5_    KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define _MO2_5_    KC_ACL0, KC_MS_L, KC_MS_D, KC_MS_R, KC_LCTL
#define _MO3_5_    KC_ACL1, KC_BTN4, XXXXXXX, KC_BTN5, KC_LSFT
#define _MO4_3_                               KC_BTN3, KC_BTN1, KC_BTN2

/* Adjustment layer
 *       ┌─────┬─────┬─────┬─────┬─────┐
 *       │QWER-│  ü  │     │EECLR│RESET│
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │ASET+│  ä  │OsSft│     │NoHrm│
 *       ├─────┼─────┼─────┼─────┼─────┤
 *       │QWER+│     │     │     │CapsW│
 * ┌─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │     │
 * └─────┴─────┴─────┘
 */
#define _AD1_5_           TO_DM,   DE_UE,  KC_NO,  EE_CLR, QK_BOOT
#define _AD2_5_           TO_AS,   DE_AE,  OS_SFT, KC_NO,  KC_NO
#define _AD3_5_           TO_DP,   NO_MOD, KC_NO,  KC_NO,  CAPSWRD
#define _AD4_3_  KC_TRNS, KC_TRNS, KC_TRNS

