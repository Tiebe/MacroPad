//
// Created by KoenDR06 on 27/09/2024.
//

#include "modes/FKeys.h"

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "usb/usb.h"

ButtonMode getFKeyMode(int button) {
    ButtonMode mode(button);

    mode.addButtonCallback(MACRO_KEY_1, [](int button, const bool state, bool controlState) -> void {
        setKey(HID_KEY_F13, state);
    });

    mode.addButtonCallback(MACRO_KEY_2, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F14, state);
    });

    mode.addButtonCallback(MACRO_KEY_3, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F15, state);
    });

    mode.addButtonCallback(MACRO_KEY_4, [](int button, const bool state, bool controlState) -> void {
        setKey(HID_KEY_F16, state);
    });

    mode.addButtonCallback(MACRO_KEY_5, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F17, state);
    });

    mode.addButtonCallback(MACRO_KEY_6, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F18, state);
    });

    mode.addButtonCallback(MACRO_KEY_7, [](int button, const bool state, bool controlState) -> void {
        setKey(HID_KEY_F19, state);
    });

    mode.addButtonCallback(MACRO_KEY_8, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F20, state);
    });

    mode.addButtonCallback(MACRO_KEY_9, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F21, state);
    });

    mode.addButtonCallback(MACRO_KEY_10, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F22, state);
    });

    mode.addButtonCallback(MACRO_KEY_11, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F23, state);
    });

    mode.addButtonCallback(MACRO_KEY_12, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_F24, state);
    });

    mode.addButtonCallback(MACRO_KEY_13, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_CONTROL_LEFT, state);
    });

    mode.addButtonCallback(MACRO_KEY_14, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_SHIFT_LEFT, state);
    });

    mode.addButtonCallback(MACRO_KEY_15, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_ALT_LEFT, state);
    });
    return mode;
}