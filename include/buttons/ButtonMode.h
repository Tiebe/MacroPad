//
// Created by tiebe on 2/28/2024.
//

#ifndef BUTTONMODE_H
#define BUTTONMODE_H
#include <functional>
#include <map>
#include <algorithm>
#include <esp32-hal-gpio.h>
#include <HWCDC.h>
#include <map>

#include "leds/leds.h"
#include "buttons/ButtonData.h"


class ButtonMode {
public:
    int ledState;
    bool empty;
    std::map<int, std::pair<int, std::function<void(int button, bool state, bool controlState)>>> callbacks;

    ButtonMode(int led_state);
    ButtonMode(int led_state,
               const std::map<int, std::pair<int, std::function<void(int button, bool state, bool controlState)>>>&
               buttonCallbacks);
    ButtonMode();
    int addButtonCallback(int gpio, std::function<void(int button, bool state, bool controlState)> callback);
    void removeButtonCallback(const int id);
    void writeLedState();

    ButtonData* getButton(int button);
};

#endif //BUTTONMODE_H
