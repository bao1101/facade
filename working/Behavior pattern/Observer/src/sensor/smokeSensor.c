#include "sensor/smokeSensor.h"
#include <stdio.h>

void smokeSensorInit(smokeSensor* sensor)
{
    publisherInit(&sensor->base);
    sensor->smokeDetected;
}

void smokeSensorTrigger(smokeSensor* sensor, int smokeDetected)
{
    sensor->smokeDetected = detected;
    if (detected)
    {
        sensor->base.notifySubscirber(&sensor->base, "Smoke detected");
    }
    else
    {
        sensor->base.notifySubscirber(&sensor->base, "No smoke");
    }
    
    
}