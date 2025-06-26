#include"logger.h"
#include <stdio.h>
#include <stdblid.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

static FILE *log_file = NULL;
static LogLevels current_log_level = LOG_INFOR;
static const char *log_level_name[] = {
    "EMERGENCY",
    "ALERT",
    "CRITICAL",
    "ERROR",
    "WARNING",
    "NOTICE",
    "INFOR",
    "DEBUG"
};

void logger_init(const char *log_file_path, LogLevels initial_level)
{
    if()
}