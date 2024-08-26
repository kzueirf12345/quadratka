#include "input.hpp"

InputCode flush()
{
    int symbol = getchar();
    for (;symbol != '\n' && symbol != EOF && ferror(stdin) == 0;
        symbol = getchar());

    return ferror(stdin) ? INPUT_FAILURE : (symbol == EOF ? INPUT_EXIT : INPUT_SUCCESS);
}

InputCode scan_double(double* const num) 
{
    assert(num && "num is nullptr");

    int correct_scan_count = scanf("%lg", num);
    int next_symbol = (feof(stdin) ? EOF : getchar());

    return (ferror(stdin) == 0)
        ? (correct_scan_count == EOF
            ? INPUT_EXIT
            : ((correct_scan_count == 1 && next_symbol == (int)'\n')
                ? INPUT_SUCCESS
                : INPUT_INCORRECT
              )
          )
        : INPUT_FAILURE;
}

InputCode input_coef(double* const num, const char* const message)
{
    assert(num && "num is nullptr");
    assert(message && "num is nullptr");

    if (printf("%s", message) <= 0)
        return INPUT_FAILURE;
    InputCode input_code = INPUT_FAILURE;
    while ((input_code = scan_double(num)) == INPUT_INCORRECT)
    {
        printf("Incorrect input, try again!\n");
        if (printf("%s", message) <= 0)
            return INPUT_FAILURE;
            
        InputCode flush_code = flush();
        if (flush_code == INPUT_FAILURE || flush_code == INPUT_EXIT)
            return flush_code;
    }

    return input_code;
}

InputCode input(Coefs* const coefs) {
    assert(coefs && "coefs is nullptr");

    constexpr size_t COUNT_COEFS = 3;
    double* coefs_array[COUNT_COEFS] = {&coefs->a, &coefs->b, &coefs->c};
    constexpr const char* const messages_array[3] = 
    {
        "Input first coef: ",
        "Input second coef: ",
        "Input third coef: "
    };

    InputCode input_code = INPUT_FAILURE;
    for (size_t i = 0; i < COUNT_COEFS; ++i)
    {
        input_code = input_coef(coefs_array[i], messages_array[i]);
        if (input_code == INPUT_FAILURE || input_code == INPUT_EXIT)
            return input_code;
    }

    return input_code;
}