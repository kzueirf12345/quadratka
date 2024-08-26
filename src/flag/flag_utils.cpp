#include "flag_utils.h"

#include <string.h>

FlagCode set_streams_files(FlagStreams* const streams) {
    if (!(streams->logout = fopen(streams->logout_name, "ab")))
        return FLAG_FAILURE;
    
    if (strcmp(streams->out_name, KWORD_TO_STDOUT) == 0)
        streams->out = stdout;
    else if (!(streams->out = fopen(streams->out_name, "ab")))
        return FLAG_FAILURE;
    
    return FLAG_SUCCESS;
}