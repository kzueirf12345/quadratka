#ifndef SRC_UTILS_H
#define SRC_UTILS_H

#include <math.h>

static constexpr double EPS = 1e-7;

inline bool is_zero(double num) { return abs(num) < EPS; }

#endif /* SRC_UTILS_H */