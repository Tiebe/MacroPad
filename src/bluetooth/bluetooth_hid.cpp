//
// Created by tiebe on 26/09/2024.
//

#include "bluetooth_hid.h"

#include <BLEDevice.h>
#include <BLEHIDDevice.h>

BLEHIDDevice* hid;
BLECharacteristic* input;
BLECharacteristic* output;

void bluetoothSetup() {
    BLEDevice::init("Macropad");
    BLEServer* server = BLEDevice::createServer();

    hid = new BLEHIDDevice(server);
    input = hid->inputReport(1); // report ID
    output = hid->outputReport(1); // report ID

    hid->manufacturer()->setValue("Tiebe");
    hid->pnp(0x02, 0xe502, 0x1209, 0x0001);
}
