#include "flag_funcs.h"


FlagCode Flag_help(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) index_argv;
    (void) argv;
    (void) argc;
    (void) streams;

    flag_commands[HELP] = command_help;

    return FLAG_SUCCESS;
}

FlagCode Flag_clean(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) index_argv;
    (void) argv;
    (void) argc;
    (void) streams;

    flag_commands[CLEAN] = command_clean;

    return FLAG_SUCCESS;
}

FlagCode Flag_infinity(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) index_argv;
    (void) argv;
    (void) argc;
    (void) streams;

    flag_commands[INFIN] = command_infinity;

    return FLAG_SUCCESS;
}

FlagCode Flag_log(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) flag_commands;

    if (*index_argv == argc - 1)
    {
        if (!(streams->logout = fopen((streams->logout_name = DEFAULT_USER_LOGOUT), "a+b")))
            return FLAG_FAILURE;
        return FLAG_SUCCESS;
    }

    if (!(streams->logout = fopen((streams->logout_name = argv[++*index_argv]), "a+b")))
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode Flag_file(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) flag_commands;

    if (*index_argv == argc - 1)
    {
        streams->out = stdout;
        return FLAG_SUCCESS;
    }

    const char* const filename = argv[++*index_argv];
    if (strcmp(filename,KWORD_TO_STDOUT) == 0)
        streams->out = stdout;
    else if (!(streams->out = fopen(filename, "a+b")))
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode Flag_print_log(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) index_argv;
    (void) argv;
    (void) argc;
    (void) streams;

    flag_commands[PRINT_LOG] = command_print_log;

    return FLAG_SUCCESS;
}

FlagCode Flag_test(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) index_argv;
    (void) argv;
    (void) argc;
    (void) streams;

    flag_commands[TEST] = command_test;

    return FLAG_SUCCESS;
}

FlagCode Flag_use(FlagCode (** const flag_commands)(FlagStreams* const streams),
    FlagStreams* const streams, int* const index_argv, 
    const char* const* const argv, const int argc)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "flags_data is nullptr");

    (void) index_argv;
    (void) argv;
    (void) argc;
    (void) streams;

    flag_commands[USE] = command_use;

    return FLAG_SUCCESS;
}