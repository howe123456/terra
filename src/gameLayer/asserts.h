#pragma once

// -----------------------------------------------------------------------------
// Terra assert macros
//
// Mode detection:
//   TERRA_ASSERT_DEBUG == 1 -> development / debug build
//   TERRA_ASSERT_DEBUG == 0 -> production / release build
//
// The four macros:
//   permaAssert                     always active, no custom message
//   permaAssertComment              always active, with a custom message
//   permaAssertDevelopenment        debug builds only, no custom message
//   permaAssertCommentDevelopenment debug builds only, with a custom message
//
// Usage:
//   permaAssert(ptr != nullptr);
//   permaAssertComment(index < size, "index out of range");
//   permaAssertDevelopenment(expensiveCheck());
//   permaAssertCommentDevelopenment(x > 0, "x must be positive");
// -----------------------------------------------------------------------------

#if defined(NDEBUG) || (defined(PRODUCTION_BUILD) && PRODUCTION_BUILD == 1)
    #define TERRA_ASSERT_DEBUG 0
#else
    #define TERRA_ASSERT_DEBUG 1
#endif

// Reports a failed assertion and never returns.
// 'comment' may be nullptr (or an empty string) when there is no custom message.
void TerraAssertFailed(const char* expression,
                       const char* comment,
                       const char* file,
                       int line);

// Always active, no custom message.
#define permaAssert(condition)                                          \
    do {                                                                \
        if (!(condition)) {                                             \
            TerraAssertFailed(#condition, nullptr, __FILE__, __LINE__); \
        }                                                               \
    } while (0)

// Always active, with a custom message.
#define permaAssertComment(condition, comment)                          \
    do {                                                                \
        if (!(condition)) {                                             \
            TerraAssertFailed(#condition, (comment), __FILE__, __LINE__); \
        }                                                               \
    } while (0)

#if TERRA_ASSERT_DEBUG
    // Debug builds: behave exactly like the always-active versions.
    #define permaAssertDevelopenment(condition) \
        permaAssert(condition)

    #define permaAssertCommentDevelopenment(condition, comment) \
        permaAssertComment(condition, comment)
#else
    // Release builds: the condition is not evaluated at all.
    #define permaAssertDevelopenment(condition) ((void)0)

    #define permaAssertCommentDevelopenment(condition, comment) ((void)0)
#endif
