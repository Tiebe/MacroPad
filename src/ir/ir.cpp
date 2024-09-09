//
// Created by tiebe on 09/09/2024.
//

#include <IRremote.hpp>

#include "ir/ir.h"

void sendNEC(const uint16_t address, const uint16_t command) {
    IrSender.sendNEC(address, command, 3);
}

void sendNECext(const uint16_t address, const uint16_t command) {
    IrSender.sendOnkyo(address, command, 3);
}