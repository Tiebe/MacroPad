//
// Created by tiebe on 19/09/2024.
//
//
// #include "wifi/wifi_manager.h"
//
// #include <WiFi.h>
//
// auto ssid = "AVT_HOOFD";
// auto password = "AVTHOOFDEN1!";
//
// bool connected = false;
//
// void wifiSetup() {
//     WiFiClass::mode(WIFI_STA);
//     WiFi.begin(ssid, password);
//
//     Serial.println("Connecting to WiFi...");
// }
//
// void wifiLoop() {
//     static uint32_t ms = 0;
//     if (millis() - ms > 500) {
//         ms = millis();
//         if (WiFiClass::status() == WL_CONNECTED && !connected) {
//             connected = true;
//             Serial.print("Connected! IP: ");
//             Serial.println(WiFi.localIP());
//         } else if (WiFiClass::status() != WL_CONNECTED && connected) {
//             connected = false;
//             Serial.println("Disconnected!");
//         }
//     }
// }