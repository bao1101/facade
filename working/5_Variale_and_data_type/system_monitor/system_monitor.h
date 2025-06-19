#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

void system_monitor_init();

void system_monitor_send_message(const char* message);

void system_monitor_report_status();

#endif //SYSTEM_MONITOR_H