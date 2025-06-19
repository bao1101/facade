#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "subscriber.h"
#define MAX_SUBSCRIBERS 10
typedef struct Publisher
{
    Subscriber* subscriber[MAX_SUBSCRIBERS];
    int subscriberCount;
    
    void (*subscribe) (struct Publisher* self, Subscriber* s);
    void (*unsubscribe) (struct Publisher* self, Subscriber* s);
    void (*notifySubscribe) (struct Publisher* self, const char* evenInfor);

} Pulisher;
 
void publisherInit(Publisher* pub);

#endif // Publisher.h
