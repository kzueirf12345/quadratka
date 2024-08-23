#ifndef SRC_TEST_H
#define SRC_TEST_H

#include <stdio.h>
#include <math.h>

#include "../structs/structs.h"
#include "../calculate/calculate.h"
#include "../output/output.h"

enum TestCode
{
    TEST_SUCCESS   = 0,
    TEST_FAILURE   = 1,
    TEST_INCORRECT = 2,
};

struct TestCase
{
    Coefs coefs;
    Answer answer;
};

OutputCode print_incorrect_test_case(FILE* stream, 
    const size_t num_test_case, const TestCase test_case, const Answer answer);
OutputCode print_correct_test_case(FILE* stream, 
    const size_t num_test_case, const TestCase test_case);

bool is_equal_answer(const Answer answer1, const Answer answer2);
TestCode testing(FILE* stream, const size_t num_test_case, const TestCase test_case);

TestCode global_testing(FILE* test_log);


#endif /* SRC_TEST_H */