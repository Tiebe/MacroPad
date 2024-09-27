#include "usb/usb.h"
#include "Adafruit_TinyUSB.h"

uint8_t const desc_hid_report[] = {
    TUD_HID_REPORT_DESC_KEYBOARD()
};

// USB HID object. For ESP32 these values cannot be changed after this declaration
// desc report, desc len, protocol, interval, use out endpoint
Adafruit_USBD_HID usb_hid;

static uint8_t keyReport[6] = {0}; // Array to hold the current key states
static bool keyPressed[256] = {false}; // Array to track pressed keys
static uint8_t modifiers = 0; // Byte to hold the current modifier state

void usbSetup() {
    if (!TinyUSBDevice.isInitialized()) {
        TinyUSBDevice.begin(0);
    }

    usb_hid.setBootProtocol(HID_ITF_PROTOCOL_KEYBOARD);
    usb_hid.setPollInterval(2);
    usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
    usb_hid.setStringDescriptor("TinyUSB Keyboard");

    usb_hid.begin();

    if (TinyUSBDevice.mounted()) {
        TinyUSBDevice.detach();
        delay(10);
        TinyUSBDevice.attach();
    }
}

void usbLoop() {
#ifdef TINYUSB_NEED_POLLING_TASK
    TinyUSBDevice.task();
#endif
    if (TinyUSBDevice.mounted()) {
        // poll gpio once each 2 ms
        static uint32_t ms = 0;
        if (millis() - ms > 2) {
            ms = millis();

            if (TinyUSBDevice.suspended()) {
                // Wake up host if we are in suspend mode
                // and REMOTE_WAKEUP feature is enabled by host
                TinyUSBDevice.remoteWakeup();
            }

            // skip if hid is not ready e.g still transferring previous report
            if (!usb_hid.ready()) return;

            // Send the key report
            usb_hid.keyboardReport(0, modifiers, keyReport);
        }
    }
}

bool setKey(const uint8_t key, const bool pressed) {
    if (key >= HID_KEY_CONTROL_LEFT && key <= HID_KEY_GUI_RIGHT) {
        uint8_t mask = 1 << (key - HID_KEY_CONTROL_LEFT);
        if (pressed) {
            modifiers |= mask;
        } else {
            modifiers &= ~mask;
        }
        return true;
    }

    for (int i = 0; i < 6; i++) {
        if (keyReport[i] == key) {
            if (!pressed) {
                keyReport[i] = 0;
                keyPressed[key] = false;
            }
            return true;
        }
    }

    if (pressed) {
        for (int i = 0; i < 6; i++) {
            if (keyReport[i] == 0) {
                keyReport[i] = key;
                keyPressed[key] = true;
                return true;
            }
        }
    }

    return false;
}