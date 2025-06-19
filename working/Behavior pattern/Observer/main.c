#include "sensor/doorSensor.h"
#include "sensor/moveSensor.h"
#include "sensor/smokeSensor.h"
#include "sensor/temperatureSensor.h"
#include "sensor/waterSensor.h"

#include "subscribers/alarm_system_controller.h"
#include "subscribers/Event_Logging_System.h"
#include "subscribers/External_Security_Monitoring_Service.h"
#include "subscribers/HVAC_controller.h"
#include "subscribers/mobile_app_notifier.h"
#include "subscribers/Smart_lighting_system.h"

#include<stdio.h>

int main()
{
//Initialize sensor (publisher)    
    doorSensor doorSensor;
    doorSensorInit(&doorSensor);

    smokeSensor smokeSensor;
    smokeSensorInit(&smokeSensor);

    moverSensor moverSensor;
    moverSensorInit(&moverSensor);

    tempuratureSensor tempuratureSensor;
    tempuratureSensorInit(&tempuratureSensor);

    waterSensor waterSensor;
    waterSensorInit(&waterSensor);

//Initialize subscribers
    AlarmSystemController alarmSystem;
    alarmSystemControllerInit(&alarmSystem);

    MobileAppNotifier mobileApp;
    mobileAppNotifierInit(&mobileApp);

    EvenLoggingSystem eventLogging;
    eventLoggingSysteminit(&eventLogging);

    ExternalSecurityMonitoringService externalSecurity;
    externalSecuritMonitoringServiceInit(&externalSecurity);

    HVACController HVAC;
    HVACControllerInit(&HVAC);

    SmartLightingSystem smartLighting;
    smartLightingSystemInit(&smartLighting);

//Register subscriber to door sensor (publisher)
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&mobileApp);
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&alarmSystem);
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&eventLogging);
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&externalSecurity);
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&HVAC);
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&smartLighting);

    // Register subsciber to smoke sensor (publisher)
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&mobileApp);
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&alarmSystem);
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&eventLogging);
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&externalSecurity);
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&HVAC);
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&smartLighting);

    // Register subsciber to water sensor (publisher)
    waterSensor.base.subscribe(&waterSensor.base, (Subscriber*)&mobileApp);
    waterSensor.base.subscribe(&waterSensor.base, (Subscriber*)&alarmSystem);
    waterSensor.base.subscribe(&waterSensor.base, (Subscriber*)&eventLogging);
    waterSensor.base.subscribe(&waterSensor.base, (Subscriber*)&externalSecurity);
    
    // Register subsciber to move sensor (publisher)
    moveSensor.base.subscribe(&moveSensor.base, (Subscriber*)&mobileApp);
    moveSensor.base.subscribe(&moveSensorr.base, (Subscriber*)&alarmSystem);
    moveSensor.base.subscribe(&moveSensor.base, (Subscriber*)&eventLogging);
    moveSensor.base.subscribe(&moveSensor.base, (Subscriber*)&externalSecurity);
    moveSensor.base.subscribe(&moveSensor.base, (Subscriber*)&HVAC);
    moveSensor.base.subscribe(&moveSensor.base, (Subscriber*)&smartLighting);

    // Register subscriber to tempurature sensor (publisher)
    tempuratureSensor.base.subscribe(&tempuratureSensor.base, (Subscriber*)&mobileApp);
    tempuratureSensor.base.subscribe(&tempuratureSensorr.base, (Subscriber*)&alarmSystem);
    tempuratureSensor.base.subscribe(&tempuratureSensor.base, (Subscriber*)&eventLogging);
    tempuratureSensor.base.subscribe(&tempuratureSensor.base, (Subscriber*)&externalSecurity);
    tempuratureSensor.base.subscribe(&tempuratureSensor.base, (Subscriber*)&HVAC);
   
    return 0;
}
