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

#include <string.h>
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
    if (is_oled_on()) {
        if (oled_task_keymap()) {
            render_status_lite(0, 0, false);
        }
    }
    return false;
}

/*-------------------------*\
|*---RENDERING FUNCTIONS---*|
\*-------------------------*/
void render_qmk_logo(uint8_t row, uint8_t col) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    oled_set_cursor(col, row);
    oled_write_P(qmk_logo, false);
}
void render_qmk_small_logo(uint8_t row, uint8_t col) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0xa0,0xa1,0xa2,0xa3,0xa4,
        0xa5,0xa6,0xa7,0xa8,0xa9,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0};
    oled_set_cursor(col, row);
    oled_write_P(qmk_logo, false);
}

void render_keymap(uint8_t row, uint8_t col, uint8_t def_layer, bool small) {
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

void render_layer(uint8_t row, uint8_t col, uint8_t top_layer, bool small) {
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
        case _ARTS_ARR:
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

void render_modifiers_lite(uint8_t row, uint8_t col, uint8_t mods, uint8_t osms, bool small) {
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

// Writes the currently used OLED display layout
#ifdef RGB_MATRIX_ENABLE
void render_rgb_lite(uint8_t row, uint8_t col) {
    // Writes the currently used OLED display layout, 19 characters
    static char rgb_temp4[4] = {0};
    // Render the oled layout
    oled_set_cursor(col, row);
    oled_write("m", false);
    itoa(rgb_matrix_get_mode(), rgb_temp4, 10);
    oled_write(rgb_temp4, false);
    oled_write(" h", false);
    itoa(rgb_matrix_get_hue(), rgb_temp4, 10);
    oled_write(rgb_temp4, false);
    oled_write(" s", false);
    itoa(rgb_matrix_get_sat(), rgb_temp4, 10);
    oled_write(rgb_temp4, false);
    oled_write(" v", false);
    itoa(rgb_matrix_get_val(), rgb_temp4, 10);
    oled_write(rgb_temp4, false);
}
#endif // RGB_MATRIX_ENABLE

void render_status_lite(uint8_t row, uint8_t col, bool small) {
    // Function to print state information; for low flash memory
    uint8_t this_map   = get_highest_layer(default_layer_state);
    uint8_t this_layer = get_highest_layer(layer_state);
    uint8_t this_mod = get_mods();
    uint8_t this_osm = get_oneshot_mods();
    uint8_t this_all = this_mod|this_osm;

    // Line 1: Layout
    render_keymap(row + 0, col, this_map, small);
    // Line 2: Layer State
    render_layer(row + 1, col, this_layer, small);

#   ifdef WPM_ENABLE
    // Line 3: WPM and layout
    oled_set_cursor(col, row + 2);
    oled_write(small ? "W: " : "WPM: ", false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
    uint8_t lastRow = 3;
#   else // WPM_ENABLE
    uint8_t lastRow = 2;
#   endif // WPM_ENABLE

    // Last line: Mod or info
    switch (this_layer) {
        // Show RGB mode as an overlay in media mode.
#       ifdef RGB_MATRIX_ENABLE
        case _MSE_ADJ:
            render_rgb_lite(row + lastRow, col);
            break;
#       endif // RGB_MATRIX_ENABLE
              // Show the modifier if nothing else is doing anything
        default:
            render_modifiers_lite(row + lastRow, col, this_all, this_osm, small);
            break;
    }
}
