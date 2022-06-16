
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
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum layers {
    // - Base layers:
    _QWER,
    _BONE,
    _NEO2,
    // additional layers
    _SYM, // symbols (neo based)
    _NAV, // navigation and key pad
    _MFN, // media and function keys
    _ADJ  // mouse and kb adjustment
};

enum custom_keycodes {
    KM_QWER = SAFE_RANGE,
    KM_NEO2,
    KM_BONE,
    // other special or replaced symbols
    SY_HELL, // horizontal ellipsis
    SY_CIRC, // caret (non dead)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
    SY_DQUO, // double quote
    SY_QUOT, // single quote
};

#define SY_UNDO C(KC_Z)
#define SY_REDO RCS(KC_Z)
#define SY_REDO2 C(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
  [_QWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q    ,KC_W    ,KC_E    ,MEH_T(KC_R),KC_T ,                 KC_Z    ,MEH_T(KC_U),KC_I ,KC_O    ,KC_P    ,//US_UDIA ,
  //├────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┤
KC_A,LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),LGUI_T(KC_G),  LGUI_T(KC_H),RSFT_T(KC_J),RCTL_T(KC_K),LALT_T(KC_L),US_ODIA,//US_ADIA,
  //├────────┼────────┼────────┼────────┼────────┤                ├────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_Y) ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                 KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,US_SS,//RSFT_T(KC_DEL),
  //└────────┴────────┴────────┴────────┴────────┘                └────────┴────────┴────────┴────────┴────────┘
                                        C(KC_INS),                S(KC_INS), // encoders = copy / paste
  //                  ┌────────┬────────┬────────┐                ┌────────┬────────┬────────┐
                TT(_NAV),LT(_SYM,KC_ENT),LT(_MFN,KC_SPC),  LT(_ADJ,KC_BSPC),LT(_SYM,KC_SPC),TT(_NAV)
  //                  └────────┴────────┴────────┘                └────────┴────────┴────────┘
    ),

/*
 * Base Layer: BONE
 */
  [_BONE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┐
     KC_J    ,KC_D    ,KC_U   ,MEH_T(KC_A), KC_X ,                KC_P  ,MEH_T(KC_H), KC_L  ,KC_M    ,KC_W    ,//US_SS   ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
KC_C,LALT_T(KC_T),LCTL_T(KC_I),LSFT_T(KC_E),LGUI_T(KC_O),  LGUI_T(KC_B),RSFT_T(KC_N),RCTL_T(KC_R),LALT_T(KC_S),KC_G,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_F) ,KC_V    ,KC_Q    ,US_ADIA ,US_ODIA ,                KC_Y    ,KC_Z    ,KC_COMM ,KC_DOT  ,RSFT_T(KC_K),
  //└────────┴────────┴────────┴────────┴────────┘               └────────┴────────┴────────┴────────┴────────┘
                                        C(KC_INS),               S(KC_INS), // encoders = copy / paste
  //                  ┌────────┬────────┬────────┐               ┌────────┬────────┬────────┐
                TT(_NAV),LT(_SYM,KC_ENT),LT(_MFN,KC_SPC),  LT(_MFN,KC_BSPC),LT(_SYM,KC_SPC),TT(_NAV)
  //                  └────────┴────────┴────────┘               └────────┴────────┴────────┘
    ),

/*
 * Base Layer: Neo2
 */
  [_NEO2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┐
     KC_X    ,KC_V    ,KC_L   ,MEH_T(KC_C), KC_W ,                KC_K  ,MEH_T(KC_H), KC_G  ,KC_F    ,KC_Q    ,US_SS   ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
KC_U,LALT_T(KC_I),LCTL_T(KC_A),LSFT_T(KC_E),LGUI_T(KC_O),  LGUI_T(KC_S),RSFT_T(KC_N),RCTL_T(KC_R),LALT_T(KC_T),KC_D,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_Y) ,US_ODIA ,US_ADIA ,KC_P    ,KC_Z    ,                KC_B    ,KC_M    ,KC_COMM ,KC_DOT  ,RSFT_T(KC_J),
  //└────────┴────────┴────────┴────────┴────────┘               └────────┴────────┴────────┴────────┴────────┘
                                        C(KC_INS),               S(KC_INS), // encoders = copy / paste
  //                  ┌────────┬────────┬────────┐               ┌────────┬────────┬────────┐
                TT(_NAV),LT(_SYM,KC_ENT),LT(_MFN,KC_SPC),  LT(_ADJ,KC_BSPC),LT(_SYM,KC_SPC),TT(_NAV)
  //                  └────────┴────────┴────────┘               └────────┴────────┴────────┘
    ),

/*
 * Symbol Layer: brackets, quotes, ...
 */
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┐
     KC_AT   ,KC_UNDS ,KC_LBRC ,KC_RBRC ,SY_CIRC ,                KC_EXLM ,KC_LABK ,KC_RABK ,KC_EQL  ,KC_AMPR ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     KC_BSLS ,KC_SLSH ,KC_LCBR ,KC_RCBR ,KC_ASTR ,                KC_QUES ,KC_LPRN ,KC_RPRN ,KC_MINS ,KC_COLN ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     KC_HASH ,KC_DLR  ,KC_PIPE ,SY_TILD ,SY_BKTK ,                KC_PLUS ,KC_PERC ,SY_DQUO ,SY_QUOT ,KC_SCLN ,
  //└────────┴────────┴────────┴────────┴────────┘               └────────┴────────┴────────┴────────┴────────┘
                                        C(KC_INS),               S(KC_INS), // encoders = copy / paste
  //                  ┌────────┬────────┬────────┐               ┌────────┬────────┬────────┐
                       _______ ,KC_TRNS ,_______ ,                _______ ,KC_TRNS ,_______
  //                  └────────┴────────┴────────┘               └────────┴────────┴────────┘
    ),

/*
 * Navigation Layer: Arrow keys, Number pad
 */
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┐
     KC_PGUP ,KC_BSPC ,KC_UP   ,KC_DEL  ,KC_INS  ,                US_IEXL ,KC_7    ,KC_8    ,KC_9    ,KC_PPLS ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     KC_HOME ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_END  ,                KC_PDOT ,KC_4    ,KC_5    ,KC_6    ,KC_COMM ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,SY_UNDO ,SY_REDO ,KC_ENT  ,KC_PGDN ,                KC_COLN ,KC_1    ,KC_2    ,KC_3    ,KC_PDOT ,
  //└────────┴────────┴────────┴────────┴────────┘               └────────┴────────┴────────┴────────┴────────┘
                                         XXXXXXX ,                XXXXXXX , // encoders
  //                  ┌────────┬────────┬────────┐               ┌────────┬────────┬────────┐
                       KC_TRNS ,_______ ,_______ ,                _______ ,_______ ,KC_TRNS
  //                  └────────┴────────┴────────┘               └────────┴────────┴────────┘
    ),

/*
 * Media and Function key Layer: Some keys…
 */
  [_MFN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,KC_VOLU ,KC_MUTE ,XXXXXXX ,                XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MPRV ,KC_VOLD ,KC_MPLY ,KC_MNXT ,                XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX,S(KC_MINS),XXXXXXX,                XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F12  ,
  //└────────┴────────┴────────┴────────┴────────┘               └────────┴────────┴────────┴────────┴────────┘
                                         XXXXXXX ,                XXXXXXX , // encoders
  //                  ┌────────┬────────┬────────┐               ┌────────┬────────┬────────┐
                       _______ ,TT(_ADJ),KC_TRNS ,                KC_TRNS ,TT(_ADJ),_______
  //                  └────────┴────────┴────────┘               └────────┴────────┴────────┘
    ),

/*
 * Adjust Layer: Mouse, RGB
 */
    [_ADJ] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐               ┌────────┬────────┬────────┬────────┬────────┐
     KC_WH_U ,KC_WBAK ,KC_MS_U ,KC_WFWD ,XXXXXXX ,                RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_VAI ,RGB_SAI ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     KC_WH_L ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_R ,                RGB_M_P ,RGB_RMOD,RGB_HUD ,RGB_VAD ,RGB_SAD ,
  //├────────┼────────┼────────┼────────┼────────┤               ├────────┼────────┼────────┼────────┼────────┤
     KM_QWER ,KM_NEO2 ,KM_BONE ,XXXXXXX ,KC_WH_D ,                KC_ACL1 ,KC_ACL2 ,KM_BONE ,KM_NEO2 ,KM_QWER ,
  //└────────┴────────┴────────┴────────┴────────┘               └────────┴────────┴────────┴────────┴────────┘
                                         XXXXXXX ,                XXXXXXX , // encoders
  //                  ┌────────┬────────┬────────┐               ┌────────┬────────┬────────┐
                       _______ ,KC_TRNS ,KC_TRNS ,                KC_TRNS ,KC_TRNS ,_______
  //                  └────────┴────────┴────────┘               └────────┴────────┴────────┘
    ),

};

#ifdef LEADER_ENABLE
// leader key definitions
LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_TWO_KEYS(KC_C, KC_O) {
        tap_code16(US_COPY);
    }
    SEQ_TWO_KEYS(KC_O, KC_C) {
        tap_code16(US_COPY);
    }
    SEQ_TWO_KEYS(KC_O, KC_R) {
        tap_code16(US_REGD);
    }
    SEQ_TWO_KEYS(KC_R, KC_O) {
        tap_code16(US_REGD);
    }
  }
}
#endif

#ifdef RGBLIGHT_LAYERS
// Light LEDs 6 to 8 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED},       // Light 3 LEDs, starting with first LED
    {17, 3, HSV_RED}       // Light 3 LEDs, starting with first LED
);
const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 4, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_mfn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 4, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_adj_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 4, HSV_GREEN}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer, // Overrides caps lock layer
    // Overrides other layers
    my_nav_layer,
    my_mfn_layer,
    my_adj_layer
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
    switch (keycode) {
        // change default layout
        case KM_QWER:
            if (record->event.pressed)
                set_single_persistent_default_layer(_QWER);
            return false;
        case KM_BONE:
            if (record->event.pressed)
                set_single_persistent_default_layer(_BONE);
            return false;
        case KM_NEO2:
            if (record->event.pressed)
                set_single_persistent_default_layer(_NEO2);
            return false;
    }
    uint8_t active_modifiers = get_mods();
    clear_mods();
    if (active_modifiers & MOD_MASK_SHIFT) {
        switch (keycode) {
            // default layer
            // case SY_MINS:
            //     if (record->event.pressed) send_unicode_string("—"); // em dash
            //     break;
            case KC_COMM:
                if (record->event.pressed) send_unicode_string("–"); // en dash
                break;
            case KC_DOT:
                if (record->event.pressed) send_unicode_string("•");
                break;
            case US_SS:
                if (record->event.pressed) send_unicode_string("ẞ"); // capital german sharp s
                break;
            // symbol layer
            // left hand
            case KC_HASH:
                if (record->event.pressed) send_unicode_string("⇑");
                break;
            case KC_LBRC:
                if (record->event.pressed) send_unicode_string("«");
                break;
            case KC_BSLS:
                if (record->event.pressed) send_unicode_string("↑");
                break;
            case KC_RBRC:
                if (record->event.pressed) send_unicode_string("»");
                break;
            case SY_CIRC:
                if (record->event.pressed) send_unicode_string("⇐");
                break;
            case KC_LCBR:
                if (record->event.pressed) send_unicode_string("←");
                break;
            case SY_TILD:
                if (record->event.pressed) send_unicode_string("↓");
                break;
            case KC_RCBR:
                if (record->event.pressed) send_unicode_string("→");
                break;
            case KC_DLR:
                if (record->event.pressed) send_unicode_string("⇒");
                break;
            case US_EURO:
                if (record->event.pressed) send_unicode_string("¢");
                break;
            case SY_BKTK:
                if (record->event.pressed) send_unicode_string("‹");
                break;
            case KC_PIPE:
                if (record->event.pressed) send_unicode_string("⇔");
                break;
            case KC_QUES:
                if (record->event.pressed) send_unicode_string("›");
                break;
            case KC_ASTR:
                if (record->event.pressed) send_unicode_string("⇓");
                break;
            // right hand
            case KC_LABK:
                if (record->event.pressed) send_unicode_string("„");
                break;
            case KC_SLSH:
                if (record->event.pressed) send_unicode_string("“");
                break;
            case KC_RABK:
                if (record->event.pressed) send_unicode_string("”");
                break;
            case KC_MINS:
                if (record->event.pressed) send_unicode_string("—"); // em dash
                break;
            case KC_RPRN:
                if (record->event.pressed) send_unicode_string("λ");
                break;
            case KC_EXLM:
                if (record->event.pressed) send_unicode_string("‚");
                break;
            case SY_DQUO:
                if (record->event.pressed) send_unicode_string("‘");
                break;
            case SY_QUOT:
                if (record->event.pressed) send_unicode_string("’");
                break;
            default:
                set_mods(active_modifiers);
                return true;
        }
    }
    // unshifted
    else switch (keycode) {
        case SY_HELL:
            if (record->event.pressed) send_unicode_string("…");
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
        case SY_DQUO:
            if (record->event.pressed) {
                tap_code16(S(KC_QUOT));
                tap_code(KC_SPC);
            }
            break;
        case SY_QUOT:
            if (record->event.pressed) {
                tap_code(KC_QUOT);
                tap_code(KC_SPC);
            }
            break;
        default:
            set_mods(active_modifiers);
            return true;
    }
    set_mods(active_modifiers);
    return false;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t active_modifiers = get_mods();
    clear_mods();
    switch (get_highest_layer(layer_state)) {
        case _SYM:
            // mouse scrolling
            tap_code16(clockwise ? KC_WH_D : KC_WH_U);
            break;
        case _NAV:
            // (browser) tabbing
            tap_code(clockwise ? C(KC_TAB) : S(C(KC_TAB)));
            break;
        case _MFN:
            // audio control
            tap_code16(clockwise ? KC_VOLU : KC_VOLD);
            break;
        default:
            if (active_modifiers & MOD_MASK_SHIFT) {
                // Line/Page up/down
                if (active_modifiers & MOD_MASK_CTRL) {
                    tap_code(clockwise ? KC_PGDN : KC_PGUP);
                } else {
                    tap_code(clockwise ? KC_DOWN : KC_UP);
                }
            } else {
                // Char/Word left/right
                if (active_modifiers & MOD_MASK_CTRL) {
                    tap_code16(C(clockwise ? KC_RIGHT : KC_LEFT));
                } else {
                    tap_code(clockwise ? KC_RIGHT : KC_LEFT);
                }
            }
    }
    set_mods(active_modifiers);
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}
static void render_logo(void) {
    // 'Kyria_OLED_mini_display', 128x32px
    static const char PROGMEM logo[] = {
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
    oled_write_raw_P(logo, sizeof(logo));
    // oled_render();
}
void oled_task_user(void) {
    // oled_clear();
    if (is_keyboard_master()) {
    // QMK Logo and version information
        static const char PROGMEM logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
        };
        oled_write_P(logo, false);
        // Host Keyboard Layout and Layer Status
        oled_write_P(PSTR("\nLayout: "), false);
        switch (biton32(default_layer_state)) {
        case _BONE:
            oled_write_P(PSTR("Bone"), false);
            break;
        case _NEO2:
            oled_write_P(PSTR("Neo2"), false);
            break;
        default:
            oled_write_P(PSTR("QWERTZ"), false);
        };
        oled_write_P(PSTR("\nLayer : "), false);
        switch (get_highest_layer(layer_state)) {
            case _SYM:
                oled_write_P(PSTR("Symbols"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Navigation"), false);
                break;
            case _MFN:
                oled_write_P(PSTR("Function"), false);
                break;
            case _ADJ:
                oled_write_P(PSTR("Adjust"), false);
                break;
            default:
                oled_write_P(PSTR("Default"), false);
        }
        // Host Keyboard LED Status
        uint8_t led_usb_state = host_keyboard_leds();
        oled_write_P(PSTR("\nLocks : "), false);
        oled_write_P(PSTR("NUM"), IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK));
        oled_write_P(PSTR("  "), false);
        oled_write_P(PSTR("CAPS"), IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK));
    } else {
        render_logo();
        oled_set_cursor(4,5);
        oled_write_P(PSTR("Kyria rev1.0"), false);
    }
}
#endif
