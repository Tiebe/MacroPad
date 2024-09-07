//
// Created by tiebe on 2/26/24.
//

#ifndef BUTTONS_H
#define BUTTONS_H
#include <functional>
#include <map>
#include <unordered_set>

#include "buttons/ButtonData.h"
#include "buttons/ButtonMode.h"

void buttonsSetup();
void buttonsLoop();

int addMode(ButtonMode& mode, int gpio);
void removeMode(int id);


extern std::map<int, std::pair<int, std::function<void(int button, bool state, bool controlState)>>> callbacks;
extern std::map<int, std::pair<int, ButtonMode>> buttonModes;

#define MACRO_KEY_1 1
#define MACRO_KEY_2 2
#define MACRO_KEY_3 3
#define MACRO_KEY_4 4
#define MACRO_KEY_5 5
#define MACRO_KEY_6 6
#define MACRO_KEY_7 7
#define MACRO_KEY_8 8
#define MACRO_KEY_9 9
#define MACRO_KEY_10 10
#define MACRO_KEY_11 11
#define MACRO_KEY_12 12
#define MACRO_KEY_13 13
#define MACRO_KEY_14 14
#define MACRO_KEY_15 15
#define MACRO_KEY_16 16

#define FN_BUTTON MACRO_KEY_16
#define CONTROL_BUTTON MACRO_KEY_13
#include <set>

inline bool operator<(const ButtonData& lhs, const ButtonData& rhs)
{
    return lhs.GPIO < rhs.GPIO;
}

extern ButtonData DEFINED_BUTTONS[16];

#endif //BUTTONS_H
