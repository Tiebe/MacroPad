
#include "usb/usb.h"
#include "Adafruit_TinyUSB.h"

Adafruit_USBD_HID usb_keyboard;
Adafruit_USBD_HID usb_mouse;

void usbSetup() {
    if (!TinyUSBDevice.isInitialized()) {
    TinyUSBDevice.begin(0);
    }

    // HID Keyboard
    usb_keyboard.setPollInterval(2);
    usb_keyboard.setBootProtocol(HID_ITF_PROTOCOL_KEYBOARD);
    usb_keyboard.setReportDescriptor(desc_keyboard_report, sizeof(desc_keyboard_report));
    usb_keyboard.setStringDescriptor("MacroPad USB Keyboard");
    usb_keyboard.begin();

    // HID Mouse
    usb_mouse.setPollInterval(2);
    usb_mouse.setBootProtocol(HID_ITF_PROTOCOL_MOUSE);
    usb_mouse.setReportDescriptor(desc_mouse_report, sizeof(desc_mouse_report));
    usb_mouse.setStringDescriptor("MacroPad USB Mouse");
    usb_mouse.begin();

}

bool sendKey(uint8_t reportId, uint8_t keycode[6]) {
    if (!usb_keyboard.ready()) return false;

    usb_keyboard.keyboardReport(reportId, 0, keycode);
    return true;
}
