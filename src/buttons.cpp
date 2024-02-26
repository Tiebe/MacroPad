//
// Created by tiebe on 2/26/24.
//

#include "buttons.h"

#include <functional>
#include <list>
#include <map>

std::map<int, std::list<std::function<void(int button)>>> callbacks;


/**
 * @brief Add a callback for button presses.
 * @param gpio GPIO pin for this button. See <buttons.h> for a list.
 * @param callback Callback that gets executed when button is pressed.
 * @return The callback provided. Run removeButtonCallback with this parameter.
 */
std::function<void(int button)> addButtonCallback(const int gpio, std::function<void(int button)> callback) {
    if (keys.find(gpio) == keys.end()) {
        throw std::invalid_argument("Button not foumd.");
    }

    callbacks[gpio].push_back(callback);

    return callback;

}

/**
 * \brief Remove a callback for button presses.
 * \param gpio GPIO pin for this button. See <buttons.h> for a list.
 * \param callback Callback to remove.
 */
void removeButtonCallback(const int gpio, const std::function<void(int button)>& callback) {
    callbacks[gpio].remove(callback);
}
