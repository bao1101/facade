#include "HVAC.h"
#include <stdio.h>
#include <stdlib.h>

void setTempurature(int tmp)
{
    printf("[HVAC] tempurature set to %d", tmp);

}
void setModeCooling()
{
    printf("[HVAC] mode set to cooling:");
}
void setModeHeating()
{
    printf("[HVAC] mode set to heating:");

}

HVACSystem* creatHvacSystem()
{
    HVACSystem* system = (HVACSystem*)malloc(sizeof(HVACSystem));
    system->setTempurature = setTempurature;
    system->setModeCooling = setModeCooling;
    system->setModeHeating = setModeHeating;
    return system;
}

