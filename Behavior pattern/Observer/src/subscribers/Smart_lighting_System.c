#include "subscribers/Smart_lighting_system.h"
#include <stdio.h>

void smartLightingUpdate(Subscriber*self, Publisher*context, const char* eventInfo)
{
    (void)self; (void)context;
    printf("[LightingSystem] Alarm: %s\n", eventInfo);
}

void smartLightingSystemInit(SmartLightingSystem* lighting)
{
    lighting->base.update = smartLightingUpdate;
    lighting->base.data = NULL;
}