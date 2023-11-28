#include QMK_KEYBOARD_H
#include "keycodes.h"
#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"
#endif


/// Enumeration of layers
enum userspace_layers {
    // Base layers
#   ifdef QWERTZ_ENABLE
    _QWERTZ,
#   endif // QWERTZ_ENABLE
#   ifdef BONE_ENABLE
    _BONE,
#   endif // BONE_ENABLE
#   ifdef WORKMAN_ENABLE
    _WORKMAN,
#   endif // WORKMAN_ENABLE
#   ifdef COLEMAK_ENABLE
    _COLMAK_DH,
#   endif // COLEMAK_ENABLE
#   ifdef LILYPOND_ENABLE
    _LILYPOND,
#   endif // LILYPOND_ENABLE
#   ifdef ASETNIOP_ENABLE
    _ASETNIOP,    // ASETNIOP layer
#   endif // ASETNIOP_ENABLE
#   ifdef ARTSENIO_ENABLE
    _ARTSENIO,    // ARTSENIO layer
    // Additional layers
    _ARTS_NUM,    // ARTSENIO numbers layer
    _ARTS_SYM,    // ARTSENIO symbols layer
    _ARTS_PAR,    // ARTSENIO parens layer
    _ARTS_NAV,    // ARTSENIO arrows layer
    _ARTS_MSE,    // ARTSENIO mouse layer
#   endif // ARTSENIO_ENABLE
    _SYM_NUM,     // L: Symbols layer,    R: Numbers layer
    _NAV_FUN,     // L: Navigation layer, R: Function keys layer
    _MSE_CTL,     // L: Mouse keys layer, R: Keyboard adjustments
    _ADJUST,      // Media and RGB keys
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │           │ Z │ U │ I │ O │ P │ Ü │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │ESC│ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ Ö │ Ä │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Y │ X │ C │ V │ B │           │ N │ M │,/;│./:│ß/?│Sft│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *         ┌─────┐                               ┌─────┐
      *         │ PUp ├─────┐                   ┌─────┤ PDn │
      *         └─MEH─┤ Esc ├─────┐       ┌─────┤ Tab ├─HYP─┘
      *               └Nv/Fn┤ Ent │       │ Spc ├Nv/Fn┘
      *                     └Sy/Nr┘       └Sy/Nr┘
      */
#ifdef QWERTZ_ENABLE
    [_QWERTZ] = LAYOUT_split_3x6_3(
        ALT_TAB, DE_Q, DE_W, DE_E, DE_R, DE_T,                          DE_Z,  DE_U, DE_I, MC_O, DE_P, ALT_UE,
        CTL_ESC, DE_A, DE_S, DE_D, DE_F, GUI_G,                         GUI_H, DE_J, DE_K, DE_L, DE_ODIA, CTL_AE,
        KC_LSFT, DE_Y, DE_X, DE_C, DE_V, DE_B,                          DE_N,  DE_M, KC_COMM, KC_DOT, DE_SS, KC_RSFT,
                                MEH_PUP, NF_ESC, SY_ENT,        SN_SPC, NF_TAB, HYP_PDN
    ),
#endif
#ifdef BONE_ENABLE
    [_BONE] = LAYOUT_split_3x6_3(
        ALT_TAB, DE_J, DE_D, DE_U, DE_A, DE_X,                          DE_P,  DE_H, DE_L, MC_M, DE_W, ALT_SS,
        CTL_ESC, DE_C, DE_T, DE_I, DE_E, GUI_O,                         GUI_B, DE_N, DE_R, DE_S, DE_G, CTL_Q,
        KC_LSFT, DE_F, DE_V, DE_UDIA, DE_ADIA, DE_ODIA,                 DE_Y,  DE_Z, KC_COMM, KC_DOT, DE_K, KC_RSFT,
                                MEH_PUP, NF_ESC, SY_ENT,        SN_SPC, NF_TAB, HYP_PDN
    ),
#endif

#ifdef WORKMAN_ENABLE
    [_WORKMAN] = LAYOUT_split_3x6_3(
        ALT_TAB, DE_Q, DE_D, DE_R, DE_W, DE_B,                          DE_J, DE_F, DE_U, DE_P, DE_ODIA, DE_UDIA,
        CTL_ESC, DE_A, DE_S, DE_H, DE_T, GUI_G,                         DE_Z, DE_N, DE_E, DE_O, DE_I, DE_ADIA,
        KC_LSFT, DE_Y, DE_X, DE_M, DE_C, DE_V,                          DE_K, DE_L, KC_COMM, KC_DOT, DE_SS, KC_RSFT,
                                MEH_PUP, NF_ESC, SY_ENT,        SN_SPC, NF_TAB, HYP_PDN
    ),
#endif // WORKMAN_ENABLE

#ifdef COLEMAK_ENABLE
    [_WORKMAN] = LAYOUT_split_3x6_3(
        ALT_TAB, DE_Q, DE_W, DE_F, DE_P, DE_B,                          DE_J, DE_L, DE_U, DE_Z, DE_ODIA, DE_UDIA,
        CTL_ESC, DE_A, DE_R, DE_S, DE_T, GUI_G,                         DE_M, DE_N, DE_E, DE_I, DE_O, DE_ADIA,
        KC_LSFT, DE_Y, DE_X, DE_C, DE_D, DE_V,                          DE_K, DE_H, KC_COMM, KC_DOT, DE_SS, KC_RSFT,
                                MEH_PUP, NF_ESC, SY_ENT,        SN_SPC, NF_TAB, HYP_PDN
    ),
#endif // COLEMAK_ENABLE

    // Symbols and Numbers
    [_SYM_NUM] = LAYOUT_split_3x6_3(
        _______, DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,       DE_0,    DE_1,    DE_2,    DE_4,    DE_8,    DE_EXLM,
        _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,       DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR, DE_EQL,
        _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT,       DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO, _______,
                                   KC_TRNS, DE_SECT, KC_TRNS,       KC_TRNS, DE_CENT, KC_TRNS
    ),
    // Navigation and Function
    [_NAV_FUN] = LAYOUT_split_3x6_3(
        _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN,       KC_F10,  KC_F1,   KC_F2,   KC_F4,   KC_F8,   KC_F11,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,        OSM_ALT, OSM_CTL, OSM_GUI, OSM_SFT, KC_RSFT, KC_F12,
        _______, KC_INS,  CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR,       KC_PWR,  OSM_AGR, OSM_MEH, OSM_HYP, CW_TOGG, CW_TOGG,
                                   KC_TRNS, LY_ADJ,  KC_TRNS,       KC_APP,  LY_ADJ,  KC_TRNS
    ),
    // Mouse and Media Control
    [_MSE_CTL] = LAYOUT_split_3x6_3(
        _______, KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,       KC_ACL2, DE_UDIA, KC_VOLU, XXXXXXX, KC_EJCT, KC_NO,
        _______, DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE,      KC_ACL1, KC_MNXT, KC_VOLD, XXXXXXX, KC_MPRV, KC_NO,
        _______, KC_BTN4, XXXXXXX, DE_UDIA, DE_ADIA, KC_BTN5,       KC_ACL0, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, _______,
                                   KC_BTN3, KC_BTN2, KC_BTN1,       KC_LSFT, KC_BTN3, KC_TRNS
    ),
    // Keyboard adjustments
    [_ADJUST]  = LAYOUT_split_3x6_3(
        _______, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
        _______, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,        EE_CLR,  QWERTZ,  BONE,    COLMAK,  WRKMAN,  KC_NO,
        _______, RGB_M_T, RGB_M_X, RGB_M_G, RGB_M_K, RGB_M_SN,       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, _______,
                                   _______, _______, _______,       _______, _______, _______
    )
};

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DE_MINS:
        case DE_UNDS:
            return true;
        default:
            return false; // Deactivate Caps Word.
    }
}
#endif

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (combo_index < ALL_ZZZ) return true;
#if defined(QWERTZ_ENABLE) || defined(BONE_ENABLE) || defined(WORKMAN_ENABLE) || defined(COLEMAK_ENABLE) || defined(LILYPOND_ENABLE)
    if (combo_index < BASE_ZZZ) {
#ifdef LILYPOND_ENABLE
        return get_highest_layer(default_layer_state) <= _LILYPOND;
#elif defined(COLEMAK_ENABLE)
        return get_highest_layer(default_layer_state) <= _COLMAK_DH;
#elif defined(WORKMAN_ENABLE)
        return get_highest_layer(default_layer_state) <= _WORKMAN;
#elif defined(BONE_ENABLE)
        return get_highest_layer(default_layer_state) <= _BONE;
#elif defined(QWERTZ_ENABLE)
        return get_highest_layer(default_layer_state) <= _QWERTZ;
#endif // QWERTZ_ENABLE, BONE_ENABLE, WORKMAN_ENABLE, COLEMAK_ENABLE, LILYPOND_ENABLE
    }
#endif // QWERTZ_ENABLE // BONE_ENABLE // WORKMAN_ENABLE // COLEMAK_ENABLE // LILYPOND_ENABLE
#ifdef ARTSENIO_ENABLE
    if (combo_index > ARTS_AAA && combo_index < ARTS_ZZZ) return get_highest_layer(default_layer_state) == _ARTSENIO;
#endif // ARTSENIO_ENABLE
#ifdef ASETNIOP_ENABLE
    if (combo_index > ASET_AAA && combo_index < ASET_ZZZ) return get_highest_layer(default_layer_state) == _ASETNIOP;
#endif // ASETNIOP_ENABLE
    return false;
}
#endif
