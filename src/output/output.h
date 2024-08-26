#ifndef SRC_OUTPUT_H
#define SRC_OUTPUT_H


#include <assert.h>
#include <stdio.h>

#include "../utils/utils.h"
#include "../structs/structs.h"


constexpr const char* const SEPARATING_LINE = "======================\n";


enum OutputCode
{
    OUTPUT_SUCCESS = 0,
    OUTPUT_FAILURE = 1,
};


inline double fix_double_zero(double num) {
    if (is_zero(num)) 
        return 0;

    return num;
}

OutputCode print_answer(FILE* stream, const Answer answer);

OutputCode print_test_case(FILE* stream, const TestCase test_case);


#endif /* SRC_OUTPUT_H */