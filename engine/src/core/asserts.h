#pragma once

#include "defines.h"

// Disable assertions by commenting out the line below.
#define RCASSERTIONS_ENABLED

#ifdef RCASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

RCAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define RCASSERT(expr) \
    { \
        if (expr) { \
        } else { \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak(); \
        } \
    }

#define RCASSERT_MSG(expr, message) \
    { \
        if (expr) { \
        } else { \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak(); \
        } \
    } 

#ifdef _DEBUG
#define RCASSERT_DEBUG(expr) \
    { \
        if (expr) { \
        } else { \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak(); \
        } \
    }
#else
#define RCASSERT_DEBUG(expr) // do nothing
#endif


#else

#define RCASSERT(expr)
#define RCASSERT_MSG(expr, message)
#define RCASSERT_DEBUG(expr)
#endif