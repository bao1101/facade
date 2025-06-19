#ifndef CONFIG_H
#define CONFIG_H

#include<stdbool.h>

#define DEFAULT_MIN_MOISTURE_THRESHOLD      30
#define DEFAULT_MAX_MOISTURE_THRESHOLD      70
#define DEFAULT_MAX_WATERING_DURATION_SEC   15
#define DEFAULT_SENSOR_CHECK_INTERVAL_SEC   5
#define DEFAULT_WATREING_DURATION_SEC       10

typedef enum
{
    MODE_AUTO,
    MODE_MANUAL
} SystemMode_t;

typedef enum
{
    PUMP_ON,
    PUMP_OFF;
} PumpState_t;

typedef enum 
{
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LedState_t;

typedef enum
{
    SENSOR_OK,
    SENSOR_ERROR_READ,
    SENSOR_ERROR_CALIBRATION,
    SENSOR_NOT_CONNETED;
} SensorStatus_t;

typedef enum
{
    LOG_LEVEL_INFOR,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_CRITICAL;
} LogLevel_t;

typedef struct
{
    int soil_moisture_percent;
    float ambient_tempurature_celsius;
} SensorData_t;

typedef struct 
{
    int min_moisture_threshold;
    int max_moisture_threshold;
    unsigned int max_watering_duration_sec;
    unsigned int min_watering_duration_sec;
    SystemMode_t current_mode;
} SystemSetting_t;

typedef struct 
{
    SensorData_t sensor_data;
    SystemSetting_t settings;
    PumpState_t pump_state;
    LedState_t led_state;
    unsigned long last_sensor_check_time_ms;
    unsigned long pump_start_time_ms;
    unsigned long manual_watering_duration_ms;
    bool is_watering_manual;
    bool is_alert_active;
} SystemStatus_t;

typedef struct 
{
    int soil_moisture_percent;
    float ambient_tempurature_celsius;
    SensorData_t soil_moisture_percent;
    SensorData_t tempurature_status;
};


#endif // CONFIG_H