//
// Created by tiebe on 09/09/2024.
//

#include "modes/AVTControlMode.h"

#include <SomfyRemote.h>

#include "buttons/buttons.h"
#include "subghz/subghz.h"
#include "ir/ir.h"

ButtonMode getAVTControlMode() {
    auto mode = ButtonMode(0b1000);
    mode.writeLedState();

    addSunCallbacks(mode);
    addBeamerDrapeCallbacks(mode);
    addBeamerIRCallbacks(mode);

    return mode;
}

void addSunCallbacks(ButtonMode &mode) {
    auto callback = [](const int button, const bool state, const bool controlState) {
        if (!state) return;

        Command command;
        int remote;
        int repeat = 4;

        switch (button) {
            case MACRO_KEY_1: { command = Command::Up; remote = REMOTE1; break; }
            case MACRO_KEY_2: { command = Command::Up; remote = REMOTE2; break; }
            case MACRO_KEY_5: { command = Command::My; remote = REMOTE1; break; }
            case MACRO_KEY_6: { command = Command::My; remote = REMOTE2; break; }
            case MACRO_KEY_9: { command = Command::Down; remote = REMOTE1; break; }
            case MACRO_KEY_10: { command = Command::Down; remote = REMOTE2; break; }
            default: return;
        }

        if (controlState) {
            command = Command::Prog;
            repeat = 10;
        }

        sendRemoteCommand(remote, command, repeat);
    };

    mode.addButtonCallback(MACRO_KEY_1, callback);
    mode.addButtonCallback(MACRO_KEY_2, callback);
    mode.addButtonCallback(MACRO_KEY_5, callback);
    mode.addButtonCallback(MACRO_KEY_6, callback);
    mode.addButtonCallback(MACRO_KEY_9, callback);
    mode.addButtonCallback(MACRO_KEY_10, callback);
}


void addBeamerDrapeCallbacks(ButtonMode &mode) {
    auto callback = [](const int button, const bool state, const bool controlState) {
        if (!state) return;

        Command command;
        bool beamer;

        switch (button) {
            case MACRO_KEY_3: { command = Command::Up; beamer = true; break; }
            case MACRO_KEY_4: { command = Command::Up; beamer = false; break; }
            case MACRO_KEY_7: { command = Command::My; beamer = true; break; }
            case MACRO_KEY_8: { command = Command::My; beamer = false; break; }
            case MACRO_KEY_11: { command = Command::Down; beamer = true; break; }
            case MACRO_KEY_12: { command = Command::Down; beamer = false; break; }
            default: return;
        }

        if (beamer) {
            sendBeamerCommand(command);
        } else {
            sendDrapeCommand(command);
        }


    };

    mode.addButtonCallback(MACRO_KEY_3, callback);
    mode.addButtonCallback(MACRO_KEY_4, callback);
    mode.addButtonCallback(MACRO_KEY_7, callback);
    mode.addButtonCallback(MACRO_KEY_8, callback);
    mode.addButtonCallback(MACRO_KEY_11, callback);
    mode.addButtonCallback(MACRO_KEY_12, callback);
}

void addBeamerIRCallbacks(ButtonMode& mode) {
    auto callback = [](const int button, const bool state, const bool controlState) {
        if (!state) return;

        int address = 0;
        int command = 0;

        switch (button) {
            case MACRO_KEY_13: { address = 0x123456; command = 0x123458; break; }
            case MACRO_KEY_14: { address = 0x123456; command = 0x123456; break; }
            default: return;
        }

        sendNEC(address, command);
    };

    mode.addButtonCallback(MACRO_KEY_13, callback);
    mode.addButtonCallback(MACRO_KEY_14, callback);
}
