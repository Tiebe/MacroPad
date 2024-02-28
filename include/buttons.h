//
// Created by tiebe on 2/26/24.
//

#ifndef BUTTONS_H
#define BUTTONS_H
#include <functional>
#include <map>
#include <unordered_set>
#include <vector>

int addButtonCallback(int gpio, const std::function<void(int button)>& callback, bool withFn);
void removeButtonCallback(int id, bool withFn);

void buttonsSetup();
void buttonsLoop();

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

#define FN_BUTTON MACRO_KEY_16
#include <set>

struct ButtonData {
    int GPIO;
    bool state;
    unsigned long millisLastPressed;
};

inline bool operator<(const ButtonData& lhs, const ButtonData& rhs)
{
    return lhs.GPIO < rhs.GPIO;
}

extern ButtonData DEFINED_BUTTONS[16];

#endif //BUTTONS_H
