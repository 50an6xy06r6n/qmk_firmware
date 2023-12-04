#include "v0.h"

void keyboard_pre_init_kb(void) {
    setPinOutput(B0);
}

void led_set_kb(led_t led_state) {
    if (led_state.caps_lock) {
        writePinLow(B0);
    } else {
        writePinHigh(B0);
    }

    led_set_user(led_state.caps_lock);
}
