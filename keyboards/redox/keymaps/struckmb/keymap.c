#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

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
    SY_SALT, // oldstlye german long s
    SY_HELL, // horizontal ellipsis
    SY_CIRC, // caret (non dead)
    SY_TILD, // tilde (non dead)
    SY_BKTK, // backtick (non dead gravis)
    SY_LSQU,
    SY_RSQU,
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

#define SY_UNDO C(DE_Z)
#define SY_REDO RCS(DE_Z)
#define SY_REDO2 C(DE_Y)
#define DE_SUP1 ALGR(DE_1)    // ¹

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
  [_QWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_CIRC ,DE_1    ,DE_2    ,DE_3    ,DE_4    ,DE_5    ,                                            DE_6    ,DE_7    ,DE_8    ,DE_9    ,DE_0    ,DE_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB ,DE_Q,DE_W,LGUI_T(DE_E),MEH_T(DE_R),LALT_T(DE_T),DE_GRV,                          DE_QUOT,LALT_T(DE_Z),MEH_T(DE_U),LGUI_T(DE_I),DE_O,DE_P,DE_UDIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LGUI_T(KC_ESC),DE_A,LALT_T(DE_S),LCTL_T(DE_D),LSFT_T(DE_F),LGUI_T(DE_G),KC_LCTL, KC_LALT,LGUI_T(DE_H),RSFT_T(DE_J),RCTL_T(DE_K),LALT_T(DE_L),DE_ODIA,DE_ADIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_BSPC),DE_Y  ,DE_X    ,DE_C    ,DE_V    ,DE_B    ,TT(_ADJ),TT(_MFN),        TT(_MFN),TT(_ADJ),DE_N  ,DE_M ,DE_COMM ,DE_DOT ,DE_SS   ,RSFT_T(KC_DEL),
  //├────────┼────────┼────────┼────────┼────────┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_LGUI,C(DE_A),C(KC_INS),S(KC_INS),TT(_NAV),LT(_SYM,KC_ENT),LT(_MFN,KC_SPC), LT(_ADJ,KC_ENT),LT(_SYM,KC_SPC),TT(_NAV),KC_APP ,KC_PWR  ,KC_PSCR ,KC_RGUI
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Base Layer: BONE
 */
  [_BONE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_CIRC ,DE_1    ,DE_2    ,DE_3    ,DE_4    ,DE_5    ,                                            DE_6    ,DE_7    ,DE_8    ,DE_9    ,DE_0    ,DE_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB ,DE_J,DE_D,LGUI_T(DE_U),MEH_T(DE_A),LALT_T(DE_X),DE_GRV,                          DE_QUOT,LALT_T(DE_P),MEH_T(DE_H),LGUI_T(DE_L),DE_M,DE_W,DE_SS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LGUI_T(KC_ESC),DE_C,LALT_T(DE_T),LCTL_T(DE_I),LSFT_T(DE_E),LGUI_T(DE_O),KC_LCTL, KC_LALT,LGUI_T(DE_B),RSFT_T(DE_N),RCTL_T(DE_R),LALT_T(DE_S),DE_G  ,DE_Q    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_BSPC),DE_F  ,DE_V    ,DE_UDIA ,DE_ADIA ,DE_ODIA ,TT(_ADJ),TT(_MFN),        TT(_MFN),TT(_ADJ),DE_Y    ,DE_Z  ,DE_COMM ,DE_DOT ,DE_K ,RSFT_T(KC_DEL),
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_LGUI,C(DE_A),C(KC_INS),S(KC_INS),TT(_NAV),LT(_SYM,KC_ENT),LT(_MFN,KC_SPC), LT(_ADJ,KC_ENT),LT(_SYM,KC_SPC),TT(_NAV),KC_APP ,KC_PWR  ,KC_PSCR ,KC_RGUI
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Base Layer: Neo2
 */
  [_NEO2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_CIRC ,DE_1    ,DE_2    ,DE_3    ,DE_4    ,DE_5    ,                                            DE_6    ,DE_7    ,DE_8    ,DE_9    ,DE_0    ,DE_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB ,DE_X,DE_V,LGUI_T(DE_L),MEH_T(DE_C),LALT_T(DE_W),DE_GRV,                          DE_QUOT,LALT_T(DE_K),MEH_T(DE_H),LGUI_T(DE_G),DE_F,DE_Q,DE_SS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LGUI_T(KC_ESC),DE_U,LALT_T(DE_I),LCTL_T(DE_A),LSFT_T(DE_E),LGUI_T(DE_O),KC_LCTL, KC_LALT,LGUI_T(DE_S),RSFT_T(DE_N),RCTL_T(DE_R),LALT_T(DE_T),DE_D  ,DE_Y    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
LSFT_T(KC_BSPC),DE_UDIA,DE_ODIA,DE_ADIA ,DE_P    ,DE_Z    ,TT(_ADJ),TT(_MFN),        TT(_MFN),TT(_ADJ),DE_B    ,DE_M  ,DE_COMM ,DE_DOT ,DE_J ,RSFT_T(KC_DEL),
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_LGUI,C(DE_A),C(KC_INS),S(KC_INS),TT(_NAV),LT(_SYM,KC_ENT),LT(_MFN,KC_SPC), LT(_ADJ,KC_ENT),LT(_SYM,KC_SPC),TT(_NAV),KC_APP ,KC_PWR  ,KC_PSCR ,KC_RGUI
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Symbol Layer: brackets, quotes, ...
 */
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,DE_SUP1 ,DE_SUP2 ,DE_SUP3 ,BN3_4   ,BN3_5   ,                                            BN3_6   ,BN3_7   ,BN3_8   ,SY_LSQU ,SY_RSQU ,SY_SALT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LEAD ,SY_HELL ,DE_UNDS ,DE_LBRC ,DE_RBRC ,SY_CIRC ,_______ ,                          _______ ,DE_EXLM ,DE_LABK ,DE_RABK ,DE_EQL  ,DE_AMPR ,DE_EURO ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_BSLS ,DE_SLSH ,DE_LCBR ,DE_RCBR ,DE_ASTR ,_______ ,                          _______ ,DE_QUES ,DE_LPRN ,DE_RPRN ,DE_MINS ,DE_COLN ,DE_AT   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DE_HASH ,DE_DLR  ,DE_PIPE ,SY_TILD ,SY_BKTK ,KC_CAPS ,_______ ,        _______ ,KC_PSCR ,DE_PLUS ,DE_PERC ,DE_DQUO ,DE_QUOT ,DE_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______,S(KC_DEL),DE_CIRC ,     DE_TILD ,    KC_TRNS ,_______ ,        _______ ,KC_TRNS ,    DE_GRV ,      DE_ACUT ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/*
 * Navigation Layer: Arrow keys, Number pad
 */
  [_NAV] = LAYOUT( // BN4_4 is undefined
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,BN4_1   ,BN4_2   ,BN4_3   ,XXXXXXX ,BN4_5   ,                                            XXXXXXX ,DE_DLR  ,KC_TAB  ,KC_PSLS ,KC_PAST ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    A(KC_TAB),KC_PGUP ,KC_BSPC ,KC_UP   ,KC_DEL  ,KC_INS  ,_______ ,                          _______ ,XXXXXXX ,DE_7    ,DE_8    ,DE_9    ,KC_PPLS ,KC_PMNS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HOME ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_END  ,_______ ,                          _______ ,XXXXXXX ,DE_4    ,DE_5    ,DE_6    ,DE_COMM ,KC_PDOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_ESC  ,SY_UNDO ,SY_REDO ,KC_ENT  ,KC_PGDN ,KC_WHOM ,_______ ,        _______ ,_______ ,DE_COLN ,DE_1    ,DE_2    ,DE_3    ,DE_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______,S(KC_DEL),SY_REDO2,     KC_TRNS ,    KC_WBAK ,KC_WFWD ,        _______ ,DE_0    ,    KC_TRNS ,     KC_PSCR ,_______ ,_______ ,_______
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
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX,S(DE_MINS),XXXXXXX,_______ ,KC_TRNS ,        KC_TRNS ,_______ ,XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F12  ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,KC_TRNS ,        KC_TRNS ,_______ ,    _______ ,     KC_PWR  ,_______ ,_______ ,KC_MUTE
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
     RGB_SAD ,RGB_M_P ,RGB_MOD ,RGB_HUI ,     KC_BTN3 ,    KC_BTN1 ,KC_BTN2 ,        KC_TRNS ,KC_ACL0 ,    XXXXXXX ,     UC_MOD  ,_______ ,_______ ,RESET
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
            case BN3_6:
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
