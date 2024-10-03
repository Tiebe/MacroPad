//
// Created by KoenDR06 on 10/1/2024.
//

#ifndef WIFI_H
#define WIFI_H

void wifiSetup();
void wifiLoop();
void makeHttpsRequest(const std::string& server_url, const std::string& http_method, std::string path);

#endif //WIFI_H
