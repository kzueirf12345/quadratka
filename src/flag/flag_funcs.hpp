#ifndef SRC_FLAG_FUNCS_H
#define SRC_FLAG_FUNCS_H


#include <assert.h>
#include <string.h>

#include "flag_utils.hpp"
#include "../command/command.hpp"


/// @brief Отмечает в FlagData изменение файла вывода логов.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_log(FlagData* const flag_data, int* const index_argv, const Args args);

/// @brief Отмечает в FlagData изменение файла основного вывода.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_file(FlagData* const flag_data, int* const index_argv, const Args args);


/// @brief Отмечает в FlagData надобность выполнения флага --help.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_help(FlagData* const flag_data, int* const index_argv, const Args args);

/// @brief Отмечает в FlagData надобность выполнения флага --clean.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_clean(FlagData* const flag_data, int* const index_argv, const Args args);

/// @brief Отмечает в FlagData надобность выполнения флага --print_log.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_print_log(FlagData* const flag_data, int* const index_argv, const Args args);



/// @brief Отмечает в FlagData надобность выполнения флага --infinity.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_infinity(FlagData* const flag_data, int* const index_argv, const Args args);

/// @brief Отмечает в FlagData надобность выполнения флага --test.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_test(FlagData* const flag_data, int* const index_argv, const Args args);

/// @brief Отмечает в FlagData надобность выполнения флага --use.
/// @param[out] flag_data Общие данные про флаги
/// @param[out] index_argv Индекс рассматриваемого флага в argv
/// @param[in] args Массив поступивших флагов с его размером
/// @return Код окончания работы
FlagCode Flag_use(FlagData* const flag_data, int* const index_argv, const Args args);


#endif /* SRC_FLAG_FUNCS_H */