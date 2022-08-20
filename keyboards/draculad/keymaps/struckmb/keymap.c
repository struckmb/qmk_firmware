/*
Copyright 2021 @mangoiv

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "sendstring_german.h"

enum layer_number {
  _0,
  _1,
  _2,
  _3,
  _4,
  _5
};

enum custom_keycodes {
  BALL_HUI = SAFE_RANGE, //cycles hue
  BALL_WHT,              //cycles white
  BALL_DEC,              //decreased color
  BALL_SCR,              //scrolls
  BALL_NCL,              //left click
  BALL_RCL,              //right click
  BALL_MCL,              //middle click
};

// osm keys:
#define OS_CTL   OSM(MOD_LCTL)
#define OS_ALT   OSM(MOD_LALT)
#define OS_GUI   OSM(MOD_LGUI)
#define OS_SCTL  OSM(MOD_LSFT | MOD_LCTL)
#define OS_SALT  OSM(MOD_LSFT | MOD_LALT)
#define OS_SGUI  OSM(MOD_LSFT | MOD_LGUI)
#define OS_CTAL  OSM(MOD_LALT | MOD_LCTL)
#define OS_MEH   OSM(MOD_LCTL | MOD_LSFT | MOD_LALT)
#define OS_HYPR  OSM(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI)

// special / multi purpose keys
#define SFT_Z   LSFT_T(DE_Z)
#define SFT_SS  RSFT_T(DE_SS)
#define LY1_SPC LT(_1,KC_SPC)
//#define SPC_LY2 LT(_2,KC_SPC)
//#define ENT_LY1 LT(_1,KC_ENT)
#define LY2_ENT LT(_2,KC_ENT)
#define FN_MO13 MO(_1)
#define FN_MO23 MO(_2)
#define LAYER_3 MO(_3)
#define DE_OE_4 LT(_4,DE_ODIA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0] =  LAYOUT(
        DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                 DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,
        DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                 DE_H,    DE_J,    DE_K,    DE_L,    DE_OE_4,
        SFT_Z,   DE_Y,    DE_C,    DE_V,    DE_B,                 DE_N,    DE_M,    DE_COMM, DE_DOT,  SFT_SS,
                                            KC_LGUI,              TG(_5),
                              FN_MO13, LY2_ENT, KC_LCTL,      KC_NO, LY1_SPC, FN_MO23
    ),
    [_1] = LAYOUT( // SYM/NUM
        DE_EURO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,              KC_RALT, DE_7,    DE_8,    DE_9,    DE_0,
        DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,              DE_MINS, DE_4,    DE_5,    DE_6,    DE_PLUS,
        DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,               DE_0,    DE_1,    DE_2,    DE_3,    DE_DOT,
                                            _______,              _______,
                              LAYER_3, KC_BSPC, KC_LALT,      KC_NO, DE_COMM, LAYER_3
    ),
    [_2] = LAYOUT( // MOV/SYM
        KC_ESC,  KC_BSPC, KC_UP,   KC_DEL,  KC_PGUP,              DE_PLUS, DE_LABK, DE_RABK, KC_EQL,  DE_AMPR,
        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,               DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,
        KC_LSFT, KC_LALT, KC_LCTL, KC_TAB,  KC_LGUI,              DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN,
                                            _______,              _______,
                              LAYER_3, _______, KC_LGUI,      KC_NO, KC_MENU, LAYER_3
    ),
    [_3] = LAYOUT( // FUN
        KC_INS,  OS_SALT, OS_SCTL, OS_SGUI, OS_MEH,                KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_MENU, OS_ALT,  OS_CTL,  OS_GUI,  OS_CTAL,               KC_LCTL, KC_F4,   KC_F5,   KC_F6,   KC_F11,
        KC_CAPS, KC_SCRL, KC_PAUS, KC_PSCR, OS_HYPR,               KC_LALT, KC_F1,   KC_F2,   KC_F3,   KC_F12,
                                            _______,              _______,
                                KC_NO, _______, _______,      KC_NO, KC_LGUI, KC_NO
    ),
    [_4] = LAYOUT( // MOUSE
        KC_PWR,  KC_WH_L, XXXXXXX, KC_WH_R, KC_WH_U,               KC_VOLU, DE_UDIA, KC_MUTE, DE_ODIA, KC_EJCT,
        DE_ADIA, XXXXXXX, XXXXXXX, XXXXXXX, DE_AT,                 KC_RGUI, KC_RSFT, KC_RCTL, KC_RALT, KC_NO,
        KC_LSFT, KC_MPRV, KC_MPLY, KC_MNXT, KC_WH_D,               KC_VOLD, KC_BTN3, KC_BTN4, KC_BTN5, KC_RALT,
                                            _______,              _______,
                              KC_BTN2, KC_BTN1, KC_RALT,      KC_NO,  S(KC_INS), C(KC_INS)
    ),
    [_5] = LAYOUT( // ADJ
        RESET,   KC_BTN4, KC_BTN5, XXXXXXX, XXXXXXX,              BALL_HUI, BALL_WHT, BALL_DEC, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, BALL_SCR,             RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD, _______,
                                            XXXXXXX,              KC_NO,
                              KC_BTN2, KC_BTN1, KC_RALT,      KC_NO,  S(KC_INS), C(KC_INS)
    )
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {

 if (is_keyboard_master()) {
    if(is_keyboard_left()){
      return OLED_ROTATION_270;
      }
      else {
        return OLED_ROTATION_90;
      }
    } else {
	    return OLED_ROTATION_0;
    }
}
static void render_logo(void) {
   static const char PROGMEM drac_logo[] = {
      // 'oledlogo', 128x64px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x1c, 0x1c, 0x1c, 0x3c, 0xfc, 0xec, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8,
      0x98, 0x1c, 0x1c, 0x0c, 0x0c, 0x0c, 0x1c, 0x1c, 0x9c, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
      0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x1c, 0x1c, 0x9c, 0x9c, 0x1c, 0x1c, 0x1c, 0x1c, 0x9c, 0x8c, 0x8c, 0x0f, 0x07, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
      0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x73, 0x71, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x20, 0x18, 0x1e, 0x0f, 0x07,
      0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03,
      0x03, 0x07, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x3e, 0x7f, 0xe3, 0xc1, 0x80, 0x80, 0x80, 0x80, 0x81, 0xc1, 0xe3, 0x7f, 0x3e, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc,
      0x8e, 0x0e, 0x0e, 0x0c, 0x1c, 0x38, 0x70, 0xe0, 0xc0, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf8, 0xfc, 0xfc, 0xfe, 0xe1, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0xc0, 0xf0, 0x30, 0x31, 0x31, 0xf1, 0xf1, 0x31, 0x31, 0x31, 0x70, 0xfc, 0x9c, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0xcc, 0xfc, 0x3c, 0x1c, 0x1c, 0x0c, 0x0c,
      0x0c, 0x0c, 0x1c, 0x3c, 0xfc, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
      0x01, 0x18, 0x18, 0x38, 0x30, 0x30, 0x70, 0xe0, 0xe1, 0xe1, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x30, 0xf0, 0xf0, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x04,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x87, 0x9f, 0x18, 0x18, 0x00, 0x01, 0x0f, 0x1c, 0x30, 0x30, 0x38, 0x1f, 0x0f, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x0e, 0x1c, 0x18, 0x18, 0x18,
      0x18, 0x18, 0x1c, 0x0e, 0xcf, 0xc3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x06, 0x06, 0x06, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x87, 0xc7, 0xff, 0xff, 0xff, 0x7f, 0x47, 0x03, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x3f, 0x3f, 0x1f, 0x0f, 0x03,
      0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x1b, 0x1f, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xff, 0x83, 0x83, 0x03, 0x1f, 0xff,
      0xc3, 0x03, 0x03, 0x87, 0xff, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x3f, 0xff, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0x1c, 0x0e, 0x06,
      0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x06, 0x0e, 0x1c, 0xf8, 0xf0, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
      0x01, 0x03, 0x03, 0x03, 0xf9, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x30, 0x30, 0x30,
      0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3f, 0x3f, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
      0x30, 0x30, 0x30, 0x30, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
   };
  oled_write_raw_P(drac_logo, sizeof(drac_logo));
}

static void render_status(void) {
    oled_write_P(PSTR("This is\n~~~~~~~~~\nDracu\nLad\n~~~~~~~~~\nv2.0 ;)\n~~~~~~~~~\n"), false);
    uint8_t n = get_current_wpm();
    char    wpm_counter[4];
    wpm_counter[3] = '\0';
    wpm_counter[2] = '0' + n % 10;
    wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
    wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
    oled_write_P(PSTR("WPM:"), false);
    oled_write(wpm_counter, false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("\nCaps: "), false);
    oled_write_P(led_state.caps_lock ? PSTR("on ") : PSTR("off"), false);
    oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _0:
            oled_write_P(PSTR("Base   "), false);
            break;
        case _1:
            oled_write_P(PSTR("Numbers"), false);
            break;
        case _2:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case _5:
            oled_write_P(PSTR("Adjust "), false);
            break;
        case _4:
            oled_write_P(PSTR("Mouse  "), false);
            break;
        default:
            oled_write_P(PSTR("Unkn "), false);
            break;
    }
}

bool oled_task_user(void) {
      if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
    return false;
}

#endif //OLED_ENABLE

uint8_t white = 0;
uint8_t red = 255;
uint8_t green = 0;
uint8_t blue = 0;

bool set_scrolling = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = mouse_report.y = 0; 
    }
    return mouse_report;
}

void ball_increase_hue(void){
      if(red!=255&&green!=255&&blue!=255){
        red =255;
      }
      if (red==255&&green<255&&blue==0){
       green += 15;
      } else if(green==255&&blue==0&&red>0){
        red-=15;
      } else if(red==0&&blue<255&&green==255){
        blue+=15;
      } else if(blue==255&&green>0&&red==0){
        green -= 15;
      } else if(green == 0&&blue==255&&red<255){
        red +=15;
      } else if(green ==0&&blue>0&&red==255){
        blue -=15;
      }
      pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void decrease_color(void){
  if (green>0){
    green-=15;
  }
  if (red>0){
    red-=15;
  }
  if (blue>0){
    blue-=15;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void cycle_white(void){
  if (white<255){
    white +=15;
  } else{
    white=0;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
  switch (keycode){
  case  BALL_HUI:
    if(record->event.pressed){
      ball_increase_hue();
    }
    break;

  case BALL_WHT:
    if(record-> event.pressed){
      cycle_white();
    }
    break;

  case BALL_DEC:
   if(record-> event.pressed){
      decrease_color();
    }
    break;

  case BALL_SCR:
   if(record->event.pressed){
     set_scrolling = true;
   } else{
     set_scrolling = false;
   }
   break;

  case BALL_NCL:
     record->event.pressed?register_code(KC_BTN1):unregister_code(KC_BTN1);
     break;
  case BALL_RCL:
      record->event.pressed?register_code(KC_BTN2):unregister_code(KC_BTN2);
      break;
  case BALL_MCL:
      record->event.pressed?register_code(KC_BTN3):unregister_code(KC_BTN3);
      break;
  }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 2) {
      switch (get_highest_layer(layer_state)) {
        case _5:
            clockwise?ball_increase_hue():cycle_white();
            break;
        case _4:
            clockwise?tap_code(KC_WH_U):tap_code(KC_WH_D);
            break;
        default:
            clockwise?tap_code(KC_PGUP):tap_code(KC_PGDN);
            break;
      }
    }
    // I only have 2 encoders on the the pimoroni example board, just add else ifs for your other encoders...
    // the missing ones are encoder 1 on the right side and encoder 3 on the left side
    return true;
}
#endif // ENCODER_ENABLE
