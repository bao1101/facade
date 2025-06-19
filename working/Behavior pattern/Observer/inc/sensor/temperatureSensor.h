#ifndef TEMPURATURE_SENSOR_H
#define TEMPURATURE_SENSOR_H

#include "../publisher.h"

typedef struct 
{
    Publisher base;
    int tempuratureDetected;
}tempuratureSensor;

void tempuratureSensorInit(tempuratureSensor* sensor);
void tempuratureSensorTrigger(tepuratureSensor* sensor, int tempuratureSensor);

#endif //tempuratureSensor