#ifndef SRC_RUN_H
#define SRC_RUN_H

#include <stdio.h>
#include "../flag/flag_utils.h"

FlagCode command_help(FlagStreams*const streams);
FlagCode command_clean(FlagStreams*const streams);
FlagCode command_print_log(FlagStreams*const streams);

FlagCode command_infinity(FlagStreams*const streams); // TODO - implementation
FlagCode command_test(FlagStreams*const streams);
FlagCode command_use(FlagStreams*const streams);

#endif /* SRC_RUN_H */