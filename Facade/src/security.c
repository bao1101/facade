#include "security.h"
#include <stdio.h>
#include <stdlib.h>

void activeAlarm()
{
    printf("[Security System] active alarm");
}

void deactiveAlarm()
{
    printf("[Security System] deactive alarm");
}

SecuritySystem* creatSecuritySystem()
{
    SecuritySystem* system = (SecuritySystem*)malloc(sizeof(SecuritySystem));
    system->activeAlarm = activeAlarm;
    system->deactiveAlarm = deactiveAlarm;
    return system;
}
