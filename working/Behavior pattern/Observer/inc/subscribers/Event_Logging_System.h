#ifndef EVENT_LOGGING_SYSTEM_H
#define EVENT_LOGGING_SYSTEM_H

#include "../subscriber.h"

typedef struct
{
    Subscriber base;
    const char* logFile
}EvenLoggingSystem;

void eventLoggingSysteminit(EventLoggingSystem* logger, const char* fileName);
void eventLoggingUpdate(Subscriber* self, Publisher* context, const char* eventInfo)

#endif //Even_logging_system_h
#include <stdio.h>

