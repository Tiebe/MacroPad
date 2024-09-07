#include "main.h"
#include "buttons/buttons.h"
#include "buttons/ButtonMode.h"
#include "usb/usb.h"

void setup() {
    Serial.begin(112500);

    // wait for serial connection to settle
    delay(2500);
    Serial.println("Starting program...");

    usbSetup();
    buttonsSetup();
    ledsSetup();

    ButtonMode defaultMode(1);

    defaultMode.addButtonCallback(MACRO_KEY_1, 0, [](int button) -> void {
        uint8_t keycode[6] = {0};
        keycode[0] = HID_KEY_A;

        sendKey(0, keycode);
        sleep(1);

    });

    addMode(defaultMode);

    Serial.println("Check");
}

void loop() {

    buttonsLoop();
}