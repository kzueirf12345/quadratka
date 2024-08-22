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

    Options options = {.do_help = false, .do_clean = false, .do_print_log = false, .do_infinity = false,
                       .logout_name = DEFAULT_USER_LOGOUT, .logout = fopen(DEFAULT_USER_LOGOUT, "a+b"),
                       .out = stdout, .print_log = stdout};
    assert(options.logout && "options.logout is nullptr");

    FlagCode fill_Options_code = FLAG_FAILURE;
    if ((fill_Options_code = fill_Options(&options, argc, argv)) != FLAG_SUCCESS)
    {
        fprintf(stderr, RED_TEXT "FLAGS_FAILURE\t error code = %d\n" NORMAL_TEXT, (int)fill_Options_code);
        return -1;
    }

    if (options.do_help)
    {
        if (command_help(&options) != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT "FLAGS_FAILURE\t error code = %d\n" NORMAL_TEXT, (int)fill_Options_code);
            return -1;
        }
    }
    if (options.do_clean)
    {
        if (command_clean(&options) != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT "FLAGS_FAILURE\t error code = %d\n" NORMAL_TEXT, (int)fill_Options_code);
            return -1;
        }
    }
    if (options.do_print_log)
    {
        if (command_print_log(&options) != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT "FLAGS_FAILURE\t error code = %d\n" NORMAL_TEXT, (int)fill_Options_code);
            return -1;
        }
    }

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

