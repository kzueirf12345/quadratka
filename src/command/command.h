#ifndef SRC_RUN_H
#define SRC_RUN_H


#include <stdio.h>

#include "../flag/flag_utils.h"

/// @brief Выполнение флага --help
/// @param[out] streams Потоки для вывода
/// @return Код окончания работы
FlagCode command_help(FlagStreams*const streams);

/// @brief Выполнение флага --clean
/// @param[out] streams Потоки для вывода
/// @return Код окончания работы
FlagCode command_clean(FlagStreams*const streams);

/// @brief Выполнение флага --print_log
/// @param[out] streams Потоки для вывода
/// @return Код окончания работы
FlagCode command_print_log(FlagStreams*const streams);


/// @brief Выполнение флага --infinity
/// @param[out] streams Потоки для вывода
/// @return Код окончания работы
FlagCode command_infinity(FlagStreams*const streams);

/// @brief Выполнение флага --test
/// @param[out] streams Потоки для вывода
/// @return Код окончания работы
FlagCode command_test(FlagStreams*const streams);

/// @brief Выполнение флага --use
/// @param[out] streams Потоки для вывода
/// @return Код окончания работы
FlagCode command_use(FlagStreams*const streams);


#endif /* SRC_RUN_H */