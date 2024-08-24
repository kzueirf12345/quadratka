#ifndef SRC_FLAG_H
#define SRC_FLAG_H


#include <string.h>

#include "../output/output.h"
#include "../utils/utils.h"
#include "../command/command.h"
#include "flag_constants.h"


FlagCode fill_flag_data(FlagData* const flag_data, const Args args);

FlagCode processing_flag_data(FlagData* const flag_data);


#endif /* SRC_FLAG_H */