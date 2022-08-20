 /* Copyright HarshitGoel96 2020
  * With permission from mattdibi, the original maintainer of the Redox hardware.
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
#include "sendstring_german.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_keycodes {
  _QWERTY,
  _SYMB,
  _NAV1,
  _NAV2,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY
 *
 * ┌────────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬────────┐
 * │        │   1  │   2  │   3  │   4  │   5  ├──────┐                ┌──────┤   6  │   7  │   8  │   9  │   0  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │                │ Adj  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Tab   │   Q  │   W  │   E  │   R  │   T  ├──────┤                ├──────┤   Z  │   U  │   I  │   O  │   P  │    Ü   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  [   │                │   ]  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Esc   │   A  │   S  │   D  │   F  │   G  │      │                │      │   H  │   J  │   K  │   L  │   Ö  │    Ä   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  LSft  │   Y  │   X  │   C  │   V  │   B  │ PgUp │ PgUp │  │ Home │  End │   N  │   M  │   ,  │   .  │ ß  ? │  RSft  │
 * ├────────┼──────┼──────┼──────┼──┬───┴──┬───┼──────┼──────┤  ├──────┼──────┼───┬──┴───┬──┼──────┼──────┼──────┼────────┤
 * │ L-GUI  │   +  │   -  │ Symb │  │  Nav │   │ BSpc │ Del  │  │ Ent  │ Space│   │ AltGr│  │ Left │ Down │  Up  │  Right │
 * └────────┴──────┴──────┴──────┘  └──────┘   └──────┴──────┘  └──────┴──────┘   └──────┘  └──────┴──────┴──────┴────────┘
 */
  [_QWERTY] = LAYOUT(
   MO(_NAV2), DE_1   , DE_2   , DE_3   , DE_4   , DE_5   ,                                        DE_6   , DE_7   , DE_8   , DE_9   , DE_0   , DE_SS,
     KC_TAB , DE_Q   , DE_W   , DE_E   , DE_R   , DE_T   , XXXXXXX,                  MO(_ADJUST), DE_Z   , DE_U   , DE_I   , DE_O   , DE_P   , KC_EQL ,
     KC_ESC , DE_A   , DE_S   , DE_D   , DE_F   , DE_G   , DE_LBRC,                      DE_RBRC, DE_H   , DE_J   , DE_K   , DE_L   , DE_SCLN, DE_QUOT,
     KC_LSFT, DE_Y   , DE_X   , DE_C   , DE_V   , DE_B   , KC_PGUP, KC_PGDN,    KC_HOME, KC_END , DE_N   , DE_M   , DE_COMM, DE_DOT , DE_SLSH, KC_RSFT,
     KC_LGUI, KC_LCTL, KC_LALT, MO(_SYMB),    MO(_NAV1),   KC_BSPC, KC_DEL,     KC_ENT , KC_SPC ,     KC_RALT ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),

  [_SYMB] = LAYOUT(
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                       KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX,
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,KC_F11  ,                     KC_F12  ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX,
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,_______ ,                     _______ ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX,
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______,    _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX,
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______,    _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX
  ),

  [_NAV1] = LAYOUT(
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                       _______ ,_______ ,_______ ,_______ ,_______ ,_______,
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                     _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,   _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,   _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ),

  [_NAV2] = LAYOUT(
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                       _______ ,_______ ,_______ ,_______ ,_______ ,_______,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,   XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,   XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ),

  [_ADJUST] = LAYOUT(
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                       KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX,
     XXXXXXX ,QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,   XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,   XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  )

};
