#include "flag_funcs.h"


FlagCode Flag_log(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    if (*index_argv == args.argc - 1)
    {
        if (!(flag_data->streams.logout
            = fopen((flag_data->streams.logout_name = DEFAULT_USER_LOGOUT), "a+b")))
            return FLAG_FAILURE;
        return FLAG_SUCCESS;
    }

    flag_data->streams.logout_name = args.argv[++*index_argv];
    if (strcmp(flag_data->streams.logout_name, KWORD_TO_STDOUT) == 0)
        flag_data->streams.logout = stdout;
    else if (!(flag_data->streams.logout = fopen(flag_data->streams.logout_name, "a+b")))
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode Flag_file(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    if (*index_argv == args.argc - 1)
    {
        flag_data->streams.out = stdout;
        return FLAG_SUCCESS;
    }

    const char* const filename = args.argv[++*index_argv];
    if (strcmp(filename, KWORD_TO_STDOUT) == 0)
        flag_data->streams.out = stdout;
    else if (!(flag_data->streams.out = fopen(filename, "a+b")))
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}


FlagCode Flag_help(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    (void) index_argv;
    (void) args;

    flag_data->commands[HELP] = command_help;

    return FLAG_SUCCESS;
}

FlagCode Flag_clean(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    (void) index_argv;
    (void) args;

    flag_data->commands[CLEAN] = command_clean;

    return FLAG_SUCCESS;
}

FlagCode Flag_print_log(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    (void) index_argv;
    (void) args;

    flag_data->commands[PRINT_LOG] = command_print_log;

    return FLAG_SUCCESS;
}


FlagCode Flag_infinity(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    (void) index_argv;
    (void) args;

    flag_data->commands[INFIN] = command_infinity;

    return FLAG_SUCCESS;
}

FlagCode Flag_test(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    (void) index_argv;
    (void) args;


    flag_data->commands[TEST] = command_test;

    return FLAG_SUCCESS;
}

FlagCode Flag_use(FlagData* const flag_data, int* const index_argv, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(index_argv && "index_argv is nullptr");

    (void) index_argv;
    (void) args;

    flag_data->commands[USE] = command_use;

    return FLAG_SUCCESS;
}