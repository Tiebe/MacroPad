#include "main.h"
#include "buttons.h"

void setup() {
    Serial.begin(112500);

    buttonsSetup();
}

void loop() {
    buttonsLoop();
}