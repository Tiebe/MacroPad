//
// Created by tiebe on 07/09/2024.
//

#ifndef BUTTONDATA_H
#define BUTTONDATA_H

struct ButtonData {
    int GPIO;
    bool state;
    unsigned long millisLastPressed;
};

#endif //BUTTONDATA_H
