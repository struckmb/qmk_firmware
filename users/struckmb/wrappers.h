#pragma once
#include "struckmb.h"
#include "keycodes.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
// clang-format on
