#ifndef WATER_SENSOR_H
#define WATER_SENSOR_H

#include "../publisher.h"

typedef struct 
{
    Publisher base;
    int waterFlows;
}waterSensor;

void waterSensorInit(waterSensor* sensor);
void waterSensorTrigger(waterSensor* sensor, int waterFlows);

#endif // water sensor