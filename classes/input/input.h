#pragma once

#include "../structs/structs.h"

#include <stdio.h>
#include <assert.h>

enum InputCode
{
    INPUT_SUCCESS   = 0,
    INPUT_FAILURE   = 1,
    INPUT_INCORRECT = 2
};

InputCode flush();
InputCode scan_double(double* const num);
InputCode input_coef(double* const num, const char* const message);
InputCode input(Coefs* const coefs);