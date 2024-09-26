//
// Created by tiebe on 3/2/24.
//

#include "subghz/subghz.h"

#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include "main.h"

EEPROMRollingCodeStorage rollingCodeStorage1(0);
EEPROMRollingCodeStorage rollingCodeStorage2(2);
EEPROMRollingCodeStorage rollingCodeStorage3(4);
EEPROMRollingCodeStorage rollingCodeStorage4(6);
SomfyRemote somfyRemote1(GDO0, REMOTE1, &rollingCodeStorage1);
SomfyRemote somfyRemote2(GDO0, REMOTE2, &rollingCodeStorage2);
SomfyRemote somfyRemote3(GDO0, REMOTE3, &rollingCodeStorage3);
SomfyRemote somfyRemote4(GDO0, REMOTE4, &rollingCodeStorage4);

bool subghzInitialized = false;

void subghzSetup() {

    somfyRemote1.setup();
    somfyRemote2.setup();
    somfyRemote3.setup();
    somfyRemote4.setup();

    ELECHOUSE_cc1101.setSpiPin(SCK, MISO, MOSI, CSN);
    ELECHOUSE_cc1101.setGDO(GDO0, GDO2);
    if (ELECHOUSE_cc1101.getCC1101()) {
        Serial.println("CC1101 found, initializing...");
        subghzInitialized = true;
    } else {
        Serial.println("CC1101 not found, not initializing.");
    }
    ELECHOUSE_cc1101.Init();

    if (!EEPROM.begin(8)) {
        Serial.println("EEPROM not found!");
    }
}


void sendRemoteCommand(const unsigned long remote, const Command command, const int repeat) {
    if (!subghzInitialized) {
        Serial.println("CC1101 not initialized, not sending command.");
        return;
    }
    ELECHOUSE_cc1101.setMHZ(SOMFY_FREQUENCY);
    ELECHOUSE_cc1101.SetTx();
    switch (remote) {
        case REMOTE1: somfyRemote1.sendCommand(command, repeat); Serial.println("sent"); break;
        case REMOTE2: somfyRemote2.sendCommand(command, repeat); break;
        case REMOTE3: somfyRemote3.sendCommand(command, repeat); break;
        case REMOTE4: somfyRemote4.sendCommand(command, repeat); break;
        default: Serial.println("Remote not found"); break;
    }

    ELECHOUSE_cc1101.setSidle();
}

void sendRawData(const int data[], const size_t size) {
    if (!subghzInitialized) {
        Serial.println("CC1101 not initialized, not sending command.");
        return;
    }
    for (int i = 0; i < size; i++) {
        const int timing = data[i];
        if (timing >= 0) {
            digitalWrite(GDO0, HIGH);
            delayMicroseconds(timing);
        } else {
            digitalWrite(GDO0, LOW);
            delayMicroseconds(timing*-1);
        }

    }
}

void sendBeamerCommand(Command command) {

}

void sendDrapeCommand(Command command) {

}

