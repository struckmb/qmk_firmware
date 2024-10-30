#include "keymap_german.h"

// one shot shortcuts
#define OSM_LS OSM(MOD_LSFT)
#define OSM_LC OSM(MOD_LCTL)
#define OSM_LA OSM(MOD_LALT)
#define OSM_RA OSM(MOD_RALT)
#define OSM_LG OSM(MOD_LGUI)
#define OSM_SC OSM(MOD_LSFT | MOD_LCTL)
#define OSM_SA OSM(MOD_LSFT | MOD_LALT)
#define OSM_SG OSM(MOD_LSFT | MOD_LGUI)
#define OSM_CA OSM(MOD_LCTL | MOD_LALT)
#define OSM_CG OSM(MOD_LCTL | MOD_LGUI)
#define OSM_AG OSM(MOD_LALT | MOD_LGUI)
#define OSM_MEH OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)
#define OSM_SCG OSM(MOD_LSFT | MOD_LCTL | MOD_LGUI)
#define OSM_SAG OSM(MOD_LSFT | MOD_LALT | MOD_LGUI)
#define OSM_CAG OSM(MOD_LCTL | MOD_LALT | MOD_LGUI)

#define ALT_BSP LALT_T(KC_BSPC)
#define ALT_DEL LALT_T(KC_DEL)
#define ALT_SZ MT(MOD_LALT, DE_SS)
#define ALT_UE LALT_T(DE_UDIA)
#define CTL_AE RCTL_T(DE_ADIA)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_Q MT(MOD_LCTL, DE_Q)
#define GUI_ENT RGUI_T(KC_ENT)
#define GUI_LT LGUI_T(DE_LABK)
#define CTL_DOT LCTL_T(KC_DOT)
#define GUI_COM LGUI_T(KC_COMM)
// some shortcuts
#define CP_CUT S(KC_DEL)
#define CP_COPY C(KC_INS)
#define CP_PSTE S(KC_INS)
#define BRI_UP KC_BRIU
#define BRI_DN KC_BRID

// Linux extended chars
#define DE_SUP1 ALGR(DE_1)    // ¹
#define DE_F1_4 ALGR(DE_4)    // ¼
#define DE_F1_2 ALGR(DE_5)    // ½
#define DE_NOT ALGR(DE_6)     // ¬ not
#define DE_CEDL ALGR(DE_ACUT) // ¸ cedilla (dead)
#define DE_EURO ALGR(DE_E)    // €
#define DE_PILC ALGR(DE_R)    // ¶
#define DE_ARRL ALGR(DE_Z)    // ← left arrow
#define DE_ARRD ALGR(DE_U)    // ↓ down arrow
#define DE_ARRR ALGR(DE_I)    // → right arrow
#define DE_DACU ALGR(DE_ODIA) // ˝ double acut (dead)
#define DE_DIAE ALGR(DE_UDIA) // ¨ diaresis (dead)
#define DE_LDOT ALGR(DE_J)    // ̣  dot below (dead)
#define DE_CARN ALGR(DE_ADIA) // ˇ caron (dead)
#define DE_RDAQ ALGR(DE_Y)    // » double guillemets left
#define DE_LDAQ ALGR(DE_X)    // « double guillemets right
#define DE_CENT ALGR(DE_C)    // ¢
#define DE_DLQU ALGR(DE_V)    // „ double quote left
#define DE_LDQU ALGR(DE_B)    // “ double quote
#define DE_RDQU ALGR(DE_N)    // ” double quote right (en)
#define DE_MDOT ALGR(DE_COMM) // · center dot
#define DE_ELLP ALGR(DE_DOT)  // … horizontal ellipsis
#define DE_NDSH ALGR(DE_MINS) // – en dash

#define DE_IEXL S(ALGR(DE_1))    // ̣¡ inverted exclamation mark
#define DE_F1_8 S(ALGR(DE_2))    // ⅛
#define DE_PND S(ALGR(DE_3))     // £
#define DE_F3_8 S(ALGR(DE_5))    // ⅜
#define DE_F5_8 S(ALGR(DE_6))    // ⅝
#define DE_F7_8 S(ALGR(DE_7))    // ⅞
#define DE_TM S(ALGR(DE_8))      // ™
#define DE_PLMN S(ALGR(DE_9))    // ±
#define DE_IQUE S(ALGR(DE_SS))   // ̣¿ inverted question mark
#define DE_OGON S(ALGR(DE_ACUT)) // ˛ ogonek (dead)
#define DE_OMEG S(ALGR(DE_Q))    // Ω
#define DE_REGD S(ALGR(DE_R))    // ®
#define DE_YEN S(ALGR(DE_Z))     // ¥ Yen
#define DE_ARRU S(ALGR(DE_U))    // ↑ up arrow
#define DE_OSTR S(ALGR(DE_O))    // Ø
#define DE_RNGA S(ALGR(DE_UDIA)) // ° ring (dead)
#define DE_MACR S(ALGR(DE_PLUS)) // ¯ macron
#define DE_FORD S(ALGR(DE_F))    // ª
#define DE_DOTA S(ALGR(DE_J))    // ˙ dot above (dead)
#define DE_BREV S(ALGR(DE_HASH)) // ˘ breve (dead)
#define DE_RSAQ S(ALGR(DE_Y))    // › single guillemets right
#define DE_LSAQ S(ALGR(DE_X))    // ‹ single guillemets left
#define DE_COPY S(ALGR(DE_C))    // ©
#define DE_SLQU S(ALGR(DE_V))    // ‚ single quote left
#define DE_LSQU S(ALGR(DE_B))    // ‘ single quote
#define DE_SQUE S(ALGR(DE_N))    // ’ single quote right (en)
#define DE_MULT S(ALGR(DE_COMM)) // × multiplication operator
#define DE_DIV S(ALGR(DE_DOT))   // ÷ division operator
#define DE_MDSH S(ALGR(DE_MINS)) // — em dash
