#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "stdintf.h"

#define MYSECTION_ATTR __attribute__((section(".my_section")))

MYSECTION_ATTR uint8_t mydata[128];

const char *STDINTF = "INTF";

void STDINTF_Task(void* pvParameters);

esp_err_t STDINTF_Test(void)
{
	ESP_LOGI(STDINTF, "Test component");
	return ESP_OK;
}

void STDINTF_InitData(void)
{
	uint32_t i = 0;
	size_t mydata_len = sizeof(mydata)/sizeof(mydata[0]);
	for(i = 0; i < mydata_len; i++)
	{
		mydata[i] = i;
	}
}

void STDINTF_Task(void* pvParameters)
{
	while(1)
	{
		ESP_LOGI(STDINTF,"Running Task");
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}