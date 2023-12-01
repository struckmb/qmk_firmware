#include "bs.h"
#include "keycodes.h"
#include "quantum_keycodes.h"

/*
 * The `LAYOUT_*_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

#define KC_NO_NO______ KC_NO, KC_NO
#define KC_NO_NO_NO___ KC_NO_NO______, KC_NO
#define KC_NO_NO_NO_NO KC_NO_NO_NO___, KC_NO
#define BASE_THUMB_ROW KC_NO_NO_NO___, MEH_PUP, NF_ESC, SY_ENT, MC_APP, AD_BSP, SN_SPC, NF_TAB, OSM_HYP, KC_NO_NO_NO___
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#ifdef QWERTZ_ENABLE
    [_QWERTZ] = LAYOUT_wrapper(KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, /*     */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,                 //
                               ALT_TAB, DE_Q, DE_W, DE_E, DE_R, DE_T, KC_NO_NO______, DE_Z, DE_U, DE_I, DE_O, DE_P, ALT_UE,        //
                               CTL_ESC, DE_A, DE_S, DE_D, DE_F, DE_G, KC_NO_NO______, DE_H, DE_J, DE_K, DE_L, DE_ODIA, CTL_AE,     //
                               KC_LSFT, DE_Y, DE_X, DE_C, DE_V, DE_B, KC_NO_NO_NO_NO, DE_N, DE_M, KC_COMM, KC_DOT, DE_SS, KC_RSFT, //
                               BASE_THUMB_ROW),
#endif // QWERTZ_ENABLE
#ifdef BONE_ENABLE
    [_BONE] = LAYOUT_wrapper(KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, /*     */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,                         //
                             ALT_TAB, DE_J, DE_D, DE_U, DE_A, DE_X, KC_NO_NO______, DE_P, DE_H, DE_L, DE_M, DE_W, ALT_SS,                //
                             CTL_ESC, DE_C, DE_T, DE_I, DE_E, DE_O, KC_NO_NO______, DE_B, DE_N, DE_R, DE_S, DE_G, CTL_Q,                 //
                             KC_LSFT, DE_F, DE_V, DE_UDIA, DE_ADIA, DE_ODIA, KC_NO_NO_NO_NO, DE_Y, DE_Z, KC_COMM, KC_DOT, DE_K, KC_RSFT, //
                             BASE_THUMB_ROW),
#endif // BONE_ENABLE
#ifdef WORKMAN_ENABLE
    [_WORKMAN] = LAYOUT_wrapper(KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, /*     */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,                 //
                                ALT_TAB, DE_Q, DE_D, DE_R, DE_W, DE_B, KC_NO_NO______, DE_J, DE_F, DE_U, DE_P, DE_ODIA, ALT_UE,     //
                                CTL_ESC, DE_A, DE_S, DE_H, DE_T, DE_G, KC_NO_NO______, DE_Z, DE_N, DE_E, DE_O, DE_I, CTL_AE,        //
                                KC_LSFT, DE_Y, DE_X, DE_M, DE_C, DE_V, KC_NO_NO_NO_NO, DE_K, DE_L, KC_COMM, KC_DOT, DE_SS, KC_RSFT, //
                                BASE_THUMB_ROW),
#endif // WORKMAN_ENABLE
#ifdef COLEMAK_ENABLE
    [_COLMAK_DH] = LAYOUT_wrapper(KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, /*     */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,                 //
                                  ALT_TAB, DE_Q, DE_W, DE_F, DE_P, DE_B, KC_NO_NO______, DE_J, DE_L, DE_U, DE_Z, DE_ODIA, ALT_UE,     //
                                  CTL_ESC, DE_A, DE_R, DE_S, DE_T, DE_G, KC_NO_NO______, DE_M, DE_N, DE_E, DE_I, DE_O, CTL_AE,        //
                                  KC_LSFT, DE_Y, DE_X, DE_C, DE_D, DE_V, KC_NO_NO_NO_NO, DE_K, DE_H, KC_COMM, KC_DOT, DE_SS, KC_RSFT, //
                                  BASE_THUMB_ROW),
#endif // COLEMAK_ENABLE

    [_SYM_NUM] = LAYOUT_wrapper(KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, /*                         */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,                    //
                                _______, DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, KC_NO_NO______, DE_0, DE_1, DE_2, DE_4, DE_8, DE_EXLM,                 //
                                _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, KC_NO_NO______, DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR, DE_EQL, //
                                _______, DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_ACUT, KC_NO_NO_NO_NO, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO, _______, //
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_SECT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ALGR(DE_C), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_NAV_FUN] = LAYOUT_wrapper(KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*                   */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12,                                    //
                        _______, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN, KC_NO_NO______, KC_F10, KC_F1, KC_F2, KC_F4, KC_F8, KC_F11,            //
                        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_NO_NO______, OSM_ALT, OSM_CTL, OSM_GUI, OSM_SFT, KC_RSFT, KC_F12, //
                        _______, KC_INS, CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR, KC_NO_NO_NO_NO, KC_PWR, OSM_AGR, OSM_MEH, OSM_HYP, CW_TOGG, CW_TOGG, //
                        KC_NO_NO_NO_NO, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, MO(_ADJUST), KC_NO_NO_NO_NO),
    // [_MSE_CTL] = LAYOUT_wrapper(KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*                         */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12 //
    //                     ),
    // [_ADJUST]  = LAYOUT_wrapper(KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /*                         */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12 //
    //                     )
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// #    ifdef QWERTZ_ENABLE
//     [_QWERTZ] = LAYOUT_redox_hrm_wrapper(_____________________NUMBER_L0____________________6_, _____________________NUMBER_R0____________________6_, //
//                                          _____________________QWERTZ_L1____________________6_, _____________________QWERTZ_R1____________________6_, //
//                                          _____________________QWERTZ_L2____________________6_, _____________________QWERTZ_R2____________________6_, //
//                                          _____________________QWERTZ_L3____________________6_, _____________________QWERTZ_R3____________________6_, //
//                                          ________________________________________THUMB_5_5____________________________________10_),
// #    endif // QWERTZ_ENABLE
// #    ifdef BONE_ENABLE
//     [_BONE] = LAYOUT_redox_hrm_wrapper(_____________________NUMBER_L0____________________6_, _____________________NUMBER_R0____________________6_, //
//                                        _______________________BONE_L1____________________6_, _______________________BONE_R1____________________6_, //
//                                        _______________________BONE_L2____________________6_, _______________________BONE_R2____________________6_, _______________________BONE_L3____________________6_, _______________________BONE_R3____________________6_, ________________________________________THUMB_5_5____________________________________10_),
// #    endif // BONE_ENABLE
// #    ifdef WORKMAN_ENABLE
//     [_WORKMAN] = LAYOUT_redox_hrm_wrapper(_____________________NUMBER_L0____________________6_, _____________________NUMBER_R0____________________6_, //
//                                           ____________________WORKMAN_L1____________________6_, ____________________WORKMAN_R1____________________6_, //
//                                           ____________________WORKMAN_L2____________________6_, ____________________WORKMAN_R2____________________6_, ____________________WORKMAN_L3____________________6_, ____________________WORKMAN_R3____________________6_, ________________________________________THUMB_5_5____________________________________10_),
// #    endif // WORKMAN_ENABLE
// #    ifdef COLEMAK_ENABLE
//     [_COLMAK_DH] = LAYOUT_redox_hrm_wrapper(_____________________NUMBER_L0____________________6_, _____________________NUMBER_R0____________________6_, //
//                                             ___________________COLEMAK_DH_L1__________________6_, ___________________COLEMAK_DH_R1__________________6_, //
//                                             ___________________COLEMAK_DH_L2__________________6_, ___________________COLEMAK_DH_R2__________________6_, ___________________COLEMAK_DH_L3__________________6_, ___________________COLEMAK_DH_R3__________________6_, ________________________________________THUMB_5_5____________________________________10_),
// #    endif // COLEMAK_ENABLE
//     [_SYM_NUM] = LAYOUT_redox_wrapper(_____________________NUMBER_L0____________________6_, _____________________NUMBER_R0____________________6_, //
//                                       _____________________SYMBOLS_L1___________________6_, _____________________SYMBOLS_R1___________________6_,
//                                       _____________________SYMBOLS_L2___________________6_, _____________________SYMBOLS_R2___________________6_,
//                                       _____________________SYMBOLS_L3___________________6_, _____________________SYMBOLS_R3___________________6_,
//                                       _____________________SYMBOLS_TB___________________6_),
//     [_NAV_FUN] = LAYOUT_redox_wrapper(______________________FUNC_L0_____________________6_, ______________________FUNC_R0_____________________6_, //
//                                       _______________NAVIGATION_L1______________________6_, _________________FUNCTION_R1______________________6_, _______________NAVIGATION_L2______________________6_, _________________FUNCTION_R2______________________6_, _______________NAVIGATION_L3______________________6_, _________________FUNCTION_R3______________________6_, _____________NAVIGATION_AND_FUNCTION_TB___________6_),
//     [_MSE_CTL] = LAYOUT_redox_wrapper(______________________FUNC_L0_____________________6_, ______________________FUNC_R0_____________________6_, //
//                                       ______________________MOUSE_L1____________________6_, ______________________MOUSE_R1____________________6_, ______________________MOUSE_L2____________________6_, ______________________MOUSE_R2____________________6_, ______________________MOUSE_L3____________________6_, ______________________MOUSE_R3____________________6_, ______________________MOUSE_TB____________________6_),
//     [_ADJUST]  = LAYOUT_redox_wrapper(______________________FUNC_L0_____________________6_, ______________________FUNC_R0_____________________6_, //
//                                       ____________________CONFIG_L1_____________________6_, ____________________CONFIG_R1_____________________6_, ____________________CONFIG_L2_____________________6_, ____________________CONFIG_R2_____________________6_, ____________________CONFIG_L3_____________________6_, ____________________CONFIG_R3_____________________6_, ____________________CONFIG_TB_____________________6_),
// };
