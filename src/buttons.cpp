//
// Created by tiebe on 2/26/24.
//

//#include "buttons.h"
#include "main.h"
#include "buttons.h"

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

ButtonData* getButton(int button) {
    return std::find_if(std::begin(DEFINED_BUTTONS), std::end(DEFINED_BUTTONS), [button](const ButtonData& buttonData) { return buttonData.GPIO == button; });
}

std::map<int, std::pair<int, std::function<void(int button)>>> callbacks;
std::map<int, std::pair<int, std::function<void(int button)>>> fn_callbacks;


/**
 * @brief Add a callback for button presses.
 * @param gpio GPIO pin for this button. See <buttons.h> for a list.
 * @param callback Callback that gets executed when button is pressed.
 * @param withFn If button is a shortcut using function button.
 * @return The unique id of the callback. Use this to remove the item.
 */
int addButtonCallback(const int gpio, const std::function<void(int button)>& callback, const bool withFn) {
    if (getButton(gpio) == std::end(DEFINED_BUTTONS)) {
        throw std::invalid_argument("Button not found.");
    }
    int next = 0;

    if (withFn) {
        if (!fn_callbacks.empty()) {
            next = callbacks.rbegin()->first + 1;
        }

        fn_callbacks.insert(std::make_pair(next, std::make_pair(gpio, callback)));
    } else {
        if (!callbacks.empty()) {
            next = callbacks.rbegin()->first + 1;
        }

        callbacks.insert(std::make_pair(next, std::make_pair(gpio, callback)));
    }

    return next;
}

/**
 * \brief Remove a callback for button presses.
 * \param id The id of the callback to be removed.
 * \param withFn If button is a shortcut using function button.
 */
void removeButtonCallback(const int id, const bool withFn) {
    if (withFn) fn_callbacks.erase(id);
    else callbacks.erase(id);
}


void buttonsSetup() {
    for (const ButtonData button : DEFINED_BUTTONS) {
        pinMode(button.GPIO, INPUT);
    }
}

// fn button, when pressed with another button, do other action
void buttonsLoop() {
    // loop through all buttons and get their values
    for (ButtonData& button : DEFINED_BUTTONS) {
        const bool newState = digitalRead(button.GPIO);

        // if button state changes, set new state
        if (newState != button.state) {
            button.state = newState;

            // only run callback on button release, not on press.
            if (newState == false && millis() - button.millisLastPressed > 50ul) {
                std::string text = "Button GPIO " + std::to_string(button.GPIO) + " has been pressed after " + std::to_string(millis() - button.millisLastPressed) + "ms.";
                Serial.println(text.c_str());

                auto callbacksToCheck = callbacks;
                if (button.GPIO != FN_BUTTON && getButton(FN_BUTTON)->state) callbacksToCheck = fn_callbacks;

                for (const auto& callback : callbacksToCheck) {
                    if (callback.second.first == button.GPIO) {
                        callback.second.second(button.state);
                    }
                }
                button.millisLastPressed = millis();
            }
        }
    }
}

