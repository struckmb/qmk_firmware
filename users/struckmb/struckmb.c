/* Copyright 2021 Batuhan Başerdem
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "struckmb.h"
/* // Language imports */
/* #include <sendstring_german.h> */

/*------------------------*\
|*-----PROCESS RECORD-----*|
\*------------------------*/
/* Process record: custom keycodes to process here
 * Allow also the following codes to hook here as well;
 *  Macro definitions
 *  Audio hooks
 */
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Return after running through all individual hooks
    return
        process_record_keymap(keycode, record)  &&
#       ifdef ENCODER_ENABLE
        process_record_encoder(keycode, record) &&
#       endif // ENCODER_ENABLE
        true;
}

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable all combos except on ASETNIOP layers */
    return get_highest_layer(default_layer_state) == _ASETNIOP;
}

// Definition of asetniop combos
const uint16_t PROGMEM combo_chr_ae[] = {DE_A, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_chr_b[] = {DE_T, DE_N, COMBO_END};
const uint16_t PROGMEM combo_chr_c[] = {DE_S, DE_T, COMBO_END};
const uint16_t PROGMEM combo_chr_d[] = {DE_S, DE_E, COMBO_END};
const uint16_t PROGMEM combo_chr_f[] = {DE_A, DE_T, COMBO_END};
const uint16_t PROGMEM combo_chr_g[] = {DE_T, DE_O, COMBO_END};
const uint16_t PROGMEM combo_chr_h[] = {DE_N, DE_I, COMBO_END};
const uint16_t PROGMEM combo_chr_j[] = {DE_S, DE_N, COMBO_END};
const uint16_t PROGMEM combo_chr_k[] = {DE_S, DE_I, COMBO_END};
const uint16_t PROGMEM combo_chr_l[] = {DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_chr_m[] = {DE_N, DE_P, COMBO_END};
const uint16_t PROGMEM combo_chr_oe[] = {DE_O, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_chr_q[] = {DE_A, DE_N, COMBO_END};
const uint16_t PROGMEM combo_chr_r[] = {DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_chr_ss[] = {DE_S, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_chr_tab[] = {DE_A, DE_S, DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_chr_u[] = {DE_N, DE_O, COMBO_END};
const uint16_t PROGMEM combo_chr_ue[] = {DE_N, DE_O, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_chr_v[] = {DE_T, DE_I, COMBO_END};
const uint16_t PROGMEM combo_chr_w[] = {DE_A, DE_S, COMBO_END};
const uint16_t PROGMEM combo_chr_x[] = {DE_A, DE_E, COMBO_END};
const uint16_t PROGMEM combo_chr_y[] = {DE_E, DE_N, COMBO_END};
const uint16_t PROGMEM combo_chr_z[] = {DE_A, DE_I, COMBO_END};
const uint16_t PROGMEM combo_cmd_bsp[] = {DE_T, DE_P, COMBO_END};
const uint16_t PROGMEM combo_cmd_bsp2[] = {KC_F4, DE_T, COMBO_END};
const uint16_t PROGMEM combo_cmd_caps[] = {KC_ESC, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_cmd_del[] = {KC_F4, DE_S, COMBO_END};
const uint16_t PROGMEM combo_cmd_enter[] = {KC_SPC, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_cmd_enter2[] = {DE_N, DE_I, DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM combo_cmd_esc[] = {KC_LEFT, DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_cmd_ins[] = {DE_2, DE_N, COMBO_END};
const uint16_t PROGMEM combo_cmd_menu[] = {OSM_GUI, OSM_ALT, COMBO_END};
const uint16_t PROGMEM combo_cmd_power[] = {KC_LEFT, KC_RGHT, OSM_CTL, KC_ESC, COMBO_END};
const uint16_t PROGMEM combo_cmd_print[] = {DE_N, KC_ESC, COMBO_END};
const uint16_t PROGMEM combo_fn_f10[] = {KC_F2, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f11[] = {KC_F1, KC_F2, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f12[] = {KC_F4, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f3[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM combo_fn_f5[] = {KC_F1, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f6[] = {KC_F2, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f7[] = {KC_F1, KC_F2, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f9[] = {KC_F1, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_nav_end[] = {KC_RGHT, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_nav_home[] = {KC_LEFT, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_nav_pgdn[] = {KC_DOWN, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_nav_pgup[] = {KC_UP, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_nav_tabNext[] = {KC_UP, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_nav_tabPrev[] = {KC_DOWN, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_num_0[] = {DE_2, DE_8, COMBO_END};
const uint16_t PROGMEM combo_num_3[] = {DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_num_5[] = {DE_1, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_6[] = {DE_2, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_7[] = {DE_1, DE_2, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_9[] = {DE_1, DE_8, COMBO_END};
const uint16_t PROGMEM combo_smb_acut[] = {DE_4, DE_T, COMBO_END};
const uint16_t PROGMEM combo_smb_at[] = {DE_I, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_smb_backslash[] = {KC_F1, DE_T, COMBO_END};
const uint16_t PROGMEM combo_smb_brckl[] = {KC_F4, DE_2, COMBO_END};
const uint16_t PROGMEM combo_smb_brckr[] = {KC_F4, DE_4, COMBO_END};
const uint16_t PROGMEM combo_smb_caret[] = {KC_F1, DE_N, COMBO_END};
const uint16_t PROGMEM combo_smb_cbracel[] = {KC_F4, DE_1, COMBO_END};
const uint16_t PROGMEM combo_smb_cbracer[] = {KC_F4, DE_8, COMBO_END};
const uint16_t PROGMEM combo_smb_cent[] = {KC_F2, DE_N, COMBO_END};
const uint16_t PROGMEM combo_smb_colon[] = {DE_O, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_smb_comma[] = {DE_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_smb_dblquot[] = {DE_E, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_smb_dollar[] = {KC_F8, DE_N, COMBO_END};
const uint16_t PROGMEM combo_smb_dot[] = {DE_S, DE_O, COMBO_END};
const uint16_t PROGMEM combo_smb_equal[] = {KC_F8, DE_1, COMBO_END};
const uint16_t PROGMEM combo_smb_euro[] = {KC_F4, DE_N, COMBO_END};
const uint16_t PROGMEM combo_smb_excl[] = {DE_I, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_grave[] = {DE_2, DE_T, COMBO_END};
const uint16_t PROGMEM combo_smb_gt[] = {KC_F4, DE_2, DE_4, COMBO_END};
const uint16_t PROGMEM combo_smb_hash[] = {DE_4, DE_8, COMBO_END};
const uint16_t PROGMEM combo_smb_lt[] = {KC_F4, DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_smb_minusN[] = {KC_F8, DE_4, COMBO_END};
const uint16_t PROGMEM combo_smb_minus[] = {DE_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_smb_parenl[] = {DE_A, DE_O, COMBO_END};
const uint16_t PROGMEM combo_smb_parenr[] = {DE_S, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_pipe[] = {DE_1, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_plus[] = {KC_F8, DE_2, COMBO_END};
const uint16_t PROGMEM combo_smb_ques[] = {DE_A, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_quot[] = {DE_E, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_scolon[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_slash[] = {KC_F8, DE_A, COMBO_END};
const uint16_t PROGMEM combo_smb_star[] = {KC_F8, DE_8, COMBO_END};
const uint16_t PROGMEM combo_smb_tilde[] = {DE_1, DE_T, COMBO_END};

enum combos_events {
    CHR_AE,
    CHR_B,
    CHR_C,
    CHR_D,
    CHR_F,
    CHR_G,
    CHR_H,
    CHR_J,
    CHR_K,
    CHR_L,
    CHR_M,
    CHR_OE,
    CHR_Q,
    CHR_R,
    CHR_SS,
    CHR_TAB,
    CHR_U,
    CHR_UE,
    CHR_V,
    CHR_W,
    CHR_X,
    CHR_Y,
    CHR_Z,
    CMD_BSP,
    CMD_BSP2,
    CMD_CAPS,
    CMD_DEL,
    CMD_ENTER,
    CMD_ENTER2,
    CMD_ESC,
    CMD_INS,
    CMD_MENU,
    CMD_POWER,
    CMD_PRINT,
    FN_F10,
    FN_F11,
    FN_F12,
    FN_F3,
    FN_F5,
    FN_F6,
    FN_F7,
    FN_F9,
    NAV_END,
    NAV_HOME,
    NAV_PGDN,
    NAV_PGUP,
    NAV_TABNEXT,
    NAV_TABPREV,
    NUM_0,
    NUM_3,
    NUM_5,
    NUM_6,
    NUM_7,
    NUM_9,
    SMB_ACUT,
    SMB_AT,
    SMB_BACKSLASH,
    SMB_BRCKL,
    SMB_BRCKR,
    SMB_CARET,
    SMB_CBRACEL,
    SMB_CBRACER,
    SMB_CENT,
    SMB_COLON,
    SMB_COMMA,
    SMB_DBLQUOT,
    SMB_DOLLAR,
    SMB_DOT,
    SMB_EQUAL,
    SMB_EURO,
    SMB_EXCL,
    SMB_GRAVE,
    SMB_GT,
    SMB_HASH,
    SMB_LT,
    SMB_MINUSN,
    SMB_MINUS,
    SMB_PARENL,
    SMB_PARENR,
    SMB_PIPE,
    SMB_PLUS,
    SMB_QUES,
    SMB_QUOT,
    SMB_SCOLON,
    SMB_SLASH,
    SMB_STAR,
    SMB_TILDE,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

combo_t key_combos[] = {
    [CHR_AE] = COMBO(combo_chr_ae, DE_AE),
    [CHR_B] = COMBO(combo_chr_b, DE_B),
    [CHR_C] = COMBO(combo_chr_c, DE_C),
    [CHR_D] = COMBO(combo_chr_d, DE_D),
    [CHR_F] = COMBO(combo_chr_f, DE_F),
    [CHR_G] = COMBO(combo_chr_g, DE_G),
    [CHR_H] = COMBO(combo_chr_h, DE_H),
    [CHR_J] = COMBO(combo_chr_j, DE_J),
    [CHR_K] = COMBO(combo_chr_k, DE_K),
    [CHR_L] = COMBO(combo_chr_l, DE_L),
    [CHR_M] = COMBO(combo_chr_m, DE_M),
    [CHR_OE] = COMBO(combo_chr_oe, DE_OE),
    [CHR_Q] = COMBO(combo_chr_q, DE_Q),
    [CHR_R] = COMBO(combo_chr_r, DE_R),
    [CHR_SS] = COMBO(combo_chr_ss, DE_SS),
    [CHR_TAB] = COMBO(combo_chr_tab, KC_TAB),
    [CHR_U] = COMBO(combo_chr_u, DE_U),
    [CHR_UE] = COMBO(combo_chr_ue, DE_UE),
    [CHR_V] = COMBO(combo_chr_v, DE_V),
    [CHR_W] = COMBO(combo_chr_w, DE_W),
    [CHR_X] = COMBO(combo_chr_x, DE_X),
    [CHR_Y] = COMBO(combo_chr_y, DE_Y),
    [CHR_Z] = COMBO(combo_chr_z, DE_Z),
    [CMD_BSP] = COMBO(combo_cmd_bsp, KC_BSPC),
    [CMD_BSP2] = COMBO(combo_cmd_bsp2, KC_BSPC),
    [CMD_CAPS] = COMBO(combo_cmd_caps, KC_CAPS),
    [CMD_DEL] = COMBO(combo_cmd_del, KC_DEL),
    [CMD_ENTER] = COMBO(combo_cmd_enter, KC_ENT),
    [CMD_ENTER2] = COMBO(combo_cmd_enter2, KC_ENT),
    [CMD_ESC] = COMBO(combo_cmd_esc, KC_ESC),
    [CMD_INS] = COMBO(combo_cmd_ins, KC_INS),
    [CMD_MENU] = COMBO(combo_cmd_menu, KC_APP),
    [CMD_POWER] = COMBO(combo_cmd_power, KC_PWR),
    [CMD_PRINT] = COMBO(combo_cmd_print, KC_PSCR),
    [FN_F10] = COMBO(combo_fn_f10, KC_F10),
    [FN_F11] = COMBO(combo_fn_f11, KC_F11),
    [FN_F12] = COMBO(combo_fn_f12, KC_F12),
    [FN_F3] = COMBO(combo_fn_f3, KC_F3),
    [FN_F5] = COMBO(combo_fn_f5, KC_F5),
    [FN_F6] = COMBO(combo_fn_f6, KC_F6),
    [FN_F7] = COMBO(combo_fn_f7, KC_F7),
    [FN_F9] = COMBO(combo_fn_f9, KC_F9),
    [NAV_END] = COMBO(combo_nav_end, KC_END),
    [NAV_HOME] = COMBO(combo_nav_home, KC_HOME),
    [NAV_PGDN] = COMBO(combo_nav_pgdn, KC_PGDN),
    [NAV_PGUP] = COMBO(combo_nav_pgup, KC_PGUP),
    [NAV_TABNEXT] = COMBO(combo_nav_tabNext, C(KC_TAB)),
    [NAV_TABPREV] = COMBO(combo_nav_tabPrev, S(C(KC_TAB))),
    [NUM_0] = COMBO(combo_num_0, DE_0),
    [NUM_3] = COMBO(combo_num_3, DE_3),
    [NUM_5] = COMBO(combo_num_5, DE_5),
    [NUM_6] = COMBO(combo_num_6, DE_6),
    [NUM_7] = COMBO(combo_num_7, DE_7),
    [NUM_9] = COMBO(combo_num_9, DE_9),
    [SMB_ACUT] = COMBO(combo_smb_acut, DE_ACUT),
    [SMB_AT] = COMBO(combo_smb_at, DE_AT),
    [SMB_BACKSLASH] = COMBO(combo_smb_backslash, DE_BSLS),
    [SMB_BRCKL] = COMBO(combo_smb_brckl, DE_LBRC),
    [SMB_BRCKR] = COMBO(combo_smb_brckr, DE_RBRC),
    [SMB_CARET] = COMBO(combo_smb_caret, DE_CIRC),
    [SMB_CBRACEL] = COMBO(combo_smb_cbracel, DE_LCBR),
    [SMB_CBRACER] = COMBO(combo_smb_cbracer, DE_RCBR),
    [SMB_CENT] = COMBO(combo_smb_cent, DE_CENT),
    [SMB_COLON] = COMBO(combo_smb_colon, DE_COLN),
    [SMB_COMMA] = COMBO(combo_smb_comma, DE_COMM),
    [SMB_DBLQUOT] = COMBO(combo_smb_dblquot, DE_DQUO),
    [SMB_DOLLAR] = COMBO(combo_smb_dollar, DE_DLR),
    [SMB_DOT] = COMBO(combo_smb_dot, DE_DOT),
    [SMB_EQUAL] = COMBO(combo_smb_equal, DE_EQL),
    [SMB_EURO] = COMBO(combo_smb_euro, DE_EURO),
    [SMB_EXCL] = COMBO(combo_smb_excl, DE_EXLM),
    [SMB_GRAVE] = COMBO(combo_smb_grave, DE_GRV),
    [SMB_GT] = COMBO(combo_smb_gt, DE_RABK),
    [SMB_HASH] = COMBO(combo_smb_hash, DE_HASH),
    [SMB_LT] = COMBO(combo_smb_lt, DE_LABK),
    [SMB_MINUSN] = COMBO(combo_smb_minusN, DE_MINS),
    [SMB_MINUS] = COMBO(combo_smb_minus, DE_MINS),
    [SMB_PARENL] = COMBO(combo_smb_parenl, DE_LPRN),
    [SMB_PARENR] = COMBO(combo_smb_parenr, DE_RPRN),
    [SMB_PIPE] = COMBO(combo_smb_pipe, DE_PIPE),
    [SMB_PLUS] = COMBO(combo_smb_plus, DE_PLUS),
    [SMB_QUES] = COMBO(combo_smb_ques, DE_QUES),
    [SMB_QUOT] = COMBO(combo_smb_quot, DE_QUOT),
    [SMB_SCOLON] = COMBO(combo_smb_scolon, DE_SCLN),
    [SMB_SLASH] = COMBO(combo_smb_slash, DE_SLSH),
    [SMB_STAR] = COMBO(combo_smb_star, DE_ASTR),
    [SMB_TILDE] = COMBO(combo_smb_tilde, DE_TILD),
};
#endif // COMBO_ENABLE

