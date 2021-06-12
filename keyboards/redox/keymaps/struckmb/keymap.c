#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum layer_names {
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
    KM_BONE,
    KM_NEO2,
    // other special or replaced symbols
    SY_HELL, // horizontal ellipsis
    SY_CIRC, // caret (non dead)
    SY_SALT, // german long s (outdated)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
    SY_MINS, // no shift minus
    SY_DQUO, // double quote
    SY_QUOT, // single quote
    // number keys in symbol layer
    BN3_4,
    BN3_5,
    BN3_6,
    BN3_7,
    BN3_8,
    // number keys in navi/keypad layer
    BN4_1,
    BN4_2,
    BN4_3,
    BN4_5
};

#define SY_UNDO C(KC_Z)
#define SY_REDO RCS(KC_Z)
#define SY_REDO2 C(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
  [_QWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_CIRC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SY_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E ,MEH_T(KC_R),KC_T    ,KC_GRV  ,                          KC_QUOT ,KC_Z  ,MEH_T(KC_U),KC_I   ,KC_O    ,KC_P    ,US_UDIA ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LGUI_T(KC_ESC),KC_A,LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),LGUI_T(KC_G),KC_LCTL, KC_LALT,LGUI_T(KC_H),RSFT_T(KC_J),RCTL_T(KC_K),LALT_T(KC_L),US_ODIA,US_ADIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_BSPC),KC_Y  ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,TT(_ADJ),TT(_MFN),        TT(_MFN),TT(_ADJ),KC_N  ,KC_M ,KC_COMM ,KC_DOT ,US_SS   ,RSFT_T(KC_DEL),
  //├────────┼────────┼────────┼────────┼────────┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_LGUI,C(KC_A),C(KC_INS),S(KC_INS),TT(_NAV),LT(_SYM,KC_ENT),LALT_T(KC_SPC), RCTL_T(KC_BSPC),LT(_SYM,KC_SPC),TT(_NAV),KC_APP ,KC_PWR  ,KC_PSCR ,KC_RGUI
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Base Layer: BONE
 */
  [_BONE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_CIRC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SY_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_J    ,KC_D    ,KC_U ,MEH_T(KC_A),KC_X    ,KC_GRV  ,                          KC_QUOT ,KC_P ,MEH_T(KC_H),KC_L    ,KC_M    ,KC_W    ,US_SS   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LGUI_T(KC_ESC),KC_C,LALT_T(KC_T),LCTL_T(KC_I),LSFT_T(KC_E),LGUI_T(KC_O),KC_LCTL, KC_LALT,LGUI_T(KC_B),RSFT_T(KC_N),RCTL_T(KC_R),LALT_T(KC_S),KC_G  ,KC_Q    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_BSPC),KC_F  ,KC_V    ,US_UDIA ,US_ADIA ,US_ODIA ,TT(_ADJ),TT(_MFN),        TT(_MFN),TT(_ADJ),KC_Y    ,KC_Z  ,KC_COMM ,KC_DOT ,KC_K ,RSFT_T(KC_DEL),
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_LGUI,C(KC_A),C(KC_INS),S(KC_INS),TT(_NAV),LT(_SYM,KC_ENT),LALT_T(KC_SPC), RCTL_T(KC_BSPC),LT(_SYM,KC_SPC),TT(_NAV),KC_APP ,KC_PWR  ,KC_PSCR ,KC_RGUI
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Base Layer: Neo2
 */
  [_NEO2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_CIRC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,SY_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_X    ,KC_V    ,KC_L    ,KC_C    ,KC_W    ,KC_GRV  ,                          KC_QUOT ,KC_K ,MEH_T(KC_H),KC_G    ,KC_F    ,KC_Q    ,US_SS   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LGUI_T(KC_ESC),KC_U,LALT_T(KC_I),LCTL_T(KC_A),LSFT_T(KC_E),LGUI_T(KC_O),KC_LCTL, KC_LALT,LGUI_T(KC_S),RSFT_T(KC_N),RCTL_T(KC_R),LALT_T(KC_T),KC_D  ,KC_Y    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_BSPC),US_UDIA,US_ODIA,US_ADIA ,KC_P    ,KC_Z    ,TT(_ADJ),TT(_MFN),        TT(_MFN),TT(_ADJ),KC_B    ,KC_M  ,KC_COMM ,KC_DOT ,KC_J ,RSFT_T(KC_DEL),
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_LGUI,C(KC_A),C(KC_INS),S(KC_INS),TT(_NAV),LT(_SYM,KC_ENT),LALT_T(KC_SPC), RCTL_T(KC_BSPC),LT(_SYM,KC_SPC),TT(_NAV),KC_APP ,KC_PWR  ,KC_PSCR ,KC_RGUI
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Symbol Layer: brackets, quotes, ...
 */
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,US_SUP1 ,US_SUP2 ,US_SUP3 ,BN3_4   ,BN3_5   ,                                            BN3_6   ,BN3_7   ,BN3_8   ,US_LSQU ,US_RSQU ,SY_SALT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LEAD ,SY_HELL ,KC_UNDS ,KC_LBRC ,KC_RBRC ,SY_CIRC ,_______ ,                          _______ ,KC_EXLM ,KC_LABK ,KC_RABK ,KC_EQL  ,KC_AMPR ,US_EURO ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_BSLS ,KC_SLSH ,KC_LCBR ,KC_RCBR ,KC_ASTR ,_______ ,                          _______ ,KC_QUES ,KC_LPRN ,KC_RPRN ,KC_MINS ,KC_COLN ,KC_AT   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_PIPE ,SY_TILD ,SY_BKTK ,KC_CAPS ,_______ ,        _______ ,KC_PSCR ,KC_PLUS ,KC_PERC ,SY_DQUO ,SY_QUOT ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______,S(KC_DEL),US_DCIR ,     US_DTIL ,    KC_TRNS ,_______ ,        _______ ,KC_TRNS ,    US_DGRV ,     US_ACUT ,US_DIAE ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Navigation Layer: Arrow keys, Number pad
 */
  [_NAV] = LAYOUT( // BN4_4 originally is undefined, I inserted a ©
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,BN4_1   ,BN4_2   ,BN4_3   ,US_COPY ,BN4_5   ,                                            US_PND  ,US_CURR ,KC_TAB  ,KC_PSLS ,KC_PAST ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    A(KC_TAB),KC_PGUP ,KC_BSPC ,KC_UP   ,KC_DEL  ,KC_INS  ,_______ ,                          _______ ,US_IEXL ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PPLS ,KC_PMNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HOME ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_END  ,_______ ,                          _______ ,US_IQUE ,KC_P4   ,KC_P5   ,KC_P6   ,KC_COMM ,KC_PDOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_ESC  ,SY_UNDO ,SY_REDO ,KC_ENT  ,KC_PGDN ,KC_WHOM ,_______ ,        _______ ,_______ ,KC_COLN ,KC_P1   ,KC_P2   ,KC_P3   ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______,S(KC_DEL),SY_REDO2,     KC_TRNS ,    KC_WBAK ,KC_WFWD ,        _______ ,KC_P0   ,    KC_TRNS ,     KC_PSCR ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Media and Function key Layer: Some keys…
 */
  [_MFN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,KC_VOLU ,KC_MUTE ,XXXXXXX ,KC_F11 ,                            KC_F12 ,XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_MPRV ,KC_VOLD ,KC_MPLY ,KC_MNXT ,_______ ,                          _______ ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX,S(KC_MINS),XXXXXXX,_______ ,KC_TRNS ,        KC_TRNS ,_______ ,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F12  ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,     RALT_T(KC_ENT),_______,   _______,     KC_PWR  ,_______ ,_______ ,KC_MUTE
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Adjust Layer: Mouse, RGB
 */
  [_ADJ] = LAYOUT(
      // no hmod on lhs to enable mouse steering (key repetition)
      // on rhs hmod (for shift-click, ctrl-click, …), set tap to NO instead of TRANSPARENT
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_SAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_VAI ,KC_WH_U ,KC_WBAK ,KC_MS_U ,KC_WFWD ,XXXXXXX ,_______ ,                          _______ ,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_VAI ,RGB_SAI ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG ,KC_WH_L ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_R ,_______ ,                          _______ ,RGB_M_P ,RGB_RMOD,RGB_HUD ,RGB_VAD ,RGB_SAD ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_VAD ,KM_QWER ,KM_NEO2 ,KM_BONE ,XXXXXXX ,KC_WH_D ,KC_TRNS ,_______ ,        KC_PAUSE,KC_TRNS ,KC_ACL1 ,KC_ACL2 ,KM_BONE ,KM_NEO2 ,KM_QWER ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     RGB_SAD ,RGB_M_P ,RGB_MOD ,RGB_HUI ,     KC_BTN3 ,    KC_BTN1 ,KC_BTN2 ,        KC_ACL0 ,XXXXXXX ,    XXXXXXX ,     UC_MOD  ,_______ ,_______ ,RESET
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

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
    switch (keycode) {
        // change layout
        case KM_QWER:
            if (record->event.pressed) set_single_persistent_default_layer(_QWER);
            return false;
        case KM_BONE:
            if (record->event.pressed) set_single_persistent_default_layer(_BONE);
            return false;
        case KM_NEO2:
            if (record->event.pressed) set_single_persistent_default_layer(_NEO2);
            return false;
    }
    uint8_t active_modifiers = get_mods();
    clear_mods();
    if (active_modifiers & MOD_MASK_SHIFT) {
        switch (keycode) {
            // number row
            case KC_1:
                if (record->event.pressed) tap_code16(US_DEG);
                break;
            case KC_2:
                if (record->event.pressed) tap_code16(US_SECT);// §
                break;
            case KC_3:
                if (record->event.pressed) send_unicode_string("ℓ");
                break;
            case KC_4:
                if (record->event.pressed) tap_code16(US_RDAQ);
                break;
            case KC_5:
                if (record->event.pressed) tap_code16(US_LDAQ);
                break;
            case KC_6:
                if (record->event.pressed) tap_code16(US_DLR); // $
                break;
            case KC_7:
                if (record->event.pressed) tap_code16(US_EURO); // €
                break;
            case KC_8:
                if (record->event.pressed) send_unicode_string("„");
                break;
            case KC_9:
                if (record->event.pressed) send_unicode_string("“");
                break;
            case KC_0:
                if (record->event.pressed) send_unicode_string("”");
                break;
            case US_SUP1:
                if (record->event.pressed) send_unicode_string("₁");
                break;
            case US_SUP2:
                if (record->event.pressed) send_unicode_string("₂");
                break;
            case US_SUP3:
                if (record->event.pressed) send_unicode_string("₃");
                break;
            case BN3_4:
                if (record->event.pressed) send_unicode_string("♀");
                break;
            case BN3_5:
                if (record->event.pressed) send_unicode_string("♂");
                break;
            case BN3_6:
                if (record->event.pressed) send_unicode_string("⚥");
                break;
            case BN3_7:
                if (record->event.pressed) send_unicode_string("ϰ");
                break;
            case BN3_8:
                if (record->event.pressed) send_unicode_string("⟨");
                break;
            case US_LSQU:
                if (record->event.pressed) send_unicode_string("⟩");
                break;
            case US_RSQU:
                if (record->event.pressed) send_unicode_string("₀");
                break;
            // default layer
            case SY_MINS:
                if (record->event.pressed) send_unicode_string("—"); // em dash
                break;
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
            // case KC_LBRC:
            //     if (record->event.pressed) send_unicode_string("«");
            //     break;
            case KC_BSLS:
                if (record->event.pressed) send_unicode_string("↑");
                break;
            // case KC_RBRC:
            //     if (record->event.pressed) send_unicode_string("»");
            //     break;
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
            // case KC_LABK:
            //     if (record->event.pressed) send_unicode_string("„");
            //     break;
            // case KC_SLSH:
            //     if (record->event.pressed) send_unicode_string("“");
            //     break;
            // case KC_RABK:
            //     if (record->event.pressed) send_unicode_string("”");
            //     break;
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
        case BN3_4:
            if (record->event.pressed) send_unicode_string("›");
            break;
        case BN3_5:
            if (record->event.pressed) send_unicode_string("‹");
            break;
        case BN3_6:
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
            if (record->event.pressed) send_string("^");
            break;
        case SY_SALT:
            if (record->event.pressed) send_unicode_string("ſ"); // german long s
            break;
        case SY_TILD:
            if (record->event.pressed) send_string("~");
            break;
        case SY_BKTK:
            if (record->event.pressed) send_string("`");
            break;
        case SY_MINS:
            if (record->event.pressed) tap_code16(KC_MINS);
            break;
        case SY_DQUO:
            if (record->event.pressed) send_string("\"");
            break;
        case SY_QUOT:
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
