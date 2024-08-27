#include "flag_utils.hpp"

#include <string.h>
#include <assert.h>

FlagCode set_streams_files(FlagStreams* const streams) {
    assert(streams && "streams is nullptr");

    if (!(streams->logout = fopen(streams->logout_name, "ab")))
        return FLAG_FAILURE;
    
    if (strcmp(streams->out_name, KWORD_TO_STDOUT) == 0)
        streams->out = stdout;
    else if (!(streams->out = fopen(streams->out_name, "ab")))
        return FLAG_FAILURE;
    
    return FLAG_SUCCESS;
}

int destroy_FlagStreams(FlagStreams* flag_streams)
{
    assert(flag_streams && "flag_streams is nullptr");

    if (flag_streams->logout && flag_streams->logout != stdout && fclose(flag_streams->logout))
    {
        fprintf(stderr, RED_TEXT("Close logout failure\n"));
        return -1;
    }
    flag_streams->logout = nullptr;

    if (flag_streams->out && flag_streams->out != stdout && fclose(flag_streams->out))
    {
        fprintf(stderr, RED_TEXT("Close out failure\n"));
        return -1;
    }
    flag_streams->out = nullptr;
    
    return 0;
}
