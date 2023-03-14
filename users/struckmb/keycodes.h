#include "keymap_german.h"

// MODs
#define OSM_AGR OSM(MOD_RALT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_HPR OSM(MOD_HYPR)
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
#define SFT_ENT  MT(MOD_RSFT, KC_ENT)
// Thumb layer keys
#define MA_ESC LT(_MSE_ADJ,KC_ESC)
#define SY_ENT LT(_SYM_NUM,KC_ENT)
#define NF_TAB LT(_NAV_FUN,KC_TAB)
#define KB_BSP LT(_ADJUST,KC_BSPC)
#define SN_SPC LT(_SYM_NUM,KC_SPC)
#define NF_APP LT(_NAV_FUN,KC_APP)

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
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

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
#define _________________QWERTZ_L1________________________6_       KC_TAB,  _________________QWERTZ_L1_______________5_
#define _________________QWERTZ_L2________________________6_       CTL_ESC, _________________QWERTZ_L2_______________5_
#define _________________QWERTZ_L3________________________6_       KC_LSFT, _________________QWERTZ_L3_______________5_
// Right half
#define _________________QWERTZ_R1________________________6_       _________________QWERTZ_R1_______________5_, DE_UDIA
#define _________________QWERTZ_R2________________________6_       _________________QWERTZ_R2_______________5_, ALT_AE
#define _________________QWERTZ_R3________________________6_       _________________QWERTZ_R3_______________5_, SFT_ENT

//  * Base Layer: BoNeo
// nx5 keyboards
// Left half
#define __________________BONEO_L1_______________5_                DE_J,    DE_D,    DE_U,    DE_A,    DE_X
#define __________________BONEO_L2_______________5_                DE_C,    DE_T,    DE_I,    DE_E,    DE_O
#define __________________BONEO_L3_______________5_                DE_F,    DE_V,    DE_UDIA, DE_ADIA, DE_ODIA
// Right half
#define __________________BONEO_R1_______________5_                DE_P,    DE_H,    DE_L,    DE_W,    DE_SS
#define __________________BONEO_R2_______________5_                DE_B,    DE_N,    DE_R,    DE_S,    DE_G
#define __________________BONEO_R3_______________5_                DE_Y,    DE_Z,    KC_COMM, KC_DOT,  SFT_K
// nx6 keyboards
#define __________________BONEO_L1________________________6_       KC_TAB,  __________________BONEO_L1_______________5_
#define __________________BONEO_L2________________________6_       CTL_ESC, __________________BONEO_L2_______________5_
#define __________________BONEO_L3________________________6_       KC_LSFT, __________________BONEO_L3_______________5_
// variant for 3x5 keyboards (q here, ue on CTL layer)
#define __________________BONEO_L3a______________5_                DE_F,    DE_V,    DE_Q,    DE_ADIA, DE_ODIA
#define __________________BONEO_L3a_______________________6_       KC_LSFT, __________________BONEO_L3a______________5_
// Left half
#define __________________BONEO_R1________________________6_       __________________BONEO_R1_______________5_, KC_BSPC
#define __________________BONEO_R2________________________6_       __________________BONEO_R2_______________5_, ALT_Q
#define __________________BONEO_R3________________________6_       __________________BONEO_R3_______________5_, SFT_ENT

// * Base Layer: Colemak DH (german variant)
#define _______________COLEMAK_DH_L1_____________5_                DE_Q,    DE_W,    DE_F,    DE_P,    DE_B
#define _______________COLEMAK_DH_L2_____________5_                DE_A,    DE_R,    DE_S,    DE_T,    DE_G
#define _______________COLEMAK_DH_L3_____________5_                DE_Y,    DE_X,    DE_C,    DE_D,    DE_V
#define _______________COLEMAK_DH_L1______________________6_       KC_TAB,  _______________COLEMAK_DH_L1_____________5_
#define _______________COLEMAK_DH_L2______________________6_       CTL_ESC, _______________COLEMAK_DH_L2_____________5_
#define _______________COLEMAK_DH_L3______________________6_       KC_LSFT, _______________COLEMAK_DH_L3_____________5_
// Left half
#define _______________COLEMAK_DH_R1_____________5_                DE_J,    DE_L,    DE_U,    DE_Z,    DE_Q
#define _______________COLEMAK_DH_R2_____________5_                DE_M,    DE_N,    DE_E,    DE_I,    DE_O
#define _______________COLEMAK_DH_R3_____________5_                DE_K,    DE_H,    KC_COMM, KC_DOT,  DE_SS
#define _______________COLEMAK_DH_R1______________________6_       _______________COLEMAK_DH_R1_____________5_, KC_BSPC
#define _______________COLEMAK_DH_R2______________________6_       _______________COLEMAK_DH_R2_____________5_, ALT_Q
#define _______________COLEMAK_DH_R3______________________6_       _______________COLEMAK_DH_R3_____________5_, SFT_ENT
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
#define __THUMB_2_L___2_                                           LT(_NAV_FUN,KC_ESC), LT(_SYM_NUM,KC_ENT)
#define __THUMB_2_R___2_                                           LT(_SYM_NUM,KC_SPC), LT(_NAV_FUN,KC_TAB)
#define _________THUMB_2_2_______4_                                __THUMB_2_L___2_, __THUMB_2_R___2_
#define _________________THUMB_3_3________________________6_       __THUMB_2_L___2_, LT(_MSE_CTL,KC_APP), LT(_ADJUST,KC_BSPC), __THUMB_2_R___2_
#define ___________________________________THUMB_5_5_________________________________________10_ \
    KC_PGUP, KC_PGDN, _________________THUMB_3_3________________________6_, OSM_MEH, OSM_HPR

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
#define ___________________BLANK__________________________6_      _______, _______, _______, _______, _______, _______
#define __________________NUMBERS________________5_               DE_0,    DE_1,    DE_2,    DE_4,    DE_8
#define _________________FUNCTIONS_______________5_               KC_F10,  KC_F1,   KC_F2,   KC_F4,   KC_F8

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------
// │  @  │  _  │  [  │  ]  │ ^ ° │             │ 0 = │ 1 ! │ 2 " │ 4 $ │ 8 ( │  !   |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │  \  │  /  │  {  │  }  │  *  │             │ < > │  (  │  )  │ - _ │  &  │  =   |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ # ' │  $  │  |  │  ~  │  ´  │             │ + * │  %  │  "  │  '  │  €  │CapsW |
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘------
//                   │  §  │ Ly3 │     │ │     │ Ly3 │  ¢  │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define _________________SYMBOLS_L1______________5_               DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define _________________SYMBOLS_L2______________5_               DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define _________________SYMBOLS_L3______________5_               DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT
#define _________________SYMBOLS_R1______________5_               __________________NUMBERS________________5_
#define _________________SYMBOLS_R2______________5_               DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR
#define _________________SYMBOLS_R3______________5_               DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO

#define _________________SYMBOLS_L1_______________________6_      _______, _________________SYMBOLS_L1______________5_
#define _________________SYMBOLS_L2_______________________6_      _______, _________________SYMBOLS_L2______________5_
#define _________________SYMBOLS_L3_______________________6_      _______, _________________SYMBOLS_L3______________5_
#define _________________SYMBOLS_R1_______________________6_      _________________SYMBOLS_R1______________5_, DE_EXLM
#define _________________SYMBOLS_R2_______________________6_      _________________SYMBOLS_R2______________5_, DE_EQL
#define _________________SYMBOLS_R3_______________________6_      _________________SYMBOLS_R3______________5_, CW_TOGG

#define __SYMBOLS_TL__2_                                          DE_SECT, MO(_MSE_CTL)
#define __SYMBOLS_TR__2_                                          MO(_MSE_CTL), ALGR(DE_C)
#define ____________SYMBOLS_TB__________4_                        __SYMBOLS_TL__2_, __SYMBOLS_TR__2_
#define _____________________SYMBOLS_TB___________________6_      __SYMBOLS_TL__2_, KC_TRNS, KC_TRNS, __SYMBOLS_TR__2_

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------
// │PgUp │ BSp │  ↑  │ Del │PgDn │             │ F10 │  F1 │  F2 │  F4 │  F8 │  F11 |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │Home │  ←  │  ↓  │  →  │ End │             │  ←  │  ↓  │  ↑  │  →  │LShft│  F12 |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ Ins │ Cut │Copy │Paste│PrScr│             │Power│OsAGr│     │     │RShft│CapsW |
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘------
//                   │ Adj │     │     │ │     │ App │ Adj │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define ________________NAVIGATION_L1____________5_                KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN
#define ________________NAVIGATION_L2____________5_                KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define ________________NAVIGATION_L3____________5_                KC_INS,  CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR
#define _________________FUNCTION_R1_____________5_                _________________FUNCTIONS_______________5_
#define _________________FUNCTION_R2_____________5_                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LSFT
#define _________________FUNCTION_R3_____________5_                KC_PWR,  OSM_AGR, XXXXXXX, XXXXXXX, KC_RSFT

#define _______________NAVIGATION_L1______________________6_       _______, ________________NAVIGATION_L1____________5_
#define _______________NAVIGATION_L2______________________6_       _______, ________________NAVIGATION_L2____________5_
#define _______________NAVIGATION_L3______________________6_       _______, ________________NAVIGATION_L3____________5_
#define _________________FUNCTION_R1______________________6_       _________________FUNCTIONS_______________5_, KC_F11
#define _________________FUNCTION_R2______________________6_       _________________FUNCTION_R2_____________5_, KC_F12
#define _________________FUNCTION_R3______________________6_       _________________FUNCTION_R3_____________5_, CW_TOGG

#define ____NAVFN_TL__2_                                           MO(_ADJUST), KC_TRNS
#define ____NAVFN_TR__2_                                           KC_APP,  MO(_ADJUST)
#define ____NAVIGATION_AND_FUNCTION_TB__4_                         ____NAVFN_TL__2_, ____NAVFN_TR__2_
#define _________NAVIGATION_AND_FUNCTION_TB_______________6_       ____NAVFN_TL__2_, KC_TRNS, KC_TRNS, ____NAVFN_TR__2_

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │ vvv │ <<< │  ↑  │ >>> │ ^^^ │             │RESET│  ü  │ XXX │ XXX │EECLR│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │  ä  │  ←  │  ↓  │  →  │Pause│             │ SBr+│ Ctl │ Gui │ XXX │ (v) │
// ├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │ XXX │ MB4 │ MB3 │ MB5 │SrlLk│             │ SBr-│ XXX │ XXX │ XXX │RShft│
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │ MB2 │ MB1 │ MB3 │ │     │LShft│ MB3 │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define __________________MOUSE_L1_______________5_                KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define __________________MOUSE_L2_______________5_                DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE
#define __________________MOUSE_L3_______________5_                XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, KC_SCRL
#define __________________MOUSE_R1_______________5_                QK_RBT,  DE_UDIA, XXXXXXX, XXXXXXX, EE_CLR
#define __________________MOUSE_R2_______________5_                KC_ACL0, KC_LCTL, KC_LGUI, XXXXXXX, _______
#define __________________MOUSE_R3_______________5_                KC_ACL2, KC_LALT, XXXXXXX, XXXXXXX, KC_RSFT

#define __________________MOUSE_L1________________________6_       _______, __________________MOUSE_L1_______________5_
#define __________________MOUSE_L2________________________6_       _______, __________________MOUSE_L2_______________5_
#define __________________MOUSE_L3________________________6_       _______, __________________MOUSE_L3_______________5_
#define __________________MOUSE_R1________________________6_       __________________MOUSE_R1_______________5_, KC_NO
#define __________________MOUSE_R2________________________6_       __________________MOUSE_R2_______________5_, KC_NO
#define __________________MOUSE_R3________________________6_       __________________MOUSE_R3_______________5_, _______

#define __________________MOUSE_TB________________________6_       KC_BTN3, KC_BTN1, KC_BTN2, _______, KC_LSFT, _______

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │Eject│ Vol-│ Mute│ Vol+│ Stop│             │ TOGG│Plain│Brthe│Rainb│Swirl│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │ XXX │ Prev│ Play│ Next│ XXX │             │ Mode│ Hue │ Sat │ Val │Brght│
// ├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │BtClr│BtPrv│ XXX │BtNxt│ XXX │             │Snake│Knght│ Xmas│Grdnt│ Test│
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │     │     │     │ │     │     │     │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define _________________CONFIG_L1_______________5_                KC_MSTP, KC_VOLD, KC_MUTE, KC_VOLU, KC_EJCT
#define _________________CONFIG_L2_______________5_                KC_MRWD, KC_MPRV, KC_MS_D, KC_MNXT, KC_MFFD
#define _________________CONFIG_L3_______________5_                XXXXXXX, KC_BRIU, XXXXXXX, KC_BRID, XXXXXXX
#define _________________CONFIG_R1_______________5_                RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW
#define _________________CONFIG_R2_______________5_                RGB_MOD, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
#define _________________CONFIG_R3_______________5_               RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T

#define _________________CONFIG_L1________________________6_       _______, _________________CONFIG_L1_______________5_
#define _________________CONFIG_L2________________________6_       _______, _________________CONFIG_L2_______________5_
#define _________________CONFIG_L3________________________6_       _______, _________________CONFIG_L3_______________5_
#define _________________CONFIG_R1________________________6_       _________________CONFIG_R1_______________5_, KC_NO
#define _________________CONFIG_R2________________________6_       _________________CONFIG_R2_______________5_, KC_NO
#define _________________CONFIG_R3________________________6_       _________________CONFIG_R3_______________5_, _______

#define _________________CONFIG_TB________________________6_       ___________________BLANK__________________________6_

