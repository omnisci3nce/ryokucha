#pragma once

#include "defines.h"
#include <stdbool.h>

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if RCRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_TRACE
} log_level;

bool initialise_logging();
void shutdown_logging();

RAPI void log_output(log_level level, const char* message, ...);

#if LOG_WARN_ENABLED == 1
#define RWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define RWARN(message, ...)'
#endif

#if LOG_INFO_ENABLED == 1
#define RINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define RINFO(message, ...)'
#endif

#if LOG_DEBUG_ENABLED == 1
#define RDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define RDEBUG(message, ...)'
#endif

#if LOG_INFO_ENABLED == 1
#define RTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define RTRACE(message, ...)'
#endif