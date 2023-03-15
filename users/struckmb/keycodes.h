#include "keymap_german.h"

// MODs
#define OSM_AGR OSM(MOD_RALT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_HYP OSM(MOD_HYPR)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_SFT OSM(MOD_LSFT)
// HRM
#define ALT_AE   MT(MOD_LALT, DE_ADIA)
#define ALT_Q    MT(MOD_LALT, DE_Q)
#define ALT_V    MT(MOD_LALT, DE_V)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_F    MT(MOD_LCTL, DE_F)
#define CTL_J    MT(MOD_LCTL, DE_J)
#define GUI_D    MT(MOD_LGUI, DE_D)
#define GUI_K    MT(MOD_LGUI, DE_K)
#define SFT_Y    MT(MOD_LSFT, DE_Y)
#define SFT_SS   MT(MOD_LSFT, DE_SS)
// Thumb layer keys
#define NF_ESC LT(_NAV_FUN,KC_ESC)
#define SY_ENT LT(_SYM_NUM,KC_ENT)
#define NF_TAB LT(_NAV_FUN,KC_TAB)
#define AD_BSP LT(_ADJUST,KC_BSPC)
#define SN_SPC LT(_SYM_NUM,KC_SPC)
#define MC_APP LT(_MSE_CTL,KC_APP)

// cut copy paste
#define CCP_CUT S(KC_DEL)
#define CCP_CPY C(KC_INS)
#define CCP_PST S(KC_INS)

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

/*
Blocks for some keyboard layouts. Organized so we can quickly adapt and modify
all of them at once, rather than for each keyboard, one at a time. And this
allows for much cleaner blocks in the keymaps. For instance Tap/Hold for
Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace then you need
to add/remove underscores to keep the lengths consistent.
*/

#ifdef QWERTZ_ENABLE
// nx5 keyboards
// Left half
#define _________________QWERTZ_L1_______________5_                DE_Q,    DE_W,    DE_E,    DE_R,    DE_T
#define _________________QWERTZ_L2_______________5_                DE_A,    DE_S,    DE_D,    DE_F,    DE_G
#define _________________QWERTZ_L3_______________5_                DE_Y,    DE_X,    DE_C,    DE_V,    DE_B
// Right half
#define _________________QWERTZ_R1_______________5_                DE_Z,    DE_U,    DE_I,    DE_O,    DE_P
#define _________________QWERTZ_R2_______________5_                DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA
#define _________________QWERTZ_R3_______________5_                DE_N,    DE_M,    KC_COMM, KC_DOT,  SFT_SS
// nx6 keyboards
// Left half
#define _____________________QWERTZ_L1____________________6_       KC_TAB,  _________________QWERTZ_L1_______________5_
#define _____________________QWERTZ_L2____________________6_       CTL_ESC, _________________QWERTZ_L2_______________5_
#define _____________________QWERTZ_L3____________________6_       KC_LSFT, _________________QWERTZ_L3_______________5_
// Right half
#define _____________________QWERTZ_R1____________________6_       _________________QWERTZ_R1_______________5_, DE_UDIA
#define _____________________QWERTZ_R2____________________6_       _________________QWERTZ_R2_______________5_, ALT_AE
#define _____________________QWERTZ_R3____________________6_       _________________QWERTZ_R3_______________5_, KC_RSFT
#endif

#ifdef BONE_ENABLE
//  * Base Layer: Bone
// nx5 keyboards
// Left half
#define __________________BONE_L1________________5_                DE_J,    DE_D,    DE_U,    DE_A,    DE_X
#define __________________BONE_L2________________5_                DE_C,    DE_T,    DE_I,    DE_E,    DE_O
#define __________________BONE_L3________________5_                DE_F,    DE_V,    DE_UDIA, DE_ADIA, DE_ODIA
// variant for 3x5 keyboards (q here, ue on CTL layer)
#define __________________BONE_L3a_______________5_                DE_F,    DE_V,    DE_Q,    DE_ADIA, DE_ODIA
// Right half
#define __________________BONE_R1________________5_                DE_P,    DE_H,    DE_L,    DE_W,    DE_SS
#define __________________BONE_R2________________5_                DE_B,    DE_N,    DE_R,    DE_S,    DE_G
#define __________________BONE_R3________________5_                DE_Y,    DE_Z,    KC_COMM, KC_DOT,  SFT_K
// nx6 keyboards
#define ______________________BONEO_L1____________________6_       KC_TAB,  __________________BONE_L1________________5_
#define ______________________BONEO_L2____________________6_       CTL_ESC, __________________BONE_L2________________5_
#define ______________________BONEO_L3____________________6_       KC_LSFT, __________________BONE_L3________________5_
#define ______________________BONEO_L3a___________________6_       KC_LSFT, __________________BONE_L3a_______________5_
// Left half
#define ______________________BONEO_R1____________________6_       __________________BONE_R1________________5_, KC_BSPC
#define ______________________BONEO_R2____________________6_       __________________BONE_R2________________5_, ALT_Q
#define ______________________BONEO_R3____________________6_       __________________BONE_R3________________5_, KC_RSFT
#endif

#ifdef COLEMAK_ENABLE
// * Base Layer: Colemak DH (german variant)
// nx5 keyboards
// Left half
#define _______________COLEMAK_DH_L1_____________5_                DE_Q,    DE_W,    DE_F,    DE_P,    DE_B
#define _______________COLEMAK_DH_L2_____________5_                DE_A,    DE_R,    DE_S,    DE_T,    DE_G
#define _______________COLEMAK_DH_L3_____________5_                DE_Y,    DE_X,    DE_C,    DE_D,    DE_V
// Left half
#define _______________COLEMAK_DH_R1_____________5_                DE_J,    DE_L,    DE_U,    DE_Z,    DE_Q
#define _______________COLEMAK_DH_R2_____________5_                DE_M,    DE_N,    DE_E,    DE_I,    DE_O
#define _______________COLEMAK_DH_R3_____________5_                DE_K,    DE_H,    KC_COMM, KC_DOT,  DE_SS
// nx6 keyboards
// Left half
#define ___________________COLEMAK_DH_L1__________________6_       KC_TAB,  _______________COLEMAK_DH_L1_____________5_
#define ___________________COLEMAK_DH_L2__________________6_       CTL_ESC, _______________COLEMAK_DH_L2_____________5_
#define ___________________COLEMAK_DH_L3__________________6_       KC_LSFT, _______________COLEMAK_DH_L3_____________5_
#define ___________________COLEMAK_DH_R1__________________6_       _______________COLEMAK_DH_R1_____________5_, KC_BSPC
#define ___________________COLEMAK_DH_R2__________________6_       _______________COLEMAK_DH_R2_____________5_, ALT_Q
#define ___________________COLEMAK_DH_R3__________________6_       _______________COLEMAK_DH_R3_____________5_, KC_RSFT
#endif

// /*
//  * Standard thumb cluster
//           | PgUp | PgDn │ Esc │Enter│ App | |BkSpc│Space│ Tab │OsMeh |OsHypr|
//            ------+------└─Fn──┴─Num─┴-Mse-   -Cfg-┴─Sym─┴─Nav─┘------+------
//  *
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        | PgUp | PgDn |MsCtl/|SymNr/|NavFn/|  |  Adj/|SymNr/|NavFn/|      |      |
//  *                        |      |      |  Esc |  Ent | Menu |  |  BSp |  Spc |  Tab |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
#define __THUMB_2_L___2_                                           NF_ESC,  SY_ENT
#define __THUMB_2_R___2_                                           SN_SPC,  NF_TAB
#define _________THUMB_2_2_______4_                                __THUMB_2_L___2_, __THUMB_2_R___2_
#define _________________THUMB_3_3________________________6_       __THUMB_2_L___2_, MC_APP,  AD_BSP,  __THUMB_2_R___2_
#define ________________________________________THUMB_5_5____________________________________10_ \
    KC_PGUP, KC_PGDN, _________________THUMB_3_3________________________6_, OSM_MEH, OSM_HYP

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
#define ______________ASETNIOP_PLUS_L1___________5_                C_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
#define ______________ASETNIOP_PLUS_L2___________5_                E_A,    DE_S,    DE_E,    DE_T,    XXXXXXX
#define ______________ASETNIOP_PLUS_L3___________5_                C_ESC,  OS_ALT,  OS_GUI,  OS_CTL,  XXXXXXX
#define ______________ASETNIOP_PLUS_L4___________3_                S_CTL,  OS_SFT,  TO_QZ

#define ______________ASETNIOP_PLUS_R1___________5_                XXXXXX, DE_1,    DE_2,    DE_4,    DE_8
#define ______________ASETNIOP_PLUS_R2___________5_                XXXXXX, DE_N,    DE_I,    DE_O,    DE_P
#define ______________ASETNIOP_PLUS_R3___________5_                XXXXXX, KC_F1,   KC_F2,   KC_F4,   KC_F8
#define _AR4_3_ TO_MA,   SYM_SPC, NO_MOD
#endif // ASETNIOP_ENABLE

// non alphas
#define X2X KC_NO, KC_NO
#define ___________________BLANK_________________5_               _______, _______, _______, _______, _______
#define _______________________BLANK______________________6_      _______, ___________________BLANK_________________5_
#define __________________NUMBERS________________5_               DE_0,    DE_1,    DE_2,    DE_4,    DE_8
#define _________________FUNCTIONS_______________5_               KC_F10,  KC_F1,   KC_F2,   KC_F4,   KC_F8

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------
// │  @  │  _  │  [  │  ]  │ ^ ° │             │ 0 = │ 1 ! │ 2 " │ 4 $ │ 8 ( │  !   |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │  \  │  /  │  {  │  }  │  *  │             │ < > │  (  │  )  │ - _ │  &  │  =   |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ # ' │  $  │  |  │  ~  │  ´  │             │ + * │  %  │  "  │  '  │  €  │      |
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘------
//                   │  §  │     │     │ │     │     │  ¢  │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define ________________SYMBOLS_L1_______________5_               DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define ________________SYMBOLS_L2_______________5_               DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define ________________SYMBOLS_L3_______________5_               DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT
#define ________________SYMBOLS_R1_______________5_               __________________NUMBERS________________5_
#define ________________SYMBOLS_R2_______________5_               DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR
#define ________________SYMBOLS_R3_______________5_               DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO

#define _____________________SYMBOLS_L1___________________6_      _______, ________________SYMBOLS_L1_______________5_
#define _____________________SYMBOLS_L2___________________6_      _______, ________________SYMBOLS_L2_______________5_
#define _____________________SYMBOLS_L3___________________6_      _______, ________________SYMBOLS_L3_______________5_
#define _____________________SYMBOLS_R1___________________6_      ________________SYMBOLS_R1_______________5_, DE_EXLM
#define _____________________SYMBOLS_R2___________________6_      ________________SYMBOLS_R2_______________5_, DE_EQL
#define _____________________SYMBOLS_R3___________________6_      ________________SYMBOLS_R3_______________5_, _______

#define __SYMBOLS_TL__2_                                          DE_SECT, KC_TRNS
#define __SYMBOLS_TR__2_                                          KC_TRNS, ALGR(DE_C)
#define ____________SYMBOLS_TB__________4_                        __SYMBOLS_TL__2_, __SYMBOLS_TR__2_
#define _____________________SYMBOLS_TB___________________6_      __SYMBOLS_TL__2_, KC_TRNS, KC_TRNS, __SYMBOLS_TR__2_

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------
// │ PgUp│ BSp │  ↑  │ Del │ PgDn│             │ F10 │  F1 │  F2 │  F4 │  F8 │  F11 |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ Home│  ←  │  ↓  │  →  │ End │             │OsAlt│OsCtl│OsGui│OsSft│ RSft│  F12 |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ Ins │ Cut │ Copy│Paste│PrScr│             │Power│OsAGr│OsMeh│OsHyp│CapsW│CapsW |
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘------
//                   │ Adj │     │     │ │     │ App │ Adj │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define ______________NAVIGATION_L1______________5_                KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN
#define ______________NAVIGATION_L2______________5_                KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define ______________NAVIGATION_L3______________5_                KC_INS,  CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR
#define _______________FUNCTION_R1_______________5_                _________________FUNCTIONS_______________5_
#define _______________FUNCTION_R2_______________5_                OSM_ALT, OSM_CTL, OSM_GUI, OSM_SFT, KC_RSFT
#define _______________FUNCTION_R3_______________5_                KC_PWR,  OSM_AGR, OSM_MEH, OSM_HYP, CW_TOGG

#define _______________NAVIGATION_L1______________________6_       _______, ______________NAVIGATION_L1______________5_
#define _______________NAVIGATION_L2______________________6_       _______, ______________NAVIGATION_L2______________5_
#define _______________NAVIGATION_L3______________________6_       _______, ______________NAVIGATION_L3______________5_
#define _________________FUNCTION_R1______________________6_       _______________FUNCTION_R1_______________5_, KC_F11
#define _________________FUNCTION_R2______________________6_       _______________FUNCTION_R2_______________5_, KC_F12
#define _________________FUNCTION_R3______________________6_       _______________FUNCTION_R3_______________5_, CW_TOGG

#define ___NAVFN_TL___2_                                           MO(_ADJUST), KC_TRNS
#define ___NAVFN_TR___2_                                           KC_APP,  MO(_ADJUST)
#define _____________NAVIGATION_AND_FUNCTION_TB___________6_       ___NAVFN_TL___2_, KC_TRNS, KC_TRNS, ___NAVFN_TR___2_

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │ vvv │ <<< │  ↑  │ >>> │ ^^^ │             │MsSp+│  ü  │ Vol+│Eject│ XXX │
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │  ä  │  ←  │  ↓  │  →  │Pause│             │MsSpN│ Prev│ Vol-│ Next│ (v) │
// ├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │ XXX │ MB4 │ MB3 │ MB5 │SrlLk│             │MsSp-│ Play│ Mute│ Stop│RShft│
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │ MB2 │ MB1 │ MB3 │ │     │LShft│ MB3 │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define __________________MOUSE_L1_______________5_                KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define __________________MOUSE_L2_______________5_                DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE
#define __________________MOUSE_L3_______________5_                XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, KC_SCRL

#define __________________MOUSE_R1_______________5_                KC_ACL2, DE_UDIA, KC_VOLU, KC_EJCT, XXXXXXX
#define __________________MOUSE_R2_______________5_                KC_ACL1, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX
#define __________________MOUSE_R3_______________5_                KC_ACL0, KC_MPLY, KC_MUTE, KC_MSTP, KC_RSFT

#define ______________________MOUSE_L1____________________6_       _______, __________________MOUSE_L1_______________5_
#define ______________________MOUSE_L2____________________6_       _______, __________________MOUSE_L2_______________5_
#define ______________________MOUSE_L3____________________6_       _______, __________________MOUSE_L3_______________5_
#define ______________________MOUSE_R1____________________6_       __________________MOUSE_R1_______________5_, KC_NO
#define ______________________MOUSE_R2____________________6_       __________________MOUSE_R2_______________5_, KC_NO
#define ______________________MOUSE_R3____________________6_       __________________MOUSE_R3_______________5_, _______

#define ___MOUSE_TL___2_                                           KC_BTN2, KC_BTN1
#define ___MOUSE_TR___2_                                           KC_LSFT, KC_BTN3
#define ______________________MOUSE_TB____________________6_       ___MOUSE_TL___2_, KC_BTN3, _______, ___MOUSE_TR___2_

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │ TOGG│Plain│Brthe│Rainb│Swirl│             │EEClr│(Bt1)│(Bt2)│(Bt3)│(B/U)│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │Speed│ Val │ Sat │ Hue │ Mode│             │(BtC)│(Bt←)│ XXX │(Bt→)│ XXX │
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼Mouse┼─────┼─────┤
// │ Test│ Xmas│Grdnt│Knght│Snake│             │Reset│Build│ XXX │ XXX │ Sft │
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │     │     │     │ │     │     │     │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define _________________CONFIG_L1_______________5_                RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW
#define _________________CONFIG_L2_______________5_                RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD
#define _________________CONFIG_L3_______________5_                RGB_M_T, RGB_M_X, RGB_M_G, RGB_M_K, RGB_M_SN
#define _________________CONFIG_R1_______________5_                EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, OU_AUTO
#define _________________CONFIG_R2_______________5_                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________CONFIG_R3_______________5_                QK_BOOT, QK_MAKE, XXXXXXX, XXXXXXX, KC_LSFT

#define ____________________CONFIG_L1_____________________6_       _______, _________________CONFIG_L1_______________5_
#define ____________________CONFIG_L2_____________________6_       _______, _________________CONFIG_L2_______________5_
#define ____________________CONFIG_L3_____________________6_       _______, _________________CONFIG_L3_______________5_
#define ____________________CONFIG_R1_____________________6_       _________________CONFIG_R1_______________5_, KC_NO
#define ____________________CONFIG_R2_____________________6_       _________________CONFIG_R2_______________5_, KC_NO
#define ____________________CONFIG_R3_____________________6_       _________________CONFIG_R3_______________5_, _______

#define ____________________CONFIG_TB_____________________6_       _______________________BLANK______________________6_
