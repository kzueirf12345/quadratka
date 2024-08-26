#include "command.hpp"

#include "../test/test.hpp"
#include "../input/input.hpp"
#include "../utils/utils.hpp"
#include "../utils/console.hpp"
#include "../flag/flag_constants.hpp"


/// @brief Вспомогательная функция для режимов --use и --infinity
/// @param[out] streams Потоки для вывода
/// @param[in] test_number Номер теста. При значении -1 номер не печатается.
/// @return Код окончания работы
///
/// Данная функция нужна, чтобы можно было нумеровать, либо же ненумеровать тест-кейсы
/// в зависимости от используемого флага (--use или --infinity). Вызывает функции input(), calculate(),
/// print_answer()
static FlagCode use(FlagStreams* const streams,const int test_number = -1);


FlagCode command_help(FlagStreams* const streams)
{
    assert(streams && "streams is nullptr");

    fprintf(streams->out, 
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

    fprintf(streams->out, "\nWithout flags the program will run once and after the "
            "solution will terminate, leaving a record in the log\n");


    fprintf(streams->out, "\nOrder processing flags:\n"
        "--file, --log, --help, --print_log, --clean, --test, --use, --infinity\n");

    static_assert(HELP == 0);
    static_assert(PRINT_LOG == 1);
    static_assert(CLEAN == 2);
    static_assert(TEST == 3);
    static_assert(USE == 4);
    static_assert(INFIN == 5);
    static_assert(FLAG_OPTIONS_SIZE == 6);
            

    if (fprintf(streams->out, "\nError codes:\nFAILURE = %d\nINCORRECT = %d\n\n", 
            (int)FLAG_FAILURE, (int)FLAG_INCORRECT) <= 0)
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode command_clean(FlagStreams* const streams)
{
    assert(streams && "streams is nullptr");


    if(fclose(streams->logout))
        return FLAG_FAILURE;

    if (!(streams->logout = fopen(streams->logout_name, "w")))
        return FLAG_FAILURE;
    
    fprintf(stderr, GREEN_TEXT("\nClean complete!\n"));

    return FLAG_SUCCESS;
}

FlagCode command_print_log(FlagStreams* const streams)
{ 
    assert(streams && "streams is nullptr");
    assert(streams->logout && "streams->logout is nullptr");


    if (fclose(streams->logout))
        return FLAG_FAILURE;
    if (!(streams->logout = fopen(streams->logout_name, "r")))
        return FLAG_FAILURE;


    int symbol = '\0';
    while ((symbol = fgetc(streams->logout)) != EOF)
    {
        if (fprintf(streams->out, "%c", (char)symbol) <= 0)
            return FLAG_FAILURE;
    }


    if (fclose(streams->logout))
        return FLAG_FAILURE;
    if (!(streams->logout = fopen(streams->logout_name, "ab")))
        return FLAG_FAILURE;

    fprintf(stderr, GREEN_TEXT("\nPrint_log complete!\n"));

    return FLAG_SUCCESS;
}


FlagCode command_infinity(FlagStreams* const streams)
{
    assert(streams && "streams is nullptr");
    assert(streams->logout && "streams->logout is nullptr");


    fprintf(streams->logout, "\nSTART INIFINITY MODE LOG\n");

    int test_number = 0;
    FlagCode command_use_code = FLAG_FAILURE;
    while ((command_use_code = use(streams, test_number++)) == FLAG_SUCCESS);

    if (command_use_code == FLAG_EXIT)
        fprintf(stderr, GREEN_TEXT("\nInfinity complete!\n"));

    return command_use_code;
}

FlagCode command_test(FlagStreams* const streams) 
{
    assert(streams && "streams is nullptr");
    assert(streams->logout && "streams->logout is nullptr");


    fprintf(streams->logout, "\nSTART TEST MODE LOG\n");

    if (global_testing(streams->logout) == TEST_FAILURE)
    {
        fprintf(stderr, RED_TEXT("TEST_FAILURE\n"));
        return FLAG_FAILURE;
    }
    fprintf(stderr, GREEN_TEXT("\nTesting complete!\n"));

    return FLAG_SUCCESS;
}

FlagCode command_use(FlagStreams* const streams)
{
    assert(streams && "streams is nullptr");
    assert(streams->logout && "streams->logout is nullptr");


    fprintf(streams->logout, "\nSTART STANDART MODE LOG\n");

    FlagCode use_code = use(streams);

    if (use_code == FLAG_SUCCESS)
        fprintf(stderr, GREEN_TEXT("\nUse complete!\n"));

    return use_code;
}


static FlagCode use(FlagStreams* const streams, const int test_number)
{
    assert(streams && "streams is nullptr");                                                    
    assert(streams->out && "streams->out is nullptr");


    Coefs coefs = {NAN, NAN, NAN};

    InputCode input_code = input(&coefs);
    if (input_code == INPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("INPUT_FAILURE\t ferror(stdin) = %d\n"), ferror(stdin));
        return FLAG_FAILURE;
    }
    if (input_code == INPUT_EXIT)
        return FLAG_EXIT;


    const Answer answer = calculate(coefs);
    if (print_test_case(streams->logout, (TestCase){test_number, coefs, answer}) == OUTPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("OUTPUT_FAILURE\n"));
        return FLAG_FAILURE;
    }


    fprintf(streams->out, "Answer: ");
    if (print_answer(streams->out, answer) == OUTPUT_FAILURE)
    {
        fprintf(stderr, RED_TEXT("OUTPUT_FAILURE\n"));
        return FLAG_FAILURE;
    }

    return FLAG_SUCCESS;
}