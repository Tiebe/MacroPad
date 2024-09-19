//
// Created by tiebe on 19/09/2024.
//

#include "wifi/wifi.h"

#include <WiFi.h>

auto ssid = "AVT_HOOFD";
auto password = "AVTHOOFDEN1!";

bool connected = false;

void wifiSetup() {
    WiFiClass::mode(WIFI_STA);
    WiFi.begin(ssid, password);

    USBSerial.println("Connecting to WiFi...");
}

void wifiLoop() {
    static uint32_t ms = 0;
    if (millis() - ms > 500) {
        ms = millis();
        if (WiFiClass::status() == WL_CONNECTED && !connected) {
            connected = true;
            USBSerial.print("Connected! IP: ");
            USBSerial.println(WiFi.localIP());
        } else if (WiFiClass::status() != WL_CONNECTED && connected) {
            connected = false;
            USBSerial.println("Disconnected!");
        }
    }
}