#ifndef SRC_FLAG_UTILS_H
#define SRC_FLAG_UTILS_H


#include <stdio.h>

#include "../utils/utils.h"


enum FlagCode
{
    FLAG_SUCCESS   = 0,
    FLAG_INCORRECT = 1,
    FLAG_FAILURE   = 2,
    FLAG_EXIT      = 3
};

struct FlagStreams
{
    const char* logout_name;
    FILE* logout;

    const char* out_name;
    FILE* out;
};

FlagCode set_streams_files(FlagStreams* const streams);


typedef FlagCode(*CommandFuncPtr)(FlagStreams* const streams);

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

struct FlagData
{
    CommandFuncPtr commands[(int)FLAG_OPTIONS_SIZE];
    FlagStreams streams;
};


struct Flag
{
    const char* name;
    const char* small_description;
    const char* description;
    FlagCode (*func)(FlagData* const flag_data, int* const index_argv, const Args args);
};


#endif /* SRC_FLAG_UTILS_H */