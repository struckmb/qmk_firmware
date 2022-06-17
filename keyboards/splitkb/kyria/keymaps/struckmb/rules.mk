# Bootloader selection
BOOTLOADER = caterina

# UNICODE_ENABLE  = yes
ENCODER_ENABLE  = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow

# Enable the use of OLED displays
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306

# Tweak for size
NO_USB_STARTUP_CHECK = yes # Prevent SUSPENDED state loop in case of no USB connection. Frees 286 bytes
EXTRAFLAGS        += -flto
