#pragma once
#include "keymap_german.h"

// MODs
#define OSM_AGR OSM(MOD_RALT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_HYP OSM(MOD_HYPR)
// extended HRM
#define ALT_SS MT(MOD_LALT, DE_SS)
#define ALT_TAB MT(MOD_LALT, KC_TAB)
#define ALT_UE MT(MOD_LALT, DE_UDIA)
#define CTL_AE MT(MOD_LCTL, DE_ADIA)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_Q MT(MOD_LCTL, DE_Q)
#define GUI_B MT(MOD_LGUI, DE_B)
#define GUI_G MT(MOD_LGUI, DE_G)
#define GUI_H MT(MOD_LGUI, DE_H)
#define GUI_M MT(MOD_LGUI, DE_M)
#define GUI_O MT(MOD_LGUI, DE_O)
#define GUI_Z MT(MOD_LGUI, DE_Z)

// Thumb / layer keys
#define AD_BSP LT(_ADJUST, KC_BSPC)
#define A_S_PDN MT(MOD_LALT | MOD_LSFT, KC_PGDN)
#define LY_ADJ MO(_ADJUST)
#define MC_APP LT(_MSE_CTL, KC_APP)
#define MC_M LT(_MSE_CTL, DE_M)
#define MC_O LT(_MSE_CTL, DE_O)
#define MC_P LT(_MSE_CTL, DE_P)
#define MC_Z LT(_MSE_CTL, DE_Z)
#define MEH_PUP MT(MOD_MEH, KC_PGUP)
#define NF_ESC LT(_NAV_FUN, KC_ESC)
#define NF_TAB LT(_NAV_FUN, KC_TAB)
#define SN_SPC LT(_SYM_NUM, KC_SPC)
#define SY_ENT LT(_SYM_NUM, KC_ENT)

// Base layers
#ifdef QWERTZ_ENABLE
#    define DF_QWER DF(_QWERTZ)
#else
#    define DF_QWER DF(0)
#endif // QWERTZ_ENABLE
#ifdef BONE_ENABLE
#    define DF_BONE DF(_BONE)
#else
#    define DF_BONE KC_NO
#endif // BONE_ENABLE
#ifdef WORKMAN_ENABLE
#    define DF_WORK DF(_WORKMAN)
#else
#    define DF_WORK KC_NO
#endif // WORKMAN_ENABLE
#ifdef COLEMAK_ENABLE
#    define DF_COLE DF(_COLEMAK_DH)
#else
#    define DF_COLE KC_NO
#endif // COLEMAK_ENABLE
#ifdef ARTSENIO_ENABLE
#    define DF_ARTS DF(_ARTSENIO)
#    define AR_A LT(_ARTS_PAR, DE_A)
#    define AR_E LT(_ARTS_SYM, DE_E)
#    define AR_S LT(_ARTS_NUM, DE_S)
#    define AR_O DE_O
#else
#    define DF_ARTS KC_NO
#endif // ARTSENIO_ENABLE
#ifdef ASETNIOP_ENABLE
#    define DF_ASET DF(_ASETNIOP)
#else
#    define DF_ASET KC_NO
#endif // ASETNIOP_ENABLE

// cut copy paste
#define CCP_CUT S(KC_DEL)
#define CCP_CPY C(KC_INS)
#define CCP_PST S(KC_INS)
#define NO_NO______ KC_NO, KC_NO
#define NO_NO_NO___ NO_NO______, KC_NO
#define NO_NO_NO_NO NO_NO_NO___, KC_NO

// Linux extended chars
#define DE_F1_2 ALGR(DE_5)    // ½
#define DE_F1_4 ALGR(DE_4)    // ¼
#define DE_NOT ALGR(DE_5)     // ¬
#define DE_CED ALGR(DE_ACUT)  // ¸ cedilla (dead)
#define DE_EURO ALGR(DE_E)    // €
#define DE_ARRL ALGR(DE_Z)    // ← left arrow
#define DE_ARRD ALGR(DE_U)    // ↓ down arrow
#define DE_ARRR ALGR(DE_I)    // → right arrow
#define DE_DIA ALGR(DE_UE)    // ¨ diaresis (dead)
#define DE_LDOT ALGR(DE_J)    // ̣  dot below (dead)
#define DE_HATS ALGR(DE_AE)   // ˇ hatschek (dead)
#define DE_FDQL ALGR(DE_Y)    // » double guillemets left
#define DE_FDQR ALGR(DE_X)    // « double guillemets right
#define DE_CENT ALGR(DE_C)    // ¢
#define DE_DQUL ALGR(DE_V)    // „ double quote left
#define DE_DQUR ALGR(DE_B)    // “ double quote right
#define DE_DQUE ALGR(DE_N)    // “ double quote right (en)
#define DE_CDOT ALGR(DE_COMM) // · center dot
#define DE_HELL ALGR(DE_DOT)  // … horizontal ellipsis
#define DE_EN ALGR(DE_MINS)   // – en dash

#define DE_IEXC S(ALGR(DE_1))    // ̣¡ inverted question mark
#define DE_F1_8 S(ALGR(DE_2))    // ⅛
#define DE_F3_8 S(ALGR(DE_5))    // ⅜
#define DE_F5_8 S(ALGR(DE_6))    // ⅝
#define DE_F7_8 S(ALGR(DE_7))    // ⅞
#define DE_TM S(ALGR(DE_8))      // ™
#define DE_IQUE S(ALGR(DE_SZ))   // ̣¿ inverted question mark
#define DE_OGNK S(ALGR(DE_ACUT)) // ˛ ogonek (dead)
#define DE_REG S(ALGR(DE_R))     // ®
#define DE_ARRU S(ALGR(DE_U))    // ↑ up arrow
#define DE_RING S(ALGR(DE_UE))   // ° ring (dead)
#define DE_MCRN S(ALGR(DE_PLUS)) // ¨ macron
#define DE_HDOT S(ALGR(DE_J))    // ˙ dot above (dead)
#define DE_BRV S(ALGR(DE_HASH))  // ˘ breve (dead)
#define DE_FSQL S(ALGR(DE_Y))    // › single guillemets left
#define DE_FSQR S(ALGR(DE_X))    // ‹ single guillemets right
#define DE_COPY S(ALGR(DE_C))    // ©
#define DE_SQUL S(ALGR(DE_V))    // ‚ single quote left
#define DE_SQUR S(ALGR(DE_B))    // ‘ single quote right
#define DE_SQUE S(ALGR(DE_N))    // ‘ single quote right (en)
#define DE_MULT S(ALGR(DE_COMM)) // × multiplication operator
#define DE_DIV S(ALGR(DE_DOT))   // ÷ division operator
#define DE_EM S(ALGR(DE_MINS))   // — em dash

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
#    define _QWER_5_L1_ DE_Q, DE_W, DE_E, DE_R, DE_T
#    define _QWER_5_L2_ DE_A, DE_S, DE_D, DE_F, GUI_G
#    define _QWER_5_L3_ DE_Y, DE_X, DE_C, DE_V, DE_B
// Right half
#    define _QWER_5_R1_ DE_Z, DE_U, DE_I, MC_O, DE_P
#    define _QWER_5_R2_ GUI_H, DE_J, DE_K, DE_L, DE_ODIA
#    define _QWER_5_R3_ DE_N, DE_M, KC_COMM, KC_DOT, DE_SS
// nx6 keyboards
#    define _QWER_6_L1_ ALT_TAB, _QWER_5_L1_
#    define _QWER_6_L2_ CTL_ESC, _QWER_5_L2_
#    define _QWER_6_L3_ KC_LSFT, _QWER_5_L3_
#    define _QWER_6_R1_ _QWER_5_R1_, ALT_UE
#    define _QWER_6_R2_ _QWER_5_R2_, CTL_AE
#    define _QWER_6_R3_ _QWER_5_R3_, KC_RSFT
#endif // QWERTZ_ENABLE

#ifdef BONE_ENABLE
// * Base Layer: Bone (matrix variant for 5 column keyboards)
// Left half
#    define _BONE_5_L1_ DE_J, DE_D, DE_U, DE_A, DE_X
#    define _BONE_5_L2_ DE_C, DE_T, DE_I, DE_E, GUI_O
#    define _BONE_5_L3_ DE_F, DE_V, DE_SS, DE_Q, DE_ODIA
// Right half
#    define _BONE_5_R1_ DE_P, DE_H, DE_L, MC_M, DE_W
#    define _BONE_5_R2_ GUI_B, DE_N, DE_R, DE_S, DE_G
#    define _BONE_5_R3_ DE_Y, DE_Z, KC_COMM, KC_DOT, DE_K
// nx6 keyboards
#    define _BONE_6_L1_ ALT_TAB, _BONE_5_L1_
#    define _BONE_6_L2_ CTL_ESC, _BONE_5_L2_
#    define _BONE_6_L3_ KC_LSFT, DE_F, DE_V, DE_UDIA, DE_ADIA, DE_ODIA
#    define _BONE_6_R1_ _BONE_5_R1_, ALT_SS
#    define _BONE_6_R2_ _BONE_5_R2_, CTL_Q
#    define _BONE_6_R3_ _BONE_5_R3_, KC_RSFT
#endif // BONE_ENABLE

#ifdef WORKMAN_ENABLE
// * Base Layer: Workman (german variant)
// I replaced ';' by 'ö' and '/' by 'ß' to have all german special chars
// available. ('ü' and 'ä' are on the outer column / on MOUSE layer.)
// TODO: define combos for umlauts: j+u=>ü, j+o=>ö, b+a=>ä (j and b are the same positions as in colemak)
//
// Left half
#    define _WORK_5_L1_ DE_Q, DE_D, DE_R, DE_W, DE_B
#    define _WORK_5_L2_ DE_A, DE_S, DE_H, DE_T, GUI_G
#    define _WORK_5_L3_ DE_Y, DE_X, DE_M, DE_C, DE_V
// Left half
#    define _WORK_5_R1_ DE_J, DE_F, DE_U, MC_P, DE_ODIA
#    define _WORK_5_R2_ GUI_Z, DE_N, DE_E, DE_O, DE_I
#    define _WORK_5_R3_ DE_K, DE_L, KC_COMM, KC_DOT, DE_SS
// nx6 keyboards
#    define _WORK_6_L1_ ALT_TAB, _WORK_5_L1_
#    define _WORK_6_L2_ CTL_ESC, _WORK_5_L2_
#    define _WORK_6_L3_ KC_LSFT, _WORK_5_L3_
#    define _WORK_6_R1_ _WORK_5_R1_, ALT_UE
#    define _WORK_6_R2_ _WORK_5_R2_, CTL_AE
#    define _WORK_6_R3_ _WORK_5_R3_, KC_RSFT
#endif // WORKMAN_ENABLE

#ifdef COLEMAK_ENABLE
// * Base Layer: Colemak DH (german variant)
// I replaced ';' by 'ö' and '/' by 'ß' to have all german special chars
// available. ('ü' and 'ä' are on the outer column / on MOUSE layer.)
//
// Left half
#    define _COLE_5_L1_ DE_Q, DE_W, DE_F, DE_P, DE_B
#    define _COLE_5_L2_ DE_A, DE_R, DE_S, DE_T, GUI_G
#    define _COLE_5_L3_ DE_Y, DE_X, DE_C, DE_D, DE_V
// Left half
#    define _COLE_5_R1_ DE_J, DE_L, DE_U, MC_Z, DE_ODIA
#    define _COLE_5_R2_ GUI_M, DE_N, DE_E, DE_I, DE_O
#    define _COLE_5_R3_ DE_K, DE_H, KC_COMM, KC_DOT, DE_SS
// nx6 keyboards
#    define _COLE_6_L1_ ALT_TAB, _COLE_5_L1_
#    define _COLE_6_L2_ CTL_ESC, _COLE_5_L2_
#    define _COLE_6_L3_ KC_LSFT, _COLE_5_L3_
#    define _COLE_6_R1_ _COLE_5_R1_, DE_UDIA
#    define _COLE_6_R2_ _COLE_5_R2_, DE_ADIA
#    define _COLE_6_R3_ _COLE_5_R3_, KC_RSFT
#endif // COLEMAK_ENABLE

#define _NUMB_6_L0_ KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5
#define _NUMB_6_R0_ KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO
#define _FUNC_6_L0_ KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define _FUNC_6_R0_ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12

// /* Standard thumb cluster */
#define _THUMB_2_L_ NF_ESC, SY_ENT
#define _THUMB_2_R_ SN_SPC, NF_TAB
#define _THUMB_2_2_ _THUMB_2_L_, _THUMB_2_R_
#define _THUMB_222_ _THUMB_2_L_, MC_APP, AD_BSP, _THUMB_2_R_
#define _THUMB_3_3_ MEH_PUP, _THUMB_2_L_, _THUMB_2_R_, A_S_PDN
#define _THUMB_4_4_ MEH_PUP, _THUMB_222_, A_S_PDN
#define _THUMB_5_5_ XXXXXXX, _THUMB_4_4_, XXXXXXX

#ifdef ASETNIOP_ENABLE
/* ASETNIOP+ layout
 * ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 * │  <  │  v  │  ^  │  >  │     │             │     │  1  │  2  │  4  │  8  │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │  a  │  s  │  e  │  t  │     │             │     │  n  │  i  │  o  │  p  │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │ Esc │ Alt │ Gui │ Ctl │     │             │     │ F1  │ F2  │ F4  │ F8  │
 * └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │ Ctl │ Sft │QUIT*│ │ Mse │Space│NoMod│
 *                   └─────┴─────┴─────┘ └─────┴─Sym─┴─────┘
 */
#    define _ASET_5_L1_ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX
#    define _ASET_5_L2_ DE_A, DE_S, DE_E, DE_T, XXXXXXX
#    define _ASET_5_L3_ KC_ESC, OS_ALT, OS_GUI, OS_CTL, XXXXXXX
#    define _ASET_3_L4_ OSM_CTL, OSM_SFT, TO_DF

#    define _ASET_5_R1_ XXXXXXX, DE_1, DE_2, DE_4, DE_8
#    define _ASET_5_R2_ XXXXXXX, DE_N, DE_I, DE_O, DE_P
#    define _ASET_5_R3_ XXXXXXX, KC_F1, KC_F2, KC_F4, KC_F8
#    define _ASET_3_R4_ TO_MA, SN_SPC, NO_MOD
#    define _ASET_33_T_ _ASET_3_L4_, _ASET_3_R4_
#endif // ASETNIOP_ENABLE

#ifdef ARTSENIO_ENABLE
/* ARTSENIO- layout
 * ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
 * │  s  │  t  │  r  │  a  │     │             │     │     │     │     │     │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │  o  │  i  │  n  │  e  │     │             │     │ Ctl │ Gui │ Alt │     │
 * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
 * │     │     │     │     │     │             │     │     │     │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │ Adj │NoMod│QWER+│ │ Adj │NoMod│QWER+│
 *                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// for all layers
#define _AX1_5_ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _AX2_5_ XXXXXXX, OS_CTL,  OS_GUI,  OS_ALT,  XXXXXXX
#define _AX3_5_ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _AX4_3_ LY_ADJ,  NO_MOD,  DF_QWER

// base layer
#define _AB1_4_ AR_S,    DE_T,    DE_R,    AR_A
#define _AB2_4_ DE_O,    DE_I,    DE_N,    AR_E
#define _AB1_5_ _AB1_4_, XXXXXXX
#define _AB2_5_ _AB2_4_, XXXXXXX
#define _AB3_5_ KC_ESC,  OS_ALT,  OS_GUI,  OS_CTL,  XXXXXXX
// numbers layer
#define _AN1_4_ KC_F8,   DE_4,    DE_2,    DE_1
#define _AN2_4_ KC_F4,   KC_F2,   KC_F1,   DE_8
#define _AN1_5_ _AN1_4_, XXXXXXX
#define _AN2_5_ _AN2_4_, XXXXXXX
// symbols layer
#define _AS1_4_ DE_BSLS, DE_HASH, DE_AMPR, KC_NO
#define _AS2_4_ DE_PLUS, DE_MINS, DE_QUES, KC_TRNS
#define _AS1_5_ _AS1_4_, XXXXXXX
#define _AS2_5_ _AS2_4_, XXXXXXX
// parens layer
#define _AP1_4_ DE_LCBR, DE_LPRN, DE_RPRN, KC_TRNS
#define _AP2_4_ DE_RCBR, DE_LBRC, DE_RBRC, KC_NO
#define _AP1_5_ _AP1_4_, XXXXXXX
#define _AP2_5_ _AP2_4_, XXXXXXX
// arrows layer
#define _AA1_4_ KC_PGUP, KC_HOME, KC_UP,   KC_END
#define _AA2_4_ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT
#define _AA1_5_ _AA1_4_, XXXXXXX
#define _AA2_5_ _AA2_4_, XXXXXXX
// arrows layer
#define _AM1_4_ KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1
#define _AM2_4_ KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R
#define _AM1_5_ _AM1_4_, XXXXXXX
#define _AM2_5_ _AM2_4_, XXXXXXX
#endif // ARTSENIO_ENABLE

// non alphas
#define X2X KC_NO, KC_NO
#define _TRANS_5_ _______, _______, _______, _______, _______
#define _TRANS_6_ _______, _TRANS_5_
#define _NUMB_5_ DE_0, DE_1, DE_2, DE_4, DE_8
#define _FUNC_5_ KC_F10, KC_F1, KC_F2, KC_F4, KC_F8

#define _SYMB_5_L1_ DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define _SYMB_5_L2_ DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define _SYMB_5_L3_ DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_ACUT
#define _SYMB_5_R1_ _NUMB_5_
#define _SYMB_5_R2_ DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR
#define _SYMB_5_R3_ DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO

#define _SYMB_6_L1_ _______, _SYMB_5_L1_
#define _SYMB_6_L2_ _______, _SYMB_5_L2_
#define _SYMB_6_L3_ _______, _SYMB_5_L3_
#define _SYMB_6_R1_ _SYMB_5_R1_, DE_EXLM
#define _SYMB_6_R2_ _SYMB_5_R2_, DE_EQL
#define _SYMB_6_R3_ _SYMB_5_R3_, _______

#define _SYMB_2_TL_ DE_SECT, KC_TRNS
#define _SYMB_2_TR_ KC_TRNS, ALGR(DE_C)
#define _SYMB_4_TB_ _SYMB_2_TL_, _SYMB_2_TR_
#define _SYMB_222_TB_ _SYMB_2_TL_, KC_TRNS, KC_TRNS, _SYMB_2_TR_
#define _SYMB_3_3_TB_ KC_TRNS, _SYMB_2_TL_, _SYMB_2_TR_, KC_TRNS
#define _SYMB_5_5_TB_ KC_TRNS, KC_TRNS, _SYMB_222_TB_, KC_TRNS, KC_TRNS

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------
// │ PgUp│ BSp │  ↑  │ Del │ PgDn│             │ F10 │  F1 │  F2 │  F4 │  F8 │  F11 |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ Home│  ←  │  ↓  │  →  │ End │             │OsAlt│OsCtl│OsGui│OsSft│ RSft│  F12 |
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// │ Ins │ Cut │ Copy│Paste│PrScr│             │Power│OsAGr│OsMeh│OsHyp│CapsW│CapsW |
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘------
//                   │ Adj │     │     │ │     │ App │ Adj │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define _NAVI_5_L1_ KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
#define _NAVI_5_L2_ KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define _NAVI_5_L3_ KC_INS, CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR
#define _FUNC_5_R1_ _FUNC_5_
#define _FUNC_5_R2_ OSM_ALT, OSM_CTL, OSM_GUI, OSM_SFT, KC_RSFT
#define _FUNC_5_R3_ KC_PWR, OSM_AGR, OSM_MEH, OSM_HYP, CW_TOGG

#define _NAVI_6_L1_ _______, _NAVI_5_L1_
#define _NAVI_6_L2_ _______, _NAVI_5_L2_
#define _NAVI_6_L3_ _______, _NAVI_5_L3_
#define _FUNC_6_R1_ _FUNC_5_R1_, KC_F11
#define _FUNC_6_R2_ _FUNC_5_R2_, KC_F12
#define _FUNC_6_R3_ _FUNC_5_R3_, CW_TOGG

#define _NAFN_2_TL_ MO(_ADJUST), KC_TRNS
#define _NAFN_2_TR_ KC_APP, MO(_ADJUST)
#define _NAFN_222_TB_ _NAFN_2_TL_, KC_TRNS, KC_TRNS, _NAFN_2_TR_
#define _NAFN_3_3_TB_ KC_TRNS, _NAFN_2_TL_, _NAFN_2_TR_, KC_TRNS
#define _NAFN_5_5_TB_ KC_TRNS, KC_TRNS, _NAFN_222_TB_, KC_TRNS, KC_TRNS

// This layer also holds some german umlauts for 5 column keyboards. Their position depends on the base layout
// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │ vvv │ <<< │  ↑  │ >>> │ ^^^ │             │MsSp+│  ü  │ Vol+│ (v) │Eject│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │  ä  │  ←  │  ↓  │  →  │Pause│             │MsSpN│ Prev│ Vol-│ XXX │ Next│
// ├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │ MB4 │ XXX │  ü  │  ä  │ MB5 │             │MsSp-│ Play│ Mute│ Stop│ Sft │
// └─────┴─────┴─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┴─────┴─────┘
//                   │ MB2 │ MB1 │ MB3 | |     │LShft│ MB3 │
//                   └─────┴─────┴-----' '-----┴─────┴─────┘
#define _MSME_5_L1_ KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define _MSME_5_L2_ DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE
#define _MSME_5_L3_ KC_BTN4, XXXXXXX, DE_UDIA, DE_ADIA, KC_BTN5
#define _MSME_5_R1_ KC_ACL2, DE_UDIA, KC_VOLU, XXXXXXX, KC_EJCT
#define _MSME_5_R2_ KC_ACL1, KC_MPRV, KC_VOLD, XXXXXXX, KC_MNXT
#define _MSME_5_R3_ KC_ACL0, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX

#define _MSME_6_L1_ _______, _MSME_5_L1_
#define _MSME_6_L2_ _______, _MSME_5_L2_
#define _MSME_6_L3_ _______, _MSME_5_L3_
#define _MSME_6_R1_ _MSME_5_R1_, XXXXXXX
#define _MSME_6_R2_ _MSME_5_R2_, XXXXXXX
#define _MSME_6_R3_ _MSME_5_R3_, _______

#define _MSME_2_TL_ KC_BTN2, KC_BTN1
#define _MSME_2_TR_ KC_LSFT, KC_BTN3
#define _MSME_222_TB_ _MSME_2_TL_, KC_BTN3, KC_TRNS, _MSME_2_TR_
#define _MSME_3_3_TB_ KC_BTN3, _MSME_2_TL_, _MSME_2_TR_, KC_TRNS
#define _MSME_5_5_TB_ KC_TRNS, KC_TRNS, _MSME_222_TB_, KC_TRNS, KC_TRNS

// ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// │ TOGG│Plain│Brthe│Rainb│Swirl│             │(BtC)│(Bt←)│(Bt0)│(Bt→)│(Out)│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// │Speed│ Val │ Sat │ Hue │ Mode│             │EEClr│QWERT│COLMK│ BONE│LYPND│
// ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼Mouse┼─────┼─────┤
// │ Test│ Xmas│Grdnt│Knght│Snake│             │Reset│WRKMN│ ASET│ARTSN│ Sft │
// └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//                   │     │     │     │ │     │     │     │
//                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
#define _CONF_5_L1_ RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW
#define _CONF_5_L2_ RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD
#define _CONF_5_L3_ RGB_M_T, RGB_M_X, RGB_M_G, RGB_M_K, RGB_M_SN
#define _CONF_5_R1_ DF_ASET, DF_ARTS, KC_BRIU, XXXXXXX, QK_BOOT
#define _CONF_5_R2_ DF_COLE, DF_QWER, KC_BRID, XXXXXXX, EE_CLR
#define _CONF_5_R3_ DF_WORK, DF_BONE, XXXXXXX, XXXXXXX, KC_LSFT

#define _CONF_6_L1_ _______, _CONF_5_L1_
#define _CONF_6_L2_ _______, _CONF_5_L2_
#define _CONF_6_L3_ _______, _CONF_5_L3_
#define _CONF_6_R1_ _CONF_5_R1_, XXXXXXX
#define _CONF_6_R2_ _CONF_5_R2_, XXXXXXX
#define _CONF_6_R3_ _CONF_5_R3_, _______

#define _CONF_3_3_TB_ _TRANS_6_
#define _CONF_222_TB_ _TRANS_6_
#define _CONF_5_5_TB_ _TRANS_5_, _TRANS_5_


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // old version of keymap.h // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// #include "keymap_german.h"

// // MODs
// #define OSM_AGR OSM(MOD_RALT)
// #define OSM_ALT OSM(MOD_LALT)
// #define OSM_CTL OSM(MOD_LCTL)
// #define OSM_GUI OSM(MOD_LGUI)
// #define OSM_SFT OSM(MOD_LSFT)
// #define OSM_MEH MT(MOD_MEH, KC_PGUP)
// #define OSM_HYP MT(MOD_HYPR, KC_PGDN)
// // HRM
// #define ALT_AE MT(MOD_LALT, DE_ADIA)
// #define CTL_ESC MT(MOD_LCTL, KC_ESC)

// // Base layers
// #ifdef QWERTZ_ENABLE
// #    define DF_QWER DF(_QWERTZ)
// #else
// #    define DF_QWER KC_NO
// #endif // QWERTZ_ENABLE
// #ifdef BONE_ENABLE
// #    define DF_BONE DF(_BONE)
// #else
// #    define DF_BONE KC_NO
// #endif // BONE_ENABLE
// #ifdef WORKMAN_ENABLE
// #    define DF_WORK DF(_WORKMAN)
// #else
// #    define DF_WORK KC_NO
// #endif // WORKMAN_ENABLE
// #ifdef COLEMAK_ENABLE
// #    define DF_COLE DF(_COLMAK_DH)
// #else
// #    define DF_COLE KC_NO
// #endif // COLEMAK_ENABLE
// #ifdef ASETNIOP_ENABLE
// #    define DF_ASET DF(_ASETNIOP)
// #else
// #    define DF_ASET KC_NO
// #endif // ASETNIOP_ENABLE
// #ifdef ARTSENIO_ENABLE
// #    define DF_ARTS DF(_ARTSENIO)
// #else
// #    define DF_ARTS KC_NO

// #endif // ARTSENIO_ENABLE

// // Thumb / layer keys
// #define NF_ESC LT(_NAV_FUN, KC_ESC)
// #define SY_ENT LT(_SYM_NUM, KC_ENT)
// #define NF_TAB LT(_NAV_FUN, KC_TAB)
// #define AD_BSP LT(_ADJUST, KC_BSPC)
// #define SN_SPC LT(_SYM_NUM, KC_SPC)
// #define MC_APP LT(_MSE_CTL, KC_APP)
// #define TO_DF DF(0)
// #define TO_MA MO(_MSE_CTL)

// // cut copy paste
// #define CCP_CUT S(KC_DEL)
// #define CCP_CPY C(KC_INS)
// #define CCP_PST S(KC_INS)

// // Linux extended chars
// #define DE_F1_2 ALGR(DE_5)    // ½
// #define DE_F1_4 ALGR(DE_4)    // ¼
// #define DE_NOT ALGR(DE_5)     // ¬
// #define DE_CED ALGR(DE_ACUT)  // ¸ cedilla (dead)
// #define DE_EURO ALGR(DE_E)    // €
// #define DE_ARRL ALGR(DE_Z)    // ← left arrow
// #define DE_ARRD ALGR(DE_U)    // ↓ down arrow
// #define DE_ARRR ALGR(DE_I)    // → right arrow
// #define DE_DIA ALGR(DE_UE)    // ¨ diaresis (dead)
// #define DE_LDOT ALGR(DE_J)    // ̣  dot below (dead)
// #define DE_HATS ALGR(DE_AE)   // ˇ hatschek (dead)
// #define DE_FDQL ALGR(DE_Y)    // » double guillemets left
// #define DE_FDQR ALGR(DE_X)    // « double guillemets right
// #define DE_CENT ALGR(DE_C)    // ¢
// #define DE_DQUL ALGR(DE_V)    // „ double quote left
// #define DE_DQUR ALGR(DE_B)    // “ double quote right
// #define DE_DQUE ALGR(DE_N)    // “ double quote right (en)
// #define DE_CDOT ALGR(DE_COMM) // · center dot
// #define DE_HELL ALGR(DE_DOT)  // … horizontal ellipsis
// #define DE_EN ALGR(DE_MINS)   // – en dash

// #define DE_IEXC S(ALGR(DE_1))    // ̣¡ inverted question mark
// #define DE_F1_8 S(ALGR(DE_2))    // ⅛
// #define DE_F3_8 S(ALGR(DE_5))    // ⅜
// #define DE_F5_8 S(ALGR(DE_6))    // ⅝
// #define DE_F7_8 S(ALGR(DE_7))    // ⅞
// #define DE_TM S(ALGR(DE_8))      // ™
// #define DE_IQUE S(ALGR(DE_SZ))   // ̣¿ inverted question mark
// #define DE_OGNK S(ALGR(DE_ACUT)) // ˛ ogonek (dead)
// #define DE_REG S(ALGR(DE_R))     // ®
// #define DE_ARRU S(ALGR(DE_U))    // ↑ up arrow
// #define DE_RING S(ALGR(DE_UE))   // ° ring (dead)
// #define DE_MCRN S(ALGR(DE_PLUS)) // ¨ macron
// #define DE_HDOT S(ALGR(DE_J))    // ˙ dot above (dead)
// #define DE_BRV S(ALGR(DE_HASH))  // ˘ breve (dead)
// #define DE_FSQL S(ALGR(DE_Y))    // › single guillemets left
// #define DE_FSQR S(ALGR(DE_X))    // ‹ single guillemets right
// #define DE_COPY S(ALGR(DE_C))    // ©
// #define DE_SQUL S(ALGR(DE_V))    // ‚ single quote left
// #define DE_SQUR S(ALGR(DE_B))    // ‘ single quote right
// #define DE_SQUE S(ALGR(DE_N))    // ‘ single quote right (en)
// #define DE_MULT S(ALGR(DE_COMM)) // × multiplication operator
// #define DE_DIV S(ALGR(DE_DOT))   // ÷ division operator
// #define DE_EM S(ALGR(DE_MINS))   // — em dash

// /*
// Blocks for some keyboard layouts. Organized so we can quickly adapt and modify
// all of them at once, rather than for each keyboard, one at a time. And this
// allows for much cleaner blocks in the keymaps. For instance Tap/Hold for
// Control on all of the layouts

// NOTE: These are all the same length.  If you do a search/replace then you need
// to add/remove underscores to keep the lengths consistent.
// */

// #ifdef QWERTZ_ENABLE
// // nx5 keyboards
// // Left half
// #    define _________________QWERTZ_L1_______________5_ DE_Q, DE_W, DE_E, DE_R, DE_T
// #    define _________________QWERTZ_L2_______________5_ DE_A, DE_S, DE_D, DE_F, DE_G
// #    define _________________QWERTZ_L3_______________5_ DE_Y, DE_X, DE_C, DE_V, DE_B
// // Right half
// #    define _________________QWERTZ_R1_______________5_ DE_Z, DE_U, DE_I, DE_O, DE_P
// #    define _________________QWERTZ_R2_______________5_ DE_H, DE_J, DE_K, DE_L, DE_ODIA
// #    define _________________QWERTZ_R3_______________5_ DE_N, DE_M, KC_COMM, KC_DOT, DE_SS
// // nx6 keyboards
// #    define _____________________QWERTZ_L1____________________6_ KC_TAB, _________________QWERTZ_L1_______________5_
// #    define _____________________QWERTZ_L2____________________6_ CTL_ESC, _________________QWERTZ_L2_______________5_
// #    define _____________________QWERTZ_L3____________________6_ KC_LSFT, _________________QWERTZ_L3_______________5_
// #    define _____________________QWERTZ_R1____________________6_ _________________QWERTZ_R1_______________5_, DE_UDIA
// #    define _____________________QWERTZ_R2____________________6_ _________________QWERTZ_R2_______________5_, ALT_AE
// #    define _____________________QWERTZ_R3____________________6_ _________________QWERTZ_R3_______________5_, KC_RSFT
// #endif // QWERTZ_ENABLE

// #ifdef BONE_ENABLE
// // * Base Layer: Bone (matrix variant for 5 column keyboards)
// // Left half
// #    define ___________________BONE_L1_______________5_ DE_J, DE_D, DE_U, DE_A, DE_X
// #    define ___________________BONE_L2_______________5_ DE_C, DE_T, DE_I, DE_E, DE_O
// #    define ___________________BONE_L3_______________5_ DE_F, DE_V, DE_SS, DE_Q, DE_ODIA
// // Right half
// #    define ___________________BONE_R1_______________5_ DE_P, DE_H, DE_L, DE_M, DE_W
// #    define ___________________BONE_R2_______________5_ DE_B, DE_N, DE_R, DE_S, DE_G
// #    define ___________________BONE_R3_______________5_ DE_Y, DE_Z, KC_COMM, KC_DOT, DE_K
// // nx6 keyboards
// #    define _______________________BONE_L1____________________6_ KC_TAB, ___________________BONE_L1_______________5_
// #    define _______________________BONE_L2____________________6_ CTL_ESC, ___________________BONE_L2_______________5_
// #    define _______________________BONE_L3____________________6_ KC_LSFT, DE_F, DE_V, DE_UDIA, DE_ADIA, DE_ODIA
// #    define _______________________BONE_R1____________________6_ ___________________BONE_R1_______________5_, DE_SS
// #    define _______________________BONE_R2____________________6_ ___________________BONE_R2_______________5_, DE_Q
// #    define _______________________BONE_R3____________________6_ ___________________BONE_R3_______________5_, KC_RSFT
// #endif // BONE_ENABLE

// #ifdef WORKMAN_ENABLE
// // * Base Layer: Workman (german variant)
// // I replaced ';' by 'ö' and '/' by 'ß' to have all german special chars
// // available. ('ü' and 'ä' are on the outer column / on MOUSE layer.)
// // TODO: define combos for umlauts: j+u=>ü, j+o=>ö, b+a=>ä (j and b are the same positions as in colemak)
// //
// // Left half
// #    define ________________WORKMAN_L1_______________5_ DE_Q, DE_D, DE_R, DE_W, DE_B
// #    define ________________WORKMAN_L2_______________5_ DE_A, DE_S, DE_H, DE_T, DE_G
// #    define ________________WORKMAN_L3_______________5_ DE_Y, DE_X, DE_M, DE_C, DE_V
// // Left half
// #    define ________________WORKMAN_R1_______________5_ DE_J, DE_F, DE_U, DE_P, DE_ODIA
// #    define ________________WORKMAN_R2_______________5_ DE_Z, DE_N, DE_E, DE_O, DE_I
// #    define ________________WORKMAN_R3_______________5_ DE_K, DE_L, KC_COMM, KC_DOT, DE_SS
// // nx6 keyboards
// #    define ____________________WORKMAN_L1____________________6_ KC_TAB, ________________WORKMAN_L1_______________5_
// #    define ____________________WORKMAN_L2____________________6_ CTL_ESC, ________________WORKMAN_L2_______________5_
// #    define ____________________WORKMAN_L3____________________6_ KC_LSFT, ________________WORKMAN_L3_______________5_
// #    define ____________________WORKMAN_R1____________________6_ ________________WORKMAN_R1_______________5_, DE_UDIA
// #    define ____________________WORKMAN_R2____________________6_ ________________WORKMAN_R2_______________5_, DE_ADIA
// #    define ____________________WORKMAN_R3____________________6_ ________________WORKMAN_R3_______________5_, KC_RSFT
// #endif // WORKMAN_ENABLE

// #ifdef COLEMAK_ENABLE
// // * Base Layer: Colemak DH (german variant)
// // I replaced ';' by 'ö' and '/' by 'ß' to have all german special chars
// // available. ('ü' and 'ä' are on the outer column / on MOUSE layer.)
// //
// // Left half
// #    define _______________COLEMAK_DH_L1_____________5_ DE_Q, DE_W, DE_F, DE_P, DE_B
// #    define _______________COLEMAK_DH_L2_____________5_ DE_A, DE_R, DE_S, DE_T, DE_G
// #    define _______________COLEMAK_DH_L3_____________5_ DE_Y, DE_X, DE_C, DE_D, DE_V
// // Left half
// #    define _______________COLEMAK_DH_R1_____________5_ DE_J, DE_L, DE_U, DE_Z, DE_ODIA
// #    define _______________COLEMAK_DH_R2_____________5_ DE_M, DE_N, DE_E, DE_I, DE_O
// #    define _______________COLEMAK_DH_R3_____________5_ DE_K, DE_H, KC_COMM, KC_DOT, DE_SS
// // nx6 keyboards
// #    define ___________________COLEMAK_DH_L1__________________6_ KC_TAB, _______________COLEMAK_DH_L1_____________5_
// #    define ___________________COLEMAK_DH_L2__________________6_ CTL_ESC, _______________COLEMAK_DH_L2_____________5_
// #    define ___________________COLEMAK_DH_L3__________________6_ KC_LSFT, _______________COLEMAK_DH_L3_____________5_
// #    define ___________________COLEMAK_DH_R1__________________6_ _______________COLEMAK_DH_R1_____________5_, DE_UDIA
// #    define ___________________COLEMAK_DH_R2__________________6_ _______________COLEMAK_DH_R2_____________5_, DE_ADIA
// #    define ___________________COLEMAK_DH_R3__________________6_ _______________COLEMAK_DH_R3_____________5_, KC_RSFT
// #endif // COLEMAK_ENABLE

// #define _____________________NUMBER_L0____________________6_ KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5
// #define _____________________NUMBER_R0____________________6_ KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO
// #define ______________________FUNC_L0_____________________6_ KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
// #define ______________________FUNC_R0_____________________6_ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12

// // /* Standard thumb cluster */
// #define __THUMB_2_L___2_ NF_ESC, SY_ENT
// #define __THUMB_2_R___2_ SN_SPC, NF_TAB
// #define _________THUMB_2_2_______4_ __THUMB_2_L___2_, __THUMB_2_R___2_
// #define ______________________THUMB_3_3___________________6_ __THUMB_2_L___2_, MC_APP, AD_BSP, __THUMB_2_R___2_
// #define ______________________________THUMB_4_4___________________________8_ OSM_MEH, ______________________THUMB_3_3___________________6_, OSM_HYP
// #define ________________________________________THUMB_5_5____________________________________10_ KC_NO, ______________________________THUMB_4_4___________________________8_, KC_NO

// #ifdef ASETNIOP_ENABLE
// /* ASETNIOP+ layout
//  * ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
//  * │  <  │  v  │  ^  │  >  │     │             │     │  1  │  2  │  4  │  8  │
//  * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
//  * │  a  │  s  │  e  │  t  │     │             │     │  n  │  i  │  o  │  p  │
//  * ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
//  * │ Esc │ Alt │ Gui │ Ctl │     │             │     │ F1  │ F2  │ F4  │ F8  │
//  * └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
//  *                   │ Ctl │ Sft │QUIT*│ │ Mse │Space│NoMod│
//  *                   └─────┴─────┴─────┘ └─────┴─Sym─┴─────┘
//  */
// #    define ______________ASETNIOP_PLUS_L1___________5_ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX
// #    define ______________ASETNIOP_PLUS_L2___________5_ E_A, DE_S, DE_E, DE_T, XXXXXXX
// #    define ______________ASETNIOP_PLUS_L3___________5_ C_ESC, OS_ALT, OS_GUI, OS_CTL, XXXXXXX
// #    define ___ASETNIOP_PLUS_L4____3_ OSM_CTL, OS_SFT, TO_DF

// #    define ______________ASETNIOP_PLUS_R1___________5_ XXXXXXX, DE_1, DE_2, DE_4, DE_8
// #    define ______________ASETNIOP_PLUS_R2___________5_ XXXXXXX, DE_N, DE_I, DE_O, DE_P
// #    define ______________ASETNIOP_PLUS_R3___________5_ XXXXXXX, KC_F1, KC_F2, KC_F4, KC_F8
// #    define ___ASETNIOP_PLUS_R4____3_ TO_MA, SN_SPC, NO_MOD
// #    define ________ASETNIOP_PLUS_THUMB_3_3___________________6_ ___ASETNIOP_PLUS_L4____3_, ___ASETNIOP_PLUS_R4____3_
// #endif // ASETNIOP_ENABLE

// // non alphas
// #define X2X KC_NO, KC_NO
// #define ___________________BLANK_________________5_ _______, _______, _______, _______, _______
// #define _______________________BLANK______________________6_ _______, ___________________BLANK_________________5_
// #define __________________NUMBERS________________5_ DE_0, DE_1, DE_2, DE_4, DE_8
// #define _________________FUNCTIONS_______________5_ KC_F10, KC_F1, KC_F2, KC_F4, KC_F8

// #define ________________SYMBOLS_L1_______________5_ DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
// #define ________________SYMBOLS_L2_______________5_ DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
// #define ________________SYMBOLS_L3_______________5_ DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_ACUT
// #define ________________SYMBOLS_R1_______________5_ __________________NUMBERS________________5_
// #define ________________SYMBOLS_R2_______________5_ DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR
// #define ________________SYMBOLS_R3_______________5_ DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO

// #define _____________________SYMBOLS_L1___________________6_ _______, ________________SYMBOLS_L1_______________5_
// #define _____________________SYMBOLS_L2___________________6_ _______, ________________SYMBOLS_L2_______________5_
// #define _____________________SYMBOLS_L3___________________6_ _______, ________________SYMBOLS_L3_______________5_
// #define _____________________SYMBOLS_R1___________________6_ ________________SYMBOLS_R1_______________5_, DE_EXLM
// #define _____________________SYMBOLS_R2___________________6_ ________________SYMBOLS_R2_______________5_, DE_EQL
// #define _____________________SYMBOLS_R3___________________6_ ________________SYMBOLS_R3_______________5_, _______

// #define __SYMBOLS_TL__2_ DE_SECT, KC_TRNS
// #define __SYMBOLS_TR__2_ KC_TRNS, ALGR(DE_C)
// #define ____________SYMBOLS_TB__________4_ __SYMBOLS_TL__2_, __SYMBOLS_TR__2_
// #define _____________________SYMBOLS_TB___________________6_ __SYMBOLS_TL__2_, KC_TRNS, KC_TRNS, __SYMBOLS_TR__2_

// // ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------
// // │ PgUp│ BSp │  ↑  │ Del │ PgDn│             │ F10 │  F1 │  F2 │  F4 │  F8 │  F11 |
// // ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// // │ Home│  ←  │  ↓  │  →  │ End │             │OsAlt│OsCtl│OsGui│OsSft│ RSft│  F12 |
// // ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------
// // │ Ins │ Cut │ Copy│Paste│PrScr│             │Power│OsAGr│OsMeh│OsHyp│CapsW│CapsW |
// // └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘------
// //                   │ Adj │     │     │ │     │ App │ Adj │
// //                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
// #define ______________NAVIGATION_L1______________5_ KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
// #define ______________NAVIGATION_L2______________5_ KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
// #define ______________NAVIGATION_L3______________5_ KC_INS, CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR
// #define _______________FUNCTION_R1_______________5_ _________________FUNCTIONS_______________5_
// #define _______________FUNCTION_R2_______________5_ OSM_ALT, OSM_CTL, OSM_GUI, OSM_SFT, KC_RSFT
// #define _______________FUNCTION_R3_______________5_ KC_PWR, OSM_AGR, OSM_MEH, OSM_HYP, CW_TOGG

// #define _______________NAVIGATION_L1______________________6_ _______, ______________NAVIGATION_L1______________5_
// #define _______________NAVIGATION_L2______________________6_ _______, ______________NAVIGATION_L2______________5_
// #define _______________NAVIGATION_L3______________________6_ _______, ______________NAVIGATION_L3______________5_
// #define _________________FUNCTION_R1______________________6_ _______________FUNCTION_R1_______________5_, KC_F11
// #define _________________FUNCTION_R2______________________6_ _______________FUNCTION_R2_______________5_, KC_F12
// #define _________________FUNCTION_R3______________________6_ _______________FUNCTION_R3_______________5_, CW_TOGG

// #define ___NAVFN_TL___2_ MO(_ADJUST), KC_TRNS
// #define ___NAVFN_TR___2_ KC_APP, MO(_ADJUST)
// #define _____________NAVIGATION_AND_FUNCTION_TB___________6_ ___NAVFN_TL___2_, KC_TRNS, KC_TRNS, ___NAVFN_TR___2_

// // This layer also holds some german umlauts for 5 column keyboards. Their position depends on the base layout
// // ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// // │ vvv │ <<< │  ↑  │ >>> │ ^^^ │             │MsSp+│  ü  │ Vol+│ (v) │Eject│
// // ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// // │  ä  │  ←  │  ↓  │  →  │Pause│             │MsSpN│ Prev│ Vol-│ XXX │ Next│
// // ├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// // │ MB4 │ XXX │  ü  │  ä  │ MB5 │             │MsSp-│ Play│ Mute│ Stop│ Sft │
// // └─────┴─────┴─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┴─────┴─────┘
// //                   │ MB2 │ MB1 │ MB3 | |     │LShft│ MB3 │
// //                   └─────┴─────┴-----' '-----┴─────┴─────┘
// #define __________________MOUSE_L1_______________5_ KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
// #define __________________MOUSE_L2_______________5_ DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE
// #define __________________MOUSE_L3_______________5_ KC_BTN4, XXXXXXX, DE_UDIA, DE_ADIA, KC_BTN5
// #define __________________MOUSE_R1_______________5_ KC_ACL2, DE_UDIA, KC_VOLU, XXXXXXX, KC_EJCT
// #define __________________MOUSE_R2_______________5_ KC_ACL1, KC_MPRV, KC_VOLD, XXXXXXX, KC_MNXT
// #define __________________MOUSE_R3_______________5_ KC_ACL0, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX

// #define ______________________MOUSE_L1____________________6_ _______, __________________MOUSE_L1_______________5_
// #define ______________________MOUSE_L2____________________6_ _______, __________________MOUSE_L2_______________5_
// #define ______________________MOUSE_L3____________________6_ _______, __________________MOUSE_L3_______________5_
// #define ______________________MOUSE_R1____________________6_ __________________MOUSE_R1_______________5_, KC_NO
// #define ______________________MOUSE_R2____________________6_ __________________MOUSE_R2_______________5_, KC_NO
// #define ______________________MOUSE_R3____________________6_ __________________MOUSE_R3_______________5_, _______

// #define ___MOUSE_TL___2_ KC_BTN2, KC_BTN1
// #define ___MOUSE_TR___2_ KC_LSFT, KC_BTN3
// #define ______________________MOUSE_TB____________________6_ ___MOUSE_TL___2_, KC_BTN3, KC_TRNS, ___MOUSE_TR___2_

// // ┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐
// // │ TOGG│Plain│Brthe│Rainb│Swirl│             │(BtC)│(Bt←)│(Bt0)│(Bt→)│(Out)│
// // ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤
// // │Speed│ Val │ Sat │ Hue │ Mode│             │EEClr│QWERT│COLMK│ BONE│LYPND│
// // ├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼Mouse┼─────┼─────┤
// // │ Test│ Xmas│Grdnt│Knght│Snake│             │Reset│WRKMN│ ASET│ARTSN│ Sft │
// // └─────┴─────┴─────┼─────┼─────┼─────┐ ┌─────┼─────┼─────┼─────┴─────┴─────┘
// //                   │     │     │     │ │     │     │     │
// //                   └─────┴─────┴─────┘ └─────┴─────┴─────┘
// #define _________________CONFIG_L1_______________5_ RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW
// #define _________________CONFIG_L2_______________5_ RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD
// #define _________________CONFIG_L3_______________5_ RGB_M_T, RGB_M_X, RGB_M_G, RGB_M_K, RGB_M_SN
// #define _________________CONFIG_R1_______________5_ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
// #define _________________CONFIG_R2_______________5_ EE_CLR, DF_QWER, DF_COLE, DF_BONE, XXXXXXX
// #define _________________CONFIG_R3_______________5_ QK_BOOT, DF_WORK, DF_ASET, DF_ARTS, KC_LSFT

// #define ____________________CONFIG_L1_____________________6_ _______, _________________CONFIG_L1_______________5_
// #define ____________________CONFIG_L2_____________________6_ _______, _________________CONFIG_L2_______________5_
// #define ____________________CONFIG_L3_____________________6_ _______, _________________CONFIG_L3_______________5_
// #define ____________________CONFIG_R1_____________________6_ _________________CONFIG_R1_______________5_, KC_NO
// #define ____________________CONFIG_R2_____________________6_ _________________CONFIG_R2_______________5_, KC_NO
// #define ____________________CONFIG_R3_____________________6_ _________________CONFIG_R3_______________5_, _______

// #define ____________________CONFIG_TB_____________________6_ _______________________BLANK______________________6_
