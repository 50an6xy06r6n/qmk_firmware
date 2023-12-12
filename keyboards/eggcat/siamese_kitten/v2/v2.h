#pragma once

#include "quantum.h"

#ifdef POINTING_DEVICE_DRIVER_cirque_pinnacle_i2c
#include "pointing_device.h"
#endif

#ifdef PS2_DRIVER_INTERRUPT
#include "ps2_mouse.h"
#endif

#define LAYOUT( \
	L00, L01,                                                        R41, R40, \
	L10, L11, L02, L03, L04, L05, L16,      R56, R45, R44, R43, R42, R51, R50, \
	L20, L21, L12, L13, L14, L15, L26,      R66, R55, R54, R53, R52, R61, R60, \
	L30, L31, L22, L23, L24, L25,                R65, R64, R63, R62, R71, R70, \
	          L32, L33, L34, L35, L36,      R76, R75, R74, R73, R72       \
) \
{ \
	{  L00,   L01,   L02,   L03,   L04,   L05,   KC_NO}, \
	{  L10,   L11,   L12,   L13,   L14,   L15,   L16  }, \
	{  L20,   L21,   L22,   L23,   L24,   L25,   L26  }, \
	{  L30,   L31,   L32,   L33,   L34,   L35,   L36  }, \
	{  R40,   R41,   R42,   R43,   R44,   R45,   KC_NO}, \
	{  R50,   R51,   R52,   R53,   R54,   R55,   R56  }, \
	{  R60,   R61,   R62,   R63,   R64,   R65,   R66  }, \
	{  R70,   R71,   R72,   R73,   R74,   R75,   R76  }, \
}
