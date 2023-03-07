#include "struckmb.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

/*------------------------*\
|*-----PROCESS RECORD-----*|
\*------------------------*/
/* Process record: custom keycodes to process here
 * Allow also the following codes to hook here as well;
 *  Macro definitions
 *  Audio hooks
 */
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Return after running through all individual hooks
    if (keycode == NO_MOD) {
        if (record->event.pressed) clear_oneshot_mods();
        return false;
    }
    return
        process_record_keymap(keycode, record)  &&
#       ifdef ENCODER_ENABLE
        process_record_encoder(keycode, record) &&
#       endif // ENCODER_ENABLE
        true;
}

/* #ifdef ARTSENIO_ENABLE */
/* void keyboard_post_init_user(void) { */
/*     if (is_keyboard_left() && is_keyboard_master()) { */
/*         /1* if (!is_transport_connected()) { *1/ */
/*             // no right half detected, switch to one handed layout */
/*             default_layer_set(1UL<<_ARTSENIO); */
/*         /1* } *1/ */
/*     } */
/* } */
/* #endif // ARTSENIO_ENABLE */

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (combo_index < ALL_ZZZ) return true;
#   ifdef ARTSENIO_ENABLE
    if (combo_index > ARTS_AAA && combo_index < ARTS_ZZZ)
            return get_highest_layer(default_layer_state) == _ARTSENIO;
#   endif // ARTSENIO_ENABLE
#   ifdef ASETNIOP_ENABLE
    if (combo_index > ASET_AAA && combo_index < ASET_ZZZ)
        return get_highest_layer(default_layer_state) == _ASETNIOP;
#   endif // ASETNIOP_ENABLE
    return false;
}
#endif // COMBO_ENABLE
