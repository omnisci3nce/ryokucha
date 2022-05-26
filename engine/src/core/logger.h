#pragma once

#include "defines.h"
#include <stdbool.h>

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1
// FATAL and ERROR are always logged so don't get a switch

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

// Export this
RCAPI void log_output(log_level level, const char* message, ...); // uses variadic arguments

#define RCFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef RCERROR
#define RCERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
#define RCWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define RCWARN(message, ...)'
#endif

#if LOG_INFO_ENABLED == 1
#define RCINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define RCINFO(message, ...)'
#endif

#if LOG_DEBUG_ENABLED == 1
#define RCDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define RCDEBUG(message, ...)'
#endif

#if LOG_TRACE_ENABLED == 1
#define RCTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define RCTRACE(message, ...)'
#endif