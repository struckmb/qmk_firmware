#include "keymap_german.h"

// MODs
#define OSM_AGR OSM(MOD_RALT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_HPR OSM(MOD_HYPR)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_SFT OSM(MOD_LSFT)
// HRM
#define ALT_AE   MT(MOD_LALT, DE_ADIA)
#define ALT_Q    MT(MOD_LALT, DE_Q)
#define ALT_V    MT(MOD_LALT, DE_V)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_F    MT(MOD_LCTL, DE_F)
#define CTL_J    MT(MOD_LCTL, DE_J)
#define GUI_D    MT(MOD_LGUI, DE_D)
#define GUI_K    MT(MOD_LGUI, DE_K)
#define SFT_Y    MT(MOD_LSFT, DE_Y)
#define SFT_SS   MT(MOD_LSFT, DE_SS)
#define SFT_ENT  MT(MOD_RSFT, KC_ENT)
// Thumb layer keys
#define MA_ESC LT(_MSE_ADJ,KC_ESC)
#define SY_ENT LT(_SYM_NUM,KC_ENT)
#define NF_TAB LT(_NAV_FUN,KC_TAB)
#define KB_BSP LT(_ADJUST,KC_BSPC)
#define SN_SPC LT(_SYM_NUM,KC_SPC)
#define NF_APP LT(_NAV_FUN,KC_APP)

// cut copy paste
#define CCP_CUT S(KC_DEL)
#define CCP_CPY C(KC_INS)
#define CCP_PST S(KC_INS)

// Linux extended chars
#define DE_F1_2 ALGR(DE_5)       // ½
#define DE_F1_4 ALGR(DE_4)       // ¼
#define DE_NOT  ALGR(DE_5)       // ¬
#define DE_CED  ALGR(DE_ACUT)    // ¸ cedilla (dead)
#define DE_EURO ALGR(DE_E)       // €
#define DE_ARRL ALGR(DE_Z)       // ← left arrow
#define DE_ARRD ALGR(DE_U)       // ↓ down arrow
#define DE_ARRR ALGR(DE_I)       // → right arrow
#define DE_DIA  ALGR(DE_UE)      // ¨ diaresis (dead)
#define DE_LDOT ALGR(DE_J)       // ̣  dot below (dead)
#define DE_HATS ALGR(DE_AE)      // ˇ hatschek (dead)
#define DE_FDQL ALGR(DE_Y)       // » double guillemets left
#define DE_FDQR ALGR(DE_X)       // « double guillemets right
#define DE_CENT ALGR(DE_C)       // ¢
#define DE_DQUL ALGR(DE_V)       // „ double quote left
#define DE_DQUR ALGR(DE_B)       // “ double quote right
#define DE_DQUE ALGR(DE_N)       // “ double quote right (en)
#define DE_CDOT ALGR(DE_COMM)    // · center dot
#define DE_HELL ALGR(DE_DOT)     // … horizontal ellipsis
#define DE_EN   ALGR(DE_MINS)    // – en dash

#define DE_IEXC S(ALGR(DE_1))    // ̣¡ inverted question mark
#define DE_F1_8 S(ALGR(DE_2))    // ⅛
#define DE_F3_8 S(ALGR(DE_5))    // ⅜
#define DE_F5_8 S(ALGR(DE_6))    // ⅝
#define DE_F7_8 S(ALGR(DE_7))    // ⅞
#define DE_TM   S(ALGR(DE_8))    // ™
#define DE_IQUE S(ALGR(DE_SZ))   // ̣¿ inverted question mark
#define DE_OGNK S(ALGR(DE_ACUT)) // ˛ ogonek (dead)
#define DE_REG  S(ALGR(DE_R))    // ®
#define DE_ARRU S(ALGR(DE_U))    // ↑ up arrow
#define DE_RING S(ALGR(DE_UE))   // ° ring (dead)
#define DE_MCRN S(ALGR(DE_PLUS)) // ¨ macron
#define DE_HDOT S(ALGR(DE_J))    // ˙ dot above (dead)
#define DE_BRV  S(ALGR(DE_HASH)) // ˘ breve (dead)
#define DE_FSQL S(ALGR(DE_Y))    // › single guillemets left
#define DE_FSQR S(ALGR(DE_X))    // ‹ single guillemets right
#define DE_COPY S(ALGR(DE_C))    // ©
#define DE_SQUL S(ALGR(DE_V))    // ‚ single quote left
#define DE_SQUR S(ALGR(DE_B))    // ‘ single quote right
#define DE_SQUE S(ALGR(DE_N))    // ‘ single quote right (en)
#define DE_MULT S(ALGR(DE_COMM)) // × multiplication operator
#define DE_DIV  S(ALGR(DE_DOT))  // ÷ division operator
#define DE_EM   S(ALGR(DE_MINS)) // — em dash

