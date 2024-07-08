#include <stdio.h>
#include "esp_err.h"
#include "app.h"
#include "wrapper.h"

const char *APP = "APP";

void APP_Task(void* pvParameters);

esp_err_t APP_Test(void)
{
	ESP_LOGI(APP, "Test component");
	
	/* Test stdintf functions */
	STDINTF_Test();
	
	return ESP_OK;
}

esp_err_t APP_Init(void)
{
	ESP_LOGI(APP, "Init app");
	
	/* Create APP task */
	xTaskCreatePinnedToCore(APP_Task, "app_task", 2048, NULL, 1, NULL, PRO_CPU_NUM);

	return ESP_OK;
}

void APP_Task(void* pvParameters)
{
	while(1)
	{
		ESP_LOGI(APP, "Running Task");
		vTaskDelay(1000/portTICK_PERIOD_MS);
		APP_Test();
	}
	
	/* Should never get here unless wanted*/
}