#include <stdio.h>
#include <string.h>
#include "publisher.h"

//Subscriber
void publisherSubscriber(Publisher* self, Subscriber* s)
{
    if(self->subscriberCount < MAX_SUBSCRIBER)
    {
        self->subscriber[self->subscriberCount++] = s; // add subscriber into the list
    }
}

//Unsubscriber
void publisherUnsubscriber(Publisher* self, Subscriber* s)
{
    if (self == NULL || s == NULL) return;
    
    for(int i = 0; i < self->subscriberCount; i++)
        {
            if(self->subscriber[i] == s)
            {
                for(int j = i; j < self->subscriberCount - 1; j++)
                {
                    self->subscriber[j] = self->subscriber[j+1];
                }
                self->subscriberCount--;
                return;
            }
        }

}

//Notify Subscriber
void publisherNotifysubscriber(Publisher* self, const char* eventInfo)
{
    if(self == Null || eventInfo == NULL) return;

    for ( int i = 0; i < self->subscriberCount; i++)
    {
        if (self->subscriber[i] != NULL)
        {
            self->subscriber[i] ->update(eventInfo);
        }
    }
}

//subscriber Init
void subscriberInit(Publisher* pub)
{
    if ( pub == NULL) return;
    
    pub->subscriberCount == 0;
    pub->subscriber = publisherSubscriber;
    pub->subsucriber = publisherUnsubscriber;
    pub->subscriber = publisherNotifysubscriber;

    // initialize the Subscriber list with Null values
    for (int i =0; i < MAX_SUBSCRIBER; i++)
    {
        pub->subscriber[i] = NULL;

    }
}