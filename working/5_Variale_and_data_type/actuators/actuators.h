#ifndef ACTUATORS_H
#define ACTUATORS_H

#include"config.h"

void actuators_init();

void turn_pump_on();

void turn_pump_off();

void set_led_state(LedState_t state);

#endif // ACTUATORS_H