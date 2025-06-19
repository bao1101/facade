#include"sensor.h"
#include"config.h"
#include"system_monitor.h" // use to send notication
#include"system_time.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

extern SystemStatus_t g_system_status;

static int mock_soil_moisture = 50;
static float mock_tempurature = 25.0f;

void sensor_init()
{
    printf("[SENSOR] Initializing sensor hardware...\n");
    srand((unsigned int )get_current_time_ms());

    g_system_status.sensor_data.soil_moisture_status = SENSOR_OK;
    g_system_status.sensor_data.tempurature_status = SENSOR_OK;
}

void read_sensor_data()
{
    // Read the sensor only if the test cycle has reached
    if(current_time - g_system_status.last_sensor_check_time_ms >=
    (unsigned long)g_system_status.settings.sensor_check_initival_sec * 1000.0)
    // ex error
    {
        if (rand() % 100 < 5)
        {
            g_system_status.sensor_data.soil_moisture_status = SENSOR_ERROR_READ;
            g_system_status.sensor_data.tempurature_status = SENSOR_ERROR_READ;
            system_monitor_send_message(LOG_LEVEL_ERROR, "Sensor fail to read data (simulated error)!");
            g_system_status.sensor_data.soil_moisture_status = -1;
            g_system_status.sensor_data.tempurature_status = -99.9f;
        }
        else
        {
            g_system_status.sensor_data.soil_moisture_status = SENSOR_OK;
            g_system_status.sensor_data.tempurature_status = SENSOR_OK;
            //Symulated soil moisture reading
            if(g_system_status.pump_state == PUMP_ON)
            {
                mock_soil_moisture += (rand() % 5) + 1;
            }
            else
            {
                mock_soil_moisture -= (rand() % 3) + 1;
            }
            if(mock_soil_moisture < 0) mock_soil_moisture = 0;
            if(mock_soil_moisture > 100) mock_soil_moisture = 100;

            g_system_status.sensor_data.soil_moisture_status = mock_soil_moisture;
            //System tempurature reading
            mock_tempurature += (float)(rand() % 3 -1);// change -1, 0, or 1
            if(mock_tempurature < 15.0) mock_tempurature = 15.0f;
            if(mock_tempurature > 35.0) mock_tempurature = 35.0f;

            g_system_status.sensor_data.ambient_tempurature_celsius = mock_tempurature;

            system_monitor_send_message(LOG_LEVEL_DEBUG, "Sensor: data had read sucsecfully");
        }
        // update when the last sensor reading was taken
        g_system_status.last_sensor_check_time_ms = current_time;
    } 
}