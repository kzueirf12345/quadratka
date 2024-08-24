#ifndef SRC_UTILS_H
#define SRC_UTILS_H


#include <math.h>


#define KWORD_TO_STDOUT "__CONCOLE__"
constexpr const char *const DEFAULT_USER_LOGOUT = "./user.log";
constexpr const char *const DEFAULT_TEST_LOGOUT = "./test.log";


inline double max(const double a, const double b) { return a > b ? a : b; }
inline double min(const double a, const double b) { return a < b ? a : b; }


inline bool is_zero(double num)
{
    static constexpr double EPS = 1e-7;
    
    return abs(num) < EPS;
}


#endif /* SRC_UTILS_H */