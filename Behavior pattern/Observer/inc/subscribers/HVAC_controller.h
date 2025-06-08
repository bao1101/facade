#ifndef HVAC_CONTROLLER_H
#define HVAC_CONTROLLER_H

#include "../subscriber.h"

typedef struct 
{
    Subscriber base;
}HVACController;

void HVACControllerInit(HVACController* HVAC);

#endif //HVACController