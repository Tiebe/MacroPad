//
// Created by KoenDR06 on 3/15/24.
//

#include <api.h>
#include <map>

int call(const std::string& path, const std::map<std::string, std::string>& arguments) {
    HTTPClient http;
    http.begin("https://api.avtolz.nl/"+path);
    http.addHeader("Content-Type", "application/json");

    String args;

    for (const auto& arg : arguments) {
        args += arg.first;
        args += "=";
        args += arg.second;
        args += "&";
    }
    args.pop_back();


    return http.POST("api.avtolz.nl/"+path, args);
}