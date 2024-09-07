//
// Created by tiebe on 2/28/2024.
//

#ifndef BUTTONMODE_H
#define BUTTONMODE_H



class ButtonMode {
public:
    int ledState;
    bool empty;
    std::map<int, std::pair<int, std::function<void(int button, bool state)>>> callbacks;

    ButtonMode(int led_state);
    ButtonMode(int led_state, std::map<int, std::pair<int, std::function<void(int button, bool state)>>> buttonCallbacks);
    ButtonMode();
    int addButtonCallback(const int gpio, const std::function<void(int button, bool state, bool controlState)>& callback);
    void removeButtonCallback(const int id);
    void writeLedState();

private:
    ButtonData* getButton(int button);
};



#endif //BUTTONMODE_H
