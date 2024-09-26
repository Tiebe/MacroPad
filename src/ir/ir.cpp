//
// Created by tiebe on 09/09/2024.
//


#include "ir/ir.h"

#include <HWCDC.h>
#include <IRsend.h>

#include "main.h"

IRsend irSend(IR_SEND_PIN);

void IRSetup() {
    irSend.begin();
}

void sendNEC(const uint16_t address, const uint16_t command) {
    Serial.println("Sending NEC");

    irSend.sendNEC(irSend.encodeNEC(address, command), 32, 3);
}

void sendNECext(const uint16_t address, const uint16_t command) {
    Serial.println("Sending NECext");
}