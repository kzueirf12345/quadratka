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
    (void) argc;
    (void) argv;
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
        fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)fill_Options_code);
        return -1;
    }

    //TODO - можно использовать указатель на функцию в массиве и пройтись циклом
    if (options.do_help)
    {
        FlagCode help_code = FLAG_FAILURE;
        if ((help_code = command_help(&options)) != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)help_code);
            return -1;
        }
        return 0;
    }
    if (options.do_clean)
    {
        FlagCode clean_code = FLAG_FAILURE;
        if ((clean_code = command_clean(&options)) != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)clean_code);
            return -1;
        }
    }
    if (options.do_print_log)
    {
        FlagCode print_log_code = FLAG_FAILURE;
        if ((print_log_code = command_print_log(&options)) != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)print_log_code);
            return -1;
        }
    }
    if (options.do_infinity)
    {
        FlagCode infinity_code = FLAG_FAILURE;
        if ((infinity_code = command_infinity(&options)) != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)infinity_code);
            return -1;
        }
    }

#endif /* TEST */

    return 0;
}


int run_test()
{
    
    FILE* test_log = fopen(DEFAULT_TEST_LOGOUT, "w");
    if (global_testing(stdout) == TEST_FAILURE)
    {
        fprintf(stderr, RED_TEXT("TEST_FAILURE\n"));
        fclose(test_log);
        return -1;
    }
    fclose(test_log);
    fprintf(stderr, GREEN_TEXT("Testing complete!\n"));
    return 0;
}

int run_use(FILE* out) { 
    Coefs coefs = {0, 0, 0};
    if (input(&coefs) == INPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("INPUT_FAILURE\t ferror(stdin) = %d"), ferror(stdin));
        return -1;
    }

    const Answer answer = calculate(coefs);

    printf("Answer: ");
    if (print(out, answer) == OUTPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("OUTPUT_FAILURE"));
        return -1;
    }

    return 0;
}

