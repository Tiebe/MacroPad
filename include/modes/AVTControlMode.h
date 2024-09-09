//
// Created by tiebe on 09/09/2024.
//

#ifndef AVTCONTROLMODE_H
#define AVTCONTROLMODE_H
#include "buttons/ButtonMode.h"

ButtonMode getAVTControlMode();
void addSunCallbacks(ButtonMode &mode);
void addBeamerDrapeCallbacks(ButtonMode &mode);
void addBeamerIRCallbacks(ButtonMode &mode);

#endif //AVTCONTROLMODE_H
