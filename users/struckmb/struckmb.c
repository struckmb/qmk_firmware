#include "struckmb.h"
#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"
#endif

/*------------------------*\
|*-----PROCESS RECORD-----*|
\*------------------------*/
/* Process record: custom keycodes to process here
 * Allow also the following codes to hook here as well;
 *  Macro definitions
 *  Audio hooks
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Return after running through all individual hooks
    if (keycode == NO_MOD) {
        if (record->event.pressed) clear_oneshot_mods();
        return false;
    }
    return process_record_keymap(keycode, record) &&
#ifdef ENCODER_ENABLE
           process_record_encoder(keycode, record) &&
#endif // ENCODER_ENABLE
           true;
}

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
#    if defined(QWERTZ_ENABLE) || defined(BONE_ENABLE) || defined(COLEMAK_ENABLE) || defined(MINE_ENABLE) || defined(WORKMAN_ENABLE)
    if (combo_index < BASE_ZZZ) {
#        ifdef WORKMAN_ENABLE
        return get_highest_layer(default_layer_state) <= _WORKMAN;
#        elif defined(MINE_ENABLE)
        return get_highest_layer(default_layer_state) <= _MINE;
#        elif defined(COLEMAK_ENABLE)
        return get_highest_layer(default_layer_state) <= _COLEMAK_DH;
#        elif defined(BONE_ENABLE)
        return get_highest_layer(default_layer_state) <= _BONE;
#        elif defined(QWERTZ_ENABLE)
        return get_highest_layer(default_layer_state) <= _QWERTZ;
#        endif // QWERTZ_ENABLE, BONE_ENABLE, WORKMAN_ENABLE, COLEMAK_ENABLE
    }
#    endif // QWERTZ_ENABLE // BONE_ENABLE // COLEMAK_ENABLE // MINE_ENABLE // WORKMAN_ENABLE
#    ifdef ARTSENIO_ENABLE
    if (combo_index > ARTS_AAA && combo_index < ARTS_ZZZ) return get_highest_layer(default_layer_state) == _ARTSENIO;
#    endif // ARTSENIO_ENABLE
#    ifdef ASETNIOP_ENABLE
    if (combo_index > ASET_AAA && combo_index < ASET_ZZZ) return get_highest_layer(default_layer_state) == _ASETNIOP;
#    endif // ASETNIOP_ENABLE
    return false;
}
#endif
