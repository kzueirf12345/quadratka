#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "src/input/input.h"
#include "src/calculate/calculate.h"
#include "src/output/output.h"
#include "src/test/test.h"

// #define TEST

int main()
{
#ifdef TEST
    if (global_testing() == TEST_FAILURE)
    {
        fprintf(stderr, "TEST_FAILURE\n");
        return -1;
    }
    fprintf(stderr, "Testing complete!\n");
#else
    Coefs coefs = {0, 0, 0};
    if (input(&coefs) == INPUT_FAILURE)
    {
        fprintf(stderr, "INPUT_FAILURE\t ferror(stdin) = %d", ferror(stdin));
        return -1;
    }

    const Answer answer = calculate(coefs);

    printf("Answer: ");
    if (print(stdout, answer) == OUTPUT_FAILURE)
    {
        fprintf(stderr, "OUTPUT_FAILURE\t ferror(stdout) = %d", ferror(stdout));
        return -1;
    }
#endif

    return 0;
}