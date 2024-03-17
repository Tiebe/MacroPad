//
// Created by KoenDR06 on 3/15/24.
//

#include <api.h>
#include <map>
#include <cstring>
#include <string>

int send(const std::string& path, const std::map<std::string, std::string>& arguments) {
    // const char* base_url = "api.avtolz.nl/";
    const char* base_url = "localhost:8080/";
    const char* Line2 = path.c_str();
    char* url{new char[strlen(base_url) + strlen(Line2) + 1] };
    url = strcpy(url, base_url);
    url = strcat(url, Line2);


    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    std::string args;

    for (const auto& arg : arguments) {
        args += arg.first;
        args += "=";
        args += arg.second;
        args += "&";
    }
    args.pop_back();


    return http.POST(String(args.c_str()));
}