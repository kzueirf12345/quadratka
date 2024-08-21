#ifndef SRC_UTILS_H
#define SRC_UTILS_H

#include <math.h>


static constexpr double EPS = 1e-7;

inline double max(const double a, const double b) { return a > b ? a : b; }
inline double min(const double a, const double b) { return a < b ? a : b; }

inline bool is_zero(double num) { return abs(num) < EPS; }

#endif /* SRC_UTILS_H */