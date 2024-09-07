//
// Created by KoenDR06 on 9/7/24.
//

#include "leds/leds.h"

LEDData DEFINED_LEDS[4] = {
        { LED_1, false },
        { LED_2, false },
        { LED_3, false },
        { LED_4, false }
};

void ledsSetup() {
    for (const LEDData led : DEFINED_LEDS) {
        pinMode(led.GPIO, OUTPUT);
    }
}