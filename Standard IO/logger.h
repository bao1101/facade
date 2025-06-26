#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>
#include <stdarg.h>

typedef enum
{
    LOG_EMERGENCY,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFOR,
    LOG_DEBUG
} LogLevels;

void logger_init(const char *log_file_path, LogLevels initial_level);

void logger_shutdown();

void logger_set_level(LogLevels new_level);

void logger_log(LogLevel level, const char *file, int line, const char *format, ...);

#define log_message(level, format, ...) \
    logger_log(level, __FILE__, __LINE__, format, ##__VA_ARGS__)

#endif // LOGGER_H

