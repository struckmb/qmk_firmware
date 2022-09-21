

# Common compilation flags
LTO_ENABLE = yes

# These should be enabled in all boards
MOUSEKEY_ENABLE = yes   # Mouse emulation keys
EXTRAKEY_ENABLE = yes   # OS signals like volume control
CAPS_WORD_ENABLE = yes

# These should be disabled in all boards
BOOTMAGIC_ENABLE = no   # Access to EEPROM settings, not needed
CONSOLE_ENABLE = no     # Allows console output with a command
COMMAND_ENABLE = no     # Some bootmagic thing i dont use
SLEEP_LED_ENABLE = no   # Breathes LED's when computer is asleep. Untested.
MIDI_ENABLE = no        # Midi driver (untested)
MUSIC_ENABLE = no
UNICODE_ENABLE = no     # We use unicodemap, not unicode
UCIS_ENABLE = no        # We use unicodemap, not ucis
VARIABLE_TRACE = no     # Allows debugging variables
KEY_LOCK_ENABLE = no    # Allows locking any key. Not used in general
RGBLIGHT_ENABLE = no    # LED strip, but there is RGB_MATRIX instead
TAP_DANCE_ENABLE = no   # Tap dance keys; i don't use tap dance
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes


# These features can be disabled at whim
NKRO_ENABLE ?= yes      # Default is 6KRO
VELOCIKEY_ENABLE ?= yes # Speed effects change with typing speed
WPM_ENABLE ?= yes       # Get WPM reports as you type

# Manually configure these on each keyboard individually
# AUDIO_ENABLE            # Audio stuff
# BACKLIGHT_ENABLE        # Switch LEDs
# ENCODER_ENABLE          # Rotary encoder
# RGB_MATRIX_ENABLE       # RGB LEDs
# OLED_ENABLE             # For OLED

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

