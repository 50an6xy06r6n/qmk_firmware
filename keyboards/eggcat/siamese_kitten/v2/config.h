#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4543 // "EC"
#define PRODUCT_ID      0x0003
#define DEVICE_VER      0x0000
#define MANUFACTURER    "EggCat"
#define PRODUCT         "Siamese Kitten"

/* split config */
#define EE_HANDS
#define SOFT_SERIAL_PIN D2
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0

/* Cirque trackpad config */
#ifdef POINTING_DEVICE_DRIVER_cirque_pinnacle_i2c
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_DEBUG
// #define POINTING_DEVICE_ROTATION_90
#define CIRQUE_PINNACLE_DIAMETER_MM 35
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#endif

/* Trackpoint config */
#ifdef PS2_DRIVER_INTERRUPT
#define PS2_CLOCK_PIN   D0
#define PS2_DATA_PIN    D1

#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC01) |      \
              (0<<ISC00));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT0);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT0);        \
} while (0)
#define PS2_INT_VECT   INT0_vect
#define PS2_MOUSE_ROTATE 180

#define PS2_MOUSE_X_MULTIPLIER 1
#define PS2_MOUSE_Y_MULTIPLIER 1

#define PS2_MOUSE_SCROLL_BTN_MASK 0x08
// #define PS2_MOUSE_DEBUG_HID
// #define PS2_MOUSE_DEBUG_RAW
#define PS2_MOUSE_USE_REMOTE_MODE
#endif

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

/* key matrix pins */
// #define MATRIX_ROW_PINS { E6, D7, D4, C6 }
#define MATRIX_ROW_PINS { D1, D0, D4, C6 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS_RIGHT { E6, D7, D4, C6 }
#define MATRIX_COL_PINS_RIGHT { F5, F6, F7, B1, B3, B2, B6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
