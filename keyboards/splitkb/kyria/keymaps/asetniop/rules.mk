# Bootloader selection
BOOTLOADER = caterina

UNICODE_ENABLE  = no
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
ENCODER_ENABLE  = no       # Enables the use of one or more encoders

# Enable the use of OLED displays
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306

MOUSEKEY_ENABLE = yes
WPM_ENABLE = yes

# Tweak for size
NO_USB_STARTUP_CHECK = yes # Prevent SUSPENDED state loop in case of no USB connection. Frees 286 bytes
EXTRAFLAGS        += -flto
