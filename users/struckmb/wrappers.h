#pragma once
#include "struckmb.h"
#include "keycodes.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

// clang-format off
// 3 rows, 5 columns, 2 encoders, 3 thumbs (draculad)
#define LAYOUT_3x5_2_3_base( \
    K00, K01, K02, K03, K04,   K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14,   K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24,   K25, K26, K27, K28, K29, \
              K32, K33, K34,   K35, K36, K37 \
  ) \
  LAYOUT_wrapper( \
      K00,        K01, K02,        K03,        K04,            K05,        K06,        K07,        LT(_MSE_CTL,K08), K09,         \
      K10,        K11, GUI_T(K12), CTL_T(K13), ALT_T(K14),     ALT_T(K15), CTL_T(K16), GUI_T(K17), K18,              K19,         \
      SFT_T(K20), K21, K22,        K23,        K24,            K25,        K26,        K27,        K28,              RSFT_T(K29), \
                                               KC_MUTE,        TG(_ADJUST), \
                       K32,        K33,        K34,            K35,        K36,        K37 \
    )
#define LAYOUT_3x5_2_3_layer( \
    K00, K01, K02, K03, K04,   K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14,   K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24,   K25, K26, K27, K28, K29, \
              K32, K33, K34,   K35, K36, K37 \
  ) \
  LAYOUT_wrapper( \
      K00, K01, K02, K03, K04,   K05, K06, K07, K08, K09, \
      K10, K11, K12, K13, K14,   K15, K16, K17, K18, K19, \
      K20, K21, K22, K23, K24,   K25, K26, K27, K28, K29, \
                     KC_MUTE,    TG(_ADJUST), \
                K32, K33, K34,   K35, K36, K37 \
    )

// 3 rows, 6 columns, 7 thumbs (kyria)
#define LAYOUT_3x6_7_base( \
    K00, K01, K02, K03, K04, K05,   K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,   K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,   K26, K27, K28, K29, K2A, K2B, \
         K31, K32, K33, K34, K35,   K36, K37, K38, K39, K3A \
  ) \
  LAYOUT_wrapper( \
      K00,        K01,        K02, K03,        K04,        K05,                                    K06,        K07,        K08,        LT(_MSE_CTL,K09), K0A,         K0B,        \
      CTL_T(K10), K11,        K12, GUI_T(K13), CTL_T(K14), ALT_T(K15),                             ALT_T(K16), CTL_T(K17), GUI_T(K18), K19,              K1A,         ALT_T(K1B), \
      K20,        SFT_T(K21), K22, K23,        K24,        K25, KC_NO, KC_NO,      KC_NO, CW_TOGG, K26,        K27,        K28,        K29,              RSFT_T(K2A), K2B,        \
                                    K31,        K32,        K33, K34,   K35,        K36,   K37,     K38, K39,        K3A \
    )
#define LAYOUT_3x6_7_layer( \
    K00, K01, K02, K03, K04, K05,   K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,   K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,   K26, K27, K28, K29, K2A, K2B, \
                   K33, K34, K35,   K36, K37, K38 \
  ) \
  LAYOUT_wrapper( \
      K00, K01, K02, K03, K04, K05,                                  K06, K07, K08, K09, K0A, K0B, \
      K10, K11, K12, K13, K14, K15,                                  K16, K17, K18, K19, K1A, K1B, \
      K20, K21, K22, K23, K24, K25, KC_NO, KC_NO,      KC_NO, KC_NO, K26, K27, K28, K29, K2A, K2B, \
                 KC_TRNS, KC_TRNS, K33, K34, K35,      K36, K37, K38, KC_TRNS, KC_TRNS \
    )

#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
// clang-format on
