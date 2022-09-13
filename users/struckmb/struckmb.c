/* Copyright 2021 Batuhan Başerdem
 * <baserdem.batuhan@gmail.com> @bbaserdem
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
// Language imports
#include <sendstring_german.h>
// Need memcpy and memcmp from string.h along with transfer stuff
#ifdef SPLIT_KEYBOARD
#include "transactions.h"
#include <string.h>
#endif // SPLIT_KEYBOARD

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
#       ifdef AUDIO_ENABLE
        process_record_audio(keycode, record)   &&
#       endif // AUDIO_ENABLE
#       ifdef ENCODER_ENABLE
        process_record_encoder(keycode, record) &&
#       endif // ENCODER_ENABLE
        /* process_record_macro(keycode, record) && */
        true;
}

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable all combos except on ASETNIOP layers */
    switch (get_highest_layer(default_layer_state)) {
        case _ASETNIOP:
            return true;
        default:
            return false;
    }
}

enum combos_events {
    chr_ae,
    chr_b,
    chr_bsp,
    chr_c,
    chr_d,
    chr_f,
    chr_g,
    chr_h,
    chr_j,
    chr_k,
    chr_l,
    chr_m,
    chr_oe,
    chr_q,
    chr_r,
    chr_ss,
    chr_tab,
    chr_u,
    chr_ue,
    chr_v,
    chr_w,
    chr_x,
    chr_y,
    chr_z,
    /* cmd_altctl, */
    /* cmd_altctlgui, */
    /* cmd_altgui, */
    /* cmd_ctlgui, */
    cmd_enter,
    /* cmd_salt, */
    /* cmd_saltctl, */
    /* cmd_saltctlgui, */
    /* cmd_saltgui, */
    /* cmd_sctl, */
    /* cmd_sctlgui, */
    /* cmd_sgui, */
    fn_f3,
    fn_f5,
    fn_f6,
    fn_f7,
    fn_f9,
    fn_f10,
    fn_f11,
    fn_f12,
    /* mse_btn2, */
    /* mse_left, */
    /* mse_pagedown, */
    /* mse_pageup, */
    /* nav_left, */
    /* nav_pagedown, */
    /* nav_pageup, */
    num_3,
    num_5,
    num_6,
    num_7,
    num_9,
    num_0,
    /* num_bsp, */
    /* num_tab, */
    symbol_chr_at,
    symbol_chr_colon,
    symbol_chr_comma,
    symbol_chr_dblquot,
    symbol_chr_dot,
    symbol_chr_excl,
    symbol_chr_gt,
    symbol_chr_lcbrace,
    symbol_chr_lparen,
    symbol_chr_lt,
    symbol_chr_minus,
    symbol_chr_ques,
    symbol_chr_quot,
    symbol_chr_rcbrace,
    symbol_chr_rparen,
    symbol_chr_scolon,
    symbol_chr_slash,
    symbol_chr_uscore,
    /* symbol_num_ampersand, */
    /* symbol_num_asterisk, */
    /* symbol_num_at, */
    /* symbol_num_backslash, */
    /* symbol_num_caret, */
    /* symbol_num_cent, */
    /* symbol_num_colon, */
    /* symbol_num_comma, */
    /* symbol_num_dollar, */
    /* symbol_num_dot, */
    /* symbol_num_equal, */
    /* symbol_num_euro, */
    /* symbol_num_exclam, */
    /* symbol_num_grave, */
    /* symbol_num_gt, */
    /* symbol_num_hash, */
    /* symbol_num_leftbracket, */
    /* symbol_num_leftcurlybrace, */
    /* symbol_num_leftparen, */
    /* symbol_num_lt, */
    /* symbol_num_minus, */
    /* symbol_num_percent, */
    /* symbol_num_pipe, */
    /* symbol_num_plus, */
    /* symbol_num_question, */
    /* symbol_num_quot, */
    /* symbol_num_rightbracket, */
    /* symbol_num_rightcurlybrace, */
    /* symbol_num_rightparen, */
    /* symbol_num_semicolon, */
    /* symbol_num_slash, */
    /* symbol_num_tilde, */
    /* symbol_num_underscore, */
    //
    /* xl_base_to_cmnd, */
    /* xl_base_to_func, */
    /* xl_base_to_navi, */
    /* xl_base_to_mous, */
    /* xl_base_to_nums, */
    /* xl_base_to_nums_os, */
    /* xl_nums_to_base, */
    /* xl_nums_to_cmnd, */
    /* xl_nums_to_navi, */
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

// Definition of asetniop combos
const uint16_t PROGMEM combo_chr_ae[] = {DE_A, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_chr_b[] = {DE_T, DE_N, COMBO_END};
const uint16_t PROGMEM combo_chr_bsp[] = {DE_T, DE_P, COMBO_END};
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
const uint16_t PROGMEM combo_cmd_altctl[] = {OSM_ALT, OSM_CTL, COMBO_END};
const uint16_t PROGMEM combo_cmd_altctlgui[] = {OSM_ALT, OSM_CTL, OSM_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_altgui[] = {OSM_ALT, OSM_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_ctlgui[] = {OSM_CTL, OSM_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_enter[] = {KC_SPC, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_cmd_salt[] = {OSM_SFT, OSM_ALT, COMBO_END};
const uint16_t PROGMEM combo_cmd_saltctl[] = {OSM_SFT, OSM_ALT, OSM_CTL, COMBO_END};
const uint16_t PROGMEM combo_cmd_saltctlgui[] = {OSM_SFT, OSM_ALT, OSM_CTL, OSM_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_saltgui[] = {OSM_SFT, OSM_ALT, OSM_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_sctl[] = {OSM_SFT, OSM_CTL, COMBO_END};
const uint16_t PROGMEM combo_cmd_sctlgui[] = {OSM_SFT, OSM_CTL, OSM_GUI, COMBO_END};
const uint16_t PROGMEM combo_cmd_sgui[] = {OSM_SFT, OSM_GUI, COMBO_END};
const uint16_t PROGMEM combo_fn_f3[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM combo_fn_f5[] = {KC_F1, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f6[] = {KC_F2, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f7[] = {KC_F1, KC_F2, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f9[] = {KC_F1, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f10[] = {KC_F2, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f11[] = {KC_F1, KC_F2, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f12[] = {KC_F4, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_mse_btn2[] = {KC_MS_D, KC_BTN1, COMBO_END};
const uint16_t PROGMEM combo_mse_left[] = {KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM combo_mse_pagedown[] = {KC_MS_D, KC_MS_R, COMBO_END};
const uint16_t PROGMEM combo_mse_pageup[] = {KC_MS_U, KC_BTN1, COMBO_END};
const uint16_t PROGMEM combo_nav_left[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM combo_nav_pagedown[] = {KC_DOWN, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_nav_pageup[] = {KC_UP, KC_RCTL, COMBO_END};

const uint16_t PROGMEM combo_num_3[] = {DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_num_5[] = {DE_1, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_6[] = {DE_2, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_7[] = {DE_1, DE_2, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_9[] = {DE_1, DE_8, COMBO_END};
const uint16_t PROGMEM combo_num_0[] = {DE_2, DE_8, COMBO_END};

const uint16_t PROGMEM combo_symbol_chr_at[] = {DE_I, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_colon[] = {DE_O, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_comma[] = {DE_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_dblquot[] = {DE_E, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_dot[] = {DE_S, DE_O, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_excl[] = {DE_I, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_gt[] = {DE_S, DE_O, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_lcbrace[] = {DE_A, DE_O, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_lparen[] = {DE_A, DE_O, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_lt[] = {DE_E, DE_I, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_minus[] = {DE_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_ques[] = {DE_A, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_quot[] = {DE_E, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_rcbrace[] = {DE_S, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_rparen[] = {DE_S, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_scolon[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_slash[] = {DE_A, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_chr_uscore[] = {DE_E, DE_O, OSM_SFT, COMBO_END};
/* const uint16_t PROGMEM combo_symbol_num_ampersand[] = {DE_7, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_asterisk[] = {DE_8, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_at[] = {DE_8, DE_0, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_backslash[] = {DE_1, DE_8, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_caret[] = {DE_7, DE_8, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_cent[] = {DE_2, DE_3, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_colon[] = {DE_9, DE_0, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_comma[] = {DE_3, DE_8, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_dollar[] = {DE_4, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_dot[] = {DE_2, DE_9, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_equal[] = {DE_4, DE_7, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_euro[] = {DE_2, DE_3, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_exclam[] = {DE_8, DE_0, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_grave[] = {DE_1, DE_7, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_gt[] = {DE_2, DE_9, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_hash[] = {DE_3, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_leftbracket[] = {DE_1, DE_9, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_leftcurlybrace[] = {DE_1, DE_4, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_leftparen[] = {DE_1, DE_9, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_lt[] = {DE_3, DE_8, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_minus[] = {DE_3, DE_9, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_percent[] = {DE_3, DE_4, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_pipe[] = {DE_1, DE_8, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_plus[] = {DE_4, DE_7, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_question[] = {DE_1, DE_0, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_quot[] = {DE_3, DE_0, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_rightbracket[] = {DE_2, DE_0, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_rightcurlybrace[] = {DE_7, DE_0, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_rightparen[] = {DE_2, DE_0, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_semicolon[] = {DE_9, DE_0, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_slash[] = {DE_1, DE_0, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_tilde[] = {DE_1, DE_7, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_symbol_num_underscore[] = {DE_3, DE_9, OSM_SFT, COMBO_END}; */
/* const uint16_t PROGMEM combo_xl_base_to_cmnd[] = {DE_S, DE_E, DE_I, DE_O, COMBO_END}; */
/* const uint16_t PROGMEM combo_xl_base_to_func[] = {DE_A, DE_E, DE_I, DE_P, COMBO_END}; */
/* const uint16_t PROGMEM combo_xl_base_to_navi[] = {DE_S, DE_E, DE_T, COMBO_END}; */
/* const uint16_t PROGMEM combo_xl_base_to_mous[] = {DE_A, DE_E, DE_T, COMBO_END}; */
const uint16_t PROGMEM combo_xl_base_to_nums[] = {DE_A, DE_T, DE_N, DE_P, COMBO_END};
/* const uint16_t PROGMEM combo_xl_base_to_nums_os[] = {DE_N, DE_I, DE_O, COMBO_END}; */
const uint16_t PROGMEM combo_xl_nums_to_base[] = {DE_1, DE_4, DE_7, DE_0, COMBO_END};
/* const uint16_t PROGMEM combo_xl_nums_to_cmnd[] = {DE_2, DE_3, DE_8, DE_9, COMBO_END}; */
/* const uint16_t PROGMEM combo_xl_nums_to_navi[] = {DE_2, DE_3, DE_4, COMBO_END}; */

combo_t key_combos[] = {
    [chr_ae] = COMBO(combo_chr_ae, DE_AE),
    [chr_b] = COMBO(combo_chr_b, DE_B),
    [chr_bsp] = COMBO(combo_chr_bsp, KC_BSPC),
    [chr_c] = COMBO(combo_chr_c, DE_C),
    [chr_d] = COMBO(combo_chr_d, DE_D),
    [chr_f] = COMBO(combo_chr_f, DE_F),
    [chr_g] = COMBO(combo_chr_g, DE_G),
    [chr_h] = COMBO(combo_chr_h, DE_H),
    [chr_j] = COMBO(combo_chr_j, DE_J),
    [chr_k] = COMBO(combo_chr_k, DE_K),
    [chr_l] = COMBO(combo_chr_l, DE_L),
    [chr_m] = COMBO(combo_chr_m, DE_M),
    [chr_oe] = COMBO(combo_chr_oe, DE_OE),
    [chr_q] = COMBO(combo_chr_q, DE_Q),
    [chr_r] = COMBO(combo_chr_r, DE_R),
    [chr_ss] = COMBO(combo_chr_ss, DE_SS),
    [chr_tab] = COMBO(combo_chr_tab, KC_TAB),
    [chr_u] = COMBO(combo_chr_u, DE_U),
    [chr_ue] = COMBO(combo_chr_ue, DE_UE),
    [chr_v] = COMBO(combo_chr_v, DE_V),
    [chr_w] = COMBO(combo_chr_w, DE_W),
    [chr_x] = COMBO(combo_chr_x, DE_X),
    [chr_y] = COMBO(combo_chr_y, DE_Y),
    [chr_z] = COMBO(combo_chr_z, DE_Z),
    /* [cmd_altctl] = COMBO(combo_cmd_altctl,     OSM(MOD_LALT|MOD_LCTL)), */
    /* [cmd_altctlgui] = COMBO(combo_cmd_altctlgui,  OSM(MOD_LALT|MOD_LCTL|MOD_LGUI)), */
    /* [cmd_altgui] = COMBO(combo_cmd_altgui,     OSM(MOD_LALT|MOD_LGUI)), */
    /* [cmd_ctlgui] = COMBO(combo_cmd_ctlgui,     OSM(MOD_LCTL|MOD_LGUI)), */
    [cmd_enter] = COMBO(combo_cmd_enter, KC_ENT),
    /* [cmd_salt] = COMBO(combo_cmd_salt,       OSM(MOD_LSFT|MOD_LALT)), */
    /* [cmd_saltctl] = COMBO(combo_cmd_saltctl,    OSM(MOD_LSFT|MOD_LALT|MOD_LCTL)), */
    /* [cmd_saltctlgui] = COMBO(combo_cmd_saltctlgui, OSM(MOD_LSFT|MOD_LALT|MOD_LCTL|MOD_LGUI)), */
    /* [cmd_saltgui] = COMBO(combo_cmd_saltgui,    OSM(MOD_LSFT|MOD_LALT|MOD_LGUI)), */
    /* [cmd_sctl] = COMBO(combo_cmd_sctl,       OSM(MOD_LSFT|MOD_LCTL)), */
    /* [cmd_sctlgui] = COMBO(combo_cmd_sctlgui,    OSM(MOD_LSFT|MOD_LCTL|MOD_LGUI)), */
    /* [cmd_sgui] = COMBO(combo_cmd_sgui,       OSM(MOD_LSFT|MOD_LGUI)), */
    [fn_f3] = COMBO(combo_fn_f3, KC_F3),
    [fn_f5] = COMBO(combo_fn_f5, KC_F5),
    [fn_f6] = COMBO(combo_fn_f6, KC_F6),
    [fn_f7] = COMBO(combo_fn_f7, KC_F7),
    [fn_f9] = COMBO(combo_fn_f9, KC_F9),
    [fn_f10] = COMBO(combo_fn_f10, KC_F10),
    [fn_f11] = COMBO(combo_fn_f11, KC_F11),
    [fn_f12] = COMBO(combo_fn_f12, KC_F12),
    /* [mse_btn2] = COMBO(combo_mse_btn2, KC_BTN2), */
    /* [mse_left] = COMBO(combo_mse_left, KC_MS_L), */
    /* [mse_pagedown] = COMBO(combo_mse_pagedown, KC_WH_D), */
    /* [mse_pageup] = COMBO(combo_mse_pageup, KC_WH_U), */
    /* [nav_left] = COMBO(combo_nav_left, KC_LEFT), */
    /* [nav_pagedown] = COMBO(combo_nav_pagedown, KC_PGDN), */
    /* [nav_pageup] = COMBO(combo_nav_pageup, KC_PGUP), */
    [num_3] = COMBO(combo_num_3, DE_3),
    [num_5] = COMBO(combo_num_5, DE_5),
    [num_6] = COMBO(combo_num_6, DE_6),
    [num_7] = COMBO(combo_num_7, DE_7),
    [num_9] = COMBO(combo_num_9, DE_9),
    [num_0] = COMBO(combo_num_0, DE_0),
    /* [num_bsp] = COMBO(combo_num_bsp, KC_BSPC), */
    /* [num_tab] = COMBO(combo_num_tab, KC_TAB), */
    [symbol_chr_at] = COMBO(combo_symbol_chr_at, DE_AT),
    [symbol_chr_colon] = COMBO(combo_symbol_chr_colon, DE_COLN),
    [symbol_chr_comma] = COMBO(combo_symbol_chr_comma, DE_COMM),
    [symbol_chr_dblquot] = COMBO(combo_symbol_chr_dblquot, DE_DQUO),
    [symbol_chr_dot] = COMBO(combo_symbol_chr_dot, DE_DOT),
    [symbol_chr_excl] = COMBO(combo_symbol_chr_excl, DE_EXLM),
    [symbol_chr_gt] = COMBO(combo_symbol_chr_gt, DE_RABK),
    [symbol_chr_lcbrace] = COMBO(combo_symbol_chr_lcbrace, DE_LCBR),
    [symbol_chr_lparen] = COMBO(combo_symbol_chr_lparen, DE_LPRN),
    [symbol_chr_lt] = COMBO(combo_symbol_chr_lt, DE_LABK),
    [symbol_chr_minus] = COMBO(combo_symbol_chr_minus, DE_MINS),
    [symbol_chr_ques] = COMBO(combo_symbol_chr_ques, DE_QUES),
    [symbol_chr_quot] = COMBO(combo_symbol_chr_quot, DE_QUOT),
    [symbol_chr_rcbrace] = COMBO(combo_symbol_chr_rcbrace, DE_RCBR),
    [symbol_chr_rparen] = COMBO(combo_symbol_chr_rparen, DE_RPRN),
    [symbol_chr_scolon] = COMBO(combo_symbol_chr_scolon, DE_SCLN),
    [symbol_chr_slash] = COMBO(combo_symbol_chr_slash, DE_SLSH),
    [symbol_chr_uscore] = COMBO(combo_symbol_chr_uscore, DE_UNDS),
    /* [symbol_num_ampersand] = COMBO(combo_symbol_num_ampersand, DE_AMPR), */
    /* [symbol_num_asterisk] = COMBO(combo_symbol_num_asterisk, DE_ASTR), */
    /* [symbol_num_at] = COMBO(combo_symbol_num_at, DE_AT), */
    /* [symbol_num_backslash] = COMBO(combo_symbol_num_backslash, DE_BSLS), */
    /* [symbol_num_caret] = COMBO(combo_symbol_num_caret, DE_CIRC), */
    /* [symbol_num_cent] = COMBO(combo_symbol_num_cent, DE_CENT), */
    /* [symbol_num_colon] = COMBO(combo_symbol_num_colon, DE_COLN), */
    /* [symbol_num_comma] = COMBO(combo_symbol_num_comma, DE_COMM), */
    /* [symbol_num_dollar] = COMBO(combo_symbol_num_dollar, DE_DLR), */
    /* [symbol_num_dot] = COMBO(combo_symbol_num_dot, DE_DOT), */
    /* [symbol_num_equal] = COMBO(combo_symbol_num_equal, DE_EQL), */
    /* [symbol_num_euro] = COMBO(combo_symbol_num_euro, DE_EURO), */
    /* [symbol_num_exclam] = COMBO(combo_symbol_num_exclam, DE_EXLM), */
    /* [symbol_num_grave] = COMBO(combo_symbol_num_grave, DE_GRV), */
    /* [symbol_num_gt] = COMBO(combo_symbol_num_gt, DE_RABK), */
    /* [symbol_num_hash] = COMBO(combo_symbol_num_hash, DE_HASH), */
    /* [symbol_num_leftbracket] = COMBO(combo_symbol_num_leftbracket, DE_LBRC), */
    /* [symbol_num_leftcurlybrace] = COMBO(combo_symbol_num_leftcurlybrace, DE_LCBR), */
    /* [symbol_num_leftparen] = COMBO(combo_symbol_num_leftparen, DE_LPRN), */
    /* [symbol_num_lt] = COMBO(combo_symbol_num_lt, DE_LABK), */
    /* [symbol_num_minus] = COMBO(combo_symbol_num_minus, DE_MINS), */
    /* [symbol_num_percent] = COMBO(combo_symbol_num_percent, DE_PERC), */
    /* [symbol_num_pipe] = COMBO(combo_symbol_num_pipe, DE_PIPE), */
    /* [symbol_num_plus] = COMBO(combo_symbol_num_plus, DE_PLUS), */
    /* [symbol_num_question] = COMBO(combo_symbol_num_question, DE_QUES), */
    /* [symbol_num_quot] = COMBO(combo_symbol_num_quot, DE_QUOT), */
    /* [symbol_num_rightbracket] = COMBO(combo_symbol_num_rightbracket, DE_RBRC), */
    /* [symbol_num_rightcurlybrace] = COMBO(combo_symbol_num_rightcurlybrace, DE_RCBR), */
    /* [symbol_num_rightparen] = COMBO(combo_symbol_num_rightparen, DE_RPRN), */
    /* [symbol_num_semicolon] = COMBO(combo_symbol_num_semicolon, DE_SCLN), */
    /* [symbol_num_slash] = COMBO(combo_symbol_num_slash, DE_SLSH), */
    /* [symbol_num_tilde] = COMBO(combo_symbol_num_tilde, DE_TILD), */
    /* [symbol_num_underscore] = COMBO(combo_symbol_num_underscore, DE_UNDS), */
    /* [xl_base_to_cmnd] = COMBO(combo_xl_base_to_cmnd, OSL(_CMND)), */
    /* [xl_base_to_func] = COMBO(combo_xl_base_to_func, OSL(_FUNC)), */
    /* [xl_base_to_navi] = COMBO(combo_xl_base_to_mous, OSL(_MOUS)), */
    /* [xl_base_to_mous] = COMBO(combo_xl_base_to_navi, OSL(_NAVI)), */
    /* [xl_base_to_nums] = COMBO(combo_xl_base_to_nums, TG(_ASETNIOP_NUM)), */
    /* [xl_base_to_nums_os] = COMBO(combo_xl_base_to_nums_os, OSL(_NUMS)), */
    /* [xl_nums_to_base] = COMBO(combo_xl_nums_to_base, TG(_ASETNIOP_NUM)), */
    /* [xl_nums_to_cmnd] = COMBO(combo_xl_nums_to_cmnd, OSL(_CMND)), */
    /* [xl_nums_to_navi] = COMBO(combo_xl_nums_to_navi, OSL(_NAVI)), */
};
#endif // COMBO_ENABLE

