#ifndef SRC_UTILS_H
#define SRC_UTILS_H

#include <math.h>


#define NORMAL_TEXT "\e[0m"

#define BLACK_TEXT "\e[30m"
#define RED_TEXT "\e[31m"
#define GREEN_TEXT "\e[32m"
#define YELLOW_TEXT "\e[33m"

#define BOLD_TEXT "\e[1m"
#define ITALIC_TEXT "\e[2m"


static constexpr double EPS = 1e-7;

inline double max(const double a, const double b) { return a > b ? a : b; }
inline double min(const double a, const double b) { return a < b ? a : b; }

inline bool is_zero(double num) { return abs(num) < EPS; }

#endif /* SRC_UTILS_H */