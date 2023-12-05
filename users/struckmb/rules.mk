# Common compilation flags
LTO_ENABLE = yes

# These should be enabled in all boards
AVR_USE_MINIMAL_PRINTF = yes
BOOTMAGIC_ENABLE = yes  # Some kind of magic...
CAPS_WORD_ENABLE = yes  # Much better key caps
COMBO_ENABLE = yes      # Press key combos to get different behaviours
EXTRAKEY_ENABLE = yes   # OS signals like volume control
LTO_ENABLE = yes        # Enable link time optimizations
MOUSEKEY_ENABLE = yes   # Mouse emulation keys

# These should be disabled in all boards
COMMAND_ENABLE = no     # Some bootmagic thing i dont use
CONSOLE_ENABLE = no     # Allows console output with a command
GRAVE_ESC_ENABLE = no
KEY_LOCK_ENABLE = no    # Allows locking any key. Not used in general
MAGIC_ENABLE = no
MIDI_ENABLE = no        # Midi driver (untested)
MUSIC_ENABLE = no
SLEEP_LED_ENABLE = no   # Breathes LED's when computer is asleep. Untested.
SPACE_CADET_ENABLE = no
TAP_DANCE_ENABLE = no   # Tap dance keys; i don't use tap dance
UCIS_ENABLE = no        # We use unicodemap, not ucis
UNICODE_ENABLE = no     # We use unicodemap, not unicode
VARIABLE_TRACE = no     # Allows debugging variables
# RGBLIGHT_ENABLE = no    # LED strip, but there is RGB_MATRIX instead

# Userspace code
SRC += struckmb.c

# Rotary encoder stuff
ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += bs-encoder.c
endif

# OLED code
ifeq ($(strip $(OLED_ENABLE)), yes)
SRC += bs-oled.c
endif

# Combo stuff
ifeq ($(strip $(COMBO_ENABLE)), yes)
VPATH += keyboards/gboards
endif
