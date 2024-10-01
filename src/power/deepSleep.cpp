//
// Created by KoenDR06 on 9/27/2024.
//

#include "buttons/ButtonMode.h"
#include "buttons/buttons.h"
#include "power/deepSleep.h"

int shutdownCounter = 0;
bool led1 = false;
bool led2 = false;
bool led3 = false;
bool led4 = false;

#define SHUTDOWN_TIME 120

void checkShutdown(const bool shuttingDown) {
    if (shuttingDown) {
        shutdownCounter++;
    } else {
        if (shutdownCounter > SHUTDOWN_TIME / 6) {
            digitalWrite(LED_1, led1);
            digitalWrite(LED_2, led2);
            digitalWrite(LED_3, led3);
            digitalWrite(LED_4, led4);
        }
        shutdownCounter = 0;
    }

    if (shutdownCounter <= SHUTDOWN_TIME / 6) {
        led1 = digitalRead(LED_1);
        led2 = digitalRead(LED_2);
        led3 = digitalRead(LED_3);
        led4 = digitalRead(LED_4);
    } else if (shutdownCounter <= SHUTDOWN_TIME / 3) {
        digitalWrite(LED_1, LOW);
        digitalWrite(LED_2, LOW);
        digitalWrite(LED_3, LOW);
        digitalWrite(LED_4, LOW);
    } else if (shutdownCounter <= SHUTDOWN_TIME / 2) {
        digitalWrite(LED_1, HIGH);
    } else if (shutdownCounter <= SHUTDOWN_TIME * 2 / 3) {
        digitalWrite(LED_2, HIGH);
    } else if (shutdownCounter <= SHUTDOWN_TIME * 5 / 6) {
        digitalWrite(LED_3, HIGH);
    } else if (shutdownCounter <= SHUTDOWN_TIME) {
        digitalWrite(LED_4, HIGH);
    } else {
        shutdown();
    }
}

void shutdown() {
    digitalWrite(LED_1, LOW);
    delay(200);
    digitalWrite(LED_2, LOW);
    delay(200);
    digitalWrite(LED_3, LOW);
    delay(200);
    digitalWrite(LED_4, LOW);
    delay(200);
    printf("Bye bye o7\n");


    // all MACRO_KEYs
    uint64_t mask = 0;
    for (const auto gpio : DEFINED_BUTTONS) {
        mask |= 1 << gpio.GPIO;
    }
    esp_sleep_enable_ext1_wakeup(mask, ESP_EXT1_WAKEUP_ANY_HIGH);
    esp_deep_sleep_start();
}