//
// Created by tiebe on 26/09/2024.
//

#include "modes/ProgrammingMode.h"

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "usb/usb.h"

ButtonMode getProgrammingMode() {
    ButtonMode mode(2);

    mode.addButtonCallback(MACRO_KEY_1, [](int button, const bool state, bool controlState) -> void {
        printf("Button 1 pressed\n");
        setKey(HID_KEY_A, state);
    });

    mode.addButtonCallback(MACRO_KEY_2, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_B, state);
    });

    mode.addButtonCallback(MACRO_KEY_3, [](int button, bool state, bool controlState) -> void {
        setKey(HID_KEY_C, state);
    });

    return mode;
}
