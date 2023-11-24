#include QMK_KEYBOARD_H
#include "keymap_german.h"

// MODs
#define OSM_AGR OSM(MOD_RALT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_MEH MT(MOD_MEH, KC_PGUP)
#define OSM_HYP MT(MOD_HYPR, KC_PGDN)
// HRM
#define ALT_AE MT(MOD_LALT, DE_ADIA)
#define ALT_Q  MT(MOD_LALT, DE_Q)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

// Base layers
#ifdef QWERTZ_ENABLE
#    define QWERTZ DF(_QWERTZ)
#else
#    define QWERTZ KC_NO
#endif // QWERTZ_ENABLE
#ifdef BONE_ENABLE
#    define BONE DF(_BONE)
#else
#    define BONE KC_NO
#endif // BONE_ENABLE
#ifdef WORKMAN_ENABLE
#    define WRKMAN DF(_WORKMAN)
#else
#    define WRKMAN KC_NO
#endif // WORKMAN_ENABLE
#ifdef COLEMAK_ENABLE
#    define COLMAK DF(_COLMAK_DH)
#else
#    define COLMAK KC_NO
#endif // COLEMAK_ENABLE
#ifdef LILYPOND_ENABLE
#    define LILYPND DF(_LILYPOND)
#else
#    define LILYPND KC_NO
#endif // LILYPOND_ENABLE
#ifdef ASETNIOP_ENABLE
#    define ASET DF(_ASETNIOP)
#else
#    define ASET KC_NO
#endif // ASETNIOP_ENABLE
#ifdef ARTSENIO_ENABLE
#    define ARTSEN DF(_ARTSENIO)
#else
#    define ARTSEN KC_NO
#endif // ARTSENIO_ENABLE

// Thumb / layer keys
#define NF_ESC LT(_NAV_FUN, KC_ESC)
#define SY_ENT LT(_SYM_NUM, KC_ENT)
#define NF_TAB LT(_NAV_FUN, KC_TAB)
#define AD_BSP LT(_ADJUST, KC_BSPC)
#define SN_SPC LT(_SYM_NUM, KC_SPC)
#define MC_APP LT(_MSE_CTL, KC_APP)
#define TO_DF DF(0)
#define TO_MA MO(_MSE_CTL)

// cut copy paste
#define CCP_CUT S(KC_DEL)
#define CCP_CPY C(KC_INS)
#define CCP_PST S(KC_INS)

// Linux extended chars
#define DE_F1_2 ALGR(DE_5)    // ½
#define DE_F1_4 ALGR(DE_4)    // ¼
#define DE_NOT ALGR(DE_5)     // ¬
#define DE_CED ALGR(DE_ACUT)  // ¸ cedilla (dead)
#define DE_EURO ALGR(DE_E)    // €
#define DE_ARRL ALGR(DE_Z)    // ← left arrow
#define DE_ARRD ALGR(DE_U)    // ↓ down arrow
#define DE_ARRR ALGR(DE_I)    // → right arrow
#define DE_DIA ALGR(DE_UE)    // ¨ diaresis (dead)
#define DE_LDOT ALGR(DE_J)    // ̣  dot below (dead)
#define DE_HATS ALGR(DE_AE)   // ˇ hatschek (dead)
#define DE_FDQL ALGR(DE_Y)    // » double guillemets left
#define DE_FDQR ALGR(DE_X)    // « double guillemets right
#define DE_CENT ALGR(DE_C)    // ¢
#define DE_DQUL ALGR(DE_V)    // „ double quote left
#define DE_DQUR ALGR(DE_B)    // “ double quote right
#define DE_DQUE ALGR(DE_N)    // “ double quote right (en)
#define DE_CDOT ALGR(DE_COMM) // · center dot
#define DE_HELL ALGR(DE_DOT)  // … horizontal ellipsis
#define DE_EN ALGR(DE_MINS)   // – en dash

#define DE_IEXC S(ALGR(DE_1))    // ̣¡ inverted question mark
#define DE_F1_8 S(ALGR(DE_2))    // ⅛
#define DE_F3_8 S(ALGR(DE_5))    // ⅜
#define DE_F5_8 S(ALGR(DE_6))    // ⅝
#define DE_F7_8 S(ALGR(DE_7))    // ⅞
#define DE_TM S(ALGR(DE_8))      // ™
#define DE_IQUE S(ALGR(DE_SZ))   // ̣¿ inverted question mark
#define DE_OGNK S(ALGR(DE_ACUT)) // ˛ ogonek (dead)
#define DE_REG S(ALGR(DE_R))     // ®
#define DE_ARRU S(ALGR(DE_U))    // ↑ up arrow
#define DE_RING S(ALGR(DE_UE))   // ° ring (dead)
#define DE_MCRN S(ALGR(DE_PLUS)) // ¨ macron
#define DE_HDOT S(ALGR(DE_J))    // ˙ dot above (dead)
#define DE_BRV S(ALGR(DE_HASH))  // ˘ breve (dead)
#define DE_FSQL S(ALGR(DE_Y))    // › single guillemets left
#define DE_FSQR S(ALGR(DE_X))    // ‹ single guillemets right
#define DE_COPY S(ALGR(DE_C))    // ©
#define DE_SQUL S(ALGR(DE_V))    // ‚ single quote left
#define DE_SQUR S(ALGR(DE_B))    // ‘ single quote right
#define DE_SQUE S(ALGR(DE_N))    // ‘ single quote right (en)
#define DE_MULT S(ALGR(DE_COMM)) // × multiplication operator
#define DE_DIV S(ALGR(DE_DOT))   // ÷ division operator
#define DE_EM S(ALGR(DE_MINS))   // — em dash


/// Enumeration of layers
enum userspace_layers {
    // Base layers
#   ifdef QWERTZ_ENABLE
    _QWERTZ,
#   endif // QWERTZ_ENABLE
#   ifdef BONE_ENABLE
    _BONE,
#   endif // BONE_ENABLE
#   ifdef WORKMAN_ENABLE
    _WORKMAN,
#   endif // WORKMAN_ENABLE
#   ifdef COLEMAK_ENABLE
    _COLMAK_DH,
#   endif // COLEMAK_ENABLE
#   ifdef LILYPOND_ENABLE
    _LILYPOND,
#   endif // LILYPOND_ENABLE
#   ifdef ASETNIOP_ENABLE
    _ASETNIOP,    // ASETNIOP layer
#   endif // ASETNIOP_ENABLE
#   ifdef ARTSENIO_ENABLE
    _ARTSENIO,    // ARTSENIO layer
    // Additional layers
    _ARTS_NUM,    // ARTSENIO numbers layer
    _ARTS_SYM,    // ARTSENIO symbols layer
    _ARTS_PAR,    // ARTSENIO parens layer
    _ARTS_NAV,    // ARTSENIO arrows layer
    _ARTS_MSE,    // ARTSENIO mouse layer
#   endif // ARTSENIO_ENABLE
    _SYM_NUM,     // L: Symbols layer,    R: Numbers layer
    _NAV_FUN,     // L: Navigation layer, R: Function keys layer
    _MSE_CTL,     // L: Mouse keys layer, R: Keyboard adjustments
    _ADJUST,      // Media and RGB keys
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │ESC│ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *          ┌────┐                                ┌───┐
      *          │LCTL├───────┐                  ┌─────┤Alt│
      *          └────┤GUI/Bsp├───────┐      ┌───┤TO(1)├───┘
      *               └───────┤ALT/ENT│      │SPC├─────┘
      *                       └───────┘      └───┘
      */
#ifdef QWERTZ_ENABLE
    [_QWERTZ] = LAYOUT_split_3x6_3(
        KC_TAB,  DE_Q, DE_W, DE_E, DE_R, DE_T,                                 DE_Z, DE_U, DE_I, LT(_MSE_CTL,DE_O), DE_P, DE_UDIA,
        CTL_ESC, DE_A, DE_S, GUI_T(DE_D), CTL_T(DE_F), ALT_T(DE_G),            ALT_T(DE_H), CTL_T(DE_J), GUI_T(DE_K), DE_L, DE_ODIA, ALT_AE,
        KC_LSFT, SFT_T(DE_Y), DE_X, DE_C, DE_V, DE_B,                          DE_N, DE_M, KC_COMM, KC_DOT, RSFT_T(DE_SS), KC_RSFT,
      //-----------------------------------------------------------            -----------------------------------------------------------------
                                           OSM_MEH, NF_ESC, SY_ENT,            SN_SPC, NF_TAB, OSM_HYP
    ),
#endif
#ifdef BONE_ENABLE
    [_BONE] = LAYOUT_split_3x6_3(
        KC_TAB,  DE_J, DE_D, DE_U, DE_A, DE_X,                                 DE_P, DE_H, DE_L, LT(_MSE_CTL,DE_M), DE_W, DE_SS,
        CTL_ESC, DE_C, DE_T, GUI_T(DE_I), CTL_T(DE_E), ALT_T(DE_O),            ALT_T(DE_B), CTL_T(DE_N), GUI_T(DE_R), DE_S, DE_G, ALT_Q,
        KC_LSFT, SFT_T(DE_F), DE_V, DE_UDIA, DE_ADIA, DE_ODIA,                 DE_Y, DE_Z, KC_COMM, KC_DOT, RSFT_T(DE_K), KC_RSFT,
      //-----------------------------------------------------------            -----------------------------------------------------------------
                                           OSM_MEH, NF_ESC, SY_ENT,            SN_SPC, NF_TAB, OSM_HYP
    ),
#endif

    [_SYM_NUM] = LAYOUT_split_3x6_3(
        _______, DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,       DE_0,    DE_1,    DE_2,    DE_4,    DE_8,    DE_EXLM,
        _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,       DE_LABK, DE_LPRN, DE_RPRN, DE_MINS, DE_AMPR, DE_EQL,
        _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT,       DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_EURO, _______,
                                   DE_SECT, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, ALGR(DE_C)
    ),
    [_NAV_FUN] = LAYOUT_split_3x6_3(
        _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN,       KC_F10,  KC_F1,   KC_F2,   KC_F4,   KC_F8,   KC_F11,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,        OSM_ALT, OSM_CTL, OSM_GUI, OSM_SFT, KC_RSFT, KC_F12,
        _______, KC_INS,  CCP_CUT, CCP_CPY, CCP_PST, KC_PSCR,       KC_PWR,  OSM_AGR, OSM_MEH, OSM_HYP, CW_TOGG, CW_TOGG,
                               MO(_ADJUST), KC_TRNS, KC_TRNS,       KC_TRNS, KC_APP,  MO(_ADJUST)
    ),
    [_MSE_CTL] = LAYOUT_split_3x6_3(
        _______, KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,       KC_ACL2, DE_UDIA, KC_VOLU, XXXXXXX, KC_EJCT, KC_NO,
        _______, DE_ADIA, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUSE,      KC_ACL1, KC_MNXT, KC_VOLD, XXXXXXX, KC_MPRV, KC_NO,
        _______, KC_BTN4, XXXXXXX, DE_UDIA, DE_ADIA, KC_BTN5,       KC_ACL0, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, _______,
                                   KC_BTN2, KC_BTN1, KC_BTN3,       KC_TRNS, KC_LSFT, KC_BTN3
    ),
    [_ADJUST]  = LAYOUT_split_3x6_3(
        _______, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,
        _______, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,        EE_CLR,  QWERTZ,  COLMAK,  BONE,    LILYPND, KC_NO,
        _______, RGB_M_T, RGB_M_X, RGB_M_G, RGB_M_K, RGB_M_SN,       QK_BOOT, WRKMAN,  ASET,    ARTSEN,  KC_LSFT, _______,
                                   _______, _______, _______,       _______, _______, _______
    )
};
