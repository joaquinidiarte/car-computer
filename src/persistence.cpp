#include <headers/Persistence.h>
#include <headers/globals.h>
void saveParameters()
{
    EEPROM.put(0, mass);
    EEPROM.put(4, maxPower);
    EEPROM.put(8, maxBrakeForce);
    EEPROM.put(12, lateralConstant);
    EEPROM.put(16, lateralAccelerationThreshold);
    EEPROM.put(20, absUpperThreshold);
    EEPROM.put(24, absLowerThreshold);
}

void loadParameters()
{
    if (EEPROM.read(0) == 0xFF)
    {
        // EEPROM no inicializada
        mass = 1200;
        maxPower = 75000;
        maxBrakeForce = 12000;
        lateralConstant = 0.0035;
        lateralAccelerationThreshold = 7.0;
        absUpperThreshold = 0.85;
        absLowerThreshold = 0.70;
        saveParameters(); // Guardar valores por defecto en EEPROM
        return;
    }
    EEPROM.get(0, mass);
    EEPROM.get(4, maxPower);
    EEPROM.get(8, maxBrakeForce);
    EEPROM.get(12, lateralConstant);
    EEPROM.get(16, lateralAccelerationThreshold);
    EEPROM.get(20, absUpperThreshold);
    EEPROM.get(24, absLowerThreshold);
}
