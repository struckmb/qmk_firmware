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
    _QWER = 0,
    _BONE,
    _NEO2,
    _COLE,
    // additional layers
    _SYM, // symbols (neo based)
    _NAV, // navigation and key pad
    _MFN, // media and function keys
    _ADJ  // mouse and kb adjustment
};

enum custom_keycodes {
    SY_HELL = SAFE_RANGE, // horizontal ellipsis
    SY_CIRC, // caret (non dead)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
};

// Aliases for base layers
#define QWER   DF(_QWER)
#define BONE   DF(_BONE)
#define NEO2   DF(_NEO2)
#define COLE   DF(_COLE)

// Aliases for additional layers
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define MFN      MO(_MFN)
#define ADJ      MO(_ADJ)
#define SYM_ENT  LT(_SYM, KC_ENT)
#define MFN_SPC  LT(_MFN, KC_SPC)
#define ADJ_ENT  LT(_ADJ, KC_ENT)
#define SYM_SPC  LT(_SYM, KC_SPC)

// Aliases for special keys
#define SY_ATAB  A(KC_TAB)
#define SY_SALL  C(DE_A)
#define SY_CUT   S(KC_DEL)
#define SY_COPY  C(KC_INS)
#define SY_PASTE S(KC_INS)
#define SY_UNDO  C(DE_Z)
#define SY_REDO  RCS(DE_Z)
#define SY_RYDO  C(DE_Y)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define SFT_BSP  MT(MOD_LSFT, KC_BSPC)
#define SFT_DEL  MT(MOD_RSFT, KC_DEL)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Aliases for home row mods
#define HA_CTL   LCTL_T(DE_A)
#define HA_MEH   MEH_T(DE_A)
#define HC_MEH   MEH_T(DE_C)
#define HD_CTL   LCTL_T(DE_D)
#define HE_CTL   LCTL_T(DE_E)
#define HE_GUI   LGUI_T(DE_E)
#define HE_SFT   LSFT_T(DE_E)
#define HF_GUI   LGUI_T(DE_F)
#define HF_SFT   LSFT_T(DE_F)
#define HG_GUI   LGUI_T(DE_G)
#define HH_MEH   MEH_T(DE_H)
#define HI_ALT   LALT_T(DE_I)
#define HI_CTL   LCTL_T(DE_I)
#define HI_GUI   LGUI_T(DE_I)
#define HJ_SFT   RSFT_T(DE_J)
#define HK_CTL   RCTL_T(DE_K)
#define HL_ALT   LALT_T(DE_L)
#define HL_GUI   LGUI_T(DE_L)
#define HL_MEH   MEH_T(DE_L)
#define HN_SFT   RSFT_T(DE_N)
#define HP_GUI   LGUI_T(DE_P)
#define HR_ALT   LALT_T(DE_R)
#define HR_CTL   RCTL_T(DE_R)
#define HR_MEH   MEH_T(DE_R)
#define HS_ALT   LALT_T(DE_S)
#define HS_CTL   LCTL_T(DE_S)
#define HT_ALT   LALT_T(DE_T)
#define HT_SFT   LSFT_T(DE_T)
#define HU_GUI   LGUI_T(DE_U)
#define HU_MEH   MEH_T(DE_U)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  Tab   │   Q  │   W  │   E  │   R  │   T  │                              │   Z  │   U  │   I  │   O  │   P  │    Ü   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   A  │   S  │   D  │   F  │   G  │                              │   H  │   J  │   K  │   L  │   Ö  │    Ä   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   Y  │   X  │   C  │   V  │   B  │ Adj  │CapsLk│  │  MFn │  Adj │   N  │   M  │   ,  │   .  │ ß  ? │RSft/DEL│
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │ Copy │ Paste│ │  Nav │ │ Symb/│ MFn  │  │ Adj/ │ Symb/│ │  Nav │ │PrtScr│ Menu │
 *                    │      │      │ │      │ │ Enter│ Space│  │ Enter│ Space│ │      │ │      │      │
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_QWER] = LAYOUT(
     KC_TAB,  DE_Q,   DE_W, HE_GUI, HR_MEH, DE_T,                                        DE_Z, HU_MEH, HI_GUI,    DE_O,    DE_P, DE_UDIA,
     CTL_ESC, DE_A, HS_ALT, HD_CTL, HF_SFT, DE_G,                                        DE_H, HJ_SFT, HK_CTL,  HL_ALT, DE_ODIA, DE_ADIA,
     SFT_BSP, DE_Y,   DE_X,   DE_C,   DE_V, DE_B,   ADJ,   KC_CAPS,      MFN,     ADJ,   DE_N,   DE_M, DE_COMM, DE_DOT,   DE_SS, SFT_DEL,
                     SY_COPY, SY_PASTE,  NAV,     SYM_ENT, MFN_SPC,    ADJ_ENT, SYM_SPC,    NAV,       KC_PSCR, KC_APP//ENC
    ),
// */

/*
 * Base Layer: Bone
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  Tab   │   J  │   D  │   U  │   A  │   X  │                              │   P  │   H  │   L  │   M  │   W  │   ß ;  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   C  │   T  │   I  │   E  │   O  │                              │   B  │   N  │   R  │   S  │   G  │   Q    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   F  │   V  │   Ü  │   Ä  │   Ö  │ Adj  │CapsLk│  │  MFn │  Adj │   Y  │   Z  │  , ; │  . : │   K  │RSft/DEL│
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │ Copy │ Paste│ │  Nav │ │ Symb/│ MFn  │  │ Adj/ │ Symb/│ │  Nav │ │PrtScr│ Menu │
 *                    │      │      │ │      │ │ Enter│ Space│  │ Enter│ Space│ │      │ │      │      │
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_BONE] = LAYOUT(
     KC_TAB,  DE_J, DE_D,   HU_GUI,  HA_MEH, DE_X,                                       DE_P, HH_MEH,  HL_GUI,   DE_M, DE_W,   DE_SS,
     CTL_ESC, DE_C, HT_ALT, HI_CTL,  HE_SFT, DE_O,                                       DE_B, HN_SFT,  HR_CTL, HS_ALT, DE_G,    DE_Q,
     SFT_BSP, DE_F, DE_V,  DE_UDIA, DE_ADIA, DE_ODIA, ADJ, KC_CAPS,      MFN,     ADJ,   DE_Y,   DE_Z, DE_COMM, DE_DOT, DE_K, SFT_DEL,
                      SY_COPY, SY_PASTE,  NAV,    SYM_ENT, MFN_SPC,    ADJ_ENT, SYM_SPC,    NAV,       KC_PSCR, KC_APP//ENC
    ),
// */

/*
 * Base Layer: NEO2
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  Tab   │   X  │   V  │   L  │   C  │   W  │                              │   K  │   H  │   G  │   F  │   Q  │   ß ;  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   U  │   I  │   A  │   E  │   O  │                              │   S  │   N  │   R  │   T  │   D  │   Y    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   Ü  │   Ö  │   Ä  │   P  │   Z  │ Adj  │CapsLk│  │  MFn │  Adj │   B  │   M  │  , ; │  . : │   J  │RSft/DEL│
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │ Copy │ Paste│ │  Nav │ │ Symb/│ MFn  │  │ Adj/ │ Symb/│ │  Nav │ │PrtScr│ Menu │
 *                    │      │      │ │      │ │ Enter│ Space│  │ Enter│ Space│ │      │ │      │      │
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_NEO2] = LAYOUT(
     KC_TAB,  DE_X,    DE_V,     HL_GUI,  HC_MEH, DE_W,                                    DE_K, HH_MEH,  HG_GUI,   DE_F, DE_Q,   DE_SS,
     CTL_ESC, DE_U,    HI_ALT,   HA_CTL,  HE_SFT, DE_O,                                    DE_S, HN_SFT,  HR_CTL, HT_ALT, DE_D,    DE_Y,
     SFT_BSP, DE_UDIA, DE_ODIA,  DE_ADIA, DE_P,   DE_Z, ADJ, KC_CAPS,      MFN,     ADJ,   DE_B,   DE_M, DE_COMM, DE_DOT, DE_J, SFT_DEL,
                       SY_COPY, SY_PASTE,    NAV,   SYM_ENT, MFN_SPC,    ADJ_ENT, SYM_SPC,    NAV,       KC_PSCR, KC_APP//ENC
    ),
// */

/*
 * Base Layer: Colemak DH (DE)
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  Tab   │   Q  │   W  │   F  │   P  │   B  │                              │   J  │   L  │   U  │   Y  │   Ö  │    Ü   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   A  │   R  │   S  │   T  │   G  │                              │   M  │ SFT/N│   E  │   I  │   O  │    Ä   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   Z  │   X  │   C  │   D  │   V  │ Adj  │CapsLk│  │  MFn │  Adj │   K  │   H  │  , ; │  . : │   ß  │RSft/DEL│
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │ Copy │ Paste│ │  Nav │ │ Symb/│ MFn  │  │ Adj/ │ Symb/│ │  Nav │ │PrtScr│ Menu │
 *                    │      │      │ │      │ │ Enter│ Space│  │ Enter│ Space│ │      │ │      │      │
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_COLE] = LAYOUT(
     KC_TAB,  DE_Q,   DE_W, HF_GUI, HP_GUI, DE_B,                                        DE_J, HL_MEH,  HU_GUI,   DE_Y, DE_ODIA, DE_UDIA,
     CTL_ESC, DE_A, HR_ALT, HS_CTL, HT_SFT, DE_G,                                        DE_M, HN_SFT,  HE_CTL, HI_ALT,    DE_O, DE_ADIA,
     SFT_BSP, DE_Z,   DE_X,   DE_C,   DE_D, DE_V, ADJ, KC_CAPS,          MFN,     ADJ,   DE_K,   DE_H, DE_COMM, DE_DOT,   DE_SS, SFT_DEL,
              SY_COPY, SY_PASTE,   NAV,     SYM_ENT, MFN_SPC,            ADJ_ENT, SYM_SPC,   NAV,      KC_PSCR, KC_APP//ENC
    ),
// */

/*
 * Sym Layer: Numbers and symbols
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │ (LEAD) │  …   │  _   │  [   │  ]   │  ^   │                              │   !  │  <   │  >   │  =   │  &   │   €    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  \   │  /   │  {   │  }   │  *   │                              │   ?  │  (   │  )   │  -   │  :   │   @    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  #   │  $   │  │   │  ~   │  `   │      │      │  │      │      │   +  │  %   │  "   │  '   │  ;   │        │
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │ Cut  │  ^   │ │  ~   │ │      │      │  │      │      │ │   `  │ │  '   │      │
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_SYM] = LAYOUT(
            KC_LEAD ,SY_HELL ,DE_UNDS ,DE_LBRC ,DE_RBRC ,SY_CIRC ,                                            DE_EXLM ,DE_LABK ,DE_RABK ,DE_EQL  ,DE_AMPR ,DE_EURO ,
            _______ ,DE_BSLS ,DE_SLSH ,DE_LCBR ,DE_RCBR ,DE_ASTR ,                                            DE_QUES ,DE_LPRN ,DE_RPRN ,DE_MINS ,DE_COLN ,DE_AT   ,
            _______ ,DE_HASH ,DE_DLR  ,DE_PIPE ,SY_TILD ,SY_BKTK ,_______ ,_______ ,        _______ ,_______ ,DE_PLUS ,DE_PERC ,DE_DQUO ,DE_QUOT ,DE_SCLN ,_______ ,
                               SY_CUT ,DE_CIRC ,     DE_TILD ,    KC_TRNS ,_______ ,        _______ ,KC_TRNS ,    DE_GRV  ,     DE_ACUT ,_______
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │ A-TAB  │ PgUp │ BSpc │   ↑  │ Del  │ Ins  │                              │   *  │   7  │   8  │   9  │   /  │    ;   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │ Home │  ←   │   ↓  │   →  │ End  │                              │   0  │   4  │   5  │   6  │   .  │    :   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │ ESC  │ Undo │ Redo │Enter │ PgDn │WHome │NumLk │  │      │      │   +  │   1  │   2  │   3  │   ,  │    -   │
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │ Cut  │Redo2 │ │      │ │ WBAK │ WFWD │  │      │      │ │      │ │      │PrtScr│
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_NAV] = LAYOUT(
            SY_ATAB, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_INS,                                             DE_ASTR, DE_7,    DE_8,    DE_9,    DE_SLSH, DE_SCLN,
            _______, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT, KC_END,                                             DE_0,    DE_4,    DE_5,    DE_6,    DE_DOT,  DE_COLN,
            _______, KC_ESC,  SY_UNDO, SY_REDO, KC_ENT,  KC_PGDN, KC_WHOM, KC_NUM,         _______, _______, DE_PLUS, DE_1,    DE_2,    DE_3,    DE_COMM, DE_MINS,
                               SY_CUT, SY_RYDO,     KC_TRNS,      KC_WBAK, KC_WFWD,        _______, _______,     KC_TRNS,      _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │        │      │      │ Vol+ │ MUTE │      │                              │      │  F7  │  F8  │  F9  │ F10  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ Prev │ Vol- │ Play │      │                              │      │  F4  │  F5  │  F6  │ F11  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │ ?en  │      │      │PAUSE │  │      │      │      │  F1  │  F2  │  F3  │ F12  │        │
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │      │      │ │      │ │      │      │  │      │      │ │      │ │ PWR  │ MUTE │
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_MFN] = LAYOUT(
     _______, XXXXXXX, XXXXXXX, KC_VOLU, KC_MUTE, XXXXXXX,                                            XXXXXXX, KC_F7 , KC_F8, KC_F9, KC_F10, XXXXXXX,
     _______, XXXXXXX, KC_MPRV, KC_VOLD, KC_MPLY, KC_MNXT,                                            XXXXXXX, KC_F4 , KC_F5, KC_F6, KC_F11, XXXXXXX,
     _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES, XXXXXXX, _______, KC_PAUS,        KC_TRNS, _______, XXXXXXX, KC_F1 , KC_F2, KC_F3, KC_F12, _______,
                       _______, _______,     _______,      _______, KC_TRNS,        _______, _______,    _______,     KC_PWR, KC_MUTE
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  VAL+  │ WH ↑ │ WBAK │ MS ↑ │ WFWD │ HUE+ │                              │ TOG  │ MOD+ │ HUE+ │ VAL+ │ SAT+ │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  TOG   │ WH ← │ MS ← │ MS ↓ │ MS → │ WH → │                              │ PAT  │ MOD- │ HUE- │ VAL- │ SAT- │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  VAL-  │QWERTY│ Bone │ Neo2 │Colmak│ WH ↓ │      │ SCRL │  │      │      │      │Colmak│ Neo2 │ BONE │QWERTY│        │
 * └────────┴──────┴──┬───┴──┬───┴──┬─┬─┴────┬─┼──────┼──────┤  ├──────┼──────┼─┬────┴─┬─┬──┴───┬──┴───┬──┴──────┴────────┘
 *                    │ PAT  │ MOD+ │ │ BT 3 │ │ BT 1 │ BT 2 │  │      │ BT 4 │ │ BT 5 │ │ UTF  │ BT 1 │
 *                    └──────┴──────┘ └──────┘ └──────┴──────┘  └──────┴──────┘ └──────┘ └──────┴──────┘
 */
    [_ADJ] = LAYOUT(
     RGB_VAI, KC_WH_U, KC_WBAK, KC_MS_U, KC_WFWD, RGB_HUI,                                            RGB_TOG,  RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, XXXXXXX,
     RGB_TOG, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,                                            RGB_M_P, RGB_RMOD, RGB_HUD, RGB_VAD, RGB_SAD, XXXXXXX,
     RGB_VAD,    QWER,    BONE,    NEO2,    COLE, KC_WH_D, KC_TRNS, KC_SCRL,        _______, KC_TRNS, XXXXXXX,     COLE,    NEO2,    BONE,    QWER, _______,
                       RGB_M_P, RGB_MOD,    KC_BTN3,       KC_BTN1, KC_BTN2,        KC_TRNS, KC_BTN4,     KC_BTN5,    UC_MOD, KC_BTN1
    ),

};

// Send custom strings or change default base layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t active_modifiers = get_mods();
    clear_mods();
    if (active_modifiers & MOD_MASK_SHIFT) {
        switch (keycode) {
//            // default layer
//            case SY_MINS:
//                if (record->event.pressed) send_unicode_string("—"); // em dash
//                break;
//            case DE_COMM:
//                if (record->event.pressed) send_unicode_string("–"); // en dash
//                break;
//            case DE_DOT:
//                if (record->event.pressed) send_unicode_string("•");
//                break;
//            case DE_SS:
//                if (record->event.pressed) send_unicode_string("ẞ"); // capital german sharp s
//                break;
//            // symbol layer
//            // left hand
//            case DE_HASH:
//                if (record->event.pressed) send_unicode_string("⇑");
//                break;
//            case DE_LBRC:
//                if (record->event.pressed) send_unicode_string("«");
//                break;
//            case DE_BSLS:
//                if (record->event.pressed) send_unicode_string("↑");
//                break;
//            case DE_RBRC:
//                if (record->event.pressed) send_unicode_string("»");
//                break;
//            case SY_CIRC:
//                if (record->event.pressed) send_unicode_string("⇐");
//                break;
//            case DE_LCBR:
//                if (record->event.pressed) send_unicode_string("←");
//                break;
//            case DE_TILD:
//                if (record->event.pressed) send_unicode_string("↓");
//                break;
//            case DE_RCBR:
//                if (record->event.pressed) send_unicode_string("→");
//                break;
//            case DE_DLR:
//                if (record->event.pressed) send_unicode_string("⇒");
//                break;
//            case DE_EURO:
//                if (record->event.pressed) send_unicode_string("¢");
//                break;
//            case SY_BKTK:
//                if (record->event.pressed) send_unicode_string("‹");
//                break;
//            case DE_PIPE:
//                if (record->event.pressed) send_unicode_string("⇔");
//                break;
//            case DE_QUES:
//                if (record->event.pressed) send_unicode_string("›");
//                break;
//            case DE_ASTR:
//                if (record->event.pressed) send_unicode_string("⇓");
//                break;
//            // right hand
//            case DE_LABK:
//                if (record->event.pressed) send_unicode_string("„");
//                break;
//            case DE_SLSH:
//                if (record->event.pressed) send_unicode_string("“");
//                break;
//            case DE_RABK:
//                if (record->event.pressed) send_unicode_string("”");
//                break;
//            case DE_MINS:
//                if (record->event.pressed) send_unicode_string("—"); // em dash
//                break;
//            case DE_RPRN:
//                if (record->event.pressed) send_unicode_string("λ");
//                break;
//            case DE_EXLM:
//                if (record->event.pressed) send_unicode_string("‚");
//                break;
//            case DE_DQUO:
//                if (record->event.pressed) send_unicode_string("‘");
//                break;
//            case DE_QUOT:
//                if (record->event.pressed) send_unicode_string("’");
//                break;
            default:
                set_mods(active_modifiers);
                return true;
        }
    }
    // unshifted
    else switch (keycode) {
        case SY_HELL:
            if (record->event.pressed) send_string("…");
            break;
        case SY_CIRC:
            if (record->event.pressed) send_string("^");
            break;
        case SY_TILD:
            if (record->event.pressed) send_string("~");
            break;
        case SY_BKTK:
            if (record->event.pressed) send_string("`");
            break;
        default:
            set_mods(active_modifiers);
            return true;
    }
    set_mods(active_modifiers);
    return false;
}

#ifdef IGNORE_MOD_TAP_INTERRUPT_PER_KEY
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_BSPC):
        case RSFT_T(KC_DEL):
        case LT(_SYM,KC_ENT):
        case LT(_SYM,KC_SPC):
            return false;
    }
    return true;
}
#endif

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
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
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWER:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _BONE:
                oled_write_P(PSTR("Bone\n"), false);
                break;
            case _NEO2:
                oled_write_P(PSTR("Neo2\n"), false);
                break;
            case _COLE:
                oled_write_P(PSTR("Colemak-D(E)H\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav/Num\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _MFN:
                oled_write_P(PSTR("Media/Fn\n"), false);
                break;
            case _ADJ:
                oled_write_P(PSTR("Mouse/Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(PSTR("\nLOCK: "), false);
        oled_write_P(PSTR("NUM"), led_usb_state.num_lock);
        oled_write_P(PSTR("  "), false);
        oled_write_P(PSTR("CAPS"), led_usb_state.caps_lock);
        oled_write_P(PSTR("  "), false);
        oled_write_P(PSTR("SCR"), led_usb_state.scroll_lock);
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

#ifdef RGBLIGHT_LAYERS
// Light inner 4 LEDs red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED},       // Light 2 LEDs, starting with first LED of left half
    {10, 2, HSV_RED}       // Light 2 LEDs, starting with first LED of right half
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_capslock_layer);
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    led_t led_state = host_keyboard_led_state();
    if (!led_state.num_lock) {
        tap_code(KC_NUMLOCK);
    }
}
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
#else
void keyboard_post_init_user(void) {
    led_t led_state = host_keyboard_led_state();
    if (!led_state.num_lock) {
        tap_code(KC_NUMLOCK);
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _MFN:
            // audio control
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;
        case _ADJ:
            // mouse scrolling
            tap_code(clockwise ? KC_WH_D : KC_WH_U);
            break;
        case _NAV:
            // (browser) tabbing
            tap_code16(clockwise ? C(KC_TAB) : RCS(KC_TAB));
        case _SYM:
            uint8_t active_modifiers = get_mods();
            // Line/Page up/down
            if (active_modifiers & MOD_MASK_CTRL) {
                clear_mods();
                tap_code(clockwise ? KC_PGDN : KC_PGUP);
                set_mods(active_modifiers);
            }
            else tap_code(clockwise ? KC_DOWN : KC_UP);
            break;
        default:
            // left/right
            tap_code(clockwise ? KC_RIGHT : KC_LEFT);
            break;
    }
    return false;
}
#endif
