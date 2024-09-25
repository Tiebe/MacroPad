#include "main.h"
#include "buttons/buttons.h"
#include "buttons/ButtonMode.h"
#include "ir/ir.h"
#include "leds/leds.h"
#include "modes/AVTControlMode.h"
#include "subghz/subghz.h"
#include "usb/usb.h"
//#include "wifi/wifi_manager.h"

void setup() {
    USBSerial.begin(112500);

    // wait for serial connection to settle
    delay(500);
    USBSerial.println("Starting program...");

   // usbSetup();
    IRSetup();
    buttonsSetup();
    ledsSetup();
    // subghzSetup();

    while (true) {
        digitalWrite(LED_1, HIGH);
        USBSerial.println("1");
        delay(500);
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, HIGH);
        USBSerial.println("2");
        delay(500);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, HIGH);
        USBSerial.println("3");
        delay(500);
        digitalWrite(LED_3, LOW);
        digitalWrite(LED_4, HIGH);
        USBSerial.println("4");
        delay(500);
        digitalWrite(LED_4, LOW);

        if (digitalRead(FN_BUTTON)) {
            break;
        }
    }


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



    addMode(mode1, MACRO_KEY_1);
    addMode(mode2, MACRO_KEY_2);
    addMode(mode3, MACRO_KEY_3);
    addMode(mode4, MACRO_KEY_4);
    addMode(mode5, MACRO_KEY_5);



    USBSerial.println("Setup Complete");
}

void loop() {
    buttonsLoop();
}