//
// Created by tiebe on 2/26/24.
//

#include "main.h"
#include "buttons/buttons.h"
#include "buttons/ButtonMode.h"

#include <functional>
#include <list>
#include <map>
#include <vector>

ButtonData DEFINED_BUTTONS[16] = {
    { MACRO_KEY_1, true, 0 },
    { MACRO_KEY_2, true, 0 },
    { MACRO_KEY_3, true, 0 },
    { MACRO_KEY_4, true, 0 },
    { MACRO_KEY_5, true, 0 },
    { MACRO_KEY_6, true, 0 },
    { MACRO_KEY_7, true, 0 },
    { MACRO_KEY_8, true, 0 },
    { MACRO_KEY_9, true, 0 },
    { MACRO_KEY_10, true, 0 },
    { MACRO_KEY_11, true, 0 },
    { MACRO_KEY_12, true, 0 },
    { MACRO_KEY_13, true, 0 },
    { MACRO_KEY_14, true, 0 },
    { MACRO_KEY_15, true, 0 },
    { MACRO_KEY_16, true, 0 }
};

std::map<int, std::pair<int, std::function<void(int button, bool state, bool controlState)>>> callbacks;
std::map<int, std::pair<int, ButtonMode>> buttonModes;

/**
 * @brief Add a mode.
 * @param mode The mode to add.
 * @param gpio The pin which when powered triggers the mode.
 * @return The unique id of the callback. Use this to remove the item.
*/
uint addMode(ButtonMode& mode, int gpio) {
    if (buttonModes.empty()) {
        callbacks = mode.callbacks;
        mode.writeLedState();
    }

    uint next = buttonModes.size() + 1;

    buttonModes.insert(std::make_pair(next, std::make_pair(gpio, mode)));

    return next;
}

/**
* @brief Remove a mode.
* @param id The id of the mode.
*/
void removeMode(int id) {
    buttonModes.erase(id);
}

void buttonsSetup() {
    for (const ButtonData button : DEFINED_BUTTONS) {
        pinMode(button.GPIO, INPUT);
    }
}

void processButtons() {
    // loop through all buttons and get their values
    for (ButtonData& button : DEFINED_BUTTONS) {
        const bool newState = digitalRead(button.GPIO);

        // if button state changes, set new state
        if (newState != button.state) {
            button.state = newState;

            if (digitalRead(FN_BUTTON) && button.GPIO != FN_BUTTON && button.state) {
                printf("Mode switch\n");

                for (auto buttonModePair : buttonModes) {
                    if (buttonModePair.second.first == button.GPIO) {
                        callbacks = buttonModePair.second.second.callbacks;
                        buttonModePair.second.second.writeLedState();
                    }
                }
            } else {
                printf("Execute callback\n");

                for (const auto& callback : callbacks) {
                    if (callback.second.first == button.GPIO) {
                        callback.second.second(button.GPIO, button.state, digitalRead(CONTROL_BUTTON));
                    }
                }
            }
        }
    }
}

void buttonsLoop() {
    static uint32_t ms = 0;
    if (millis() - ms > 10) {
        ms = millis();
        processButtons();
    }
}

