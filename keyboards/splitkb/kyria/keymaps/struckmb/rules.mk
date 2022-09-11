# Bootloader selection
BOOTLOADER = caterina

# UNICODE_ENABLE  = no
# COMBO_ENABLE = yes
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
# ENCODER_ENABLE  = no       # Enables the use of one or more encoders

# Enable the use of OLED displays
# OLED_ENABLE     = yes
# OLED_DRIVER     = SSD1306

# MOUSEKEY_ENABLE = yes
# WPM_ENABLE = no

# Tweak for size
# NO_USB_STARTUP_CHECK = yes # Prevent SUSPENDED state loop in case of no USB connection. Frees 286 bytes
# EXTRAFLAGS        += -flto

# Kyria hardware
ifneq (,$(findstring splitkb/kyria/rev1,$(KEYBOARD)))
    # Elective features
    ENCODER_ENABLE = yes
    OLED_ENABLE = yes
    # Nonexistent features
    AUDIO_ENABLE = no
    BACKLIGHT_ENABLE = no
    RGB_MATRIX_ENABLE = no
    # Space savers
    NKRO_ENABLE = no
    VELOCIKEY_ENABLE = no
    WPM_ENABLE = yes
endif

