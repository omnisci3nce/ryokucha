#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    
    RCFATAL("A test message: %f", 3.14f);
    RCERROR("A test message: %f", 3.14f);
    RCWARN("A test message: %f", 3.14f);
    RCINFO("A test message: %f", 3.14f);
    RCDEBUG("A test message: %f", 3.14f);
    RCTRACE("A test message: %f", 3.14f);

    RCASSERT(TRUE);

    return 0;
}