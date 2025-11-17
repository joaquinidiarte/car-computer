#include <Arduino_FreeRTOS.h>
#include <queue.h>
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
// Variables globales accidentado
extern volatile bool crashed;
extern volatile bool absActivated;
extern volatile bool absWarningActive;

// ## Pines ##
// Acelerometros
extern int pinAcelerador;
extern int pinFreno;
extern int pinVolante;

// Botones
extern int pinSensorChoque;
extern int pinToggleABS;

// Colores led
extern int pinRojo;
extern int pinVerde;

// Variables de parámetros del vehículo
extern float mass;                         // Kg
extern float maxPower;                     // Watts
extern float maxBrakeForce;                // N
extern float lateralConstant;              // 1/(rad · s)
extern float lateralAccelerationThreshold; // m/s²
extern float absUpperThreshold;            // %
extern float absLowerThreshold;            // %
extern float effectiveBrakeForce;          // N

// Cola de mensajes para el logger
extern QueueHandle_t logQueue;

#define LOG_MESSAGE_SIZE 128
typedef struct
{
    char message[LOG_MESSAGE_SIZE];
} LogMessage;

#endif