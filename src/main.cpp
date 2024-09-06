#include "main.h"
#include "buttons/buttons.h"
#include "usb/usb.h"

void setup() {
    Serial.begin(112500);

    // wait for serial connection to settle
    delay(2500);
    Serial.println("Starting program...");

    usbSetup();
    buttonsSetup();

    addButtonCallback(MACRO_KEY_1, [](int button) -> void {
        uint8_t keycode[6] = {0};
        keycode[0] = HID_KEY_A;

        sendKey(0, keycode);
        sleep(1);
        
    });
    

    Serial.println("checjk2");

    Serial.println("Check");
}

void loop() {

    buttonsLoop();
}