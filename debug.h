#ifndef DEBUG_H
#define DEBUG_H

#ifndef NDEBUG
#define PRINT(...) printf(__VA_ARGS__)
#else
#define PRINT(...) ((void)0)
#endif /* NDEBUG */

#endif /* DEBUG_H */