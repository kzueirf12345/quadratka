#include "test.h"

#include "../utils/console.h"

bool is_equal_answer(const Answer answer1, const Answer answer2)
{
    if (answer1.count_solutions != answer2.count_solutions) return false;

    if (answer1.count_solutions == TWO_SOLUTIONS)
    {
        return is_zero(min(answer1.root1, answer1.root2) - min(answer2.root1, answer2.root2)) &&
               is_zero(max(answer1.root1, answer1.root2) - max(answer2.root1, answer2.root2));
    }
    if (answer1.count_solutions == ONE_SOLUTIONS)
        return is_zero(answer1.root1 - answer2.root1);
    
    return true;
}

OutputCode print_incorrect_test_case(FILE* stream, 
    const size_t num_test_case, const TestCase test_case, const Answer answer)
{
    assert(stream && "stream is nullptr");

    fprintf(stream, "======================\n");

    char first_message[100] = {};
    if (stream == stdout)
    {
        if (sprintf(first_message, 
                    BOLD_TEXT "Test_case №%lu is " 
                    RED_TEXT "INcorrect" BLACK_TEXT "!" NORMAL_TEXT,
                    num_test_case) <= 0)
            return OUTPUT_FAILURE;
    }
    else
    {
        if (sprintf(first_message, "Test_case №%lu is INcorrect!", num_test_case) <= 0)
            return OUTPUT_FAILURE;
    }

    if (fprintf(stream, 
                "%s\n"
                "Coefs: %g, %g, %g\n",
                first_message,
                test_case.coefs.a, test_case.coefs.b, test_case.coefs.c) <= 0)
        return OUTPUT_FAILURE;
    

    fprintf(stream, "Correct answer: ");
    if (print(stream, test_case.answer) == OUTPUT_FAILURE) 
        return OUTPUT_FAILURE;

    fprintf(stream, "Programm answer: ");
    if (print(stream, answer) == OUTPUT_FAILURE) 
        return OUTPUT_FAILURE;
    
    fprintf(stream, "======================\n");

    return OUTPUT_SUCCESS;
}

OutputCode print_correct_test_case(FILE* stream, 
    const size_t num_test_case, const TestCase test_case)
{
    assert(stream && "stream is nullptr");

    fprintf(stream, "======================\n");

    char first_message[100] = {};
    if (stream == stdout)
    {
        if (sprintf(first_message, 
                    BOLD_TEXT "Test_case №%lu is " 
                    GREEN_TEXT "correct" BLACK_TEXT "!" NORMAL_TEXT,
                    num_test_case) <= 0)
            return OUTPUT_FAILURE;
    }
    else
    {
        if (sprintf(first_message, "Test_case №%lu is correct!", num_test_case) <= 0)
            return OUTPUT_FAILURE;
    }

    if (fprintf(stream, 
                "%s\n"
                "Coefs: %g, %g, %g\n",
                first_message,
                test_case.coefs.a, test_case.coefs.b, test_case.coefs.c) <= 0)
        return OUTPUT_FAILURE;

    fprintf(stream, "Answer: ");
    if (print(stream, test_case.answer) == OUTPUT_FAILURE) 
        return OUTPUT_FAILURE;
    
    fprintf(stream, "======================\n");

    return OUTPUT_SUCCESS;
}

TestCode testing(FILE* stream, const size_t num_test_case, const TestCase test_case)
{
    assert(stream && "stream is nullptr");

    Answer answer = calculate(test_case.coefs);

    if (!is_equal_answer(answer, test_case.answer))
    {
        if (print_incorrect_test_case(stream, num_test_case, test_case, answer) == OUTPUT_FAILURE)
            return TEST_FAILURE;
        return TEST_INCORRECT;
    }

    if (print_correct_test_case(stream, num_test_case, test_case) == OUTPUT_FAILURE)
        return TEST_FAILURE;
    return TEST_SUCCESS;
}

TestCode global_testing(FILE* test_log)
{ 
    assert(test_log && "test log is nullptr");

    static constexpr size_t TEST_CASES_SIZE = 8;
    static const TestCase test_cases[TEST_CASES_SIZE] =
        {
            (TestCase){(Coefs){0, 0, 1},(Answer){NAN, NAN, INF_SOLUTIONS}},
            (TestCase){(Coefs){0, 0, 12},(Answer){NAN, NAN, ZERO_SOLUTIONS}},
            (TestCase){(Coefs){0, 7, 0},(Answer){0, NAN, ONE_SOLUTIONS}},
            (TestCase){(Coefs){0, 7, 12},(Answer){-12*1./7, NAN, ONE_SOLUTIONS}},
            (TestCase){(Coefs){0, 7, -12},(Answer){12*1./7, -3, ONE_SOLUTIONS}},
            (TestCase){(Coefs){1, 7, 12},(Answer){-4, -3, TWO_SOLUTIONS}},
            (TestCase){(Coefs){1, 7, -8},(Answer){1, -8, TWO_SOLUTIONS}},
            (TestCase){(Coefs){-8, 7, 1},(Answer){1, -1*1./8, TWO_SOLUTIONS}}
        };

    for (size_t i = 0; i < TEST_CASES_SIZE; ++i)
    {
        if (testing(test_log, i, test_cases[i]) == TEST_FAILURE)
            return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}
