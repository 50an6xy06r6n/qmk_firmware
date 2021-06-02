#pragma once

#include "quantum.h"

#define LAYOUT( \
	     K01,                                                        K41, \
	K10, K11, K02, K03, K04, K05, K16,      K56, K45, K44, K43, K42, K51, K50, \
	K20, K21, K12, K13, K14, K15, K26,      K66, K55, K54, K53, K52, K61, K60, \
	K30, K31, K22, K23, K24, K25,                K65, K64, K63, K62, K71, K70, \
	          K32, K33, K34, K35, K36,      K76, K75, K74, K73, K72       \
) \
{ \
	{  KC_NO, K01,   K02,   K03,   K04,   K05,   KC_NO}, \
	{  K10,   K11,   K12,   K13,   K14,   K15,   K16  }, \
	{  K20,   K21,   K22,   K23,   K24,   K25,   K26  }, \
	{  K30,   K31,   K32,   K33,   K34,   K35,   K36  }, \
	{  KC_NO, K41,   K42,   K43,   K44,   K45,   KC_NO}, \
	{  K50,   K51,   K52,   K53,   K54,   K55,   K56  }, \
	{  K60,   K61,   K62,   K63,   K64,   K65,   K66  }, \
	{  K70,   K71,   K72,   K73,   K74,   K75,   K76  }, \
}
