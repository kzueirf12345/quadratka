#ifndef SRC_FLAG_H
#define SRC_FLAG_H

#include <string.h>

#include "../output/output.h"
#include "../utils/utils.h"


struct Options
{
    bool do_help;
    bool do_clean;
    bool do_print_log;
    bool do_infinity;

    const char* logout_name;
    FILE* logout;

    FILE* out;
    FILE* print_log;
};

enum FlagCode
{
    FLAG_SUCCESS = 0,
    FLAG_INCORRECT = 1,
    FLAG_FAILURE = 2,
};

struct Flag
{
    const char* name;
    const char* small_description;
    const char* description;
    FlagCode (*func)(Options* const options, size_t* const index_argv, 
        const char* const* const argv, const size_t argc);
};


FlagCode Flag_help(Options* const options, size_t* const index_argv, 
    const char* const* const argv, const size_t argc);
FlagCode Flag_clean(Options* const options, size_t* const index_argv, 
    const char* const* const argv, const size_t argc);
FlagCode Flag_infinity(Options* const options, size_t* const index_argv, 
    const char* const* const argv, const size_t argc);
FlagCode Flag_log(Options* const options, size_t* const index_argv, 
    const char* const* const argv, const size_t argc);
FlagCode Flag_file(Options* const options, size_t* const index_argv, 
    const char* const* const argv, const size_t argc);
FlagCode Flag_print_log(Options* const options, size_t* const index_argv, 
    const char* const* const argv, const size_t argc);


constexpr size_t FLAGS_SIZE = 6;
constexpr Flag FLAGS[FLAGS_SIZE] = 
{
    (Flag){.name = "--help", .small_description = nullptr, .description = nullptr, 
        .func = Flag_help},
    (Flag){.name = "--clean", .small_description = "--clean", 
        .description = "Clean log", .func = Flag_clean},
    (Flag){.name = "--infinity", .small_description = "--infinity",
        .description = "After solving next equation, the program starts over again",
        .func = Flag_infinity},
    (Flag){.name = "--log", .small_description = "--log ?[STREAM]",
        .description = "Changes the file for writing logs. "
        "If file is not found, a new one will be created. "
        "If [STREAM] not specified, than output will be do in ./user.log.",
        .func = Flag_log},
    (Flag){.name = "--file", .small_description = "--file ?[STREAM]", 
        .description = "Changes the output stream to the file specified by the next parameter. "
        "If file is not found, a new one will be created. "
        "If [STREAM] not specified, than output will be do in console. "
        "To use the console as the output stream, enter "
        KWORD_TO_STDOUT
        " in place of the file name", 
        .func = Flag_file},
    (Flag){.name = "--print_log", .small_description = "--print_log ?[STREAM]",
        .description = "Output contents of logout to the file specified by the next parameter. "
        "If [STREAM] not specified, than output will be do in console. "
        "To use the console as the output stream, enter "
        KWORD_TO_STDOUT
        " in place of the file name", 
        .func = Flag_print_log}
};


FlagCode fill_Options(Options*const options, const size_t argc,const char * const * const argv);

FlagCode command_help(Options*const options);
FlagCode command_clean(Options*const options);
FlagCode command_print_log(Options*const options);
FlagCode command_infinity(Options*const options); // TODO - implementation and run.h and run.cpp



#endif /* SRC_FLAG_H */