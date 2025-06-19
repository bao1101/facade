#include"actuator.h"
#include"config.h"
#include"system_monitor.h"
#include"system_time.h"
#include<stdio.h>

extern SystemStatus_t g_system_status;

void actuators_init()
{
    printf("[Actuators]: Initializing pump and Led hardware...\n");

    g_system_status.pump_state = PUMP_OFF;
    g_system_status.led_state = LED_NORMAL;
}

void turn_pump_on()
{
    if(g_system_status.pump_state != PUMP_ON)
    {
        g_system_status.pump_state = PUMP_ON;
        //record when the pump starts working to caculate the watering time
        g_system_status.pump_start_time_ms = get_current_time_ms;
        system_monitor_send_message(LOG_LEVEL_INFO, "Pump: ON - Watering stated.");
    }
}

void turn_pump_off()
{
    if(g_system_status.pump_state != PUMP_OFF)
    {
        g_system_status.pump_state = PUMP_OFF;
        //Be sure tp turn off the manual irrifation flag when the pump is off
        g_system_status.is_watering_manual = false;
        system_monitor_send_message(LOG_LEVEL_INFO, "Pump : OFF - Watering stopped" );
    }
}

void set_led_state(LedState_t state)
{
    // change the led only if it different from the current state
    if(g_system_status.led_state != state)
    {
        g_system_status.led_state = state;
        char* led_message;
        switch (state)
        {
        case LED_NORMAL:
            led_message = "NORMAL ( Green)";
            break;
        
        case LED_WATERING:
            led_message = "WATERING (Yellow)";
            break;
        case LED_LOW_MOISTURE_ALERT:
            led_message = "LOW MOISTURE (Red)";
            break;
        case LED_ERROR:
            led_message "UNKNOW";
            break;
        }
         char log_buffer[50];
         snprintf(log_buffer, sizeof(log_buffer), "LED : %s", led_message);
         system_monitor_send_message(LOG_LEVEL_INFO, log_buffer);
    }
}
    