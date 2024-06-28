/*
 * main.cpp
 *
 *  Created on: 26 jun 2024
 *      Author: Lucas Fabricio Monzon Languasco
 */

#include "esp32-hal-gpio.h"
#include <Arduino.h>

bool estado = 0;

void test(void* pvParameters)
{
	ESP_LOGI("TEST", "TEST TASK");
	while(1)
	{
		Serial.println("Hello from Arduino on ESP-IDF!");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}


void setup() {
    Serial.begin(115200);
    pinMode(25, OUTPUT);
    xTaskCreatePinnedToCore(test, "test_task", 2048, NULL, 1, NULL, PRO_CPU_NUM);
}


void loop() {
	estado = !estado;
    Serial.println("Hello from Arduino on ESP-IDF!");
    delay(1000);
    digitalWrite(25, estado);   
}

extern "C" void app_main() {
    initArduino();
    setup();
    while (true) {
        loop();
    }
}