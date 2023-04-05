
#pragma once

#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "wrappers.h"

/* Besides loading libraries and definitions, this file has my layout defs
 * LAYOUTS:
 *  This file has a couple layouts I use; so that the general changes can be
 *  propagated by only editing this file.
 */

// Rotary encoder
#ifdef ENCODER_ENABLE
#include "bs-encoder.h"
#endif // ENCODER_ENABLE

// Oled screen
#ifdef OLED_ENABLE
#include "bs-oled.h"
#endif // OLED_ENABLE

// Make it so that keymaps can use KEYMAP_SAFE_RANGE for custom keycodes
#ifdef KEYMAP_SAFE_RANGE
#define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

// Custom macro keycode ranges
enum userspace_custom_keycodes {
    // Safe stuff
    NO_MOD = PLACEHOLDER_SAFE_RANGE,
#   ifdef ARTSENIO_ENABLE
    /* AR_START, AR_END, // Dummy key codes for combo definitions */
    AR_A, AR_S, AR_E, AR_O,
#   endif // ARTSENIO_ENABLE
#   ifdef ASETNIOP_ENABLE
    /* AS_START, AS_END, // Dummy key codes for combo definitions */
#   endif // ASETNIOP_ENABLE
    // Encoder button
#   ifdef ENCODER_ENABLE
    BS_ENC0,
    BS_ENC1,
#   endif // ENCODER_ENABLE
    //use for keymap specific codes
    KEYMAP_SAFE_RANGE
};

#ifndef ENCODER_ENABLE
#define BS_ENC0 KC_NO
#define BS_ENC1 KC_NO
#endif // NO ENCODER_ENABLE

/// Enumeration of layers
enum userspace_layers {
    // Base layers
#   ifdef QWERTZ_ENABLE
    _QWERTZ,
#   endif // QWERTZ_ENABLE
#   ifdef BONEM_ENABLE
    _BONEM,
#   endif // BONEM_ENABLE
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
