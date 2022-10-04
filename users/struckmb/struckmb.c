/* Copyright 2021 Batuhan Başerdem
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

#include "struckmb.h"
#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"
#endif // COMBO_ENABLE

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

#ifdef ARTSENIO_ENABLE
void keyboard_post_init_user(void) {
    if (is_keyboard_left() && is_keyboard_master()) {
        /* if (!is_transport_connected()) { */
            // no right half detected, switch to one handed layout
            default_layer_set(1UL<<_ARTSENIO);
        /* } */
    }
}
#endif // ARTSENIO_ENABLE

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (combo_index < ALL_ZZZ) return true;
#   ifdef COMBO_ENABLE
    uint8_t this_default_layer = get_highest_layer(default_layer_state);
#   ifdef ARTSENIO_ENABLE
    if (combo_index > ARTS_AAA && combo_index < ARTS_ZZZ && this_default_layer == _ARTSENIO) return true;
#   endif // ARTSENIO_ENABLE
#   ifdef ASETNIOP_ENABLE
    if (combo_index > ASET_AAA && combo_index < ASET_ZZZ && this_default_layer == _ASETNIOP) return true;
#   endif // ASETNIOP_ENABLE
#   endif // COMBO_ENABLE
    return false;
}
#endif // COMBO_ENABLE

