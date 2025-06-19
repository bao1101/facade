#include"button.h"
#include"config.h"
#include"system_monitor.h"
#include"system_time.h"
#include"actuator.h"
#include<stdio.h>

extern SystemStatus_t g_system_status;

define BUTTON_DEBOUNCE_TIME_MS 200

static unsigned long last_button1_press_time_ms = 0;
static unsigned long last_button2_press_time_ms = 0;
//flag signal that the button has been presses
static bool button1_triggered = false;
static bool button1_triggeres = false;

void button_inti() 
{
    // simulator GPIO pin initializing for push press
    printf("[Button]: Initializing button hardware...\n");
}

void trigger_button1_press()
{
    if(get_current_time_ms() - last_button1_press_time_ms > BUTTON_DEBOUNCE_TIME_MS)
    {
        button1_triggered = true;
        last_button1_press_time_ms = get_current_time_ms();
        system_monitor_send_message(LOG_LEVEL_INFOR, "Button: Button 1 (mode toggle) passed");
    }
    else
    {
        system_monitor_send_message(LOG_LEVEL_INFOR, "Button: Button 1 press ignorred (deboundcing).");
    }  
}

void trigger_button2_press()
{
    if(get_current_time_ms() - last_button2_press_time_ms > BUTTON_DEBOUNCE_TIME_MS)
    {
        button2_triggered = true;
        last_button2_press_time_ms = get_current_time_ms();
        system_monitor_send_message(LOG_LEVEL_INFOR, "Button: Button 2 (mode toggle) passed");
    }
    else
    {
        system_monitor_send_message(LOG_LEVEL_INFOR, "Button: Button 2 press ignorred (deboundcing).");
    }  
}

void handle_button_events()
{
    //switch between auto/manual mode
    if(button1_triggered)
    {
        button1_triggered = false;
        if(g_system_status.settings.current_mode == MODE_AUTO)
        {
            g_system_status.settings.current_mode = MODE_MANUAL;
            turn_pump_off();
            system_monitor_send_message(LOG_LEVEL_INFOR, "System mode: switch to Manual ");
        }
        else 
        {
            system_monitor_send_message(LOG_LEVEL_INFOR, "System mode: switch to Auto")
        }
    }
    //manual watering
    if(button2_triggered)
    {
        button2_triggered = false;
        if(g_system_status.settings.current_mode == MODE_MANUAL)
        {
            if(g_system_status.pump_state == PUMP_OFF)
            {
                system_monitor_send_message(LOG_LEVEL_INFOR, "Manual watering activated");
                turn_pump_on();
                g_system_status.is_watering_manual = true;
                g_system_status.manual_watering_duration_ms = get_current_time_ms();
            }
            else
            {
                system_monitor_send_message(LOG_LEVEL_INFOR, "Manual watering: Pump is already ON, Ignoring request");
            }
            else
            {
                system_monitor_send_message(LOG_LEVEL_INFOR, "Manual watering: Only available in MANUAL mode");
            }
        }
    }
}
