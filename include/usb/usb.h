#include "Adafruit_TinyUSB.h"

uint8_t const desc_keyboard_report[] = {
    TUD_HID_REPORT_DESC_KEYBOARD()
};

uint8_t const desc_mouse_report[] = {
    TUD_HID_REPORT_DESC_MOUSE()
};


extern Adafruit_USBD_HID usb_keyboard;
extern Adafruit_USBD_HID usb_mouse;

void usbSetup();
void usbLoop();

bool setKey(uint8_t key, bool state);