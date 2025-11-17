#include <headers/TaskStatus.h>
#include <headers/globals.h>

void yellowLed()
{
    analogWrite(pinRojo, 255);
    analogWrite(pinVerde, 80);
}

void orangeLed()
{
    analogWrite(pinRojo, 255);
    analogWrite(pinVerde, 20);
}

void greenLed()
{
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 255);
}

void redLed()
{
    analogWrite(pinRojo, 255);
    analogWrite(pinVerde, 0);
}
void apagarLed()
{
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 0);
}
void taskStatus(void *parameter)
{
    for (;;)
    { // Loop infinito obligatorio
        if (crashed)
        {
            redLed();
        }
        else if (absWarningActive)
        {
            orangeLed();
        }
        else if (!absActivated)
        {
            yellowLed();
        }
        else
        {
            greenLed();
        }
        vTaskDelay(pdMS_TO_TICKS(500));
        apagarLed();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
