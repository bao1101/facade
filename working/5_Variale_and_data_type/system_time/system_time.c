#include <time.h>
#include <stdbool.h>
#include "system_time.h"

static clock_t start_time_ticks;

static bool timer_initialized = false;

void init_system_timer() {
    if (!timer_initialized) 
    {
        start_time_ticks = clock();
        timer_initialized= true;
    }
}

unsigned long get_current_time_ms()
{
    if (!timer_initialized)
    {
        init_system_timer();
    }

    // get the current tick count and caculate the different from the initilization time
    clock_t current_tick = clock();
    double elapsed_second = (double)(current_tick - start_time_ticks); 
    return (unsigned long)(elapsed_second * 1000.0); // milisecond
}

void delay_ms(unsigned int ms)
{
    unsigned long start_delay_time = get_current_time_ms();
    while (get_current_time_ms - start_delay_time < ms)
    {
        /* code */
    }
    
}