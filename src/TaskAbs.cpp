#include "headers/TaskAbs.h"
#include <headers/globals.h>
void calcAbs(float brakePercentage)
{
    float absForce = absLowerThreshold * pow((brakePercentage - absUpperThreshold) / (absUpperThreshold - absLowerThreshold), 2) * maxBrakeForce;
    effectiveBrakeForce = absForce;
    LogMessage msg;
    snprintf(msg.message, sizeof(msg.message), "ABS activado: Fuerza de frenado efectiva = %.2f N", effectiveBrakeForce);
    xQueueSend(logQueue, &msg, pdMS_TO_TICKS(100));
}
void taskABS(void *parameter)
{
    for (;;)
    {
        float brakePercentage = analogRead(pinFreno) / 1023.0;
        if (!absActivated)
            return;
        if (brakePercentage > absUpperThreshold)
        {
            absWarningActive = true;
            calcAbs(brakePercentage);
        }
        else if (brakePercentage < absLowerThreshold)
        {
            effectiveBrakeForce = brakePercentage * maxBrakeForce;
            absWarningActive = false;
        }
    }
}
