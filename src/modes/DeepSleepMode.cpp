//
// Created by KoenDR06 on 9/27/2024.
//

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "modes/DeepSleepMode.h"

ButtonMode getDeepSleepMode(int button) {
    ButtonMode mode(button);


    // all MACRO_KEYs
    uint64_t mask = 0;
    for (const auto gpio : DEFINED_BUTTONS) {
        mask |= 1 << gpio.GPIO;
    }
    esp_sleep_enable_ext1_wakeup(mask, ESP_EXT1_WAKEUP_ANY_HIGH);

    mode.addButtonCallback(MACRO_KEY_1, [](int, const bool, bool) -> void {
        // if (state && digitalRead(MACRO_KEY_4) && digitalRead(MACRO_KEY_16)) {
            digitalWrite(LED_1, HIGH);
            delay(200);
            digitalWrite(LED_2, HIGH);
            delay(200);
            digitalWrite(LED_3, HIGH);
            delay(200);
            digitalWrite(LED_4, HIGH);
            delay(200);
            printf("Bye bye o7\n");
            delay(1000);
            digitalWrite(LED_1, LOW);
            digitalWrite(LED_2, LOW);
            digitalWrite(LED_3, LOW);
            digitalWrite(LED_4, LOW);

            esp_deep_sleep_start();
        // }
    });

    return mode;
}
