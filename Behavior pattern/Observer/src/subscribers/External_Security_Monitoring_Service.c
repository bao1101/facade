#include "subscribers/External_Security_Monitoring_Service.h"
#include <stdio.h>

void externalSecurityMonitoringUpdate(Subscriber* self, Publisher* context, const char* eventInfo)
{
    (void)self; (void)context;
    printf("[ExternalSecurityMonitoring] Alarm: %s\n", eventInfo);
}

void externalSecuritMonitoringServiceInit(ExternalSecurityMonitoringService* Service)
{
    Service->base.update = externalSecurityMonitoringUpdate;
    Service->base.data = NULL;
}