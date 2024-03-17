//
// Created by KoenDR06 on 3/15/24.
//

#ifndef MACROPAD_API_H
#define MACROPAD_API_H

#include <HTTPClient.h>
#include <map>

int send(const std::string& path, const std::map<std::string, std::string>& arguments);

#endif //MACROPAD_API_H
