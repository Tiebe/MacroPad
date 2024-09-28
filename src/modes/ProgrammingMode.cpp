//
// Created by tiebe on 26/09/2024.
//

#include "modes/ProgrammingMode.h"

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "usb/usb.h"

ButtonMode getProgrammingMode(int button) {
    ButtonMode mode(button);

    // run button intellij
    mode.addHIDButtonCallback(MACRO_KEY_1, {HID_KEY_SHIFT_LEFT, HID_KEY_F10});
    // debug button intellij
    mode.addHIDButtonCallback(MACRO_KEY_2, {HID_KEY_SHIFT_LEFT, HID_KEY_F9});



    // stop button intellij
    mode.addHIDButtonCallback(MACRO_KEY_4, {HID_KEY_CONTROL_LEFT, HID_KEY_F2});

    return mode;
}
