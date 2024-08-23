#ifndef SRC_FLAG_FUNCS_H
#define SRC_FLAG_FUNCS_H

#include <assert.h>
#include <string.h>

#include "flag_utils.h"
#include "../command/command.h"

FlagCode Flag_help(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
FlagCode Flag_clean(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
FlagCode Flag_infinity(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
FlagCode Flag_log(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
FlagCode Flag_file(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
FlagCode Flag_print_log(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
FlagCode Flag_test(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);
FlagCode Flag_use(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, int* const index_argv, 
        const char* const* const argv, const int argc);

#endif /* SRC_FLAG_FUNCS_H */