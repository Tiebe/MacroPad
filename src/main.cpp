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

void fancyStartup() {
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

    fancyStartup();
}

void loop() {
    buttonsLoop();
    usbLoop();
}