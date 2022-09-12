#pragma once
#include "asetniop.h"

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable all combos except on layer `_ASETNIOP` */
            if (layer_state_is(_ASETNIOP)) {
    return true;
            }
                return false;

}

// Definition of asetniop combos
const uint16_t PROGMEM combo_alpha_b[] = {DE_T, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_bsp[] = {DE_T, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_c[] = {DE_S, DE_T, COMBO_END};
const uint16_t PROGMEM combo_alpha_d[] = {DE_S, DE_E, COMBO_END};
const uint16_t PROGMEM combo_alpha_f[] = {DE_A, DE_T, COMBO_END};
const uint16_t PROGMEM combo_alpha_g[] = {DE_T, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_h[] = {DE_N, DE_I, COMBO_END};
const uint16_t PROGMEM combo_alpha_j[] = {DE_S, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_k[] = {DE_S, DE_I, COMBO_END};
const uint16_t PROGMEM combo_alpha_l[] = {DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_m[] = {DE_N, DE_P, COMBO_END};
const uint16_t PROGMEM combo_alpha_q[] = {DE_A, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_r[] = {DE_E, DE_T, COMBO_END};
/* const uint16_t PROGMEM combo_alpha_ss[] = {DE_S, KEY_DIA, COMBO_END}; */
const uint16_t PROGMEM combo_alpha_tab[] = {DE_A, DE_S, DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_alpha_u[] = {DE_N, DE_O, COMBO_END};
const uint16_t PROGMEM combo_alpha_v[] = {DE_T, DE_I, COMBO_END};
const uint16_t PROGMEM combo_alpha_w[] = {DE_A, DE_S, COMBO_END};
const uint16_t PROGMEM combo_alpha_x[] = {DE_A, DE_E, COMBO_END};
const uint16_t PROGMEM combo_alpha_y[] = {DE_E, DE_N, COMBO_END};
const uint16_t PROGMEM combo_alpha_z[] = {DE_A, DE_I, COMBO_END};
/* const uint16_t PROGMEM combo_cmd_altctl[] = {KEY_ALT, KEY_CTL, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_altctlgui[] = {KEY_ALT, KEY_CTL, KEY_GUI, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_altgui[] = {KEY_ALT, KEY_GUI, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_ctlgui[] = {KEY_CTL, KEY_GUI, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_salt[] = {OSM_SFT, KEY_ALT, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_saltctl[] = {OSM_SFT, KEY_ALT, KEY_CTL, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_saltctlgui[] = {OSM_SFT, KEY_ALT, KEY_CTL, KEY_GUI, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_saltgui[] = {OSM_SFT, KEY_ALT, KEY_GUI, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_sctl[] = {OSM_SFT, KEY_CTL, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_sctlgui[] = {OSM_SFT, KEY_CTL, KEY_GUI, COMBO_END}; */
/* const uint16_t PROGMEM combo_cmd_sgui[] = {OSM_SFT, KEY_GUI, COMBO_END}; */
const uint16_t PROGMEM combo_fn_f11[] = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM combo_fn_f12[] = {KC_F8, KC_F9, COMBO_END};
const uint16_t PROGMEM combo_fn_f5[] = {KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_fn_f6[] = {KC_F7, KC_F8, COMBO_END};
const uint16_t PROGMEM combo_global_enter[] = {KC_SPC, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_mse_btn2[] = {KC_MS_D, KC_BTN1, COMBO_END};
const uint16_t PROGMEM combo_mse_left[] = {KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM combo_mse_pagedown[] = {KC_MS_D, KC_MS_R, COMBO_END};
const uint16_t PROGMEM combo_mse_pageup[] = {KC_MS_U, KC_BTN1, COMBO_END};
const uint16_t PROGMEM combo_nav_left[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM combo_nav_pagedown[] = {KC_DOWN, KC_RGHT, COMBO_END};
const uint16_t PROGMEM combo_nav_pageup[] = {KC_UP, KC_RCTL, COMBO_END};
const uint16_t PROGMEM combo_num_5[] = {DE_3, DE_4, COMBO_END};
const uint16_t PROGMEM combo_num_6[] = {DE_7, DE_8, COMBO_END};
const uint16_t PROGMEM combo_num_bsp[] = {DE_4, DE_0, COMBO_END};
const uint16_t PROGMEM combo_num_tab[] = {DE_1, DE_2, DE_3, DE_4, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_at[] = {DE_I, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_colon[] = {DE_O, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_comma[] = {DE_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_dblquot[] = {DE_E, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_dot[] = {DE_S, DE_O, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_exclamation[] = {DE_I, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_gt[] = {DE_S, DE_O, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_leftcurlybrace[] = {DE_A, DE_O, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_leftparen[] = {DE_A, DE_O, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_lt[] = {DE_E, DE_I, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_minus[] = {DE_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_question[] = {DE_A, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_quot[] = {DE_E, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_rightcurlybrace[] = {DE_S, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_rightparen[] = {DE_S, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_semicolon[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_slash[] = {DE_A, DE_P, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_alpha_underscore[] = {DE_E, DE_O, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_ampersand[] = {DE_7, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_asterisk[] = {DE_8, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_at[] = {DE_8, DE_0, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_backslash[] = {DE_1, DE_8, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_caret[] = {DE_7, DE_8, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_cent[] = {DE_2, DE_3, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_colon[] = {DE_9, DE_0, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_comma[] = {DE_3, DE_8, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_dollar[] = {DE_4, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_dot[] = {DE_2, DE_9, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_equal[] = {DE_4, DE_7, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_euro[] = {DE_2, DE_3, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_exclam[] = {DE_8, DE_0, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_grave[] = {DE_1, DE_7, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_gt[] = {DE_2, DE_9, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_hash[] = {DE_3, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_leftbracket[] = {DE_1, DE_9, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_leftcurlybrace[] = {DE_1, DE_4, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_leftparen[] = {DE_1, DE_9, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_lt[] = {DE_3, DE_8, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_minus[] = {DE_3, DE_9, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_percent[] = {DE_3, DE_4, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_pipe[] = {DE_1, DE_8, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_plus[] = {DE_4, DE_7, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_question[] = {DE_1, DE_0, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_quot[] = {DE_3, DE_0, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_rightbracket[] = {DE_2, DE_0, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_rightcurlybrace[] = {DE_7, DE_0, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_rightparen[] = {DE_2, DE_0, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_semicolon[] = {DE_9, DE_0, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_slash[] = {DE_1, DE_0, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_tilde[] = {DE_1, DE_7, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_symbol_num_underscore[] = {DE_3, DE_9, OSM_SFT, COMBO_END};
const uint16_t PROGMEM combo_xl_base_to_cmnd[] = {DE_S, DE_E, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_xl_base_to_func[] = {DE_A, DE_E, DE_I, DE_P, COMBO_END};
const uint16_t PROGMEM combo_xl_base_to_navi[] = {DE_S, DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_xl_base_to_mous[] = {DE_A, DE_E, DE_T, COMBO_END};
const uint16_t PROGMEM combo_xl_base_to_nums[] = {DE_A, DE_T, DE_N, DE_P, COMBO_END};
const uint16_t PROGMEM combo_xl_base_to_nums_os[] = {DE_N, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_xl_nums_to_base[] = {DE_1, DE_4, DE_7, DE_0, COMBO_END};
const uint16_t PROGMEM combo_xl_nums_to_cmnd[] = {DE_2, DE_3, DE_8, DE_9, COMBO_END};
const uint16_t PROGMEM combo_xl_nums_to_navi[] = {DE_2, DE_3, DE_4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_alpha_b, DE_B),
    COMBO(combo_alpha_bsp, KC_BSPC),
    COMBO(combo_alpha_c, DE_C),
    COMBO(combo_alpha_d, DE_D),
    COMBO(combo_alpha_f, DE_F),
    COMBO(combo_alpha_g, DE_G),
    COMBO(combo_alpha_h, DE_H),
    COMBO(combo_alpha_j, DE_J),
    COMBO(combo_alpha_k, DE_K),
    COMBO(combo_alpha_l, DE_L),
    COMBO(combo_alpha_m, DE_M),
    COMBO(combo_alpha_q, DE_Q),
    COMBO(combo_alpha_r, DE_R),
    COMBO(combo_alpha_ss, DE_SS),
    COMBO(combo_alpha_tab, KC_TAB),
    COMBO(combo_alpha_u, DE_U),
    COMBO(combo_alpha_v, DE_V),
    COMBO(combo_alpha_w, DE_W),
    COMBO(combo_alpha_x, DE_X),
    COMBO(combo_alpha_y, DE_Y),
    COMBO(combo_alpha_z, DE_Z),
    COMBO(combo_cmd_altctl,     OSM(MOD_LALT|MOD_LCTL)),
    COMBO(combo_cmd_altctlgui,  OSM(MOD_LALT|MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_altgui,     OSM(MOD_LALT|MOD_LGUI)),
    COMBO(combo_cmd_ctlgui,     OSM(MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_salt,       OSM(MOD_LSFT|MOD_LALT)),
    COMBO(combo_cmd_saltctl,    OSM(MOD_LSFT|MOD_LALT|MOD_LCTL)),
    COMBO(combo_cmd_saltctlgui, OSM(MOD_LSFT|MOD_LALT|MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_saltgui,    OSM(MOD_LSFT|MOD_LALT|MOD_LGUI)),
    COMBO(combo_cmd_sctl,       OSM(MOD_LSFT|MOD_LCTL)),
    COMBO(combo_cmd_sctlgui,    OSM(MOD_LSFT|MOD_LCTL|MOD_LGUI)),
    COMBO(combo_cmd_sgui,       OSM(MOD_LSFT|MOD_LGUI)),
    COMBO(combo_fn_f11, KC_F11),
    COMBO(combo_fn_f12, KC_F12),
    COMBO(combo_fn_f5, KC_F5),
    COMBO(combo_fn_f6, KC_F6),
    COMBO(combo_global_enter, KC_ENT),
    COMBO(combo_mse_btn2, KC_BTN2),
    COMBO(combo_mse_left, KC_MS_L),
    COMBO(combo_mse_pagedown, KC_WH_D),
    COMBO(combo_mse_pageup, KC_WH_U),
    COMBO(combo_nav_left, KC_LEFT),
    COMBO(combo_nav_pagedown, KC_PGDN),
    COMBO(combo_nav_pageup, KC_PGUP),
    COMBO(combo_num_5, DE_5),
    COMBO(combo_num_6, DE_6),
    COMBO(combo_num_bsp, KC_BSPC),
    COMBO(combo_num_tab, KC_TAB),
    COMBO(combo_symbol_alpha_at, DE_AT),
    COMBO(combo_symbol_alpha_colon, DE_COLN),
    COMBO(combo_symbol_alpha_comma, DE_COMM),
    COMBO(combo_symbol_alpha_dblquot, DE_DQUO),
    COMBO(combo_symbol_alpha_dot, DE_DOT),
    COMBO(combo_symbol_alpha_exclamation, DE_EXLM),
    COMBO(combo_symbol_alpha_gt, DE_RABK),
    COMBO(combo_symbol_alpha_leftcurlybrace, DE_LCBR),
    COMBO(combo_symbol_alpha_leftparen, DE_LPRN),
    COMBO(combo_symbol_alpha_lt, DE_LABK),
    COMBO(combo_symbol_alpha_minus, DE_MINS),
    COMBO(combo_symbol_alpha_question, DE_QUES),
    COMBO(combo_symbol_alpha_quot, DE_QUOT),
    COMBO(combo_symbol_alpha_rightcurlybrace, DE_RCBR),
    COMBO(combo_symbol_alpha_rightparen, DE_RPRN),
    COMBO(combo_symbol_alpha_semicolon, DE_SCLN),
    COMBO(combo_symbol_alpha_slash, DE_SLSH),
    COMBO(combo_symbol_alpha_underscore, DE_UNDS),
    COMBO(combo_symbol_num_ampersand, DE_AMPR),
    COMBO(combo_symbol_num_asterisk, DE_ASTR),
    COMBO(combo_symbol_num_at, DE_AT),
    COMBO(combo_symbol_num_backslash, DE_BSLS),
    COMBO(combo_symbol_num_caret, DE_CIRC),
    COMBO(combo_symbol_num_cent, DE_CENT),
    COMBO(combo_symbol_num_colon, DE_COLN),
    COMBO(combo_symbol_num_comma, DE_COMM),
    COMBO(combo_symbol_num_dollar, DE_DLR),
    COMBO(combo_symbol_num_dot, DE_DOT),
    COMBO(combo_symbol_num_equal, DE_EQL),
    COMBO(combo_symbol_num_euro, DE_EURO),
    COMBO(combo_symbol_num_exclam, DE_EXLM),
    COMBO(combo_symbol_num_grave, DE_GRV),
    COMBO(combo_symbol_num_gt, DE_RABK),
    COMBO(combo_symbol_num_hash, DE_HASH),
    COMBO(combo_symbol_num_leftbracket, DE_LBRC),
    COMBO(combo_symbol_num_leftcurlybrace, DE_LCBR),
    COMBO(combo_symbol_num_leftparen, DE_LPRN),
    COMBO(combo_symbol_num_lt, DE_LABK),
    COMBO(combo_symbol_num_minus, DE_MINS),
    COMBO(combo_symbol_num_percent, DE_PERC),
    COMBO(combo_symbol_num_pipe, DE_PIPE),
    COMBO(combo_symbol_num_plus, DE_PLUS),
    COMBO(combo_symbol_num_question, DE_QUES),
    COMBO(combo_symbol_num_quot, DE_QUOT),
    COMBO(combo_symbol_num_rightbracket, DE_RBRC),
    COMBO(combo_symbol_num_rightcurlybrace, DE_RCBR),
    COMBO(combo_symbol_num_rightparen, DE_RPRN),
    COMBO(combo_symbol_num_semicolon, DE_SCLN),
    COMBO(combo_symbol_num_slash, DE_SLSH),
    COMBO(combo_symbol_num_tilde, DE_TILD),
    COMBO(combo_symbol_num_underscore, DE_UNDS),
    /* COMBO(combo_xl_base_to_cmnd, OSL(_CMND)), */
    /* COMBO(combo_xl_base_to_func, OSL(_FUNC)), */
    /* COMBO(combo_xl_base_to_navi, OSL(_NAVI)), */
    /* COMBO(combo_xl_base_to_mous, OSL(_MOUS)), */
    COMBO(combo_xl_base_to_nums, TO(_AST_NUM)),
    /* COMBO(combo_xl_base_to_nums_os, OSL(_NUMS)), */
    COMBO(combo_xl_nums_to_base, TO(_AST_ALP)),
    /* COMBO(combo_xl_nums_to_cmnd, OSL(_CMND)), */
    /* COMBO(combo_xl_nums_to_navi, OSL(_NAVI)), */
};

