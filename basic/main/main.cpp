/*
 * main.cpp
 *
 *  Created on: 26 jun 2024
 *      Author: Lucas Fabricio Monzon Languasco
 */

#include "esp32-hal-gpio.h"
#include "esp_attr.h"
#include <Arduino.h>
#include "stdintf.h"
#include <sys/_stdint.h>

bool estado = 0;

extern "C" esp_err_t STDINTF_Test(void);
extern "C" esp_err_t APP_Init(void);

void loop() {
	estado = !estado;
    Serial.println("Hello from Arduino on ESP-IDF!");
    delay(1000);
    digitalWrite(25, estado);
}

extern "C" void app_main() {
    initArduino();
    APP_Init();
    while (true) {
        loop();
    }
}