#include "main.h"

#include "buttons/buttons.h"
#include "buttons/ButtonMode.h"
#include "ir/ir.h"
#include "leds/leds.h"
#include "subghz/subghz.h"
#include "usb/usb.h"
#include "wifi/wifi.h"

#include "modes/MacroMode.h"
#include "modes/NumPadMode.h"
#include "modes/ProgrammingMode.h"

#include "Adafruit_TinyUSB.h"
#include <BLEDevice.h>
#include <thread>
#include <WiFi.h>

void startupAnimation() {
    const bool led1 = digitalRead(LED_1);
    const bool led2 = digitalRead(LED_2);
    const bool led3 = digitalRead(LED_3);
    const bool led4 = digitalRead(LED_4);

    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    delay(100);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    delay(200);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    delay(100);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    printf("Setup Complete\n");
    delay(250);

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
    wifiSetup();


    ButtonMode macroMode = getMacroMode(1);
    ButtonMode programming = getProgrammingMode(2);
    ButtonMode numPadMode = getNumPadMode(3);

    addMode(programming, MACRO_KEY_2);
    addMode(macroMode, MACRO_KEY_1);
    addMode(numPadMode, MACRO_KEY_3);

    startupAnimation();
}

void loop() {
    buttonsLoop();
    usbLoop();
    wifiLoop();
}