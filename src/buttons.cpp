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

std::set<int> DEFINED_BUTTONS = std::set<int> {
    MACRO_KEY_1,
    MACRO_KEY_2,
    MACRO_KEY_3,
    MACRO_KEY_4,
    MACRO_KEY_5,
    MACRO_KEY_6,
    MACRO_KEY_7,
    MACRO_KEY_8,
    MACRO_KEY_9,
    MACRO_KEY_10,
    MACRO_KEY_11,
    MACRO_KEY_12,
    MACRO_KEY_13,
    MACRO_KEY_14,
    MACRO_KEY_15,
    MACRO_KEY_16,
};


std::map<int, std::pair<int, std::function<void(int button)>>> callbacks;


/**
 * @brief Add a callback for button presses.
 * @param gpio GPIO pin for this button. See <buttons.h> for a list.
 * @param callback Callback that gets executed when button is pressed.
 * @return The unique id of the callback. Use this to remove the item.
 */
int addButtonCallback(const int gpio, const std::function<void(int button)>& callback) {
    if (DEFINED_BUTTONS.find(gpio) == DEFINED_BUTTONS.end()) {
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
 * \brief Remove a callback for button presses.
 * \param id The id of the callback to be removed.
 */
void removeButtonCallback(const int id) {
    callbacks.erase(id);
}

void buttonsSetup() {
    for (int button : DEFINED_BUTTONS) {
        pinMode(button, INPUT);
    }
}


void buttonsLoop() {
    for (const int button : DEFINED_BUTTONS) {
        std::string text = "Button GPIO " + std::to_string(button) + " is " + std::to_string(digitalRead(button));
        Serial.println(text.c_str());
    }
}