#include "flag.h"

FlagCode Flag_help(Options* const options, size_t* const index_argv, 
        const char* const* const argv, const size_t argc)
{
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    options->help = true;

    return FLAG_SUCCESS;
}

FlagCode Flag_clean(Options* const options, size_t* const index_argv, const char* const* const argv,
                    const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    options->clean = true;

    return FLAG_SUCCESS;
}

FlagCode Flag_infinity(Options* const options, size_t* const index_argv,
                       const char* const* const argv, const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    options->infinity = true;

    return FLAG_SUCCESS;
}

FlagCode Flag_log(Options* const options, size_t* const index_argv, const char* const* const argv,
                  const size_t argc) {
    assert(options && "options is nullptr");
    assert(index_argv && "index_argv is nullptr");
    assert(argv && "options is nullptr");

    if (*index_argv == argc - 1)
        if (!(options->out = fopen(DEFAULT_USER_LOGOUT, "a+b")))
            return FLAG_FAILURE;
        return FLAG_SUCCESS;
    

    const char* const filename = argv[++*index_argv];
    if (!(options->out = fopen(filename, "a+b")))
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
        options->log_print = stdout;
        return FLAG_SUCCESS;
    
    const char* const filename = argv[++*index_argv];
    if (strcmp(filename, KWORD_TO_STDOUT) == 0)
        options->log_print = stdout;
    else if (!(options->log_print = fopen(filename, "a+b")))
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

void command_help(Options*const options)
{
    fprintf (
    options->out, 
    "===== QUADRATKA HELP =====\n"
    "Use: ./quadratka.out [FLAGS]\n"
    "This program solves second degree equations\n"
    "\n"
    "FLAGS:\n");

    for (size_t i = 1; i < FLAGS_SIZE; ++i)
    {
        fprintf(options->out, "%-30s %s\n", FLAGS[i].small_description, FLAGS[i].description);
    }

    fprintf(options->out, "\nWithout --infinity the program will run once and after the "
        "solution will terminate, leaving a record in the log\n");
    fprintf(options->out, "Error code:\nFAILURE = %d\nINCORRECT = %d\n\n", 
        (int)FLAG_FAILURE, (int)FLAG_INCORRECT);
}

// OutputCode command_print_help(FILE* const output_stream) { 
//     assert(output_stream && "output_stream is nullptr");

//     fprintf (
//         output_stream, 
//         "===== QUADRATKA HELP =====\n"
//         "Use: ./quadratka.out [FLAGS]\n"
//         "This program solves second degree equations\n"
//         "\n"
//         "FLAGS:\n"
//         "--clean                \t Clean log\n"
//         "--infinity             \t After solving next equation, the program starts over again\n"
//         "--log  [FILENAME]  a    \t Changes the file for writing logs."
//             "If file is not found, a new one will be created\n"
//         "--file [FILENAME]        \t Changes the output stream to the file specified by the next parameter."
//             "If file is not found, a new one will be created\n"
//         "--print_log ?[STREAM]      \t Output contents of logout to the file specified by the next parameter."
//             "If [STREAM] not specified, than output will be do in conCole\n"
//         "\n"
//         "Without --infinity the program will run once and after the solution will terminate, leaving a record in the log"
//     );
// }