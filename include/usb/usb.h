#include "Adafruit_TinyUSB.h"

uint8_t const desc_keyboard_report[] = {
    TUD_HID_REPORT_DESC_KEYBOARD()
};

uint8_t const desc_mouse_report[] = {
    TUD_HID_REPORT_DESC_MOUSE()
};


Adafruit_USBD_HID usb_keyboard;
Adafruit_USBD_HID usb_mouse;

void usbSetup();
void usbLoop();

bool sendKey(uint8_t reportId, uint8_t keycode[6]);