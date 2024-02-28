#include "main.h"
#include "buttons.h"

void setup() {
    Serial.begin(112500);

    // wait for serial connection to settle
    delay(500);
    Serial.println("Starting program...");

    buttonsSetup();
}

void loop() {
    buttonsLoop();
}