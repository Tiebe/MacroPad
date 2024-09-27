//
// Created by KoenDR06 on 9/27/2024.
//

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "modes/DeepSleepMode.h"

ButtonMode getDeepSleepMode(int button) {
    ButtonMode mode(button);

    mode.addButtonCallback(MACRO_KEY_1, [](int button, const bool state, bool controlState) -> void {
        // if (state && digitalRead(MACRO_KEY_4) && digitalRead(MACRO_KEY_16)) {
            digitalWrite(LED_1, HIGH);
            esp_deep_sleep_start();
        // }
    });

    return mode;
}
