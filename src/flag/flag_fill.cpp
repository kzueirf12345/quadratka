#include "flag_fill.h"

FlagCode fill_Options(FlagCode (** const flag_commands)(FlagStreams* const streams),
        FlagStreams* const streams, const int argc, const char * const * const argv)
{
    assert(streams && "streams is nullptr");
    assert(flag_commands && "streams is nullptr");
    assert(argv && "argv is nullptr");

    for (int i = 1; i < argc; ++i)
    {
        for (size_t j = 0; j < FLAGS_SIZE; ++j)
        {
            if (strcmp(argv[i], FLAGS[j].name) == 0)
            {
                FlagCode flags_func_code = FLAG_FAILURE;
                if ( (flags_func_code = FLAGS[j].func(flag_commands, streams, &i, argv, argc)) != FLAG_SUCCESS)
                    return flags_func_code;
            }
        }
    }
    return FLAG_SUCCESS;
}