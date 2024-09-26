
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

    if (TinyUSBDevice.mounted()) {
        TinyUSBDevice.detach();
        delay(10);
        TinyUSBDevice.attach();
    }
}

void usbLoop() {
    if (TinyUSBDevice.mounted()) {
        // poll gpio once each 2 ms
        static uint32_t ms = 0;
        if (millis() - ms > 2) {
            ms = millis();
            // used to avoid send multiple consecutive zero report for keyboard
            static bool keyPressedPreviously = false;

            uint8_t count = 0;
            uint8_t keycode[6] = {0};

            if (TinyUSBDevice.suspended() && count) {
                // Wake up host if we are in suspend mode
                // and REMOTE_WAKEUP feature is enabled by host
                TinyUSBDevice.remoteWakeup();
            }

            // skip if hid is not ready e.g still transferring previous report
            if (!usb_keyboard.ready()) return;

            if (count) {
                // Send report if there is key pressed
                uint8_t const report_id = 0;
                uint8_t const modifier = 0;

                keyPressedPreviously = true;
                printf("test");
                Serial.println("Sending report");
                usb_keyboard.keyboardReport(report_id, modifier, keycode);
            } else {
                // Send All-zero report to indicate there is no keys pressed
                // Most of the time, it is, though we don't need to send zero report
                // every loop(), only a key is pressed in previous loop()
                if (keyPressedPreviously) {
                    keyPressedPreviously = false;
                    usb_keyboard.keyboardRelease(0);
                }
            }
        }
    }
}


bool sendKey(uint8_t reportId, uint8_t keycode[6]) {
    if (!usb_keyboard.ready()) return false;

    usb_keyboard.keyboardReport(reportId, 0, keycode);
    return true;
}
