#include "output.h"

#include "../utils/console.h"

OutputCode print(FILE* stream, const Answer answer)
{
    assert(stream && "stream is nullptr");
    
    int count_output = 0;
    switch (answer.count_solutions) 
    {
        case ZERO_SOLUTIONS:
        {
            count_output = fprintf(stream, "zero solutions\n");
            break;
        }
        case ONE_SOLUTIONS: 
        {
            count_output = fprintf(stream, "x = %g\n", fix_double_zero(answer.root1));
            break;
        }
        case TWO_SOLUTIONS: 
        {
            count_output = fprintf(stream, "x = %g, %g\n", 
                fix_double_zero(answer.root1), 
                fix_double_zero(answer.root2));
            break;
        }
        case INF_SOLUTIONS: 
        {
            count_output = fprintf(stream, "x - any number\n");
            break;
        }
        case NOT_REAL_SOLUTIONS: 
        {
            count_output = fprintf(stream, "no real solutions\n");
            break;
        }
        default: 
        {
            assert(0 && "Unknown error\n");
            break;
        }
    }
    return count_output > 0 ? OUTPUT_SUCCESS : OUTPUT_FAILURE;
}

OutputCode print_test_case(FILE* stream, const TestCase test_case)
{
    assert(stream && "stream is nullptr");
    assert(std::isfinite(test_case.coefs.a) && "test_case.coefs.a is not finite");
    assert(std::isfinite(test_case.coefs.b) && "test_case.coefs.b is not finite");
    assert(std::isfinite(test_case.coefs.c) && "test_case.coefs.c is not finite");

    constexpr size_t FIRST_MESSAGE_SIZE = 128;
    char first_message[FIRST_MESSAGE_SIZE] = {};

    if (test_case.num >= 0)
    {
        if (stream == stdout && 
            snprintf(first_message, FIRST_MESSAGE_SIZE, BOLD_TEXT("Test_case  №%d!"), test_case.num) <= 0)
            return OUTPUT_FAILURE;
        if (stream != stdout && 
            snprintf(first_message, FIRST_MESSAGE_SIZE, "Test_case №%d!", test_case.num) <= 0)
            return OUTPUT_FAILURE;
    }
    else 
    {
        if (stream == stdout)
            snprintf(first_message, FIRST_MESSAGE_SIZE, BOLD_TEXT("Test_case!"));
        else
            snprintf(first_message, FIRST_MESSAGE_SIZE, "Test_case!");
    }

    if (fprintf(stream, "%s\n" "Coefs: %g, %g, %g\n", first_message,
        test_case.coefs.a, test_case.coefs.b, test_case.coefs.c) <= 0)
        return OUTPUT_FAILURE;

    fprintf(stream, "Answer: ");
    if (print(stream, test_case.answer) == OUTPUT_FAILURE) 
        return OUTPUT_FAILURE;

    return OUTPUT_SUCCESS;
}
