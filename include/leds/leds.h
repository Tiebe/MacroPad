//
// Created by horseman on 9/7/24.
//

#ifndef MACROPAD_LEDS_H
#define MACROPAD_LEDS_H

struct LEDData {
    int GPIO;
    bool state;
};

void ledsSetup();

extern LEDData DEFINED_LEDS[4];

#define LED_1 33;
#define LED_2 34;
#define LED_3 35;
#define LED_4 36;

#endif //MACROPAD_LEDS_H
