# Bootloader selection
BOOTLOADER = caterina

COMBO_ENABLE = yes

MOUSEKEY_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

# Tweak for size
NO_USB_STARTUP_CHECK = yes # Prevent SUSPENDED state loop in case of no USB connection. Frees 286 bytes
EXTRAFLAGS        += -flto
