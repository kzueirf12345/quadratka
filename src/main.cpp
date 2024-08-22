#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "input/input.h"
#include "calculate/calculate.h"
#include "test/test.h"
#include "utils/console.h"
#include "flag/flag.h"

// #define TEST

int run_test();
int run_use(FILE* out);

int main(const int argc,const char* argv[])
{
#ifdef TEST

    return run_test();

#else

    if (argc == 1)
        return run_use(stdout);

    Options options = {.help = false, .clean = false, .infinity = false, .print_log = false,
                       .out = stdout, .logout = fopen("./user.log", "a+b"), .log_print = stdout};
    assert(options.logout && "options.logout is nullptr");

    FlagCode fill_Options_code = FLAG_FAILURE;
    if ((fill_Options_code = fill_Options(&options, argc, argv)) != FLAG_SUCCESS)
    {
        fprintf(stderr, RED_TEXT "FLAGS_FAILURE\t error code = %d\n" NORMAL_TEXT, (int)fill_Options_code);
        return -1;
    }

    if (options.help)
        command_help(&options);

#endif /* TEST */
    return 0;
}


int run_test()
{
    
    FILE* test_log = fopen(DEFAULT_TEST_LOGOUT, "w");
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

int run_use(FILE* out) { 
    Coefs coefs = {0, 0, 0};
    if (input(&coefs) == INPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT "INPUT_FAILURE\t ferror(stdin) = %d" NORMAL_TEXT, ferror(stdin));
        return -1;
    }

    const Answer answer = calculate(coefs);

    printf("Answer: ");
    if (print(out, answer) == OUTPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT "OUTPUT_FAILURE" NORMAL_TEXT);
        return -1;
    }

    return 0;
}

