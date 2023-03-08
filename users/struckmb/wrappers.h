#pragma once
#include "struckmb.h"
#include "keycodes.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

// clang-format off
// Base Layout (QWRTZ)
//      ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
//  Tab │  q  │  w  │  e  │  r  │  t  │             │  z  │  u  │  i  │  o  │  p  │  ü
//      ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
//  C/E │  a  │  s  │  d  │  f  │  g  │             │  h  │  j  │  k  │  l  │  ö  │ A/ä
//      ├─────┼─────┼─Gui─┼─Ctl─┼─────┤             ├─────┼─Ctl─┼─Gui─┼─────┼─Adj─┤
//  Sft │  y  │  x  │  c  │  v  │  b  │             │  n  │  m  │ , ; │ . : │ ß ? │ Sft
//      └─Sft─┴─────┴─────┼─Alt─┼─────┼─────┐ ┌─────┼─────┼─Alt─┼─────┴─────┴─Sft─┘
//                        │ Esc │Enter│ Tab │ │BkSpc│Space│ App │
//                        └─Adj─┴─Num─┴─Fun─┘ └─Cfg─┴─Sym─┴─Nav─┘
// Left half
#define _________________QWERTZ_L1_______________5_       DE_Q,    DE_W,    DE_E,    DE_R,    DE_T
#define _________________QWERTZ_L2_______________5_       DE_A,    DE_S,    DE_D,    DE_F,    DE_G
#define _________________QWERTZ_L3_______________5_       DE_Y,    DE_X,    DE_C,    DE_V,    DE_B
// Left half
#define _________________QWERTZ_R1_______________5_       DE_Z,    DE_U,    DE_I,    DE_O,    DE_P
#define _________________QWERTZ_R1_______________6_       _________________QWERTZ_R1_______________5_, DE_UDIA
#define _________________QWERTZ_R2_______________5_       DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA
#define _________________QWERTZ_R2_______________6_       _________________QWERTZ_R2_______________5_, CTL_AE
#define _________________QWERTZ_R3_______________5_       DE_N,    DE_M,    KC_COMM, KC_DOT,  SFT_SS

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
#define __________________BONEO_L1_______________5_       DE_J,    DE_D,    DE_U,    DE_A,    DE_X
#define __________________BONEO_L2_______________5_       DE_C,    DE_T,    DE_I,    DE_E,    DE_O
#define __________________BONEO_L3_______________5_       DE_F,    DE_V,    DE_UDIA, DE_ADIA, DE_ODIA
// variant for 3x5 keyboards (q here, ue on CTL layer)
#define __________________BONEO_L3a______________5_       DE_F,    DE_V,    DE_Q,    DE_ADIA, DE_ODIA
// Left half
#define __________________BONEO_R1_______________5_       DE_P,    DE_H,    DE_L,    DE_W,    DE_SS
#define __________________BONEO_R1_______________6_       _________________QWERTZ_R1_______________5_, KC_BSPC
#define __________________BONEO_R2_______________5_       DE_B,    DE_N,    DE_R,    DE_S,    DE_G
#define __________________BONEO_R2_______________6_       _________________QWERTZ_R2_______________5_, CTL_Q
#define __________________BONEO_R3_______________5_       DE_N,    DE_M,    KC_COMM, KC_DOT,  SFT_K

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
// *                        `----------------------------------'  `----------------------------------'
// */
//    [_COLEMAK_DH] = LAYOUT(
//     KC_TAB  , DE_Q ,  DE_W   ,  DE_F  ,   DE_P ,   DE_B ,                                        DE_J,   DE_L ,  DE_U ,   DE_Z ,KC_SCLN, KC_BSPC,
//     CTL_ESC , DE_A ,  DE_R   ,  DE_S  ,   DE_T ,   DE_G ,                                        DE_M,   DE_N ,  DE_E ,   DE_I ,  DE_O , CTL_AE,
//     KC_LSFT , DE_Y ,  DE_X   ,  DE_C  ,   DE_D ,   DE_V , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, DE_K,   DE_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
//                                 ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
//    ),
#define _______________COLEMAK_DH_L1_____________5_       DE_Q,    DE_W,    DE_F,    DE_P,    DE_B
#define _______________COLEMAK_DH_L2_____________5_       DE_A,    DE_R,    DE_S,    DE_T,    DE_G
#define _______________COLEMAK_DH_L3_____________5_       DE_Y,    DE_X,    DE_C,    DE_D,    DE_V
// Left half
#define _______________COLEMAK_DH_R1_____________5_       DE_J,    DE_L,    DE_U,    DE_Z,    DE_SS
#define _______________COLEMAK_DH_R1_____________6_       _________________QWERTZ_R1_______________5_, KC_BSPC
#define _______________COLEMAK_DH_R2_____________5_       DE_B,    DE_N,    DE_R,    DE_S,    DE_G
#define _______________COLEMAK_DH_R2_____________6_       _________________QWERTZ_R2_______________5_, CTL_Q
#define _______________COLEMAK_DH_R3_____________5_       DE_N,    DE_M,    KC_COMM, KC_DOT,  SFT_K

// /*
//  * Standard thumb cluster
//  *
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      | LAlt/| Space| Nav  |  | Sym  | Space| AltGr|      |      |
//  *                        |      |      | Enter|      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
#define _________________THUMB_3_3_______________6_       LT(_MSE_CTL,KC_ESC), LT(_SYM_NUM,KC_ENT), LT(_NAV_FUN,KC_TAB), LT(_ADJUST,KC_BSPC), LT(_SYM_NUM,KC_SPC), LT(_NAV_FUN,KC_APP)

#ifdef ASETNIOP_ENABLE
/* ASETNIOP+ layout
 * ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 * │  <  │  v  │  ^  │  >  │     │             │     │  1  │  2  │  4  │  8  │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │  a  │  s  │  e  │  t  │     │             │     │  n  │  i  │  o  │  p  │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │ Esc │ Alt │ Gui │ Ctl │     │             │     │ F1  │ F2  │ F4  │ F8  │
 * └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │ Ctl │ Sft │QWER+│ │ Adj │Space│NoMod│
 *                   └─────┴─────┴─────┘ └─────┴─Sym─┴─────┘
 */
#define _________________QWERTZ_R3_______________5_       DE_N,    DE_M,    KC_COMM, KC_DOT,  SFT_SS
#define ______________ASETNIOP_PLUS_L1___________5_ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
#define ______________ASETNIOP_PLUS_L2___________5_ DE_A,    DE_S,    DE_E,    DE_T,    XXXXXXX
#define ______________ASETNIOP_PLUS_L3___________5_ KC_ESC,  OS_ALT,  OS_GUI,  OS_CTL,  XXXXXXX
#define ______________ASETNIOP_PLUS_L4___________3_ OS_CTL,  OS_SFT,  TO_QZ

#define ______________ASETNIOP_PLUS_R1___________5_ XXXXXXX, DE_1,    DE_2,    DE_4,    DE_8
#define ______________ASETNIOP_PLUS_R2___________5_ XXXXXXX, DE_N,    DE_I,    DE_O,    DE_P
#define ______________ASETNIOP_PLUS_R3___________5_ XXXXXXX, KC_F1,   KC_F2,   KC_F4,   KC_F8
#define _AR4_3_ TO_MA,   SYM_SPC, NO_MOD
#endif // ASETNIOP_ENABLE

// non alphas
#define X2X KC_NO, KC_NO
#define ___________________BLANK_________________5_       _______, _______, _______, _______, _______
#define ___________________BLANK_________________6_       _______, _______, _______, _______, _______, _______
#define __________________NUMBERS________________5_       DE_0,    DE_1,    DE_2,    DE_4,    DE_8
#define _________________FUNCTIONS_______________5_       KC_F10,  KC_F1,   KC_F2,   KC_F4,   KC_F8

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------
// │  @  │  _  │  [  │  ]  │ ^ ° │             │ 0 = │ 1 ! │ 2 " │ 4 $ │ 8 ( │  !  |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │  \  │  /  │  {  │  }  │  *  │             │ < > │  (  │  )  │ - _ │  &  │  =  |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ # ' │  $  │  |  │  ~  │  ´  │             │ + * │  %  │  "  │  '  │  €  │CapsW|
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘------
//                   │  §  │     │     │ │     │     │  ¢  │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define _________________SYMBOLS_L1______________5_       DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define _________________SYMBOLS_L2______________5_       DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define _________________SYMBOLS_L3______________5_       DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT

#define _________________SYMBOLS_R1______________5_       __________________NUMBERS________________5_
#define _________________SYMBOLS_R2______________5_       DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR
#define _________________SYMBOLS_R3______________5_       DE_PLUS, DE_PERC, DE_PIPE, DE_TILD, DE_ACUT
#define _________________SYMBOLS_R1______________6_       __________________NUMBERS________________5_, DE_EXLM
#define _________________SYMBOLS_R2______________6_       DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR, DE_EQL
#define _________________SYMBOLS_R3______________6_       DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO, CW_TOGG

#define _________________SYMBOLS_TB______________6_       DE_SECT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ALGR(DE_C)

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │PgUp │ BSp │  ↑  │ Del │PgDn │             │ F10 │  F1 │  F2 │  F4 │  F8 │
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │Home │  ←  │  ↓  │  →  │ End │             │OsSft│OsCtl│OsGui│     │OsAGr│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │ Ins │ Cut │Copy │Paste│PrScr│             │Power│OsAlt│     │     │CapsW│
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │ARTS-│ASET+│     │ │     │ App │CapsW│
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define ________________NAVIGATION_L1____________5_       KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN
#define ________________NAVIGATION_L2____________5_       KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define ________________NAVIGATION_L3____________5_       KC_INS,  CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR

#define _________________FUNCTION_R1_____________5_       _________________FUNCTIONS_______________5_
#define _________________FUNCTION_R2_____________5_       OSM_SFT, OSM_CTL, OSM_GUI, XXXXXXX, OSM_AGR
#define _________________FUNCTION_R3_____________5_       KC_PWR,  OSM_ALT, XXXXXXX, XXXXXXX, CW_TOGG
#define _________________FUNCTION_R1_____________6_       _________________FUNCTIONS_______________5_, KC_F11
#define _________________FUNCTION_R2_____________6_       OSM_SFT, OSM_CTL, OSM_GUI, XXXXXXX, OSM_AGR, KC_NO
#define _________________FUNCTION_R3_____________6_       KC_PWR,  OSM_ALT, XXXXXXX, XXXXXXX, CW_TOGG, _______

#define _________NAVIGATION_AND_FUNCTION_TB______6_       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, CW_TOGG

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │ vvv │ <<< │  ↑  │ >>> │ ^^^ │             │ XXX │  ü  │ XXX │EECLR│RESET│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │  ä  │  ←  │  ↓  │  →  │Pause│             │ XXX │ Ctl │ Gui │ XXX │ (v) │
// ├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │ XXX │ Bt4 │ Bt3 │ Bt5 │SrlLk│             │ XXX │ XXX │ XXX │ XXX │CapsW│
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │ Bt3 │ Bt1 │ Bt2 │ │     │     │     │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define __________________MOUSE_L1_______________5_       KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define __________________MOUSE_L2_______________5_       DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE
#define __________________MOUSE_L3_______________5_       XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, KC_SCRL

#define __________________MOUSE_R1_______________5_       XXXXXXX, DE_UDIA, XXXXXXX, EE_CLR,  QK_RBT
#define __________________MOUSE_R2_______________5_       KC_ACL0, KC_LCTL, KC_LGUI, XXXXXXX, _______
#define __________________MOUSE_R3_______________5_       KC_ACL2, KC_LALT, KC_ALGR, XXXXXXX, XXXXXXX

#define __________________MOUSE_TB_______________6_       KC_BTN3, KC_BTN1, KC_BTN2, _______, KC_LSFT, _______

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │ STP │ Vol-│ Mute│ Vol+│Eject│             │ TOGG│Plain│Brthe│Rainb│Swirl│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │PrvT │ Prv │ Play│ Next│NextT│             │ Mode│ Hue │ Sat │ Val │Brght│
// ├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │ XXX │SBr- │ XXX │SBr+ │ XXX │             │Snake│Knght│ Xmas│Grdnt│ Test│
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │     │     │     │ │     │     │     │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define _________________CONFIG_L1_______________5_       KC_MSTP, KC_VOLD, KC_MUTE, KC_VOLU, KC_EJCT
#define _________________CONFIG_L2_______________5_       KC_MRWD, KC_MPRV, KC_MS_D, KC_MNXT, KC_MFFD
#define _________________CONFIG_L3_______________5_       XXXXXXX, KC_BRIU, XXXXXXX, KC_BRID, XXXXXXX

#define _________________CONFIG_R1_______________5_       RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW
#define _________________CONFIG_R2_______________5_       RGB_MOD, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
#define _________________CONFIG_R3_______________5_      RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T

#define _________________CONFIG_TB_______________6_       ___________________BLANK_________________6_

// clang-format on
