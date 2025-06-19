#ifndef LIGHTING_SYSTEM_H
#define LIGHTING_SYSTEM_H

typedef struct 
{
    void turnOnLight();
    void turnOffLight();
    void setBrightness(int level);

}LightingSystem;

LightingSystem* creatLightingSystem();

#endif// lighting