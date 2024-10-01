//
// Created by KoenDR06 on 27/09/2024.
//

#include "modes/MacroMode.h"

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "usb/usb.h"

ButtonMode getMacroMode(int button) {
    ButtonMode mode(button);

    mode.addHIDButtonCallback(MACRO_KEY_1, {HID_KEY_F13});
    mode.addHIDButtonCallback(MACRO_KEY_2, {HID_KEY_F14});
    mode.addHIDButtonCallback(MACRO_KEY_3, {HID_KEY_F15});
    mode.addHIDButtonCallback(MACRO_KEY_4, {HID_KEY_F16});
    mode.addHIDButtonCallback(MACRO_KEY_5, {HID_KEY_F17});
    mode.addHIDButtonCallback(MACRO_KEY_6, {HID_KEY_F18});
    mode.addHIDButtonCallback(MACRO_KEY_7, {HID_KEY_F19});
    mode.addHIDButtonCallback(MACRO_KEY_8, {HID_KEY_F20});
    mode.addHIDButtonCallback(MACRO_KEY_9, {HID_KEY_F21});
    mode.addHIDButtonCallback(MACRO_KEY_10, {HID_KEY_F22});
    mode.addHIDButtonCallback(MACRO_KEY_11, {HID_KEY_F23});
    mode.addHIDButtonCallback(MACRO_KEY_12, {HID_KEY_F24});

    mode.addHIDButtonCallback(MACRO_KEY_13, {HID_KEY_CONTROL_LEFT});
    mode.addHIDButtonCallback(MACRO_KEY_14, {HID_KEY_SHIFT_LEFT});
    mode.addHIDButtonCallback(MACRO_KEY_15, {HID_KEY_ALT_LEFT});

    return mode;
}