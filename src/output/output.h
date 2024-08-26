#ifndef SRC_OUTPUT_H
#define SRC_OUTPUT_H


#include <assert.h>
#include <stdio.h>

#include "../utils/utils.h"
#include "../structs/structs.h"


/// @brief Линия для разделения вывода тест-кейсов
constexpr const char* const SEPARATING_LINE = "======================\n";


/// @brief Код окончания работы в функциях вывода
enum OutputCode
{
    OUTPUT_SUCCESS = 0, ///< Успешеное выполнение
    OUTPUT_FAILURE = 1  ///< Фатальная ошибка
};


/// @brief Исправление -0 при выводе чисел с плавающей точкой
/// @param[in] num Исправляемое значение
/// @return Исправленное значение
inline double fix_double_zero(double num) {
    if (is_zero(num)) 
        return 0;

    return num;
}


/// @brief Вывод ответа на уравнение в поток
/// @param[out] stream Поток вывода
/// @param[in] answer Ответ на уравнение
/// @return Код окончания работы
OutputCode print_answer(FILE* stream, const Answer answer);

/// @brief Вывод тест-кейса в поток
/// @param[out] stream Поток вывода
/// @param[in] test_case Тест-кейс
/// @return Код окончания работы
OutputCode print_test_case(FILE* stream, const TestCase test_case);


#endif /* SRC_OUTPUT_H */