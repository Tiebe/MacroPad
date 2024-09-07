//
// Created by tiebe on 2/28/2024.
//

#include "buttons/ButtonMode.h"

class ButtonMode {
public:
    int ledState;
    std::map<int, std::pair<int, std::function<void(int button, bool state)>>> callbacks;
    bool empty;

    /**
     * @param led_state The state the four LEDs will be in. The int is converted to binary, that's what shows.
     * @param buttonCallbacks The callbacks that every button has.
     */
    ButtonMode(int led_state) {
        ledState = led_state;
        empty = false;
    }

    /**
     * @param led_state The state the four LEDs will be in. The int is converted to binary, that's what shows.
     * @param buttonCallbacks The callbacks that every button has.
     */
    ButtonMode(int led_state, std::map<int, std::pair<int, std::function<void(int button, bool state)>>> buttonCallbacks) {
        ledState = led_state;
        callbacks = buttonCallBacks;
        empty = false;
    }

    ButtonMode() {
        empty = true;
    }

    /**
    * @brief Add a callback for button presses.
    * @param gpio GPIO pin for this button. See <buttons.h> for a list.
    * @param callback Callback that gets executed when button is pressed.
    * @return The unique id of the callback. Use this to remove the item.
    */
    int addButtonCallback(const int gpio, const std::function<void(int button, bool state, bool controlState)>& callback) {
        if (getButton(gpio) == std::end(DEFINED_BUTTONS)) {
            throw std::invalid_argument("Button not found.");
        }
        int next = 0;


        if (!callbacks.empty()) {
            next = callbacks.rbegin()->first + 1;
        }

        callbacks.insert(std::make_pair(next, std::make_pair(gpio), callback)));

        return next;
    }

    /**
     * @brief Remove a callback for button presses.
     * @param id The id of the callback to be removed.
     */
    void removeButtonCallback(const int id) {
        callbacks.erase(id);
    }

private:
    ButtonData* getButton(int button) {
        return std::find_if(std::begin(DEFINED_BUTTONS), std::end(DEFINED_BUTTONS), [button](const ButtonData& buttonData) { return buttonData.GPIO == button; });
    }
};