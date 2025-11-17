#include "headers/ToggleABSInterrupt.h"
#include <headers/globals.h>
void interruptToggleABS()
{
    absActivated = !absActivated;
    Serial.println("ABS Toggled");
}