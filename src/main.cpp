#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "command/command.h"
#include "flag/flag_fill.h"
#include "utils/console.h"


int destroy_FlagStreams(FlagStreams* flag_streams);


int main(const int argc, const char* argv[])
{
    FlagData flag_data =
    {
        .commands = {},
        .streams = {.logout_name = DEFAULT_USER_LOGOUT, 
        .logout = fopen(DEFAULT_USER_LOGOUT, "a+b"), .out = stdout} 
        // FIXME - make default logout independently flags 
    };
    if (!flag_data.streams.logout)
    {
        fprintf(stderr, RED_TEXT("Open logout failure\n"));
        return -1;
    }


    if (argc == 1)
    {
        FlagCode command_use_code = command_use(&flag_data.streams);
        if (command_use_code != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)command_use_code);
            return -1;
        }
        return 0;
    }


    FlagCode fill_flag_data_code = fill_flag_data(&flag_data, (Args){.argv = argv, .argc = argc});
    if (fill_flag_data_code != FLAG_SUCCESS && fill_flag_data_code != FLAG_EXIT)
    {
        fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)fill_flag_data_code);
        return -1;
    }

    FlagCode processing_flag_data_code = processing_flag_data(&flag_data);
    if (processing_flag_data_code!= FLAG_SUCCESS)
    {
        fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"),
            (int)processing_flag_data_code);
        return -1;
    }

    return destroy_FlagStreams(&flag_data.streams);
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

