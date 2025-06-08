#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include "../publisher.h"

//DoorSensor
typedef struct 
{
    Publisher base;
    int isOpen;
}doorSensor;

void doorSensorInit(doorSensor* sensor);
void doorSensorTrigger(doorSensor* sensor, int open);

#endif // doorSensor
