#include "headers/TaskLogger.h"
#include <headers/globals.h>
void taskLogger(void *parameter)
{

    LogMessage msg;
    for (;;)
    {
        if (xQueueReceive(logQueue, &msg, portMAX_DELAY) == pdTRUE)
        {
            Serial.println(msg.message);
        }
    }
}