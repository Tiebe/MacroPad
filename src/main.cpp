#include "main.h"
#include "buttons/buttons.h"
#include "subghz/subghz.h"

void setup() {
    Serial.begin(112500);

    // wait for serial connection to settle
    delay(2500);
    Serial.println("Starting program...");

    buttonsSetup();
    //subghzSetup();

    Serial.println("checjk2");

    Serial.println("Check");
}

void loop() {

    buttonsLoop();
}