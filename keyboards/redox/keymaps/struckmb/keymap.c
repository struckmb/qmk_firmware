#include QMK_KEYBOARD_H
#include "struckmb.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef QWERTZ_ENABLE
    [_QWERTZ] = LAYOUT_wrapper(_NUMB_6_L0_, /*        */ _NUMB_6_R0_, //
                               _QWER_6_L1_, NO_NO______, _QWER_6_R1_,    //
                               _QWER_6_L2_, NO_NO______, _QWER_6_R2_,    //
                               _QWER_6_L3_, NO_NO_NO_NO, _QWER_6_R3_,    //
                               NO_NO______, _THUMB_5_5_, NO_NO______),
#endif // QWERTZ_ENABLE

#ifdef BONE_ENABLE
    [_BONE] = LAYOUT_wrapper(_NUMB_6_L0_, /*        */ _NUMB_6_R0_, //
                             _BONE_6_L1_, NO_NO______, _BONE_6_R1_,    //
                             _BONE_6_L2_, NO_NO______, _BONE_6_R2_,    //
                             _BONE_6_L3_, NO_NO_NO_NO, _BONE_6_R3_,    //
                             NO_NO______, _THUMB_5_5_, NO_NO______),
#endif // BONE_ENABLE
#ifdef WORKMAN_ENABLE
    [_WORKMAN] = LAYOUT_wrapper(_NUMB_6_L0_, /*        */ _NUMB_6_R0_, //
                                _WORK_6_L1_, NO_NO______, _WORK_6_R1_,    //
                                _WORK_6_L2_, NO_NO______, _WORK_6_R2_,    //
                                _WORK_6_L3_, NO_NO_NO_NO, _WORK_6_R3_,    //
                                NO_NO______, _THUMB_5_5_, NO_NO______),
#endif // WORKMAN_ENABLE
#ifdef COLEMAK_ENABLE
    [_COLEMAK_DH] = LAYOUT_wrapper(_NUMB_6_L0_, /*        */ _NUMB_6_R0_, //
                                   _COLE_6_L1_, NO_NO______, _COLE_6_R1_,    //
                                   _COLE_6_L2_, NO_NO______, _COLE_6_R2_,    //
                                   _COLE_6_L3_, NO_NO_NO_NO, _COLE_6_R3_,    //
                                   NO_NO______, _THUMB_5_5_, NO_NO______),
#endif // COLEMAK_ENABLE

    // Symbols and Numbers
    [_SYM_NUM] = LAYOUT_wrapper(_FUNC_6_L0_, /*        */ _FUNC_6_R0_, //
                                _SYMB_6_L1_, NO_NO______, _SYMB_6_R1_,    //
                                _SYMB_6_L2_, NO_NO______, _SYMB_6_R2_,    //
                                _SYMB_6_L3_, NO_NO_NO_NO, _SYMB_6_R3_,    //
                                NO_NO______, _SYMB_5_5_TB_, NO_NO______),
    // // Navigation and Function
    [_NAV_FUN] = LAYOUT_wrapper(_FUNC_6_L0_, /*        */ _FUNC_6_R0_, //
                                _NAVI_6_L1_, NO_NO______, _FUNC_6_R1_,    //
                                _NAVI_6_L2_, NO_NO______, _FUNC_6_R2_,    //
                                _NAVI_6_L3_, NO_NO_NO_NO, _FUNC_6_R3_,    //
                                NO_NO______, _NAFN_5_5_TB_, NO_NO______),
    // // Mouse and Media Control
    [_MSE_CTL] = LAYOUT_wrapper(_FUNC_6_L0_, /*        */ _FUNC_6_R0_, //
                                _MSME_6_L1_, NO_NO______, _MSME_6_R1_,    //
                                _MSME_6_L2_, NO_NO______, _MSME_6_R2_,    //
                                _MSME_6_L3_, NO_NO_NO_NO, _MSME_6_R3_,    //
                                NO_NO______, _MSME_5_5_TB_, NO_NO______),
    // // Keyboard adjustments
    [_ADJUST] = LAYOUT_wrapper(_FUNC_6_L0_, /*        */ _FUNC_6_R0_, //
                               _CONF_6_L1_, NO_NO______, _CONF_6_R1_,    //
                               _CONF_6_L2_, NO_NO______, _CONF_6_R2_,    //
                               _CONF_6_L3_, NO_NO_NO_NO, _CONF_6_R3_,    //
                               NO_NO______, _CONF_5_5_TB_, NO_NO______),

};
