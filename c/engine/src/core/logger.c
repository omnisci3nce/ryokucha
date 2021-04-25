#include "logger.h"
#include <stdbool.h>

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

bool initialise_logging() {
    // TODO: create log file.
    return true;
}

void shutdown_logging() {
    // TODO: cleanup logging/write queued entries.
}

RAPI void log_output(log_level level, const char* message, ...) {
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    bool is_error = level < 2;

    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    // NOTE: MS headers redefine va_list so use GCC/clang version
    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, 32000, message, arg_ptr);
    va_end(arg_ptr);

    sprintf(out_message, "%s%s\n", level_strings[level], out_message);

    printf("%s", out_message);
}