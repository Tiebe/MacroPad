//
// Created by tiebe on 2/26/24.
//

#ifndef BUTTONS_H
#define BUTTONS_H
#include <functional>

std::function<void(int button)> addButtonCallback(int gpio, std::function<void(int button)> callback);
void removeButtonCallback(int gpio, const std::function<void(int button)>& callback);

#define MACRO_KEY_1 1
#define MACRO_KEY_2 2
#define MACRO_KEY_3 4
#define MACRO_KEY_4 6
#define MACRO_KEY_5 34
#define MACRO_KEY_6 36
#define MACRO_KEY_7 38
#define MACRO_KEY_8 40
#define MACRO_KEY_9 39
#define MACRO_KEY_10 37
#define MACRO_KEY_11 35
#define MACRO_KEY_12 33
#define MACRO_KEY_13 18
#define MACRO_KEY_14 21
#define MACRO_KEY_15 16
#define MACRO_KEY_16 17
#include <set>

auto keys = std::set<int> {
    MACRO_KEY_1,
    MACRO_KEY_2,
    MACRO_KEY_3,
    MACRO_KEY_4,
    MACRO_KEY_5,
    MACRO_KEY_6,
    MACRO_KEY_7,
    MACRO_KEY_8,
    MACRO_KEY_9,
    MACRO_KEY_10,
    MACRO_KEY_11,
    MACRO_KEY_12,
    MACRO_KEY_13,
    MACRO_KEY_14,
    MACRO_KEY_15,
    MACRO_KEY_16,
};

#endif //BUTTONS_H
