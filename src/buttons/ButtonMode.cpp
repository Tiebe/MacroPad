//
// Created by tiebe on 2/28/2024.
//
#include <Arduino.h>


#include "buttons/ButtonMode.h"

#include "buttons/buttons.h"


/**
 * @param ledState The state the four LEDs will be in. The int is converted to binary, that's what shows.
 */
ButtonMode::ButtonMode(int ledState) {
    this->ledState = ledState;
    empty = false;
}

/**
 * @param led_state The state the four LEDs will be in. The int is converted to binary, that's what shows.
 * @param buttonCallbacks The callbacks that every button has.
 */
ButtonMode::ButtonMode(int led_state, const std::map<int, std::pair<int, std::function<void(int button, bool state, bool controlState)>>>& buttonCallbacks) {
    ledState = led_state;
    callbacks = buttonCallbacks;
    empty = false;
}

ButtonMode::ButtonMode() {
    ledState = 0;
    empty = true;
}

/**
* @brief Add a callback for button presses.
* @param gpio GPIO pin for this button. See <buttons.h> for a list.
* @param callback Callback that gets executed when button is pressed.
* @return The unique id of the callback. Use this to remove the item.
*/
int ButtonMode::addButtonCallback(const int gpio, const std::function<void(int button, bool state, bool controlState)>& callback) {
    if (getButton(gpio) == std::end(DEFINED_BUTTONS)) {
        throw std::invalid_argument("Button not found.");
    }
    int next = 0;


    if (!callbacks.empty()) {
        next = callbacks.rbegin()->first + 1;
    }

    callbacks.insert(std::make_pair(next, std::make_pair(gpio, callback)));

    return next;
}

/**
 * @brief Remove a callback for button presses.
 * @param id The id of the callback to be removed.
 */
void ButtonMode::removeButtonCallback(const int id) {
    callbacks.erase(id);
}

/**
 * @brief Call this function when switching modes to write the new LED state.
 */
void ButtonMode::writeLedState() {
    // const std::string text = "LED State to write: " + std::to_string(this->ledState);
    // USBSerial.println(text.c_str());
    int i = 0;
    for (const LEDData led : DEFINED_LEDS) {
        if ((this->ledState >> i) & 0x1 == 1) {
            // std::string text = "Writing HIGH";
            // USBSerial.println(text.c_str());
            digitalWrite(led.GPIO, HIGH);
        } else {
            // std::string text = "Writing LOW";
            // USBSerial.println(text.c_str());
            digitalWrite(led.GPIO, LOW);
        }
        i++;
    }
}

ButtonData* ButtonMode::getButton(int button) {
    return std::find_if(std::begin(DEFINED_BUTTONS), std::end(DEFINED_BUTTONS), [button](const ButtonData& buttonData) { return buttonData.GPIO == button; });
}
