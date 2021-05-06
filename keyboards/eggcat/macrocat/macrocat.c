#include "macrocat.h"

void keyboard_pre_init_kb(void) {
    setPinOutput(B0);
}

void led_set_kb(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinLow(B0);
    } else {
        writePinHigh(B0);
    }

    led_set_user(usb_led);
}
