#ifndef MOVE_SENSOR_H
#define MOVE_SENSOR_H

#include "../publisher.h"

typedef struct 

{
    Publisher base;
    int Move;

}moverSensor;

void moverSensorInit (moverSensor* sensor);
void moverSensorTrigger (moverSensor* sensor, int Move);

#endif // Move sensor