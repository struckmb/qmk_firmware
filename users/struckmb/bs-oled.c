/* Copyright 2021 Batuhan Başerdem
 * <baserdem.batuhan@gmail.com> @bbaserdem
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
#include "bs-oled.h"

/* #include <string.h> */
// Grab the print function 
#ifdef ENCODER_ENABLE
#   include "bs-encoder.h"
#endif // ENCODER_ENABLE

/* OLED
 * This contains general purpose oled code
 */ 

// Allow default to be overwritten by keymap if they return false
__attribute__ ((weak)) bool oled_task_keymap(void) {return true;}

// Do sane defaults for regular oled rendering
bool oled_task_user(void) {
    if (is_oled_on() && oled_task_keymap()) {
        if (is_keyboard_master()) {
            render_status_lite(0, 0, false);
        } else {
            render_qmk_logo(0, 0);
        }
    }
    return false;
}

/*-------------------------*\
|*---RENDERING FUNCTIONS---*|
\*-------------------------*/
void render_qmk_logo(uint8_t col, uint8_t row) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    oled_set_cursor(col, row);
    oled_write_P(qmk_logo, false);
}
void render_qmk_small_logo(uint8_t col, uint8_t row) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0xa0,0xa1,0xa2,0xa3,0xa4,
        0xa5,0xa6,0xa7,0xa8,0xa9,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0};
    oled_set_cursor(col, row);
    oled_write_P(qmk_logo, false);
}

void render_keymap(uint8_t col, uint8_t row, uint8_t def_layer, bool small) {
    oled_set_cursor(col, row);
    oled_write(small ? "B: " : "Base: ", false);
    switch (def_layer) {
#       ifdef QWERTZ_ENABLE
        case _QWERTZ:
            oled_write("QWERTZ", false);
            break;
#       endif // QWERTZ_ENABLE
#       ifdef ASETNIOP_ENABLE
        case _ASETNIOP:
            oled_write("ASET++", false);
            break;
#       endif // ASETNIOP_ENABLE
#       ifdef ARTSENIO_ENABLE
        case _ARTSENIO:
            oled_write("ARTSEN", false);
            break;
#       endif // ARTSENIO_ENABLE
        default:
            oled_write(" N/A! ", false);
    }
}

void render_layer(uint8_t col, uint8_t row, uint8_t top_layer, bool small) {
    oled_set_cursor(col, row);
    oled_write(small ? "L: " : "Layr: ", false);
    switch (top_layer) {
        case 0:
            oled_write("Default", false);
            break;
        case _SYM_NUM:
            oled_write("Sym/Num", false);
            break;
        case _NAV_FUN:
            oled_write("Nav/Fn ", false);
            break;
        case _MSE_ADJ:
            oled_write("Mse/Adj", false);
            break;
#       ifdef ARTSENIO_ENABLE
        case _ARTS_NUM:
            oled_write("AS 1/F1", false);
            break;
        case _ARTS_PAR:
            oled_write("AS {[]}", false);
            break;
        case _ARTS_SYM:
            oled_write("AS Sym.", false);
            break;
        case _ARTS_NAV:
            oled_write("AS Nav.", false);
            break;
        case _ARTS_MSE:
            oled_write("AS Mse ", false);
            break;
#       endif // ARTSENIO_ENABLE
        default:
            oled_write("? N/A ? ", false);
    }
}

void render_modifiers(uint8_t col, uint8_t row, uint8_t mods, uint8_t osms, bool small) {
    bool capsLock = host_keyboard_led_state().caps_lock;
    // Write the modifier state
    oled_set_cursor(col, row);
    oled_write(small ? "M: " : "Mods: ", false);
    oled_write((mods & MOD_MASK_SHIFT  ) ? "S" : " ", (osms & MOD_MASK_SHIFT  ));
    oled_write((mods & MOD_MASK_CTRL   ) ? "C" : " ", (osms & MOD_MASK_CTRL   ));
    oled_write((mods & MOD_BIT(KC_RALT)) ? "R" : " ", (osms & MOD_BIT(KC_RALT)));
    oled_write((mods & MOD_MASK_ALT    ) ? "A" : " ", (osms & MOD_MASK_ALT    ));
    oled_write((mods & MOD_MASK_GUI    ) ? "M" : " ", (osms & MOD_MASK_GUI    ));
    oled_write(capsLock ? " L" : "  ", capsLock);
}

void render_status_lite(uint8_t row, uint8_t col, bool small) {
    uint8_t oneshotMods  = get_oneshot_mods();

    // Line 1: Layout
    render_keymap(col, row + 0, get_highest_layer(default_layer_state), small);
    // Line 2: Layer State
    render_layer(col,  row + 1, get_highest_layer(layer_state), small);
    // Line 3: Modifiers
    render_modifiers(col, row + 2, get_mods() | oneshotMods, oneshotMods, small);

#       ifdef WPM_ENABLE
    // Last line: WPM and layout
    oled_set_cursor(col, row + 3);
    oled_write(small ? "W: " : "WPM: ", false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
#       endif // WPM_ENABLE
}
