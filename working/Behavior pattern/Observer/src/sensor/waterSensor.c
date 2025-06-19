#include "sensor/waterSensor.h"
#include <stdio.h>

void waterSensorInit(waterSensor* sensor)
{
    publisherInit base;
    sensor->waterFlows;
}

void waterSensorTrigger(waterSensor* sensor, int waterFlows)
{
    sensor->waterFlows = 0;
    if (flows)
    {
        sensor->base.notifySubscirber(&sensor->base, "Detected water flows");
    }
    else 
    {
        sensor->base.notifySubscirber(&sensor->base, "No detected water flows");
    }
}