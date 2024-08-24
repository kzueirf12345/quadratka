#include "input.h"

InputCode flush()
{
    for (int symbol = getchar();
        symbol != '\n' && symbol != EOF && ferror(stdin) == 0;
        symbol = getchar());

    return ferror(stdin) ? INPUT_FAILURE : INPUT_SUCCESS;
}

InputCode scan_double(double* const num) 
{
    assert(num && "num is nullptr");

    int correct_scan_count = scanf("%lg", num);
    int next_symbol = getchar();

    return (ferror(stdin) == 0 && correct_scan_count != EOF) //TODO - eof INPUT_EXIT
        ? ((correct_scan_count == 1 && next_symbol == (int)'\n')
            ? INPUT_SUCCESS
            : INPUT_INCORRECT)
        : INPUT_FAILURE;
}

InputCode input_coef(double* const num, const char* const message)
{
    assert(num && "num is nullptr");
    assert(message && "num is nullptr");

    printf("%s", message); //TODO - check input
    InputCode input_code = INPUT_FAILURE;
    while ((input_code = scan_double(num)) == INPUT_INCORRECT)
    {
        printf("Incorrect input, try again!\n");
        printf("%s", message);
        flush();
    }

    return input_code;
}

InputCode input(Coefs* const coefs) {
    assert(coefs && "coefs is nullptr");

    InputCode input_code = INPUT_FAILURE;

    constexpr size_t COUNT_COEFS = 3;
    double* coefs_array[COUNT_COEFS] = {&coefs->a, &coefs->b, &coefs->c};
    constexpr char* const messages_array[3] = 
    {
        "Input first coef: ",
        "Input second coef: ",
        "Input third coef: "
    };

    for (size_t i = 0; i < COUNT_COEFS; ++i)
    {
        input_code = input_coef(coefs_array[i], messages_array[i]);
        if (input_code == INPUT_FAILURE)
            return input_code;
    }

    return input_code;
}