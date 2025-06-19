#ifndef EXTERNAL_SECURITY_MONITORING_SERVICE_H
#define EXTERNAL_SECURITY_MONITORING_SERVICE_H

#include "../subscriber.h"

typedef struct
{
    Subscriber base;
}ExternalSecurityMonitoringService;

void externalSecuritMonitoringServiceInit(ExternalSecurityMonitoringService* Service);

#endif //external_security_monitoring_service_h