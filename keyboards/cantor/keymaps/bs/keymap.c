#include "bs.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// clang-format off
     /* ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │           │ Z │ U │ I │ O │ P │ Ü │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │ESC│ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ Ö │ Ä │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Y │ X │ C │ V │ B │           │ N │ M │,/;│./:│ß/?│Sft│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *         ┌─────┐                               ┌─────┐
      *         │ PUp ├─────┐                   ┌─────┤ PDn │
      *         └─MEH─┤ Esc ├─────┐       ┌─────┤ Tab ├─HYP─┘
      *               └Nv/Fn┤ Ent │       │ Spc ├Nv/Fn┘
      *                     └Sy/Nr┘       └Sy/Nr┘
      */
// clang-format on
#ifdef QWERTZ_ENABLE
    [_QWERTZ] = LAYOUT_split_3x6_3(ALT_TAB, DE_Q, DE_W, DE_E, DE_R, DE_T, DE_Z, DE_U, DE_I, MC_O, DE_P, ALT_UE,        //
                                   CTL_ESC, DE_A, DE_S, DE_D, DE_F, GUI_G, GUI_H, DE_J, DE_K, DE_L, DE_ODIA, CTL_AE,   //
                                   KC_LSFT, DE_Y, DE_X, DE_C, DE_V, DE_B, DE_N, DE_M, KC_COMM, KC_DOT, DE_SS, KC_RSFT, //
                                   MEH_PUP, NF_ESC, SY_ENT, SN_SPC, NF_TAB, HYP_PDN),
#endif // QWERTZ_ENABLE

#ifdef BONE_ENABLE
    [_BONE] = LAYOUT_split_3x6_3(ALT_TAB, DE_J, DE_D, DE_U, DE_A, DE_X, DE_P, DE_H, DE_L, MC_M, DE_W, ALT_SS,                //
                                 CTL_ESC, DE_C, DE_T, DE_I, DE_E, GUI_O, GUI_B, DE_N, DE_R, DE_S, DE_G, CTL_Q,               //
                                 KC_LSFT, DE_F, DE_V, DE_UDIA, DE_ADIA, DE_ODIA, DE_Y, DE_Z, KC_COMM, KC_DOT, DE_K, KC_RSFT, //
                                 MEH_PUP, NF_ESC, SY_ENT, SN_SPC, NF_TAB, HYP_PDN),
#endif // BONE_ENABLE

#ifdef WORKMAN_ENABLE
    [_WORKMAN] = LAYOUT_split_3x6_3(ALT_TAB, DE_Q, DE_D, DE_R, DE_W, DE_B, DE_J, DE_F, DE_U, DE_P, DE_ODIA, DE_UDIA,    //
                                    CTL_ESC, DE_A, DE_S, DE_H, DE_T, GUI_G, DE_Z, DE_N, DE_E, DE_O, DE_I, DE_ADIA,      //
                                    KC_LSFT, DE_Y, DE_X, DE_M, DE_C, DE_V, DE_K, DE_L, KC_COMM, KC_DOT, DE_SS, KC_RSFT, //
                                    MEH_PUP, NF_ESC, SY_ENT, SN_SPC, NF_TAB, HYP_PDN),
#endif // WORKMAN_ENABLE

#ifdef COLEMAK_ENABLE
    [_COLMAK_DH] = LAYOUT_split_3x6_3(ALT_TAB, DE_Q, DE_W, DE_F, DE_P, DE_B, DE_J, DE_L, DE_U, DE_Z, DE_ODIA, DE_UDIA,    //
                                      CTL_ESC, DE_A, DE_R, DE_S, DE_T, GUI_G, DE_M, DE_N, DE_E, DE_I, DE_O, DE_ADIA,      //
                                      KC_LSFT, DE_Y, DE_X, DE_C, DE_D, DE_V, DE_K, DE_H, KC_COMM, KC_DOT, DE_SS, KC_RSFT, //
                                      MEH_PUP, NF_ESC, SY_ENT, SN_SPC, NF_TAB, HYP_PDN),
#endif // COLEMAK_ENABLE

    // Symbols and Numbers
    [_SYM_NUM] = LAYOUT_split_3x6_3(_______, DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_0, DE_1, DE_2, DE_4, DE_8, DE_EXLM,                 //
                                    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR, DE_EQL, //
                                    _______, DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_ACUT, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO, _______, //
                                    KC_TRNS, DE_SECT, KC_TRNS, KC_TRNS, DE_CENT, KC_TRNS),
    // Navigation and Function
    [_NAV_FUN] = LAYOUT_split_3x6_3(_______, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN, KC_F10, KC_F1, KC_F2, KC_F4, KC_F8, OSM_ALT,           //
                                    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, OSM_GUI, KC_F11, KC_F12, OSM_SFT, KC_RSFT, OSM_CTL,  //
                                    _______, KC_INS, CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR, KC_PWR, OSM_AGR, OSM_MEH, OSM_HYP, CW_TOGG, CW_TOGG, //
                                    KC_TRNS, LY_ADJ, KC_TRNS, KC_APP, LY_ADJ, KC_TRNS),
    // Mouse and Media Control
    [_MSE_CTL] = LAYOUT_split_3x6_3(_______, KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_ACL2, DE_UDIA, KC_VOLU, XXXXXXX, KC_EJCT, KC_NO,   //
                                    _______, DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE, KC_ACL1, KC_MNXT, KC_VOLD, XXXXXXX, KC_MPRV, KC_NO,  //
                                    _______, KC_BTN4, XXXXXXX, DE_UDIA, DE_ADIA, KC_BTN5, KC_ACL0, KC_MPLY, KC_MUTE, KC_MSTP, KC_RSFT, _______, //
                                    KC_BTN3, KC_BTN2, KC_BTN1, KC_LSFT, KC_BTN3, KC_TRNS),
    // Keyboard adjustments
    [_ADJUST] = LAYOUT_split_3x6_3(_______, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, DF_ASET, DF_ARTS, KC_BRIU, XXXXXXX, EE_CLR, QK_BOOT,  //
                                   _______, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, DF_COLE, DF_QWER, KC_BRID, XXXXXXX, XXXXXXX, EE_CLR,   //
                                   _______, RGB_M_T, RGB_M_X, RGB_M_G, RGB_M_K, RGB_M_SN, DF_WORK, DF_BONE, XXXXXXX, XXXXXXX, KC_LSFT, _______, //
                                   _______, _______, _______, _______, _______, _______)};
