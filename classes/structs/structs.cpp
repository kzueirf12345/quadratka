#include "structs.h"

bool is_zero(double num) { return abs(num) < EPS; }

double fix_double_zero(double num) {
    if (is_zero(num)) 
    {
        return 0;
    }
    return num;
}