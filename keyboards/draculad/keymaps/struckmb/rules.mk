# only uncomment on the side you have your trackball on
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball
# OLED_ENABLE = yes
# OLED_DRIVER = SSD1306
# MOUSEKEY_ENABLE = yes


#COMBO_ENABLE = yes

# Kyria hardware
ifneq (,$(findstring draculad,$(KEYBOARD)))
    # Elective features
    COMBO_ENABLE = yes
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

# Combo stuff
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
endif

