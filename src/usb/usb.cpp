#include "usb/usb.h"
#include "Adafruit_TinyUSB.h"

uint8_t const desc_hid_report[] = {
    TUD_HID_REPORT_DESC_KEYBOARD()
};

// USB HID object. For ESP32 these values cannot be changed after this declaration
// desc report, desc len, protocol, interval, use out endpoint
Adafruit_USBD_HID usb_hid;

void hid_report_callback(uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize) {
    (void) report_id;
    (void) bufsize;

    // LED indicator is output report with only 1 byte length
    if (report_type != HID_REPORT_TYPE_OUTPUT) return;

    // The LED bit map is as follows: (also defined by KEYBOARD_LED_* )
    // Kana (4) | Compose (3) | ScrollLock (2) | CapsLock (1) | Numlock (0)
    uint8_t ledIndicator = buffer[0];

    // turn on LED if capslock is set
    digitalWrite(LED_BUILTIN, ledIndicator & KEYBOARD_LED_CAPSLOCK);
}

void usbSetup() {
    if (!TinyUSBDevice.isInitialized()) {
        TinyUSBDevice.begin(0);
    }

    usb_hid.setBootProtocol(HID_ITF_PROTOCOL_KEYBOARD);
    usb_hid.setPollInterval(2);
    usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
    usb_hid.setStringDescriptor("TinyUSB Keyboard");

    // Set up output report (on control endpoint) for Capslock indicator
    usb_hid.setReportCallback(NULL, hid_report_callback);

    usb_hid.begin();

    if (TinyUSBDevice.mounted()) {
        TinyUSBDevice.detach();
        delay(10);
        TinyUSBDevice.attach();
    }
}

uint8_t keycode[6] = {0};
bool keyPressed[6] = {false};
bool keyPressedPreviously[6] = {false};

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
                for (bool i : keyPressedPreviously) {
                    if (i) {
                        TinyUSBDevice.remoteWakeup();
                        break;
                    }
                }
            }

            // skip if hid is not ready e.g still transferring previous report
            if (!usb_hid.ready()) return;

            for (uint8_t i = 0; i < 6; i++) {
                if (keyPressed[i]) {
                    // Send report if there is key pressed
                    uint8_t const report_id = i;
                    uint8_t const modifier = 0;

                    keyPressedPreviously[i] = true;
                    printf("Sending key %d\n", keycode[i]);
                    printf(" at index %d\n", i);
                    usb_hid.keyboardReport(report_id, modifier, &keycode[i]);
                } else {
                    // Send All-zero report to indicate there is no keys pressed
                    // Most of the time, it is, though we don't need to send zero report
                    // every loop(), only a key is pressed in previous loop()
                    if (keyPressedPreviously[i]) {
                        keyPressedPreviously[i] = false;
                        usb_hid.keyboardRelease(i);
                    }
                }
            }
        }
    }
}

bool setKey(const uint8_t key, const bool pressed) {
    for (uint8_t i = 0; i < 6; i++) {
        if (pressed) {
            if (!keyPressed[i]) {
                keycode[i] = key;
                keyPressed[i] = true;
                return true;
            }
        } else {
            if (keyPressed[i] && keycode[i] == key) {
                keyPressed[i] = false;
                return true;
            }
        }
    }
    return false;
}