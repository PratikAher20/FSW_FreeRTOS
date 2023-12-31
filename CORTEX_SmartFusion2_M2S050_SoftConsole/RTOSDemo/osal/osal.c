#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include <FreeRTOS-Source/include/task.h>
#include "osal.h"


void vTask_Delay(uint16_t timems){
	TickType_t tick_for_time;

	tick_for_time = pdMS_TO_TICKS(timems);

	vTaskDelay(tick_for_time);

}

TickType_t xMsToTicks(uint16_t timems){
	return pdMS_TO_TICKS(timems);
}
