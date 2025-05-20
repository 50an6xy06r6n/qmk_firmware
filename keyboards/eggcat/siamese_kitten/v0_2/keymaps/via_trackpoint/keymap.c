/* Copyright 2021 Gareth Chen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    NUMPAD,
    ARROWS,
    MOUSE,
    FUNC
};

#define SPC_LT1 LT(NUMPAD, KC_SPC)
#define BT2_LT1 LT(NUMPAD, KC_BTN2)
#define MO_ARR MO(ARROWS)
#define MO_FUNC MO(FUNC)

extern keymap_config_t keymap_config;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  KC_ESC,                                                                                                 KC_DEL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    	KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,      _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    	KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL, \
    	                  _______, MO_FUNC, KC_LGUI, SPC_LT1, KC_LALT,      KC_ENT,  SPC_LT1, MO_ARR,  _______, _______ \
    ),
    [NUMPAD] = LAYOUT(
        _______, _______,                                                                                                 _______, _______,
        _______, KC_PPLS, KC_7,    KC_8,    KC_9,    KC_EQL,  _______,      _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, _______, \
    	_______, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_0,    _______,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,  \
    	_______, KC_DOT,  KC_1,    KC_2,    KC_3,    KC_PSLS,                        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, \
    	                  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______ \
    ),
    [ARROWS] = LAYOUT(
        _______, _______,                                                                                                _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_BSPC,   KC_UP,  KC_DEL, XXXXXXX, _______, \
    	KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
    	_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    	                  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______ \
    ),
    [MOUSE] = LAYOUT(
         _______, _______,                                                                                                _______, _______,
         _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
         _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
         _______, _______, _______, _______, _______, _______,                        KC_BTN4, _______, _______, _______, _______, _______, \
                           _______, _______, _______, _______, _______,      KC_BTN1, BT2_LT1, KC_BTN3, _______, _______ \
    ),
    [FUNC] = LAYOUT(
         _______, _______,                                                                                                _______, _______,
         _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,      _______, _______, _______, _______, _______, _______, _______, \
         _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,      _______, _______, _______, _______, _______, _______, _______, \
         _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,                         _______, _______, _______, _______, _______, _______, \
                           _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______ \
    ),
};

static uint16_t auto_mouse_timer;
extern int tp_buttons; // mousekey button state set in action.c and used in ps2_mouse.c

#define AUTO_BUTTONS_TIMEOUT 1000
#define MOUSE_BUTTON_MOVE_THRESHOLD 2

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
  debug_mouse=true;
  ps2_mouse_set_resolution(PS2_MOUSE_8_COUNT_MM);
}

// Runs just one time when the keyboard initializes. 
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) { 
    if (auto_mouse_timer && (timer_elapsed(auto_mouse_timer) > AUTO_BUTTONS_TIMEOUT)) {
        if (!tp_buttons) {
            layer_off(MOUSE);
            auto_mouse_timer = 0;
        }
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, row: %u, col: %u, pressed: %d, time: %u, interrupt: %d, count: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    if (record->event.pressed) {
        switch(keycode) {
        case KC_BTN1 ... KC_BTN5:
            break;
        default:
            layer_off(MOUSE);
        }
    }
    return true;
};

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
    // ps2_mouse_print_report(mouse_report);
    // uprintf("x: %d y: %d\n", mouse_report->x, mouse_report->y);
    // uprintf("d: %d\n", abs(mouse_report->x) + abs(mouse_report->y));
    if (abs(mouse_report->x) + abs(mouse_report->y) >= MOUSE_BUTTON_MOVE_THRESHOLD) {
        layer_on(MOUSE);
        if (auto_mouse_timer) {
            auto_mouse_timer = timer_read();
        } else {
            if (!tp_buttons) {
                auto_mouse_timer = timer_read();
            }
        }
    }
}
