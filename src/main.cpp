#include "main.h"
#include "buttons/buttons.h"
#include "buttons/ButtonMode.h"
#include "ir/ir.h"
#include "leds/leds.h"
#include "subghz/subghz.h"
#include "usb/usb.h"
//#include "wifi/wifi_manager.h"
#include <BLEDevice.h>
#include "Adafruit_TinyUSB.h"
#include "modes/DeepSleepMode.h"

#include "modes/FKeys.h"
#include "modes/ProgrammingMode.h"

void startupAnimation() {
    const bool led1 = digitalRead(LED_1);
    const bool led2 = digitalRead(LED_2);
    const bool led3 = digitalRead(LED_3);
    const bool led4 = digitalRead(LED_4);

    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    delay(200);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    delay(200);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    delay(200);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    printf("Setup Complete\n");
    delay(500);

    digitalWrite(LED_1, led1);
    digitalWrite(LED_2, led2);
    digitalWrite(LED_3, led3);
    digitalWrite(LED_4, led4);
}

void setup() {
    Serial.begin(112500);

    usbSetup();
    IRSetup();
    buttonsSetup();
    ledsSetup();
    subghzSetup();


    ButtonMode programming = getProgrammingMode(2);
    ButtonMode fKeyMode = getFKeyMode(12);
    ButtonMode deepSleep = getDeepSleepMode(0);

    addMode(programming, MACRO_KEY_2);
    addMode(fKeyMode, MACRO_KEY_12);
    addMode(deepSleep, MACRO_KEY_13);

    startupAnimation();
}

void loop() {
    buttonsLoop();
    usbLoop();
}