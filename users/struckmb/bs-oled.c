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

/* // kyria default */
/* bool oled_task_user(void) { */
/*     if (is_keyboard_master()) { */
/*         // QMK Logo and version information */
/*         // clang-format off */
/*         static const char PROGMEM qmk_logo[] = { */
/*             0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
/*             0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
/*             0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0}; */
/*         // clang-format on */

/*         oled_write_P(qmk_logo, false); */
/*         oled_write_P(PSTR("Kyria rev1.0\n\n"), false); */

/*         // Host Keyboard Layer Status */
/*         oled_write_P(PSTR("Layer: "), false); */
/*         switch (get_highest_layer(layer_state|default_layer_state)) { */
/*             case _QWERTZ: */
/*                 oled_write_P(PSTR("QWERTY\n"), false); */
/*                 break; */
/* //            case _BONE: */
/* //                oled_write_P(PSTR("BoNeo\n"), false); */
/* //                break; */
/* //            case _COLEMAK_DH: */
/* //                oled_write_P(PSTR("Colemak-DH\n"), false); */
/* //                break; */
/*             case _SYM_NUM: */
/*                 oled_write_P(PSTR("Sym/Num\n"), false); */
/*                 break; */
/*             case _NAV_FUN: */
/*                 oled_write_P(PSTR("Nav/Fn\n"), false); */
/*                 break; */
/*             case _MSE_CTL: */
/*                 oled_write_P(PSTR("Mse/Ctrl\n"), false); */
/*                 break; */
/*             case _ADJUST: */
/*                 oled_write_P(PSTR("Adjust\n"), false); */
/*                 break; */
/*             default: */
/*                 oled_write_P(PSTR("Undefined\n"), false); */
/*         } */

/*         // Write host Keyboard LED Status to OLEDs */
/*         led_t led_usb_state = host_keyboard_led_state(); */
/*         oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false); */
/*         oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false); */
/*         oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false); */
/*     } else { */
/*         // clang-format off */
/*         static const char PROGMEM kyria_logo[] = { */
/*             0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0, */
/*             0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*             0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 */
/*         }; */
/*         // clang-format on */
/*         oled_write_raw_P(kyria_logo, sizeof(kyria_logo)); */
/*     } */
/*     return false; */
/* } */
// Do sane defaults for regular oled rendering
bool oled_task_user(void) {
    if (is_oled_on() && oled_task_keymap()) {
        if (is_keyboard_master()) {
            render_qmk_small_logo(0, 0);
            render_status_lite(5, 0, false);
        } else {
            render_logo_keyboard(0, 0);
        }
    }
    return false;
}

/*-------------------------*\
|*---RENDERING FUNCTIONS---*|
\*-------------------------*/
__attribute__ ((weak)) void render_logo_keyboard(uint8_t col, uint8_t row) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    oled_set_cursor(col, row);
    oled_write_P(qmk_logo, false);
}
void render_qmk_small_logo(uint8_t col, uint8_t row) {
    static const char PROGMEM logo1[] = { 0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0};
    static const char PROGMEM logo2[] = { 0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0};
    static const char PROGMEM logo3[] = { 0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0};
    oled_set_cursor(col, row);
    oled_write_P(logo1, false);
    oled_set_cursor(col, row + 1);
    oled_write_P(logo2, false);
    oled_set_cursor(col, row + 2);
    oled_write_P(logo3, false);
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
        case _MSE_CTL:
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
