#ifndef SRC_FLAG_UTILS_H
#define SRC_FLAG_UTILS_H


#include <stdio.h>

#include "../utils/utils.hpp"
#include "../utils/console.hpp"


/// @brief Код окончания работы в функциях, обрабатывающих флаги
enum FlagCode
{
    FLAG_SUCCESS   = 0, ///< Успешное выполнение
    FLAG_INCORRECT = 1, ///< Некорректный флаг
    FLAG_FAILURE   = 2, ///< Фатальная ошибка обработки
    FLAG_EXIT      = 3  ///< Выход для commmand_infinity()
};

/// @brief Потоки вывода для обработки флагов
struct FlagStreams
{
    const char* logout_name; ///< Имя потока вывода для логов
    FILE* logout; ///< Поток вывода для логов

    const char* out_name; ///< Имя основного потока вывода
    FILE* out; ///< Основной поток вывода
};


/// @brief устанавливает в структуре FlagStreams потоки вывода и логов соответствующие их названиям
/// @param[out] streams Потоки для вывода
/// @return Код окончания работы
FlagCode set_streams_files(FlagStreams* const streams);

/// @brief При необходимости закрывает потоки вывода FlagStreams
/// @param flag_streams Потоки вывода
/// @return Код работы программы (по аналогии с return'ом в main)
int destroy_FlagStreams(FlagStreams* flag_streams);


/// @brief Указатель на функцию выполняющую действие соответсвующее флагу
typedef FlagCode(*CommandFuncPtr)(FlagStreams* const streams);


/// @brief Возможные выполняемые флаги в порядке выполнения
enum FlagOptions
{
    HELP              = 0, ///< --help
    PRINT_LOG         = 1, ///< --print_log
    CLEAN             = 2, ///< --clean
    TEST              = 3, ///< --test
    USE               = 4, ///< --use
    INFIN             = 5, ///< --infinity
    FLAG_OPTIONS_SIZE = 6  ///< Размер массива исполняемых флагов
};

/// @brief Общие данные флагов
struct FlagData
{
    /// @brief Массив указатель на функции сответсвующие флагам
    CommandFuncPtr commands[(int)FLAG_OPTIONS_SIZE];
    /// @brief Потоки вывода
    FlagStreams streams;
};


/// @brief Описание флага
struct Flag
{
    /// @brief Название флага
    const char* name;
    /// @brief Маленькое описание флага (пример использования)
    const char* small_description;
    /// @brief Описание работы флага
    const char* description;
    /// @brief Указатель на функцию заполнения информации о флаге в FlagData
    FlagCode (*func)(FlagData* const flag_data, int* const index_argv, const Args args);
};


#endif /* SRC_FLAG_UTILS_H */