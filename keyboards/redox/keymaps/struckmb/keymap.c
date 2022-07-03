#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

enum layer_names {
    // - Base layers:
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
    // special or replaced symbols
    SY_SALT = SAFE_RANGE, // oldstlye german long s
    SY_HELL, // horizontal ellipsis
    SY_CIRC, // caret (non dead)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
    SY_LSQU,
    SY_RSQU,
    // number keys in symbol layer
    BN3_4,
    BN3_5,
    SY_CENT, // BN3_6
    BN3_7,
    BN3_8,
    // number keys in navi/keypad layer
    BN4_1,
    BN4_2,
    BN4_3,
    BN4_5
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
#define DE_SUP1 ALGR(DE_1)    // ¹

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  ~ °   │   1  │   2  │   3  │   4  │   5  ├──────┐                ┌──────┤   6  │   7  │   8  │   9  │   0  │    -   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  `   │                │   ´  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Tab   │   Q  │   W  │   E  │   R  │   T  ├──────┤                ├──────┤   Z  │   U  │   I  │   O  │   P  │    Ü   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ CTL  │                │  ALT ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   A  │   S  │   D  │   F  │   G  │      │                │      │   H  │   J  │   K  │   L  │   Ö  │    Ä   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   Y  │   X  │   C  │   V  │   B  │ Adj  │CapsLk│  │  MFn │  Adj │   N  │   M  │   ,  │   .  │ ß  ? │RSft/DEL│
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │ L-GUI  │Select│ Copy │ Paste│  │ Nav  │   │ Symb/│ MFn  │  │ Adj/ │ Symb/│   │  Nav │  │PrtScr│ Menu │ Power│  R-GUI │
 * │        │  All │      │      │  │      │   │ Enter│ Space│  │ Enter│ Space│   │      │  │      │      │      │        │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_QWER] = LAYOUT(
     KC_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                                                DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS,
     KC_TAB,  DE_Q,    DE_W,    HE_GUI,  HR_MEH,  DE_T,    DE_GRV,                            DE_QUOT, DE_Z,    HU_MEH,  HI_GUI,  DE_O,    DE_P,    DE_UDIA,
     CTL_ESC, DE_A,    HS_ALT,  HD_CTL,  HF_SFT,  DE_G,    KC_LCTL,                           KC_LALT, DE_H,    HJ_SFT,  HK_CTL,  HL_ALT,  DE_ODIA, DE_ADIA,
     SFT_BSP, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    ADJ,     KC_CAPS,         MFN,     ADJ,     DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SS,   SFT_DEL,
     KC_LGUI, SY_SALL, SY_COPY, SY_PASTE,     NAV,         SYM_ENT, MFN_SPC,         ADJ_ENT, SYM_SPC,     NAV,          KC_PSCR, KC_APP,  KC_PWR,  KC_RGUI
  ),

/*
 * Base Layer: BONE
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  ~ °   │   1  │   2  │   3  │   4  │   5  ├──────┐                ┌──────┤   6  │   7  │   8  │   9  │   0  │    -   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  `   │                │   ´  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Tab   │   J  │   D  │   U  │   A  │   X  ├──────┤                ├──────┤   P  │   H  │   L  │   M  │   W  │    ß   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ CTL  │                │  ALT ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   C  │   T  │   I  │   E  │   O  │      │                │      │   B  │   N  │   R  │   S  │   G  │    Q   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   F  │   V  │   Ü  │   Ä  │   Ö  │ Adj  │CapsLk│  │  MFn │  Adj │   Y  │   Z  │   ,  │   .  │   K  │RSft/DEL│
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │ L-GUI  │Select│ Copy │ Paste│  │ Nav  │   │ Symb/│ MFn  │  │ Adj/ │ Symb/│   │  Nav │  │PrtScr│ Menu │ Power│  R-GUI │
 * │        │  All │      │      │  │      │   │ Enter│ Space│  │ Enter│ Space│   │      │  │      │      │      │        │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_BONE] = LAYOUT(
     KC_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                                                DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS,
     KC_TAB,  DE_J,    DE_D,    HU_GUI,  HA_MEH,  DE_X,    DE_GRV,                            DE_QUOT, DE_P,    HH_MEH,  HL_GUI,  DE_M,    DE_W,    DE_SS,
     CTL_ESC, DE_C,    HT_ALT,  HI_CTL,  HE_SFT,  DE_O,    KC_LCTL,                           KC_LALT, DE_B,    HN_SFT,  HR_CTL,  HS_ALT,  DE_G,    DE_Q,
     SFT_BSP, DE_F,    DE_V,    DE_UDIA, DE_ADIA, DE_ODIA, ADJ,     KC_CAPS,         MFN,     ADJ,     DE_Y,    DE_Z,    DE_COMM, DE_DOT,  DE_K,    SFT_T(KC_DEL),
     KC_LGUI, SY_SALL, SY_COPY, SY_PASTE,     NAV,         SYM_ENT, MFN_SPC,         ADJ_ENT, SYM_SPC,     NAV,          KC_PSCR, KC_APP,  KC_PWR,  KC_RGUI
  ),

/*
 * Base Layer: Neo2
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  ~ °   │   1  │   2  │   3  │   4  │   5  ├──────┐                ┌──────┤   6  │   7  │   8  │   9  │   0  │    -   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  `   │                │   ´  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Tab   │   X  │   V  │   L  │   C  │   W  ├──────┤                ├──────┤   K  │   H  │   G  │   F  │   Q  │    ß   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ CTL  │                │  ALT ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   U  │   I  │   A  │   E  │   O  │      │                │      │   S  │   N  │   R  │   T  │   D  │    Y   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   Ü  │   Ö  │   Ä  │   P  │   Z  │ Adj  │CapsLk│  │  MFn │  Adj │   B  │   M  │   ,  │   .  │   J  │RSft/DEL│
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │ L-GUI  │Select│ Copy │ Paste│  │ Nav  │   │ Symb/│ MFn  │  │ Adj/ │ Symb/│   │  Nav │  │PrtScr│ Menu │ Power│  R-GUI │
 * │        │  All │      │      │  │      │   │ Enter│ Space│  │ Enter│ Space│   │      │  │      │      │      │        │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_NEO2] = LAYOUT(
     KC_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                                                DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS,
     KC_TAB,  DE_X,    DE_V,    HL_GUI,  HC_MEH,  DE_W,    DE_GRV,                            DE_QUOT, DE_K,    HH_MEH,  HG_GUI,  DE_F,    DE_Q,    DE_SS,
     CTL_ESC, DE_U,    HI_ALT,  HA_CTL,  HE_SFT,  DE_O,    KC_LCTL,                           KC_LALT, DE_S,    HN_SFT,  HR_CTL,  HT_ALT,  DE_D,    DE_Y,
     SFT_BSP, DE_UDIA, DE_ODIA, DE_ADIA, DE_P,    DE_Z,    ADJ,     MFN,             MFN,     ADJ,     DE_B,    DE_M,    DE_COMM, DE_DOT,  DE_J,    SFT_DEL,
     KC_LGUI, SY_SALL, SY_COPY, SY_PASTE,     NAV,         SYM_ENT, MFN_SPC,         ADJ_ENT, SYM_SPC,     NAV,          KC_PSCR, KC_APP,  KC_PWR,  KC_RGUI
  ),

/*
 * Base Layer: Colemak DH (DE)
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  ~ °   │   1  │   2  │   3  │   4  │   5  ├──────┐                ┌──────┤   6  │   7  │   8  │   9  │   0  │    -   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  `   │                │   ´  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Tab   │   Q  │   W  │   F  │   P  │   B  ├──────┤                ├──────┤   J  │   L  │   U  │   Y  │   Ö  │    Ü   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ CTL  │                │  ALT ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │Ctrl/Esc│   A  │   R  │   S  │   T  │   G  │      │                │      │   M  │ SFT/N│   E  │   I  │   O  │    Ä   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │LSft/BSP│   Z  │   X  │   C  │   D  │   V  │ Adj  │CapsLk│  │  MFn │  Adj │   K  │   H  │  , ; │  . : │   ß  │RSft/DEL│
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │ L-GUI  │Select│ Copy │ Paste│  │ Nav  │   │ Symb/│ MFn  │  │ Adj/ │ Symb/│   │  Nav │  │PrtScr│ Menu │ Power│  R-GUI │
 * │        │  All │      │      │  │      │   │ Enter│ Space│  │ Enter│ Space│   │      │  │      │      │      │        │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_COLE] = LAYOUT(
     KC_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                                                DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS,
     KC_TAB,  DE_Q,    DE_W,    HF_GUI,  HP_GUI,  DE_B,    DE_GRV,                            DE_QUOT, DE_J,    HL_MEH,  HU_GUI,  DE_Y,    DE_ODIA, DE_UDIA,
     CTL_ESC, DE_A,    HR_ALT,  HS_CTL,  HT_SFT,  DE_G,    KC_LCTL,                           KC_LALT, DE_M,    HN_SFT,  HE_CTL,  HI_ALT,  DE_O,    DE_ADIA,
     SFT_BSP, DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,    ADJ, KC_CAPS,                 MFN,     ADJ, DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_SS,   SFT_DEL,
     KC_LGUI, SY_SALL, SY_COPY, SY_PASTE,     NAV,         SYM_ENT, MFN_SPC,         ADJ_ENT, SYM_SPC,     NAV,          KC_PSCR, KC_APP,  KC_PWR,  KC_RGUI
  ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  ~ °   │  ¹   │  ²   │  ³   │  ›   │  ‹   ├──────┐                ┌──────┤   ¢  │   ¥  │  ‚   │   9  │   0  │    -   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ (LEAD) │  …   │  _   │  [   │  ]   │  ^   ├──────┤                ├──────┤   !  │  <   │  >   │  =   │  &   │   €    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  \   │  /   │  {   │  }   │  *   │      │                │      │   ?  │  (   │  )   │  -   │  :   │   @    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  #   │  $   │  |   │  ~   │  `   │      │      │  │      │      │   +  │  %   │  "   │  '   │  ;   │        │
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │        │      │ Cut  │ ^(d) │  │ ~(d) │   │      │      │  │      │      │   │ `(d) │  │ '(d) │      │      │        │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_SYM] = LAYOUT(
     _______, DE_SUP1, DE_SUP2, DE_SUP3, BN3_4,   BN3_5,                                               SY_CENT,   BN3_7,   BN3_8,   SY_LSQU, SY_RSQU, SY_SALT,
     KC_LEAD, SY_HELL, DE_UNDS, DE_LBRC, DE_RBRC, SY_CIRC, _______,                           _______, DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_EURO,
     _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, _______,                           _______, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
     _______, DE_HASH, DE_DLR,  DE_PIPE, SY_TILD, SY_BKTK, _______, _______,         _______, _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______,
     _______, _______, SY_CUT,  DE_CIRC,      DE_TILD,     KC_TRNS, _______,         _______, KC_TRNS,     DE_GRV,       DE_ACUT, _______, _______, _______
  ),

/*
 * Navigation Layer: Arrow keys, Number pad
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  ~ °   │  ª   │  º   │  №   │      │  ·   ├──────┐                ┌──────┤      │   $  │   €  │   ¢  │  TAB │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ A-TAB  │ PgUp │BkSpc │  Up  │ Del  │ Ins  ├──────┤                ├──────┤      │   7  │   8  │   9  │   /  │    *   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │ Home │  ←   │   ↓  │   →  │ End  │      │                │      │   -  │   4  │   5  │   6  │   0  │    ;   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │ ESC  │ Undo │ Redo │Enter │ PgDn │WHome │NumLk │  │      │      │   +  │   1  │   2  │   3  │   :  │        │
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │        │      │ Cut  │Redo2 │  │      │   │ WBAK │ WFWD │  │   ,  │   .  │   │      │  │   ;  │PrtScr│      │        │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_NAV] = LAYOUT( // BN4_4 is undefined
     _______, BN4_1,   BN4_2,   BN4_3,   XXXXXXX, BN4_5,                                               XXXXXXX, DE_DLR,  DE_EURO, SY_CENT, KC_TAB,  _______,
     SY_ATAB, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_INS,  _______,                           _______, XXXXXXX, DE_7,    DE_8,    DE_9,    KC_PSLS, KC_PAST,
     _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,  _______,                           _______, KC_PMNS, DE_4,    DE_5,    DE_6,    DE_0,    DE_SCLN,
     _______, KC_ESC,  SY_UNDO, SY_REDO, KC_ENT,  KC_PGDN, KC_WHOM, KC_NUM,          _______, _______, KC_PPLS, DE_1,    DE_2,    DE_3,    DE_COLN, _______,
     _______ ,_______, SY_CUT,  SY_RYDO,     KC_TRNS,      KC_WBAK, KC_WFWD,         DE_COMM, KC_PDOT,     KC_TRNS,      _______, _______ ,_______ ,_______
  ),

/*
 * Media and Function key Layer: Some keys…
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │        │  F1  │  F2  │  F3  │  F4  │  F5  ├──────┐                ┌──────┤   F6 │  F7  │  F8  │  F9  │  F10 │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ F11  │                │ F12  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ (LEAD) │      │      │ Vol+ │ MUTE │      ├──────┤                ├──────┤      │  F7  │  F8  │  F9  │  F10 │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ Prev │ Vol- │ Play │      │      │                │      │      │  F4  │  F5  │  F6  │  F11 │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │ ?en  │      │      │PAUSE │  │      │      │      │  F1  │  F2  │  F3  │  F12 │        │
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │  │      │   │      │      │  │      │      │   │      │  │ PWR  │      │      │  Mute  │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_MFN] = LAYOUT(
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
     _______, XXXXXXX, XXXXXXX, KC_VOLU, KC_MUTE, XXXXXXX, KC_F11,                             KC_F12, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
     _______, XXXXXXX, KC_MPRV, KC_VOLD, KC_MPLY, KC_MNXT, _______,                           _______, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
     _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUES, XXXXXXX, _______, KC_PAUS,         KC_TRNS, _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3   ,KC_F12  ,_______,
     _______, _______, _______, _______,      _______,     _______, KC_TRNS,         _______, _______,     _______,      KC_PWR,  _______, _______, KC_MUTE
  ),

/*
 * Adjust Layer: Mouse, RGB
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │  SAT+  │      │      │      │      │      ├──────┐                ┌──────┤      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  VAL+  │ WH ↑ │ WBAK │ MS ↑ │ WFWD │      ├──────┤                ├──────┤ TOG  │ MOD+ │ HUE+ │ VAL+ │ SAT+ │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  TOG   │ WH ← │ MS ← │ MS ↓ │ MS → │ WH → │      │                │      │ PAT  │ MOD- │ HUE- │ VAL- │ SAT- │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  VAL-  │QWERTY│ Bone │ Neo2 │Colmak│ WH ↓ │      │ SCRL │  │      │      │      │Colmak│ Neo2 │ BONE │QWERTY│        │
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │  SAT-  │ PAT  │ MOD+ │ HUE+ │  │ BT 3 │   │ BT 1 │ BT 2 │  │      │ BT 4 │   │ BT 5 │  │ UTF  │      │      │  RESET │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_ADJ] = LAYOUT(
      // no hmod on lhs to enable mouse steering (key repetition)
      // on rhs hmod (for shift-click, ctrl-click, …), set tap to NO instead of TRANSPARENT
     RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     RGB_VAI, KC_WH_U, KC_WBAK, KC_MS_U, KC_WFWD, XXXXXXX, RESET,                               RESET, RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, XXXXXXX,
     RGB_TOG, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______,                           _______, RGB_M_P, RGB_RMOD,RGB_HUD, RGB_VAD, RGB_SAD, XXXXXXX,
     RGB_VAD,    QWER,    BONE,    NEO2,    COLE, KC_WH_D, KC_TRNS, KC_SCRL,        _______, KC_TRNS, XXXXXXX,     COLE,    NEO2,    BONE,    QWER, _______,
     RGB_SAD, RGB_M_P, RGB_MOD, RGB_HUI,    KC_BTN3,       KC_BTN1, KC_BTN2,        KC_TRNS, KC_BTN4,     KC_BTN5,        UC_MOD, _______, _______, _______
  )

};

#ifdef LEADER_ENABLE
// leader key definitions
LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_TWO_KEYS(DE_C, DE_O) {
        send_string("©");
    }
    SEQ_TWO_KEYS(KC_O, KC_C) {
        send_string("©");
    }
    SEQ_TWO_KEYS(KC_O, KC_R) {
        send_string("®");
    }
    SEQ_TWO_KEYS(KC_R, KC_O) {
        send_string("®");
    }
  }
}
#endif

#ifdef RGBLIGHT_LAYERS
// Light LEDs 6 to 8 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED},      // Light 3 LEDs, starting with first LED
    {11, 3, HSV_RED}       // Light 3 LEDs, starting with first LED
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_CYAN},
    {12, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_PURPLE},
    {12, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GREEN},
    {12, 1, HSV_GREEN}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer, // Overrides caps lock layer
    // Overrides other layers
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer
);
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
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MFN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJ));
    return state;
}
#else
void keyboard_post_init_user(void) {
    led_t led_state = host_keyboard_led_state();
    if (!led_state.num_lock) {
        tap_code(KC_NUMLOCK);
    }
}
#endif

#ifdef IGNORE_MOD_TAP_INTERRUPT_PER_KEY
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_BSPC):
        case RSFT_T(KC_DEL):
        case LT(_SYM,KC_ENT):
        case LT(_SYM,KC_SPC):
            return false;
        default:
            return true;
    }
}
#endif

// Send custom strings or change default base layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t active_modifiers = get_mods();
    clear_mods();
    if (active_modifiers & MOD_MASK_SHIFT) {
        switch (keycode) {
            // number row
            case DE_SUP1:
                if (record->event.pressed) send_unicode_string("₁");
                break;
            case DE_SUP2:
                if (record->event.pressed) send_unicode_string("₂");
                break;
            case DE_SUP3:
                if (record->event.pressed) send_unicode_string("₃");
                break;
            case BN3_4:
                if (record->event.pressed) send_unicode_string("♀");
                break;
            case BN3_5:
                if (record->event.pressed) send_unicode_string("♂");
                break;
            case SY_CENT:
                if (record->event.pressed) send_unicode_string("⚥");
                break;
            case BN3_7:
                if (record->event.pressed) send_unicode_string("ϰ");
                break;
            case BN3_8:
                if (record->event.pressed) send_unicode_string("⟨");
                break;
            case SY_LSQU:
                if (record->event.pressed) send_unicode_string("⟩");
                break;
            case SY_RSQU:
                if (record->event.pressed) send_unicode_string("₀");
                break;
            // default layer
            case DE_MINS:
                if (record->event.pressed) send_unicode_string("—"); // em dash
                break;
            case DE_COMM:
                if (record->event.pressed) send_unicode_string("–"); // en dash
                break;
            case DE_DOT:
                if (record->event.pressed) send_unicode_string("•");
                break;
            case DE_SS:
                if (record->event.pressed) send_unicode_string("ẞ"); // capital german sharp s
                break;
            // symbol layer
            // left hand
            case DE_HASH:
                if (record->event.pressed) send_unicode_string("⇑");
                break;
            // case DE_LBRC:
            //     if (record->event.pressed) send_unicode_string("«");
            //     break;
            case DE_BSLS:
                if (record->event.pressed) send_unicode_string("↑");
                break;
            // case DE_RBRC:
            //     if (record->event.pressed) send_unicode_string("»");
            //     break;
            case SY_CIRC:
                if (record->event.pressed) send_unicode_string("⇐");
                break;
            case DE_LCBR:
                if (record->event.pressed) send_unicode_string("←");
                break;
            case SY_TILD:
                if (record->event.pressed) send_unicode_string("↓");
                break;
            case DE_RCBR:
                if (record->event.pressed) send_unicode_string("→");
                break;
            case DE_DLR:
                if (record->event.pressed) send_unicode_string("⇒");
                break;
            case DE_EURO:
                if (record->event.pressed) send_unicode_string("¢");
                break;
            case SY_BKTK:
                if (record->event.pressed) send_unicode_string("‹");
                break;
            case DE_PIPE:
                if (record->event.pressed) send_unicode_string("⇔");
                break;
            case DE_QUES:
                if (record->event.pressed) send_unicode_string("›");
                break;
            case DE_ASTR:
                if (record->event.pressed) send_unicode_string("⇓");
                break;
            // right hand
            // case DE_LABK:
            //     if (record->event.pressed) send_unicode_string("„");
            //     break;
            // case DE_SLSH:
            //     if (record->event.pressed) send_unicode_string("“");
            //     break;
            // case DE_RABK:
            //     if (record->event.pressed) send_unicode_string("”");
            //     break;
            // case DE_MINS:
            //     if (record->event.pressed) send_unicode_string("—"); // em dash
            //     break;
            case DE_RPRN:
                if (record->event.pressed) send_unicode_string("λ");
                break;
            case DE_EXLM:
                if (record->event.pressed) send_unicode_string("‚");
                break;
            case DE_DQUO:
                if (record->event.pressed) send_unicode_string("‘");
                break;
            case DE_QUOT:
                if (record->event.pressed) send_unicode_string("’");
                break;
            default:
                set_mods(active_modifiers);
                return true;
        }
    }
    // unshifted
    else switch (keycode) {
        case BN3_4:
            if (record->event.pressed) send_unicode_string("›");
            break;
        case BN3_5:
            if (record->event.pressed) send_unicode_string("‹");
            break;
        case SY_CENT:
            if (record->event.pressed) send_unicode_string("¢");
            break;
        case BN3_7:
            if (record->event.pressed) send_unicode_string("¥");
            break;
        case BN3_8:
            if (record->event.pressed) send_unicode_string("‚");
            break;
        case SY_HELL:
            if (record->event.pressed) send_unicode_string("…"); // horizontal ellipsis
            break;
        case SY_CIRC:
            if (record->event.pressed) send_string("^ ");
            break;
        case SY_SALT:
            if (record->event.pressed) send_unicode_string("ſ"); // german long s
            break;
        case SY_TILD:
            if (record->event.pressed) send_string("~");
            break;
        case SY_BKTK:
            if (record->event.pressed) send_string("` ");
            break;
        case DE_MINS:
            if (record->event.pressed) tap_code16(DE_MINS);
            break;
        case DE_DQUO:
            if (record->event.pressed) send_string("\"");
            break;
        case DE_QUOT:
            if (record->event.pressed) send_string("'");
            break;
        // keys of NAVP layer
        case BN4_1:
            if (record->event.pressed) send_unicode_string("ª");
            break;
        case BN4_2:
            if (record->event.pressed) send_unicode_string("º");
            break;
        case BN4_3:
            if (record->event.pressed) send_unicode_string("№");
            break;
        case BN4_5:
            if (record->event.pressed) send_unicode_string("·");
            break;
        default:
            set_mods(active_modifiers);
            return true;
    }
    set_mods(active_modifiers);
    return false;
}
