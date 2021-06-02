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
#define SPC_LT1 LT(1,KC_SPC)


keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                 KC_ESC,                                                                                                 KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,      _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    	KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,      _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    	KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
    	                  _______, _______, KC_LGUI, SPC_LT1, KC_LALT,      KC_ENT,  SPC_LT1, MO(2),   _______, _______ \
    ),
    [1] = LAYOUT(
                 KC_ESC,                                                                                                 _______,
        _______, KC_PPLS, KC_7,    KC_8,    KC_9,    KC_EQL,  _______,      _______, _______, _______, KC_LPRN, KC_RPRN, XXXXXXX, _______, \
    	_______, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_0,    _______,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,  \
    	_______, KC_PDOT, KC_1,    KC_2,    KC_3,    KC_PSLS,                        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, \
    	                  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______ \
    ),
    [2] = LAYOUT(
                 _______,                                                                                                _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_BSPC,   KC_UP,  KC_DEL, XXXXXXX, _______, \
    	_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
    	_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    	                  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______ \
    ),
    [3] = LAYOUT(
                  _______,                                                                                                _______,
         _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
         _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
         _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                           _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______ \
    ),
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, row: %u, col: %u, pressed: %d, time: %u, interrupt: %d, count: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif
    return true;
};
