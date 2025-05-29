#ifndef DEBUG_H
#define DEBUG_H

#ifndef NDEBUG
#include <iostream>
#include <utility> // for std::forward
#include <mutex>
#endif /* NDEBUG */

#ifndef NDEBUG
#define DPRINT(...) DebugPrint(__VA_ARGS__)
#else
#define DPRINT(...) ((void)0)
#endif /* NDEBUG */

template <typename... Args>
void DebugPrint(Args&&... args) {
    static std::mutex mut_debug; // ensure thread-safe output
    std::lock_guard<std::mutex> lock(mut_debug); // lock the mutex for thread safety
    (std::cerr << ... << args) << std::endl;  // fold expression (C++17+)
}

#endif /* DEBUG_H */