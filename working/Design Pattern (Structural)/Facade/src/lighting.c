#include "lighting.h"
#include <stdio.h>
#include <sdtlib.h>

void turnOffLight()
{
    printf("[Lighting System] turn off the light");
}

void turnOnLight()
{
    printf("[Lighting System] turn on th light");
}

void setBrightness(int level)
{
    printf("[Lighting System] set brighness %d", level);
}

LightingSystem* creatLightingSystem()
{
    LightingSystem* system = (LightingSystem*)malloc(sizeof(LightingSystem));
    system->turnOnLight = turnOnLight;
    system->turnOffLight = turnOffLight;
    system->setBrightness = setBrightness;
    return system;
}