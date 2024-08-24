#ifndef SRC_INPUT_H
#define SRC_INPUT_H


#include <stdio.h>
#include <assert.h>

#include "../structs/structs.h"


enum InputCode
{
    INPUT_SUCCESS   = 0,
    INPUT_FAILURE   = 1,
    INPUT_INCORRECT = 2,
    INPUT_EXIT      = 3
};

InputCode flush();
InputCode scan_double(double* const num);
InputCode input_coef(double* const num, const char* const message);
InputCode input(Coefs* const coefs);


#endif /* SRC_INPUT_H */