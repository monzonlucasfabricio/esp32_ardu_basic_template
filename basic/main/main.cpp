/*
 * main.cpp
 *
 *  Created on: 26 jun 2024
 *      Author: Lucas Fabricio Monzon Languasco
 */

#include "esp32-hal-gpio.h"
#include "esp_attr.h"
#include <Arduino.h>
#include <sys/_stdint.h>

#define MYSECTION_ATTR __attribute__((section(".my_section")))

MYSECTION_ATTR uint8_t mydata[128];

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

void init_data(void)
{
	uint32_t i = 0;
	size_t mydata_len = sizeof(mydata)/sizeof(mydata[0]);
	for(i = 0; i < mydata_len; i++)
	{
		mydata[i] = i;
	}
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
    init_data();
    while (true) {
        loop();
    }
}