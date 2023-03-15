#pragma once
#include "struckmb.h"
#include "keycodes.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
/* Re-pass though to allow templates to be used */
#define LAYOUT_kyria_hrm_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)
#define LAYOUT_kyria_wrapper(...)           LAYOUT_kyria_layer(__VA_ARGS__)

/*
 * The `LAYOUT_kyria_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */
#define LAYOUT_kyria_base( \
    K00, K01, K02, K03, K04, K05,   K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,   K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,   K26, K27, K28, K29, K2A, K2B, \
         K31, K32, K33, K34, K35,   K36, K37, K38, K39, K3A \
  ) \
  LAYOUT_wrapper( \
      K01, K01,        K02, K03,        K04,        K05,                                    K06,        K07,        K08,        K09, K0A,              K0B, \
      K10, K11,        K12, GUI_T(K13), CTL_T(K14), ALT_T(K15),                             ALT_T(K16), CTL_T(K17), GUI_T(K18), K19, LT(_MSE_CTL,K1A), K1B, \
      K20, SFT_T(K21), K22, K23,        K24,        K25, KC_NO, KC_NO,      KC_NO, CW_TOGG, K26,        K27,        K28,        K29, RSFT_T(K2A),      K2B, \
                            K31,        K32,        K33, K34,   K35,        K36,   K37,     K38, K39,        K3A \
    )
#define LAYOUT_kyria_layer( \
    K00, K01, K02, K03, K04, K05,   K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,   K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,   K26, K27, K28, K29, K2A, K2B, \
                   K33, K34, K35,   K36, K37, K38 \
  ) \
  LAYOUT_wrapper( \
      K01, K01, K02, K03, K04, K05,                                  K06, K07, K08, K09, K0A, K0B, \
      K10, K11, K12, K13, K14, K15,                                  K16, K17, K18, K19, K1A, K1B, \
      K20, K21, K22, K23, K24, K25, KC_NO, KC_NO,      KC_NO, KC_NO, K26, K27, K28, K29, K2A, K2B, \
                 KC_TRNS, KC_TRNS, K33, K34, K35,      K36, K37, K38, KC_TRNS, KC_TRNS \
    )

// clang-format on
