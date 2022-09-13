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
    }
    return false;
}

// Definition of asetniop combos
/* const uint16_t PROGMEM combo_mse_btn2[] = {KC_MS_D, KC_BTN1, COMBO_END}; */
/* const uint16_t PROGMEM combo_mse_left[] = {KC_MS_D, KC_MS_U, COMBO_END}; */
/* const uint16_t PROGMEM combo_mse_pgdn[] = {KC_MS_D, KC_MS_R, COMBO_END}; */
/* const uint16_t PROGMEM combo_mse_pgup[] = {KC_MS_U, KC_BTN1, COMBO_END}; */
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
const uint16_t PROGMEM combo_cmd_del[] = {KC_F4, DE_S, COMBO_END};
const uint16_t PROGMEM combo_cmd_enter[] = {KC_SPC, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_fn_f10[] = {KC_F2, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f11[] = {KC_F1, KC_F2, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f12[] = {KC_F4, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_fn_f3[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM combo_fn_f5[] = {KC_F1, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f6[] = {KC_F2, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f7[] = {KC_F1, KC_F2, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f9[] = {KC_F1, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_nav_pgdn[] = {KC_DOWN, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_nav_pgup[] = {KC_UP, KC_LEFT, COMBO_END};
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
const uint16_t PROGMEM combo_smb_gt[] = {KC_F4, DE_4, DE_8, COMBO_END};
const uint16_t PROGMEM combo_smb_hash[] = {DE_4, DE_8, COMBO_END};
const uint16_t PROGMEM combo_smb_lt[] = {KC_F4, DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_smb_minusN[] = {KC_F8, DE_4, COMBO_END};
const uint16_t PROGMEM combo_smb_minus[] = {DE_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_smb_parenl[] = {DE_A, DE_O, COMBO_END};
const uint16_t PROGMEM combo_smb_parenr[] = {DE_S, DE_P,COMBO_END};
const uint16_t PROGMEM combo_smb_pipe[] = {DE_1, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_plus[] = {KC_F8, DE_2, COMBO_END};
const uint16_t PROGMEM combo_smb_ques[] = {DE_A, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_quot[] = {DE_E, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_scolon[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM combo_smb_slash[] = {KC_F8, DE_A, COMBO_END};
const uint16_t PROGMEM combo_smb_star[] = {KC_F8, DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_smb_tilde[] = {DE_1, DE_T, COMBO_END};

enum combos_events {
    /* mse_btn2, */
    /* mse_left, */
    /* mse_pgdn, */
    /* mse_pgup, */
    chr_ae,
    chr_b,
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
    cmd_bsp,
    cmd_bsp2,
    cmd_del,
    cmd_enter,
    fn_f10,
    fn_f11,
    fn_f12,
    fn_f3,
    fn_f5,
    fn_f6,
    fn_f7,
    fn_f9,
    nav_pgdn,
    nav_pgup,
    num_0,
    num_3,
    num_5,
    num_6,
    num_7,
    num_9,
    smb_acut,
    smb_at,
    smb_backslash,
    smb_brckl,
    smb_brckr,
    smb_caret,
    smb_cbracel,
    smb_cbracer,
    smb_cent,
    smb_colon,
    smb_comma,
    smb_dblquot,
    smb_dollar,
    smb_dot,
    smb_equal,
    smb_euro,
    smb_excl,
    smb_grave,
    smb_gt,
    smb_hash,
    smb_lt,
    smb_minusN,
    smb_minus,
    smb_parenl,
    smb_parenr,
    smb_pipe,
    smb_plus,
    smb_ques,
    smb_quot,
    smb_scolon,
    smb_slash,
    smb_star,
    smb_tilde,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

combo_t key_combos[] = {
    /* [mse_btn2] = COMBO(combo_mse_btn2, KC_BTN2), */
    /* [mse_left] = COMBO(combo_mse_left, KC_MS_L), */
    /* [mse_pgdn] = COMBO(combo_mse_pgdn, KC_WH_D), */
    /* [mse_pgup] = COMBO(combo_mse_pgup, KC_WH_U), */
    [chr_ae] = COMBO(combo_chr_ae, DE_AE),
    [chr_b] = COMBO(combo_chr_b, DE_B),
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
    [cmd_bsp] = COMBO(combo_cmd_bsp, KC_BSPC),
    [cmd_bsp2] = COMBO(combo_cmd_bsp2, KC_BSPC),
    [cmd_del] = COMBO(combo_cmd_del, KC_DEL),
    [cmd_enter] = COMBO(combo_cmd_enter, KC_ENT),
    [fn_f10] = COMBO(combo_fn_f10, KC_F10),
    [fn_f11] = COMBO(combo_fn_f11, KC_F11),
    [fn_f12] = COMBO(combo_fn_f12, KC_F12),
    [fn_f3] = COMBO(combo_fn_f3, KC_F3),
    [fn_f5] = COMBO(combo_fn_f5, KC_F5),
    [fn_f6] = COMBO(combo_fn_f6, KC_F6),
    [fn_f7] = COMBO(combo_fn_f7, KC_F7),
    [fn_f9] = COMBO(combo_fn_f9, KC_F9),
    [nav_pgdn] = COMBO(combo_nav_pgdn, KC_PGDN),
    [nav_pgup] = COMBO(combo_nav_pgup, KC_PGUP),
    [num_0] = COMBO(combo_num_0, DE_0),
    [num_3] = COMBO(combo_num_3, DE_3),
    [num_5] = COMBO(combo_num_5, DE_5),
    [num_6] = COMBO(combo_num_6, DE_6),
    [num_7] = COMBO(combo_num_7, DE_7),
    [num_9] = COMBO(combo_num_9, DE_9),
    [smb_acut] = COMBO(combo_smb_acut, DE_ACUT),
    [smb_at] = COMBO(combo_smb_at, DE_AT),
    [smb_backslash] = COMBO(combo_smb_backslash, DE_BSLS),
    [smb_brckl] = COMBO(combo_smb_brckl, DE_LBRC),
    [smb_brckr] = COMBO(combo_smb_brckr, DE_RBRC),
    [smb_caret] = COMBO(combo_smb_caret, DE_CIRC),
    [smb_cbracel] = COMBO(combo_smb_cbracel, DE_LCBR),
    [smb_cbracer] = COMBO(combo_smb_cbracer, DE_RCBR),
    [smb_cent] = COMBO(combo_smb_cent, DE_CENT),
    [smb_colon] = COMBO(combo_smb_colon, DE_COLN),
    [smb_comma] = COMBO(combo_smb_comma, DE_COMM),
    [smb_dblquot] = COMBO(combo_smb_dblquot, DE_DQUO),
    [smb_dollar] = COMBO(combo_smb_dollar, DE_DLR),
    [smb_dot] = COMBO(combo_smb_dot, DE_DOT),
    [smb_equal] = COMBO(combo_smb_equal, DE_EQL),
    [smb_euro] = COMBO(combo_smb_euro, DE_EURO),
    [smb_excl] = COMBO(combo_smb_excl, DE_EXLM),
    [smb_grave] = COMBO(combo_smb_grave, DE_GRV),
    [smb_gt] = COMBO(combo_smb_gt, DE_RABK),
    [smb_hash] = COMBO(combo_smb_hash, DE_HASH),
    [smb_lt] = COMBO(combo_smb_lt, DE_LABK),
    [smb_minusN] = COMBO(combo_smb_minusN, DE_MINS),
    [smb_minus] = COMBO(combo_smb_minus, DE_MINS),
    [smb_parenl] = COMBO(combo_smb_parenl, DE_LPRN),
    [smb_parenr] = COMBO(combo_smb_parenr, DE_RPRN),
    [smb_pipe] = COMBO(combo_smb_pipe, DE_PIPE),
    [smb_plus] = COMBO(combo_smb_plus, DE_PLUS),
    [smb_ques] = COMBO(combo_smb_ques, DE_QUES),
    [smb_quot] = COMBO(combo_smb_quot, DE_QUOT),
    [smb_scolon] = COMBO(combo_smb_scolon, DE_SCLN),
    [smb_slash] = COMBO(combo_smb_slash, DE_SLSH),
    [smb_star] = COMBO(combo_smb_star, DE_ASTR),
    [smb_tilde] = COMBO(combo_smb_tilde, DE_TILD),
};
#endif // COMBO_ENABLE

