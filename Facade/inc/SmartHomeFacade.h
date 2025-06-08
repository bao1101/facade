#include "lighting.h"
#include "security.h"
#include "HVAC.h"

typedef struct 
{
    LightingSystem* lighting;
    SecuritySystem* security;
    HVACSystem* hvac;
}SmartHomeFacade;

SmartHomeFacade* creatSmartHomeFacade();

void activeMorningRoutine(SmartHomeFacade* facade);
void activeAwayRoutine(SmartHomeFacade* facade);
void setMovieNightScene(SmartHomeFacade* facade);

#endif //Smart Home Facade.h
