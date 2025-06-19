#ifndef WATERING_LOGIC_H
#define WATERING_LOGIC_H

#include "config.h"

void watering_logic_init();

void handle_auto_watering_logic();

void handle_manual_watering_logic();

void update_led_status();

#endif // WATERING_LOGIC_H