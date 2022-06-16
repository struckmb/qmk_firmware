# Bootloader selection
BOOTLOADER = caterina

OLED_ENABLE        = yes
OLED_DRIVER        = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE     = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE    = yes

# own additions
UNICODE_ENABLE     = yes
#LEADER_ENABLE      = yes

NO_USB_STARTUP_CHECK = yes # Prevent SUSPENDED state loop in case of no USB connection. Frees 286 bytes
EXTRAFLAGS        += -flto
