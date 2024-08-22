#include "flag.h"

FlagCode Flag_help(Options* const options, size_t* const index_argv, 
        const char* const* const argv, const size_t argc)
{
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    options->do_help = true;

    return FLAG_SUCCESS;
}

FlagCode Flag_clean(Options* const options, size_t* const index_argv, const char* const* const argv,
                    const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    options->do_clean = true;

    return FLAG_SUCCESS;
}

FlagCode Flag_infinity(Options* const options, size_t* const index_argv,
                       const char* const* const argv, const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    options->do_infinity = true;

    return FLAG_SUCCESS;
}

FlagCode Flag_log(Options* const options, size_t* const index_argv, const char* const* const argv,
                  const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    if (*index_argv == argc - 1)
        if (!(options->logout = fopen((options->logout_name = DEFAULT_USER_LOGOUT), "a+b")))
            return FLAG_FAILURE;
        return FLAG_SUCCESS;
    

    if (!(options->logout = fopen((options->logout_name = argv[++*index_argv]), "a+b")))
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode Flag_file(Options* const options, size_t* const index_argv, const char* const* const argv,
                   const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    if (*index_argv == argc - 1)
        options->out = stdout;
        return FLAG_SUCCESS;
    
    const char* const filename = argv[++*index_argv];
    if (strcmp(filename,KWORD_TO_STDOUT) == 0)
        options->out = stdout;
    else if (!(options->out = fopen(filename, "a+b")))
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode Flag_print_log(Options* const options, size_t* const index_argv,
                        const char* const* const argv, const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    if (*index_argv == argc - 1)
        options->print_log = stdout;
        return FLAG_SUCCESS;
    
    const char* const filename = argv[++*index_argv];
    if (strcmp(filename, KWORD_TO_STDOUT) == 0)
        options->print_log = stdout;
    else if (!(options->print_log = fopen(filename, "a+b")))
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode fill_Options(Options*const options, const size_t argc,const char * const * const argv)
{
    assert(options && "options is nullptr");

    for (size_t i = 1; i < argc; ++i)
    {
        for (size_t j = 0; j < FLAGS_SIZE; ++j)
        {
            if (strcmp(argv[i], FLAGS[j].name) == 0)
            {
                FlagCode flags_func_code = FLAG_FAILURE;
                if ( (flags_func_code = FLAGS[j].func(options, &i, argv, argc)) != FLAG_SUCCESS)
                    return flags_func_code;
            }
        }
    }
    return FLAG_SUCCESS;
}

FlagCode command_help(Options*const options)
{
    assert(options && "options is nullptr");

    fprintf (
    options->out, 
    "===== QUADRATKA HELP =====\n"
    "Use: ./quadratka.out [FLAGS]\n"
    "This program solves second degree equations\n"
    "\n"
    "FLAGS:\n");

    for (size_t i = 1; i < FLAGS_SIZE; ++i)
    {
        if (fprintf(options->out, "%-30s %s\n", FLAGS[i].small_description, FLAGS[i].description)
            <= 0)
            return FLAG_FAILURE;
    }

    fprintf(options->out, "\nWithout --infinity the program will run once and after the "
        "solution will terminate, leaving a record in the log\n");

    if (fprintf(options->out, "Error code:\nFAILURE = %d\nINCORRECT = %d\n\n", 
        (int)FLAG_FAILURE, (int)FLAG_INCORRECT) <= 0)
        return FLAG_FAILURE;

    return FLAG_SUCCESS;
}

FlagCode command_clean(Options* const options)
{
    assert(options && "options is nullptr");

    if(fclose(options->logout)){
        return FLAG_FAILURE;}
    options->logout = nullptr;

    if (remove(options->logout_name)){
        return FLAG_FAILURE;}
    options->logout_name = nullptr;

    return FLAG_SUCCESS;
}

FlagCode command_print_log(Options* const options) { 
    assert(options && "options is nullptr");

    unsigned char symbol = '\0';
    while ((symbol = getc(options->logout)) != EOF)
    {
        if (fprintf(options->print_log, "%c", symbol) <= 0)
            return FLAG_FAILURE;
    }
    return FLAG_SUCCESS;
}

FlagCode command_infinity(Options* const options)
{ 
    assert(options && "options is nullptr");

    
}
