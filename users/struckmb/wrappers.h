#pragma once
#include "struckmb.h"

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


// Linux extended chars
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

// cut copy paste
#define CCP_CUT S(KC_DEL)
#define CCP_CPY C(KC_INS)
#define CCP_PST S(KC_INS)

// MODs
#define OSM_ALT OSM(MOD_LALT)
#define OSM_AGR OSM(MOD_RALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
// HRM
#define ALT_M    MT(MOD_LALT, DE_M)
#define ALT_V    MT(MOD_LALT, DE_V)
#define CTL_AE   MT(MOD_LCTL, DE_ADIA)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_F    MT(MOD_LCTL, DE_F)
#define CTL_J    MT(MOD_LCTL, DE_J)
#define GUI_D    MT(MOD_LGUI, DE_D)
#define GUI_K    MT(MOD_LGUI, DE_K)
#define SFT_Y    MT(MOD_LSFT, DE_Y)
#define SFT_SS   MT(MOD_LSFT, DE_SS)
// Thumb layer keys
#define MA_ESC LT(_MSE_ADJ,KC_ESC)
#define SY_ENT LT(_SYM_NUM,KC_ENT)
#define NF_TAB LT(_NAV_FUN,KC_TAB)
#define KB_BSP LT(_KB_CONF,KC_BSPC)
#define SN_SPC LT(_SYM_NUM,KC_SPC)
#define NF_APP LT(_NAV_FUN,KC_APP)



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
#define _________________QWERTZ_R1_______________6_       DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA
#define _________________QWERTZ_R2_______________6_       DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, CTL_AE
#define _________________QWERTZ_R3_______________5_       DE_N,    DE_M,    KC_COMM, KC_DOT,  SFT_SS
// Thumb cluster
#define _________________THUMB_3_3_______________6_       LT(_MSE_ADJ,KC_ESC), LT(_SYM_NUM,KC_ENT), LT(_NAV_FUN,KC_TAB), LT(_KB_CONF,KC_BSPC), LT(_SYM_NUM,KC_SPC), LT(_NAV_FUN,KC_APP)

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
#define _________________SYMBOLS_R3______________6_       DE_PLUS, DE_PERC, DE_PIPE, DE_TILD, DE_ACUT, CW_TOGG

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
