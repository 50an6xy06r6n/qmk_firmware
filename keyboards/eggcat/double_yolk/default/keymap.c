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

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
        KC_KP_7, KC_KP_8, KC_KP_9, _______, \
        KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, \
        KC_KP_1, KC_KP_2, KC_KP_3, _______, \
        _______, KC_KP_0, KC_PDOT, KC_PENT, \
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
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
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, row: %u, col: %u, pressed: %d, time: %u, interrupt: %d, count: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
}
