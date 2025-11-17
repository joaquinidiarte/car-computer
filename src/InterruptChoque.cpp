#include "headers/InterruptChoque.h"
#include <headers/globals.h>
void interruptChoque()
{
    crashed = true;
    Serial.println("¡Choque detectado!");
}