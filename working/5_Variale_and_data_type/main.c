#include <stdio.h>    
#include <stdbool.h>  

#include "config.h"
#include "system_time.h"
#include "sensors.h"
#include "actuators.h"
#include "button.h"
#include "watering_logic.h"
#include "system_monitor.h"

SystemStatus_t g_system_status;

void system_init()
{
    init_system_timer();

    g_system_status.settings.min_moisture_threshold = DEFAULT_MIN_MOISTURE_THRESHOLD;
    g_system_status.settings.max_moisture_threshold = DEFAULT_MAX_MOISTURE_THRESHOLD;
    g_system_status.settings.max_watering_duration_sec = DEFAULT_MAX_WATERING_DURATION_SEC;
    g_system_status.settings.sensor_check_interval_sec = DEFAULT_SENSOR_CHECK_INTERVAL_SEC;

    g_system_status.settings.current_mode = MODE_AUTO; 
    g_system_status.pump_state = PUMP_OFF;
    g_system_status.led_state = LED_NORMAL;
    
    g_system_status.last_sensor_check_time_ms = get_current_time_ms();
    g_system_status.pump_start_time_ms = 0; 
    g_system_status.manual_watering_duration_ms = 0; 
    g_system_status.is_watering_manual = false;
    g_system_status.is_alert_active = false;
    g_system_status.sensor_data.soil_moisture_percent = 0; 
    g_system_status.sensor_data.ambient_temperature_celsius = 0.0f;
    g_system_status.sensor_data.soil_moisture_status = SENSOR_NOT_CONNECTED; 
    g_system_status.sensor_data.temperature_status = SENSOR_NOT_CONNECTED; 


    
    actuators_init();
    buttons_init();
    watering_logic_init();
    system_monitor_init();

    system_monitor_send_message(LOG_LEVEL_INFO, "System: Smart Plant Watering System initialized and ready!");

    system_monitor_report_status();
}


int main()
{
    printf("\n--- SPWS Simulation Started ---\n");
    printf("Press '1' and Enter to toggle AUTO/MANUAL mode.\n");
    printf("Press '2' and Enter to activate manual watering (only in MANUAL mode).\n");
    printf("-------------------------------\n\n");

   
    while (true)
    { 
        char input_char;

        if (scanf("%c", &input_char) == 1)
        {
            if (input_char == '1')
            {
                trigger_button1_press(); 
            } else if (input_char == '2')
            {
                trigger_button2_press(); 
            }
            
            while (getchar() != '\n');
        }
        read_sensor_data();

        handle_button_events();

        if (g_system_status.settings.current_mode == MODE_AUTO)
        {
            handle_auto_watering_logic(); 
        }
        else
        { 
            handle_manual_watering_logic();
        }

        update_led_status();

        system_monitor_report_status();

        delay_ms(100); 
    }

    return 0; 
}