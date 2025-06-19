#include "system_monitor.h"
#include "config.h"
#include "system_timer.h" // Dùng get_current_time_ms()
#include <stdio.h>

extern SystemStatus_t g_system_status;

static unsigned long last_report_time_ms = 0;
#define REPORT_INTERVAL_SEC 3 

void system_monitor_init() 
{
    printf("System Monitor: Initialized.\n");
}

void system_monitor_send_message(const char* message) 
{
    printf("[System Log]: %s\n", message);
}

void system_monitor_report_status() 
{
    unsigned long current_time = get_current_time_ms();
    if (current_time - last_report_time_ms >= (unsigned long)REPORT_INTERVAL_SEC * 1000)
    {
        printf("\n--- System Status Report (%lu ms) ---\n", current_time);
        printf("Mode: %s\n", (g_system_status.settings.current_mode == MODE_AUTO) ? "AUTO" : "MANUAL");
        printf("Pump: %s\n", (g_system_status.pump_state == PUMP_ON) ? "ON" : "OFF");
        printf("LED: ");
        switch (g_system_status.led_state)
        {
            case LED_NORMAL: printf("NORMAL (Green)\n"); break;
            case LED_WATERING: printf("WATERING (Yellow)\n"); break;
            case LED_LOW_MOISTURE_ALERT: printf("LOW MOISTURE (Red)\n"); break;
            case LED_ERROR: printf("ERROR (Blinking Red)\n"); break;
            default: printf("UNKNOWN\n"); break;
        }
        printf("Soil Moisture: %d%%\n", g_system_status.sensor_data.soil_moisture_percent);
        printf("Temperature: %.1f C\n", g_system_status.sensor_data.ambient_temperature_celsius);
        printf("----------------------------------\n\n");
        last_report_time_ms = current_time;
    }
}