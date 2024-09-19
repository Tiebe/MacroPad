//
// Created by tiebe on 09/09/2024.
//

#ifndef IR_H
#define IR_H

#define IR_SEND_PIN 3
#define NO_LED_FEEDBACK_CODE
#include <cstdint>

void IRSetup();

void sendNEC(uint16_t address, uint16_t command);
void sendNECext(uint16_t address, uint16_t command);

#endif //IR_H
