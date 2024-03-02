//
// Created by tiebe on 3/2/24.
//

#ifndef SUBGHZ_H
#define SUBGHZ_H

#include <EEPROM.h>
#include <EEPROMRollingCodeStorage.h>
#include <SomfyRemote.h>

#define EMITTER_GPIO 13
#define REMOTE1 0x65dc00
#define REMOTE2 0x25b5d5
#define REMOTE3 0xc6c78f
#define REMOTE4 0x59714b

#define CC1101_FREQUENCY 433.42

void subghzSetup();
void sendRemoteCommand(unsigned long remote, Command command);

#endif //SUBGHZ_H
