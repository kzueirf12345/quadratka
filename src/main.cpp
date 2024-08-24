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
    FlagStreams flag_streams = {.logout_name = DEFAULT_USER_LOGOUT, 
        .logout = fopen(DEFAULT_USER_LOGOUT, "a+b"), .out = stdout };
    assert(flag_streams.logout && "flag_data.logout is nullptr"); // TODO 


    if (argc == 1)
        return command_use(&flag_streams); //REVIEW - 

    FlagCode (*flag_commands[FLAG_OPTIONS_SIZE])(FlagStreams* const streams) = {};


    FlagCode fill_Options_code = FLAG_FAILURE;
    if ((fill_Options_code = fill_Options(flag_commands, &flag_streams, argc, argv)) 
        != FLAG_SUCCESS)
    {
        fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)fill_Options_code);
        return -1;
    }

    for (size_t option = 0; option < (size_t)FLAG_OPTIONS_SIZE; ++option)
    {
        if (flag_commands[option])
        {
            FlagCode error_flag_code = FLAG_FAILURE;
            if (flag_commands[option](&flag_streams) != FLAG_SUCCESS)
            {
                fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"),
                    (int)error_flag_code);
                return -1;
            }
        }
    }

    return destroy_FlagStreams(&flag_streams);
}

int destroy_FlagStreams(FlagStreams* flag_streams)
{
    assert(flag_streams && "flag_streams is nullptr");

    if (flag_streams->logout && fclose(flag_streams->logout))
    {
        fprintf(stderr, RED_TEXT("Close fail flag_streams.logout failure\n"));
        return -1;
    }
    flag_streams->logout = nullptr;

    if (flag_streams->out && fclose(flag_streams->out))
    {
        fprintf(stderr, RED_TEXT("Close fail flag_streams.out failure\n"));
        return -1;
    }
    flag_streams->out = nullptr;
    
    return 0;
}

