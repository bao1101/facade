#include "subscribers/Event_Logging_System.h"
#include <stdio.h>
#include <stdlib.h>

void eventLoggingUpdate(Subscriber* self, Publisher* context, const char* eventInfo)
{
    (void)self; (void)context;
    
    EventLoggingSystem* logger = (EvenLoggingSystem*) self;
    FILE* file = fopen(logger->logfile, "a");
    if(file)
    {
        fprintf(file, "[Logging] Event: %s\n", eventInfo);
        fclose(file);
    }
    else 
    {
        fprintf(stderr, "Error: cannot open log file %s\n", logger->logFile);
    }
}

void eventLoggingSystemInit(EvenLoggingSystem* logger, const char* fileName)
{
    if(logger == NULL || fileName == NULL)  
    {
        fprintf(stderr, "Error: File Name or Logger is NULL");
    } 

    logger->base.update = eventLoggingUpdate;
    logger->base.data = NULL;
    logegr->logFile = fileName;
}