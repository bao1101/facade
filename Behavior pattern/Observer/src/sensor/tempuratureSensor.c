#include "sensor/temperatureSensor.h"
#include <stdio.h>

void tempuratureSensorInit(tempuratureSensor* sensor)
{
    publisherInit(&sensor->base);
    sensor->tempuratureDetected;
}

void tempuratureSensorTrigger(tepuratureSensor* sensor, int tempuratureSensor)
{
    sensor->temperatureSensor = 0;
    if (detected) 
    {
        sensor->base.notifySubscirber(&sensor->base, "Tempurature detected");
    }
    else
    {
        sensor->base.notifySubscirber(&sensor->base, "No tempurature detected");
    }
    
}