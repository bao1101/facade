    #include <stdio.h>
#include <stdlib.h>

#include "SmartHomeFacade.h"

SmartHomeFacade* creatSmartHomeFacade()
{
    SmartHomeFacade* facade = (SmartHomeFacade*)malloc(sizeof(SmartHomeFacade));
    facade->lighting = creatLightingSystem();
    facade->hvac = creatHvacSystem();
    facade->security = creatSecuritySystem();
    return facade;
}


void activeMorningRoutine(SmartHomeFacade* facade)
{
    printf("[SmartHomeFacade] Activating Morning Routine...\n");
    facade->lighting->turnOnLight();
    facade->hvac->setTempurature(22);
    facade->security->deactiveAlarm();
    facade->lighting->setBrightness(50);
    facade->hvac->setModeCooling()
}

void activeAwayRoutine(creatSmartHomeFacade* facade)
{
    printf("[Smart Home Facade] Active Away Routine...\n");
    facade->lighting->turnOffLight();
    facade->hvac->setTempurature(26);
    facade->security->activeAlarm();

}

void setMovieNightScene(creatSmartHomeFacade* facade)
{
    printf("[Smart Home Facade] Active Movie Night Scene...\n");
    facade->lighting->setBrightness(20);
    facade->hvac->setModeCooling();
    facade->security->activeAlarm();
}
