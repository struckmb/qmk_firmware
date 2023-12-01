#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

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
