#include "logger.h"
#include <stdio.h>
#include <stdlib.h>

void some_function() {
    log_message(LOG_INFO, "This is an informational message from some_function.");
    log_message(LOG_DEBUG, "Debugging information: x = %d, y = %.2f", 10, 20.5);
}

int main() {
    logger_init("application.log", LOG_INFO);

    log_message(LOG_INFO, "Application started.");
    log_message(LOG_DEBUG, "This debug message should NOT be visible initially."); 

    int error_code = 101;
    log_message(LOG_ERROR, "Failed to connect to database. Error code: %d", error_code);
    log_message(LOG_WARNING, "Configuration file not found, using default settings.");

    some_function();

    logger_set_level(LOG_DEBUG);
    log_message(LOG_DEBUG, "This debug message SHOULD be visible now!"); 

    log_message(LOG_NOTICE, "User 'admin' logged in successfully.");
    log_message(LOG_CRITICAL, "System memory usage is critical!");
    log_message(LOG_ALERT, "Intrusion detected! Immediate action required.");

     logger_log(LOG_EMERGENCY, __FILE__, __LINE__, "System is shutting down due to unrecoverable error!");

    log_message(LOG_INFO, "Application finished.");

        logger_shutdown();

    return 0;
}