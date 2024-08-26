#ifndef SRC_FLAG_CONSTANTS_H
#define SRC_FLAG_CONSTANTS_H


#include <stdio.h>

#include "flag_funcs.hpp"


/// @brief Массив флагов с их описанием
constexpr Flag FLAGS[] = 
{
    (Flag){.name = "--help", .small_description = nullptr, .description = nullptr,
        .func = Flag_help},
    (Flag){.name = "--clean", .small_description = "--clean", .description = "Clean --log file", 
        .func = Flag_clean},
    (Flag){.name = "--infinity", .small_description = "--infinity ",
        .description = "Infinity mode of the program. "
        "After solving another one equation, the program starts over again. "
        "Output the result of the work to the argument of the variable --file "
        "or to the console if it is not specified. "
        "Input ENTER+CTRL+Z (ENTER+CTRL+D for Linux) for end input", 
        .func = Flag_infinity},
    (Flag){.name = "--log", .small_description = "--log ?[STREAM]",
        .description = "Changes the file for writing logs. "
        "If file is not found, a new one will be created. "
        "If [STREAM] not specified, than output will be do in ./user.log.",
        .func = Flag_log},
    (Flag){.name = "--file", .small_description = "--file ?[STREAM]", 
        .description = "Changes the output stream to the file specified by the next parameter. "
        "If file is not found, a new one will be created. "
        "If [STREAM] not specified, than output will be do in console. "
        "To use the console as the output stream, enter "
        KWORD_TO_STDOUT
        " in [STREAM]", 
        .func = Flag_file},
    (Flag){.name = "--print_log", .small_description = "--print_log",
        .description = "Output contents of logout to the argument of the variable --file "
        "or to the console if it is not specified", 
        .func = Flag_print_log},
    (Flag){.name = "--test", .small_description = "--test",
        .description = "FOR DEVELOPERS. Test mode of the program. "
        "Runs the solution of pre-recorded in programm tests. "
        "Outputs the result of the work to the argument of the variable --file"
        "or to the console, if it is not specified", 
        .func = Flag_test},
    (Flag){.name = "--use", .small_description = "--use",
        .description = "Standard mode of the program. "
        "Starts solving one equation. "
        "Output the result of the work to the argument of the variable --file "
        "or to the console if it is not specified", 
        .func = Flag_use}
};
/// @brief Размер массива флагов FLAGS
constexpr size_t FLAGS_SIZE = sizeof(FLAGS) / sizeof(*FLAGS);


#endif /* SRC_FLAG_CONSTANTS_H */