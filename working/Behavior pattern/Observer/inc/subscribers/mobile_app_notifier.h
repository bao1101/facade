#ifndef MOBILE_APP_NOTIFIER_H
#define MOBILE_APP_NOTIFIER_H

#include "../subscriber.h"

typedef struct 
{
    Subscriber base;
    /* data */
}MobileAppNotifier;

void mobileAppNotifierInit(MobileAppNotifier* notifier);

#endif //mobile_app_notifier_h