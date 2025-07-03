#include"logger.h"
#include <stdio.h>
#include <stdblid.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

static FILE *log_file = NULL;
static LogLevels current_log_level = LOG_INFO;
static const char *log_level_name[] = {
    "EMERGENCY",
    "ALERT",
    "CRITICAL",
    "ERROR",
    "WARNING",
    "NOTICE",
    "INFO",
    "DEBUG"
};

void logger_init(const char *log_file_path, LogLevels initial_level)
{
    if (log_file_path != NULL) {
        log_file = fopen(log_file_path, "a"); 
        if (log_file == NULL) {
            fprintf(stderr, "[ERROR] [logger.c:%d] - Could not open log file: %s\n", __LINE__, log_file_path);
        }
    }
    current_log_level = initial_level;
    log_message(LOG_INFO, "Logger initialized. Current log level: %s", log_level_names[current_log_level]);
}        
void logger_shutdown() {
    if (log_file != NULL) {
        log_message(LOG_INFO, "Logger shutting down.");
        fclose(log_file);
        log_file = NULL;
    }
}

void logger_set_level(LogLevel new_level) {
    if (new_level >= LOG_EMERGENCY && new_level <= LOG_DEBUG) {
        current_log_level = new_level;
        log_message(LOG_INFO, "Log level changed to: %s", log_level_names[current_log_level]);
    } else {
        log_message(LOG_WARNING, "Attempted to set invalid log level: %d", new_level);
    }
}

void logger_log(LogLevel level, const char *file, int line, const char *format, ...) {
    if (level > current_log_level) {
        return;
    }

    time_t timer;
    char time_buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);
    strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    char message_buffer[1024]; 
    va_list args;
    va_start(args, format);
    int len = vsnprintf(message_buffer, sizeof(message_buffer), format, args);
    va_end(args);

    if (len < 0) {
        strcpy(message_buffer, "ERROR: Failed to format log message.");
    } else if ((size_t)len >= sizeof(message_buffer)) {
        
    }
    FILE *console_output = (level <= LOG_ERROR) ? stderr : stdout;
    fprintf(console_output, "[%s] [%s] [%s:%d] - %s\n",
            time_buffer, log_level_names[level], file, line, message_buffer);
    fflush(console_output);
    if (log_file != NULL) {
        fprintf(log_file, "[%s] [%s] [%s:%d] - %s\n",
                time_buffer, log_level_names[level], file, line, message_buffer);
        fflush(log_file);
    }
}