#ifndef SRC_OUTPUT_H
#define SRC_OUTPUT_H

#include <assert.h>
#include <stdio.h>

#include "../utils/utils.h"
#include "../structs/structs.h"

//TODO: log_out in run

enum OutputCode
{
    OUTPUT_SUCCESS   = 0,
    OUTPUT_FAILURE   = 1,
};

inline double fix_double_zero(double num) {
    if (is_zero(num)) 
    {
        return 0;
    }
    return num;
}

OutputCode print(FILE* stream, const Answer answer);

#endif /* SRC_OUTPUT_H */