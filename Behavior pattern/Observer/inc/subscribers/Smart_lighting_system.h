#ifndef SMART_LIGHTING_SYSTEM_H
#define SMART_LIGHTING_SYSTEM_H

#include "../subscriber.h"

typedef struct 
{
    Subscriber base;
}SmartLightingSystem;

void smartLightingSystemInit(SmartLightingSystem* lighting);

#endif //smart lighting system.h