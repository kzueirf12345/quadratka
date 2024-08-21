#ifndef SRC_OUTPUT_H
#define SRC_OUTPUT_H

#include <assert.h>
#include <stdio.h>

#include "../utils/utils.h"
#include "../structs/structs.h"

inline double fix_double_zero(double num) {
    if (is_zero(num)) 
    {
        return 0;
    }
    return num;
}

void print(const Answer answer);

#endif /* SRC_OUTPUT_H */