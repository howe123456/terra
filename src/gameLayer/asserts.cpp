#include "asserts.h"

#include <cstdio>
#include <cstdlib>

#if defined(_MSC_VER)
    #include <intrin.h>
    #define TERRA_DEBUG_BREAK() __debugbreak()
#elif defined(__GNUC__) || defined(__clang__)
    #define TERRA_DEBUG_BREAK() __builtin_trap()
#else
    #define TERRA_DEBUG_BREAK() ((void)0)
#endif

void TerraAssertFailed(const char* expression,
                       const char* comment,
                       const char* file,
                       int line)
{
    std::fprintf(stderr, "\n[ASSERT FAILED] %s\n", expression ? expression : "(null)");

    if (comment != nullptr && comment[0] != '\0')
    {
        std::fprintf(stderr, "  Message : %s\n", comment);
    }

    std::fprintf(stderr, "  File    : %s\n", file ? file : "(unknown)");
    std::fprintf(stderr, "  Line    : %d\n", line);
    std::fflush(stderr);

#if TERRA_ASSERT_DEBUG
    // Stop in the debugger when one is attached.
    TERRA_DEBUG_BREAK();
#endif

    std::abort();
}
