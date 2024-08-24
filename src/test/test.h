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


bool is_equal_answer(const Answer answer1, const Answer answer2);

OutputCode print_test_case_correctness(FILE* stream, const TestCase test_case,bool correct = true,
    const Answer answer = {.root1 = NAN, .root2 = NAN, .count_solutions = TWO_SOLUTIONS});

TestCode testing(FILE* stream, const TestCase test_case);
TestCode global_testing(FILE* test_log);


#endif /* SRC_TEST_H */