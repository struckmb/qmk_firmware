# Bootloader selection
BOOTLOADER = caterina

SPLIT_KEYBOARD = yes

# Enable the use of OLED displays
# OLED_ENABLE     = yes
# OLED_DRIVER     = SSD1306

# MOUSEKEY_ENABLE = yes
# WPM_ENABLE = no

# Tweak for size
# NO_USB_STARTUP_CHECK = yes # Prevent SUSPENDED state loop in case of no USB connection. Frees 286 bytes
# EXTRAFLAGS        += -flto

# Hardware settings
ifneq (,$(findstring splitkb/kyria/rev1,$(KEYBOARD)))
    # Elective features
    COMBO_ENABLE = yes
    ENCODER_ENABLE = no
    OLED_ENABLE = yes
    # Nonexistent features
    AUDIO_ENABLE = no
    BACKLIGHT_ENABLE = no
    RGB_MATRIX_ENABLE = no
    # Space savers
    NKRO_ENABLE = no
    VELOCIKEY_ENABLE = no
    WPM_ENABLE = no
endif

