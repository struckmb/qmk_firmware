#pragma once

#define EE_HANDS

// Space saving
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif
#ifndef NO_DEBUG
#    define NO_DEBUG
#endif
#define NO_MUSIC_MODE

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif

// Mousekey mode
#ifdef MOUSEKEY_ENABLE
#    define MK_COMBINED
#    define MOUSEKEY_MAX_SPEED 4
#    define MOUSEKEY_TIME_TO_MAX 45
#    define MOUSEKEY_WHEEL_MAX_SPEED 20
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 60
#endif // MOUSEKEY_ENABLE

#ifdef COMBO_ENABLE
#    define COMBO_SHOULD_TRIGGER
#endif // COMBO_ENABLE

// Tap-hold settings
#define TAPPING_TERM 200
#define TAP_CODE_DELAY 20
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define ONESHOT_TAP_TOGGLE 2

