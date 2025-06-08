#include "HVAC.h"
#include "lighting.h"
#include "security.h"
#include "SmartHomeFacade.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    SmartHomeFacade* smartHome = creatSmartHomeFacade();
    activeMorningRoutine(smartHome);
    activeAwayRoutine(smartHome);
    setMovieNightScene(smartHome);

    printf("\n Freeing allocated memory...\n");
    free(smartHome->lighting);
    free(smartHome->hvac);
    free(smartHome->security);
    free(smartHome);
}
