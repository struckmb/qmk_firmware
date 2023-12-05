#include "struckmb.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef QWERTZ_ENABLE
    [_QWERTZ] = LAYOUT_wrapper(_QWER_6_L1_, _QWER_6_R1_, //
                               _QWER_6_L2_, _QWER_6_R2_, //
                               _QWER_6_L3_, _QWER_6_R3_, //
                               _THUMB_3_3_),
#endif // QWERTZ_ENABLE

#ifdef BONE_ENABLE
    [_BONE] = LAYOUT_wrapper(_BONE_6_L1_, _BONE_6_R1_, //
                             _BONE_6_L2_, _BONE_6_R2_, //
                             _BONE_6_L3_, _BONE_6_R3_, //
                             _THUMB_3_3_),
#endif // BONE_ENABLE

#ifdef WORKMAN_ENABLE
    [_WORKMAN] = LAYOUT_wrapper(_WORK_6_L1_, _WORK_6_R1_, //
                                _WORK_6_L2_, _WORK_6_R2_, //
                                _WORK_6_L3_, _WORK_6_R3_, //
                                _THUMB_3_3_),
#endif // WORKMAN_ENABLE

#ifdef COLEMAK_ENABLE
    [_COLEMAK_DH] = LAYOUT_wrapper(_COLE_6_L1_, _COLE_6_R1_, //
                                   _COLE_6_L2_, _COLE_6_R2_, //
                                   _COLE_6_L3_, _COLE_6_R3_, //
                                   _THUMB_3_3_),
#endif // COLEMAK_ENABLE

    // Symbols and Numbers
    [_SYM_NUM] = LAYOUT_wrapper(_SYMB_6_L1_, _SYMB_6_R1_, //
                                _SYMB_6_L2_, _SYMB_6_R2_, //
                                _SYMB_6_L3_, _SYMB_6_R3_, //
                                _SYMB_3_3_TB_),
    // Navigation and Function
    [_NAV_FUN] = LAYOUT_wrapper(_NAVI_6_L1_, _FUNC_6_R1_, //
                                _NAVI_6_L2_, _FUNC_6_R2_, //
                                _NAVI_6_L3_, _FUNC_6_R3_, //
                                _NAFN_3_3_TB_),
    // Mouse and Media Control
    [_MSE_CTL] = LAYOUT_wrapper(_MSME_6_L1_, _MSME_6_R1_, //
                                _MSME_6_L2_, _MSME_6_R2_, //
                                _MSME_6_L3_, _MSME_6_R3_, //
                                _MSME_3_3_TB_),
    // Keyboard adjustments
    [_ADJUST] = LAYOUT_wrapper(_CONF_6_L1_, _CONF_6_R1_, //
                               _CONF_6_L2_, _CONF_6_R2_, //
                               _CONF_6_L3_, _CONF_6_R3_, //
                               _CONF_3_3_TB_)};
