#include "sensor/moveSensor.h"
#include <stdio.h>

void moverSensorInit(moverSensor* sensor)
{
    publisherInit(&sensor->base);
    sensor->moveSensor = 0;
}

void moverSensorTrigger(moverSensor* sensor, int noMove)
{
    sensor->Move = Move;
    if(Move)
    {
        sensor->base.notifySubscirber(&sensor->base, "Detecting movement");
    }
    else
    {
        sensor->base.notifySubscirber(&sensor->base, "No detecting movement");
    }
}