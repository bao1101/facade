#include "watering_logic.h"
#include "config.h"
#include "actuators.h"
#include "system_monitor.h"
#include "system_timer.h" 
#include <stdio.h>

extern SystemStatus_t g_system_status;

void watering_logic_init()
{
    printf("Watering Logic: Initialized.\n");
}

void handle_auto_watering_logic() {
    if (g_system_status.settings.current_mode == MODE_AUTO)
    {
        if (g_system_status.pump_state == PUMP_OFF)
        {
            if (g_system_status.sensor_data.soil_moisture_percent < g_system_status.settings.min_moisture_threshold)
            {
                turn_pump_on();
                g_system_status.is_alert_active = false; 
            } else
            {
                g_system_status.is_alert_active = false;
            }
        }
        else
        { 
           
            unsigned long watering_duration = get_current_time_ms() - g_system_status.pump_start_time_ms;
            if (g_system_status.sensor_data.soil_moisture_percent >= g_system_status.settings.max_moisture_threshold ||
                watering_duration >= (unsigned long)g_system_status.settings.max_watering_duration_sec * 1000)
            {
                turn_pump_off();
            }
        }
    }
}

void handle_manual_watering_logic()
{
    if (g_system_status.is_watering_manual)
    {
        unsigned long manual_watering_elapsed = get_current_time_ms() - g_system_status.manual_watering_duration_ms;
        if (manual_watering_elapsed >= (unsigned long)MANUAL_WATERING_DURATION_SEC * 1000)
        {
            turn_pump_off();
            g_system_status.is_watering_manual = false;
            system_monitor_send_message("Manual watering completed.");
        }
    }
}

void update_led_status()
{
    if (g_system_status.pump_state == PUMP_ON)
    {
        set_led_state(LED_WATERING);
    }
    else
    {
        if (g_system_status.settings.current_mode == MODE_AUTO &&
            g_system_status.sensor_data.soil_moisture_percent < g_system_status.settings.min_moisture_threshold)
        {
            set_led_state(LED_LOW_MOISTURE_ALERT);
            g_system_status.is_alert_active = true;
        }
        else
        {
            set_led_state(LED_NORMAL);
            g_system_status.is_alert_active = false;
        }
    }
}