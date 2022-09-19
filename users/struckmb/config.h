/*
  Copyright (c) 2020 Fred Silberberg

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#pragma once

// Space saving
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif
#ifndef NO_DEBUG
#   define NO_DEBUG
#endif
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#   define NO_PRINT
#endif

// Mousekey mode
#ifdef MOUSEKEY_ENABLE
#   define MK_COMBINED
#   define MOUSEKEY_MAX_SPEED 4
#   define MOUSEKEY_TIME_TO_MAX 45
#   define MOUSEKEY_WHEEL_MAX_SPEED 20
#   define MOUSEKEY_WHEEL_TIME_TO_MAX 60
#endif // MOUSEKEY_ENABLE

#ifdef COMBO_ENABLE
#   define COMBO_SHOULD_TRIGGER
#endif // COMBO_ENABLE

// Tap-hold settings
#define TAPPING_TERM 200
#define TAP_CODE_DELAY 20
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define ONESHOT_TAP_TOGGLE 2

// OLED definitions
#ifdef OLED_ENABLE
    // Fade out the screen when timing out
#   define OLED_FADE_OUT
#   define OLED_FADE_OUT_INTERVAL 15
#endif // OLED_ENABLE

