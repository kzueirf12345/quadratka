#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "input/input.h"
#include "calculate/calculate.h"
#include "output/output.h"
#include "test/test.h"
#include "utils/console.h"

#define TEST

int run_test();
int run_user();

int main()
{
#ifdef TEST
    return run_test();
#else
    return run_user();
#endif

    return 0;
}

int run_test()
{
    
    FILE* test_log = fopen("log/test.log", "w");
    if (global_testing(test_log) == TEST_FAILURE)
    {
        fprintf(stderr, RED_TEXT "TEST_FAILURE\n" NORMAL_TEXT);
        fclose(test_log);
        return -1;
    }
    fclose(test_log);
    fprintf(stderr, GREEN_TEXT "Testing complete!\n" NORMAL_TEXT);
    return 0;
}

int run_user() { 
    Coefs coefs = {0, 0, 0};
    if (input(&coefs) == INPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT "INPUT_FAILURE\t ferror(stdin) = %d" NORMAL_TEXT, ferror(stdin));
        return -1;
    }

    const Answer answer = calculate(coefs);

    printf("Answer: ");
    if (print(stdout, answer) == OUTPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT "OUTPUT_FAILURE\t ferror(stdout) = %d" NORMAL_TEXT, ferror(stdout));
        return -1;
    }

    return 0;
}
