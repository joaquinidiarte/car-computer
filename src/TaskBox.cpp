#include <headers/globals.h>
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
void taskBox(void *parameter)
{
    LogMessage msg;

    for (;;)
    {
        snprintf(msg.message, sizeof(msg.message),
                 "Estado - Vel: %.2f m/s | Acel: %.1f%% | Freno: %.1f%%",
                 currentSpeed,
                 appliedThrottlePercentage * 100.0f,
                 effectiveBrakePercentage * 100.0f);

        xQueueSend(logQueue, &msg, pdMS_TO_TICKS(10));
        vTaskDelay(pdMS_TO_TICKS(350));
    }
}