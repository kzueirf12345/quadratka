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

// #define TEST

int run_test();
int run_use();

OutputCode command_print_help(FILE* output_stream);
OutputCode command_print_log(FILE* output_stream);

int main(int argc, char* argv[])
{
#ifdef TEST

    return run_test() // TODO: argc and argv arguments

#else

    //TODO: log_out in run

    FILE* logout_stream = fopen("./log/test.log", "a+");

    if (argc == 1)
    {
        return run_use();
    }

    FILE* output_stream = stdout;
    // TODO: custom stream "--file <filename>"
    // TODO: infinity mode "--infinity"
    // TODO: clean log "--clean"
    for (size_t i = 1; i < argc; ++i)
    {
        if (argv[i] == "--help")
        {
            if (command_print_help(output_stream) == OUTPUT_FAILURE)
            {
                fprintf(stderr, 
                        RED_TEXT "OUTPUT_FAILURE\t ferror(stdout) = %d" NORMAL_TEXT, 
                        ferror(stdout));
                return -1;
            }
        }
        else if (argv[i] == "--log")
        {
            if (command_print_log(output_stream) == OUTPUT_FAILURE)
            {
                fprintf(stderr, 
                        RED_TEXT "OUTPUT_FAILURE\t ferror(stdout) = %d" NORMAL_TEXT, 
                        ferror(stdout));
                return -1;
            }
        }
    }

#endif
    return 0;
}

OutputCode command_print_help(FILE* output_stream) { 
    assert(output_stream && "output_stream is nullptr");

    fprintf (
        output_stream, 
        "===== QUADRATKA HELP =====\n"
        "Use: ./quadratka.out [FLAGS]\n"
        "This program solves second degree equations\n"
        "\n"
        "FLAGS:\n"
        "--clean                \t Clean log\n"
        "--infinity             \t After solving next equation, the program starts over again\n"
        "--log  [FILENAME]      \t Changes the file for writing logs."
            "If file is not found, a new one will be created\n"
        "--file [FILENAME]        \t Changes the output stream to the file specified by the next parameter."
            "If file is not found, a new one will be created\n"
        "--print_log ?[STREAM]  \t Output contents of logout to the file specified by the next parameter."
            "If [STREAM] not specified, than output will be do in conCole\n"
        "\n"
        "Without --infinity the program will run once and after the solution will terminate, leaving a record in the log"
    );
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

int run_use() { 
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

