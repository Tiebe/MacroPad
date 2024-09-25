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


#define LED_1 4
#define LED_2 17
#define LED_3 18
#define LED_4 46

extern LEDData DEFINED_LEDS[4];

#endif //MACROPAD_LEDS_H
