#ifndef SMOKE_SENSOR_H
#define SMOKE_SENSOR_H

#include "../publisher.h"

typedef struct 
{
    Publisher base;
    int smokeDetected;

}smokeSensor;

void smokeSensorInit(smokeSensor* sensor);
void smokeSensorTrigger(smokeSensor* sensor, int smokeDetected);

#endif //smoke sensor