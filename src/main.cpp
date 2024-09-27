#include "main.h"
#include "buttons/buttons.h"
#include "buttons/ButtonMode.h"
#include "ir/ir.h"
#include "leds/leds.h"
#include "modes/AVTControlMode.h"
#include "subghz/subghz.h"
#include "usb/usb.h"
//#include "wifi/wifi_manager.h"

#include <BLEDevice.h>

#include "Adafruit_TinyUSB.h"
#include "modes/ProgrammingMode.h"

void setup() {
    Serial.begin(112500);

    usbSetup();
    IRSetup();
    buttonsSetup();
    ledsSetup();
    subghzSetup();

    ButtonMode mode1(1);
    ButtonMode mode2(2);
    ButtonMode mode3(3);
    ButtonMode mode4(4);
    ButtonMode mode5(5);

    mode1.addButtonCallback(MACRO_KEY_1, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, HIGH);
    });
    mode2.addButtonCallback(MACRO_KEY_2, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, HIGH);
    });
    mode3.addButtonCallback(MACRO_KEY_3, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, HIGH);
    });
    mode4.addButtonCallback(MACRO_KEY_4, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, HIGH);
    });
    mode5.addButtonCallback(MACRO_KEY_5, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, HIGH);
    });

    mode1.addButtonCallback(MACRO_KEY_6, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, LOW);
    });
    mode2.addButtonCallback(MACRO_KEY_7, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, LOW);
    });
    mode3.addButtonCallback(MACRO_KEY_8, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, LOW);
    });
    mode4.addButtonCallback(MACRO_KEY_9, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, LOW);
    });
    mode5.addButtonCallback(MACRO_KEY_10, [](int button, bool state, bool controlState) -> void {
        digitalWrite(LED_4, LOW);
    });

    ButtonMode programmingMode = getProgrammingMode();

    addMode(mode1, MACRO_KEY_1);
    addMode(programmingMode, MACRO_KEY_2);
    addMode(mode3, MACRO_KEY_3);
    addMode(mode4, MACRO_KEY_4);
    addMode(mode5, MACRO_KEY_5);

    printf("Setup Complete\n");
}

void loop() {
    buttonsLoop();
    usbLoop();
}