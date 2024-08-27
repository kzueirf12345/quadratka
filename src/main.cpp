#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "command/command.hpp"
#include "flag/flag_fill.hpp"
#include "utils/console.hpp"

int main(const int argc, const char* argv[])
{
    FlagData flag_data =
    {
        .commands = {},
        .streams = {.logout_name = DEFAULT_USER_LOGOUT, .logout = nullptr,
            .out_name = KWORD_TO_STDOUT, .out = nullptr}
    };


    if (argc == 1)
    {
        FlagCode set_streams_files_code = set_streams_files(&flag_data.streams);
        if (set_streams_files_code == FLAG_FAILURE)
        {
            fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"),
                (int)set_streams_files_code);
            return -1;
        }

        FlagCode command_use_code = command_use(&flag_data.streams);
        if (command_use_code != FLAG_SUCCESS)
        {
            fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)command_use_code);
            return -1;
        }
        return destroy_FlagStreams(&flag_data.streams);
    }


    FlagCode fill_flag_data_code = fill_flag_data(&flag_data, (Args){.argv = argv, .argc = argc});
    if (fill_flag_data_code != FLAG_SUCCESS && fill_flag_data_code != FLAG_EXIT)
    {
        fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)fill_flag_data_code);
        return -1;
    }

    FlagCode set_streams_files_code = set_streams_files(&flag_data.streams);
    if (set_streams_files_code == FLAG_FAILURE)
    {
        fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"), (int)set_streams_files_code);
        return -1;
    }

    FlagCode processing_flag_data_code = processing_flag_data(&flag_data);
    if (processing_flag_data_code != FLAG_SUCCESS && processing_flag_data_code != FLAG_EXIT)
    {
        fprintf(stderr, RED_TEXT("FLAGS_FAILURE\t error code = %d\n"),
            (int)processing_flag_data_code);
        return -1;
    }

    return destroy_FlagStreams(&flag_data.streams);
}