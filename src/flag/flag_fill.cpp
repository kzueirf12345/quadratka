#include "flag_fill.hpp"


FlagCode fill_flag_data(FlagData* const flag_data, const Args args)
{
    assert(flag_data && "flag_data is nullptr");
    assert(args.argv && "args.argc is nullptr");

    for (int i = 1; i < args.argc; ++i)
    {
        bool is_find_flag = false;
        for (size_t j = 0; j < FLAGS_SIZE; ++j)
        {
            assert(args.argv[i] && "args.argc[i] is nullptr");
            assert(FLAGS[j].name && "FLAGS[j].name is nullptr");

            if (strcmp(args.argv[i], FLAGS[j].name) == 0)
            {
                is_find_flag = true;
                FlagCode flags_func_code = FLAG_FAILURE;
                if ((flags_func_code = FLAGS[j].func(flag_data, &i, args)) != FLAG_SUCCESS)
                    return flags_func_code;
            }
        }
        if (!is_find_flag)
            return FLAG_INCORRECT;
    }

    return FLAG_SUCCESS;
}

FlagCode processing_flag_data(FlagData* const flag_data)
{ 
    assert(flag_data && "flag_data is nullptr");
    for (size_t option = 0; option < (size_t)FLAG_OPTIONS_SIZE; ++option)
    {
        assert(flag_data->commands && "flag_data->commands is nullptr");
        if (flag_data->commands[option])
        {
            FlagCode error_flag_code = flag_data->commands[option](&flag_data->streams);
            if (error_flag_code != FLAG_SUCCESS)
            {
                return error_flag_code;
            }
        }
    }
    return FLAG_SUCCESS;
}
