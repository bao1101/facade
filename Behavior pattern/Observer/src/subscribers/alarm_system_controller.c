#include "subscribers/alarm_system_controller.h"
#include <stdio.h>

void alarmSystemUpdate(Subscriber* self, Publisher* context, const char* eventInfor)
{
    (void)self; (void)context;
    printf("[AlarmSystem] Alarm: %s\n", evenInfor);
}

void alarmSystemControllerInit(AlarmSystemController* controller)
{
    controller->base.update = AlarmSystemUpdate;
    controller->base.data = NULL;
}