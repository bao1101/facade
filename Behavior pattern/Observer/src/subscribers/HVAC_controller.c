#include "subscribers/HVAC_controller.h"
#include <stdio.h>

void HVACUpdate(Subscriber* self, Publisher* context, const char* eventInfo)
{
    (void)self; (void)context;
    printf("[HVACController] Alarm: %s\n", eventInfo);
}

void HVACControllerInit(HVACController* HVAC)
{
    HVAC->base.update = HVACUpdate;
    HVAC->base.data = NULL;
}