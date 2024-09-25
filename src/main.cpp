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
    subghzSetup();

    /*while (true)
    {
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
    }*/


    ButtonMode defaultMode(2);

    /*defaultMode.addButtonCallback(MACRO_KEY_1, [](int button, bool state, bool controlState) -> void {
        uint8_t keycode[6] = {0};
        keycode[0] = HID_KEY_A;

        sendKey(0, keycode);
        sleep(1);

    });*/

    defaultMode.addButtonCallback(MACRO_KEY_1, [](int button, bool state, bool controlState) -> void {
        if (controlState) {
            digitalWrite(LED_1, LOW);
        } else {
            digitalWrite(LED_1, HIGH);
        }
    });

    // defaultMode.addButtonCallback(MACRO_KEY_2, [](int button, bool state, bool controlState) -> void {
    //     if (controlState) {
    //         digitalWrite(LED_2, LOW);
    //     } else {
    //         digitalWrite(LED_2, HIGH);
    //     }
    // });

    addMode(defaultMode, MACRO_KEY_1);

    auto avtControlMode = getAVTControlMode();
    addMode(avtControlMode, MACRO_KEY_2);

    USBSerial.println("Setup Complete");
}

void loop() {
    buttonsLoop();
}