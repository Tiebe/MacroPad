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


#define LED_1 36
#define LED_2 35
#define LED_3 34
#define LED_4 33

extern LEDData DEFINED_LEDS[4];

#endif //MACROPAD_LEDS_H
