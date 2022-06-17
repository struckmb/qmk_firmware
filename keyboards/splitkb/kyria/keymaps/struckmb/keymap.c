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
 */
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

enum layers {
    _QWERTZ = 0,
    _DVORAK,
    _COLEMAK,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

enum custom_keycodes {
    //KM_QWER = SAFE_RANGE,
    //KM_COLEMAK,
    //KM_DVORAK,
    // other special or replaced symbols
    SY_HELL = SAFE_RANGE, // horizontal ellipsis
    SY_CIRC, // caret (non dead)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
};

// Aliases for readability
#define QWER   DF(_QWERTZ)
#define COLEMAK   DF(_COLEMAK)
#define DVORAK   DF(_DVORAK)

#define NAV      MO(_NAV)
#define SYM      MO(_SYM)
#define MFN      MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define SYM_ENT  LT(_SYM, KC_ENT)
#define MFN_SPC  LT(_FUNCTION, KC_SPC)
#define ADJ_ENT  LT(_ADJUST, KC_ENT)
#define SYM_SPC  LT(_SYM, KC_SPC)

#define SY_CUT   S(KC_DEL)
#define SY_COPY  C(KC_INS)
#define SY_PASTE S(KC_INS)
#define SY_UNDO  C(DE_Z)
#define SY_REDO  RCS(DE_Z)
#define SY_REDO2 C(DE_Y)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define SFT_BSP  MT(MOD_LSFT, KC_BSPC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define QE_GUI   LGUI_T(DE_E)
//#define QR_MEH   MEH(DE_R)
//#define QU_MEH   MEH(DE_U)
#define QI_GUI   LGUI_T(DE_I)
#define QS_ALT   LALT_T(DE_S)
#define QD_CTL   LCTL_T(DE_D)
#define QF_SFT   LSFT_T(DE_F)
#define QJ_SFT   LSFT_T(DE_J)
#define QK_CTL   LCTL_T(DE_K)
#define QL_ALT   LALT_T(DE_L)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |    Ü   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |    Ä   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTZ] = LAYOUT(
     KC_TAB  , DE_Q ,  DE_W   , QE_GUI ,   DE_R ,  DE_T ,                                        DE_Z,   DE_U , QI_GUI ,   DE_O ,   DE_P , DE_UDIA,
     CTL_ESC , DE_A , QS_ALT  , QD_CTL , QF_SFT ,  DE_G ,                                        DE_H, QJ_SFT , QK_CTL , QL_ALT , DE_ODIA, DE_ADIA,
     SFT_BSP , DE_Y ,  DE_X   ,  DE_C  ,   DE_V ,  DE_B , DE_LBRC, KC_CAPS,     MFN    , DE_RBRC, DE_N,   DE_M , DE_COMM, DE_DOT ,  DE_SS , KC_RSFT,
                                SY_CUT ,SY_PASTE,  NAV  , SYM_ENT, MFN_SPC,     ADJ_ENT, SYM_SPC, NAV, KC_PSCR, KC_APP//ENC
    ),

/*
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   | ' "  | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |Ctrl/- _|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | ; :  |   Q  |   J  |   K  |   X  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DVORAK] = LAYOUT(
     KC_TAB  ,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,                                        KC_F,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_BSPC,
     CTL_ESC , KC_A ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I ,                                        KC_D,   KC_H ,  KC_T ,   KC_N ,  KC_S , CTL_MINS,
     SFT_BSP ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X ,DE_LBRC, KC_CAPS,     MFN    , DE_RBRC, KC_B,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
                                SY_CUT ,SY_PASTE,  NAV  , SYM_ENT, MFN_SPC,     ADJ_ENT, SYM_SPC, NAV, KC_PSCR, KC_APP//ENC
    ),

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
     CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
     SFT_BSP , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , DE_LBRC, KC_CAPS,     MFN    , DE_RBRC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                SY_CUT ,SY_PASTE,  NAV  , SYM_ENT, MFN_SPC,     ADJ_ENT, SYM_SPC, NAV, KC_PSCR, KC_APP//ENC
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
            _______, KC_PGUP, KC_BSPC, KC_UP  , KC_DEL , KC_INS ,                                            XXXXXXX, DE_7   , DE_8   , DE_9   , KC_PPLS, KC_PMNS,
            _______, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT, KC_END ,                                            XXXXXXX, DE_4   , DE_5   , DE_6   , DE_COMM, KC_PDOT,
            _______, KC_ESC , SY_UNDO, SY_REDO, KC_ENT , KC_PGDN, KC_WHOM, KC_SLCK,        _______, _______, DE_COLN, DE_1   , DE_2   , DE_3   , DE_SCLN, _______,
                               SY_CUT,SY_REDO2,     KC_TRNS ,     KC_WBAK, KC_WFWD,        _______, DE_0   ,     KC_TRNS,      KC_PSCR, C(DE_W)
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     KC_LEAD ,SY_HELL ,DE_UNDS ,DE_LBRC ,DE_RBRC ,SY_CIRC ,                                            DE_EXLM ,DE_LABK ,DE_RABK ,DE_EQL  ,DE_AMPR ,DE_EURO ,
     _______ ,DE_BSLS ,DE_SLSH ,DE_LCBR ,DE_RCBR ,DE_ASTR ,                                            DE_QUES ,DE_LPRN ,DE_RPRN ,DE_MINS ,DE_COLN ,DE_AT   ,
     _______ ,DE_HASH ,DE_DLR  ,DE_PIPE ,SY_TILD ,SY_BKTK ,_______ ,_______ ,        _______ ,_______ ,DE_PLUS ,DE_PERC ,DE_DQUO ,DE_QUOT ,DE_SCLN ,_______ ,
                      S(KC_DEL),DE_CIRC ,     DE_TILD ,    KC_TRNS ,_______ ,        _______ ,KC_TRNS ,    DE_GRV  ,     DE_ACUT ,_______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
     _______ ,XXXXXXX ,XXXXXXX ,KC_VOLU ,KC_MUTE ,XXXXXXX ,                                            XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
     _______ ,XXXXXXX ,KC_MPRV ,KC_VOLD ,KC_MPLY ,KC_MNXT ,                                            XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX,S(DE_MINS),XXXXXXX,_______ ,KC_TRNS ,        KC_TRNS ,_______ ,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F12  ,_______ ,
                       _______ ,_______ ,     _______ ,    _______ ,KC_TRNS ,        KC_TRNS ,_______ ,    _______ ,     KC_PWR  ,KC_MUTE
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
     RGB_VAI ,KC_WH_U ,KC_WBAK ,KC_MS_U ,KC_WFWD ,RGB_HUI ,                                            RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_VAI ,RGB_SAI ,XXXXXXX ,
     RGB_TOG ,KC_WH_L ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_R ,                                            RGB_M_P ,RGB_RMOD,RGB_HUD ,RGB_VAD ,RGB_SAD ,XXXXXXX ,
     RGB_VAD ,   QWER ,DVORAK ,COLEMAK ,XXXXXXX ,KC_WH_D ,KC_TRNS ,_______ ,        KC_PAUSE,KC_TRNS ,KC_ACL1 ,KC_ACL2 ,COLEMAK ,DVORAK ,QWER ,_______ ,
                       RGB_M_P ,RGB_MOD ,     KC_BTN3 ,    KC_BTN1 ,KC_BTN2 ,        KC_TRNS ,KC_ACL0 ,    XXXXXXX ,     UC_MOD  ,KC_BTN1
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// Send custom strings or change default base layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t active_modifiers = get_mods();
    clear_mods();
    if (active_modifiers & MOD_MASK_SHIFT) {
        switch (keycode) {
//            // default layer
//            // case SY_MINS:
//            //     if (record->event.pressed) send_unicode_string("—"); // em dash
//            //     break;
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
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTZ:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _COLEMAK:
                oled_write_P(PSTR("Colemak\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav/Num\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Mouse/Fn\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
