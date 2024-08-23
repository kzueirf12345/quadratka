#include "command.h"

#include "../test/test.h"
#include "../input/input.h"
#include "../utils/utils.h"
#include "../utils/console.h"
#include "../flag/flag_constants.h"

FlagCode command_infinity(FlagStreams* const streams) { 
    (void) streams;
    return FLAG_SUCCESS; 
}

FlagCode command_test(FlagStreams* const streams) {
    assert(streams && "streams is nullptr");
    assert(streams->logout && "streams->logout is nullptr");

    if (global_testing(streams->logout) == TEST_FAILURE)
    {
        fprintf(stderr, RED_TEXT("TEST_FAILURE\n"));
        fclose(streams->logout);
        return FLAG_FAILURE;
    }
    fclose(streams->logout);
    fprintf(stderr, GREEN_TEXT("Testing complete!\n"));
    return FLAG_SUCCESS;
}

FlagCode command_use(FlagStreams* const streams)
{ 
    assert(streams && "streams is nullptr");
    assert(streams->out && "streams->out is nullptr");

    Coefs coefs = {NAN, NAN, NAN};
    if (input(&coefs) == INPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("INPUT_FAILURE\t ferror(stdin) = %d\n"), ferror(stdin));
        return FLAG_FAILURE;
    }

    const Answer answer = calculate(coefs);
    if (print_test_case(streams->logout, (TestCase){-1,coefs,answer}) == OUTPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("OUTPUT_FAILURE\n"));
        return FLAG_FAILURE;
    }

    printf("Answer: ");
    if (print(streams->out, answer) == OUTPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("OUTPUT_FAILURE\n"));
        return FLAG_FAILURE;
    }

    return FLAG_SUCCESS;
}


FlagCode command_help(FlagStreams*const streams)
{
    assert(streams && "streams is nullptr");

    fprintf (
    streams->out, 
    "===== QUADRATKA HELP =====\n"
    "Use: ./quadratka.out [FLAGS]\n"
    "This program solves second degree equations\n"
    "\n"
    "FLAGS:\n");

    for (size_t i = 1; i < FLAGS_SIZE; ++i)
    {
        if (fprintf(streams->out, "%-30s %s\n", FLAGS[i].small_description, FLAGS[i].description)
            <= 0)
            return FLAG_FAILURE;
    }

    fprintf(streams->out, "\nWithout --infinity the program will run once and after the "
        "solution will terminate, leaving a record in the log\n");

    if (fprintf(streams->out, "Error code:\nFAILURE = %d\nINCORRECT = %d\n\n", 
        (int)FLAG_FAILURE, (int)FLAG_INCORRECT) <= 0)
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode command_clean(FlagStreams* const streams)
{
    assert(streams && "streams is nullptr");

    if(fclose(streams->logout)){
        return FLAG_FAILURE;}
    streams->logout = nullptr;

    if (remove(streams->logout_name)){
        return FLAG_FAILURE;}
    streams->logout_name = nullptr;

    return FLAG_SUCCESS;
}

FlagCode command_print_log(FlagStreams* const streams) { 
    assert(streams && "streams is nullptr");

    int symbol = '\0';
    while ((symbol = getc(streams->logout)) != EOF)
    {
        if (fprintf(streams->out, "%c", (char)symbol) <= 0)
            return FLAG_FAILURE;
    }
    return FLAG_SUCCESS;
}
