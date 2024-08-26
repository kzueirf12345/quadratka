#ifndef SRC_FLAG_FUNCS_H
#define SRC_FLAG_FUNCS_H


#include <assert.h>
#include <string.h>

#include "flag_utils.h"
#include "../command/command.h"


FlagCode Flag_log(FlagData* const flag_data, int* const index_argv, const Args args);
FlagCode Flag_file(FlagData* const flag_data, int* const index_argv, const Args args);

FlagCode Flag_help(FlagData* const flag_data, int* const index_argv, const Args args);
FlagCode Flag_clean(FlagData* const flag_data, int* const index_argv, const Args args);
FlagCode Flag_print_log(FlagData* const flag_data, int* const index_argv, const Args args);

FlagCode Flag_infinity(FlagData* const flag_data, int* const index_argv, const Args args);
FlagCode Flag_test(FlagData* const flag_data, int* const index_argv, const Args args);
FlagCode Flag_use(FlagData* const flag_data, int* const index_argv, const Args args);


#endif /* SRC_FLAG_FUNCS_H */