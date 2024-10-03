//
// Created by KoenDR06 on 10/1/2024.
//

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include "wifi/wifi.h"
#include "env.h"

void wifiSetup() {
    WiFiClass::mode(WIFI_STA);
    WiFi.disconnect();
    WiFiClass::setHostname(WIFI_HOSTNAME);

    int n = WiFi.scanNetworks();
    bool foundTargetNetwork = false;
    for (int i = 0; i < n; i++) {
        if (WiFi.SSID(i) == WIFI_SSID) {
            foundTargetNetwork = true;
            break;
        }
    }
    if (!foundTargetNetwork) return;

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFiClass::status() != WL_CONNECTED) {
        delay(1000);
    }
}

void wifiLoop() {
    if (WiFiClass::status() == WL_DISCONNECTED) {
        WiFi.reconnect();
    }
}

void makeHttpsRequest(const std::string& server_url, const std::string& http_method, std::string path) {
    WiFiClientSecure client;

    client.connect(server_url.c_str(), 8080);

    client.println((http_method + " " + server_url + path).c_str());
    client.println("Host: www.howsmyssl.com");
    client.println("Connection: close");
    client.println();
}