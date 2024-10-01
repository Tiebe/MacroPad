//
// Created by KoenDR06 on 10/1/2024.
//

#include "modes/NumPadMode.h"

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "usb/usb.h"

// -----------------
// | 7 | 8 | 9 | - |
// | 4 | 5 | 6 | + |
// | 1 | 2 | 3 | * |
// | = | 0 | . |   |


ButtonMode getNumPadMode(int button) {
    ButtonMode mode(button);

    // Numbers
    mode.addHIDButtonCallback(MACRO_KEY_1, {HID_KEY_KEYPAD_7});
    mode.addHIDButtonCallback(MACRO_KEY_2, {HID_KEY_KEYPAD_8});
    mode.addHIDButtonCallback(MACRO_KEY_3, {HID_KEY_KEYPAD_9});
    mode.addHIDButtonCallback(MACRO_KEY_5, {HID_KEY_KEYPAD_4});
    mode.addHIDButtonCallback(MACRO_KEY_6, {HID_KEY_KEYPAD_5});
    mode.addHIDButtonCallback(MACRO_KEY_7, {HID_KEY_KEYPAD_6});
    mode.addHIDButtonCallback(MACRO_KEY_9, {HID_KEY_KEYPAD_1});
    mode.addHIDButtonCallback(MACRO_KEY_10, {HID_KEY_KEYPAD_2});
    mode.addHIDButtonCallback(MACRO_KEY_11, {HID_KEY_KEYPAD_3});
    mode.addHIDButtonCallback(MACRO_KEY_14, {HID_KEY_KEYPAD_0});


    // Operators
    mode.addHIDButtonCallback(MACRO_KEY_4, {HID_KEY_KEYPAD_SUBTRACT});
    mode.addHIDButtonCallback(MACRO_KEY_8, {HID_KEY_KEYPAD_ADD});
    mode.addHIDButtonCallback(MACRO_KEY_12, {HID_KEY_KEYPAD_MULTIPLY});
    mode.addHIDButtonCallback(MACRO_KEY_13, {HID_KEY_ENTER});
    mode.addHIDButtonCallback(MACRO_KEY_15, {HID_KEY_KEYPAD_COMMA});

    return mode;
}