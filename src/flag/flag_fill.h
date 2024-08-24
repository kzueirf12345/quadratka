#ifndef SRC_FLAG_H
#define SRC_FLAG_H


#include <string.h>

#include "../output/output.h"
#include "../utils/utils.h"
#include "../command/command.h"
#include "flag_constants.h"


FlagCode fill_Options(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, const int argc,const char * const * const argv);


#endif /* SRC_FLAG_H */