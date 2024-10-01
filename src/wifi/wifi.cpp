//
// Created by KoenDR06 on 10/1/2024.
//

#include <WiFi.h>

#include "wifi/wifi.h"

void wifiSetup() {
    WiFi.mode(WIFI_STA);

    WiFi.disconnect();
    WiFi.begin("ssid", "passcode");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}
