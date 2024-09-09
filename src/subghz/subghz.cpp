//
// Created by tiebe on 3/2/24.
//

#include "subghz/subghz.h"

#include <ELECHOUSE_CC1101_SRC_DRV.h>

EEPROMRollingCodeStorage rollingCodeStorage1(0);
EEPROMRollingCodeStorage rollingCodeStorage2(2);
EEPROMRollingCodeStorage rollingCodeStorage3(4);
EEPROMRollingCodeStorage rollingCodeStorage4(6);
SomfyRemote somfyRemote1(EMITTER_GPIO, REMOTE1, &rollingCodeStorage1);
SomfyRemote somfyRemote2(EMITTER_GPIO, REMOTE2, &rollingCodeStorage2);
SomfyRemote somfyRemote3(EMITTER_GPIO, REMOTE3, &rollingCodeStorage3);
SomfyRemote somfyRemote4(EMITTER_GPIO, REMOTE4, &rollingCodeStorage4);

void subghzSetup() {
    somfyRemote1.setup();
    somfyRemote2.setup();
    somfyRemote3.setup();
    somfyRemote4.setup();

    Serial.println("test");
    ELECHOUSE_cc1101.setSpiPin(7, 9, 11, 12);
    Serial.println("test");
    ELECHOUSE_cc1101.Init(); // <--- hangs here
    Serial.println("test");

    if (!EEPROM.begin(8)) {
        Serial.println("EEPROM not found!");
    }
}


void sendRemoteCommand(const unsigned long remote, const Command command) {
    ELECHOUSE_cc1101.setMHZ(SOMFY_FREQUENCY);
    ELECHOUSE_cc1101.SetTx();
    switch (remote) {
        case REMOTE1: somfyRemote1.sendCommand(command); Serial.println("sent"); break;
        case REMOTE2: somfyRemote2.sendCommand(command); break;
        case REMOTE3: somfyRemote3.sendCommand(command); break;
        case REMOTE4: somfyRemote4.sendCommand(command); break;
        default: Serial.println("Remote not found"); break;
    }

    ELECHOUSE_cc1101.setSidle();
}

void sendRawData(const int data[], const size_t size) {
    for (int i = 0; i < size; i++) {
        const int timing = data[i];
        if (timing >= 0) {
            digitalWrite(EMITTER_GPIO, HIGH);
            delayMicroseconds(timing);
        } else {
            digitalWrite(EMITTER_GPIO, LOW);
            delayMicroseconds(timing*-1);
        }

    }
}

void sendBeamerCommand(Command command) {

}

void sendDrapeCommand(Command command) {

}

