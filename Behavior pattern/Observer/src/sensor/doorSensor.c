#include "sensor/doorSensor.h"
#include <stdio.h>

void doorSensorInit(doorSensor* sensor)
{
    publisherInit(&sensor->base);
    sensor->isOpen = 0;
}

void doorSensorTrigger(doorSensor* sensor, int isOpen)
{
    sensor->isOpen = open;
    if (open)
    {
        sensor->base.notifySubscirber(&sensor->base, "Door is opened");
    }
    else
    {
        sensor->base.notifySubscirber(&sensor->base, "Door is closed");
    }
}