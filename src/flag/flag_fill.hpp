#ifndef SRC_FLAG_H
#define SRC_FLAG_H


#include <string.h>

#include "../output/output.h"
#include "../utils/utils.h"
#include "../command/command.h"
#include "flag_constants.h"


/// @brief Заполняет FlagData для последующей обработки обработки флагов. Вызывает соответствующие
/// флагам flag-функции
/// @param[out] flag_data Общие данные про флаги
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode fill_flag_data(FlagData* const flag_data, const Args args);

/// @brief Обрабатывает заполненный FlagData. Вызывает нужные command-функции
/// @param[out] flag_data Общие данные про флаги
/// @return Код окончания работы
FlagCode processing_flag_data(FlagData* const flag_data);


#endif /* SRC_FLAG_H */