#include "test.h"

#include "../utils/console.h"


bool is_equal_answer(const Answer answer1, const Answer answer2)
{
    if (answer1.count_solutions != answer2.count_solutions) return false;

    if (answer1.count_solutions == TWO_SOLUTIONS)
        return is_zero(min(answer1.root1, answer1.root2) - min(answer2.root1, answer2.root2))
            && is_zero(max(answer1.root1, answer1.root2) - max(answer2.root1, answer2.root2));

    if (answer1.count_solutions == ONE_SOLUTIONS)
        return is_zero(answer1.root1 - answer2.root1);
    
    return true;
}


OutputCode print_incorrect_test_case(FILE* stream, const TestCase test_case, const Answer answer)
{
    assert(stream && "stream is nullptr");
    assert(std::isfinite(test_case.coefs.a) && "test_case.coefs.a is not finite");
    assert(std::isfinite(test_case.coefs.b) && "test_case.coefs.b is not finite");
    assert(std::isfinite(test_case.coefs.c) && "test_case.coefs.c is not finite");

    fprintf(stream, SEPARATING_LINE);

    if (stream == stdout && fprintf(stream, RED_TEXT("INCORRECT TEST!\n")) <= 0)
        return OUTPUT_FAILURE;
    if (stream != stdout && fprintf(stream, "INCORRECT TEST!\n") <= 0)
        return OUTPUT_FAILURE;
        
    print_test_case(stream, test_case);

    fprintf(stream, "Your answer: ");
    if (print(stream, answer) == OUTPUT_FAILURE) 
        return OUTPUT_FAILURE;
    
    fprintf(stream, SEPARATING_LINE);

    return OUTPUT_SUCCESS;
}

OutputCode print_correct_test_case(FILE* stream, const TestCase test_case)
{ // TODO flag
    assert(stream && "stream is nullptr");
    assert(std::isfinite(test_case.coefs.a) && "test_case.coefs.a is not finite");
    assert(std::isfinite(test_case.coefs.b) && "test_case.coefs.b is not finite");
    assert(std::isfinite(test_case.coefs.c) && "test_case.coefs.c is not finite");

    fprintf(stream, SEPARATING_LINE);

    if (stream == stdout && fprintf(stream, GREEN_TEXT("CORRECT TEST!\n")) <= 0)
        return OUTPUT_FAILURE;
    if (stream != stdout && fprintf(stream, "CORRECT TEST!\n") <= 0)
        return OUTPUT_FAILURE;

    print_test_case(stream, test_case);
    
    fprintf(stream, SEPARATING_LINE);

    return OUTPUT_SUCCESS;
}

TestCode testing(FILE* stream, const TestCase test_case)
{
    assert(stream && "stream is nullptr");
    assert(std::isfinite(test_case.coefs.a) && "test_case.coefs.a is not finite");
    assert(std::isfinite(test_case.coefs.b) && "test_case.coefs.b is not finite");
    assert(std::isfinite(test_case.coefs.c) && "test_case.coefs.c is not finite");

    Answer answer = calculate(test_case.coefs);

    if (!is_equal_answer(answer, test_case.answer))
    {
        if (print_incorrect_test_case(stream, test_case, answer) == OUTPUT_FAILURE)
            return TEST_FAILURE;

        return TEST_INCORRECT;
    }

    if (print_correct_test_case(stream, test_case) == OUTPUT_FAILURE)
        return TEST_FAILURE;

    return TEST_SUCCESS;
}

TestCode global_testing(FILE* test_log)
{ 
    assert(test_log && "test log is nullptr");

    static constexpr TestCase test_cases[] =
    { // TODO table
        (TestCase){-1,(Coefs){0, 0, 0},(Answer){NAN, NAN, INF_SOLUTIONS}},
        (TestCase){-1,(Coefs){0, 0, 12},(Answer){NAN, NAN, ZERO_SOLUTIONS}},
        (TestCase){-1,(Coefs){0, 7, 0},(Answer){0, NAN, ONE_SOLUTIONS}},
        (TestCase){-1,(Coefs){0, 7, 12},(Answer){-12*1./7, NAN, ONE_SOLUTIONS}},
        (TestCase){-1,(Coefs){0, 7, -12},(Answer){12*1./7, -3, ONE_SOLUTIONS}},
        (TestCase){-1,(Coefs){1, 7, 12},(Answer){-4, -3, TWO_SOLUTIONS}},
        (TestCase){-1,(Coefs){1, 7, -8},(Answer){1, -8, TWO_SOLUTIONS}},
        (TestCase){-1,(Coefs){-8, 7, 1},(Answer){1, -1*1./8, TWO_SOLUTIONS}}
    };
    constexpr int TEST_CASES_SIZE = sizeof(test_cases)/sizeof(*test_cases);

    for (int i = 0; i < TEST_CASES_SIZE; ++i)
    {
        if (testing(test_log, (TestCase){i, test_cases[i].coefs, test_cases[i].answer})
            == TEST_FAILURE)
            return TEST_FAILURE;
    }
    fprintf(test_log, "\n"); // NOTE - for nice format

    return TEST_SUCCESS;
}
