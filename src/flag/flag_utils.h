#ifndef SRC_FLAG_UTILS_H
#define SRC_FLAG_UTILS_H


#include <stdio.h>

#include "../utils/utils.h"


enum FlagOptions
{
    HELP              = 0,
    PRINT_LOG         = 1,
    CLEAN             = 2,
    TEST              = 3,
    USE               = 4,
    INFIN             = 5,
    FLAG_OPTIONS_SIZE = 6
};

struct FlagStreams
{
    const char* logout_name;
    FILE* logout;

    FILE* out;
};

enum FlagCode
{
    FLAG_SUCCESS   = 0,
    FLAG_INCORRECT = 1,
    FLAG_FAILURE   = 2,
};

struct Flag
{
    const char* name;
    const char* small_description;
    const char* description;
    FlagCode (*func)(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
};


#endif /* SRC_FLAG_UTILS_H */