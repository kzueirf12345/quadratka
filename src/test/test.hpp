#ifndef SRC_TEST_H
#define SRC_TEST_H


#include <stdio.h>
#include <math.h>

#include "../structs/structs.h"
#include "../calculate/calculate.h"
#include "../output/output.h"


/// @brief Код окончания работы в функциях тестирования
enum TestCode
{
    TEST_SUCCESS   = 0, ///< Успешное выполнение
    TEST_FAILURE   = 1, ///< Фатальная ошибка
    TEST_INCORRECT = 2  ///< Некорректный ответ на тест
};


/// @brief Проверяет два ответа на то, что они одинаковые
/// @param[in] answer1 Первый ответ
/// @param[in] answer2 Второй ответ
/// @return true - корни равны, false - корни различные
bool is_equal_answer(const Answer answer1, const Answer answer2);


/// @brief Вывод тест_кейса в поток с обозначнием его (не-)правильности
/// @param[out] stream Поток вывода
/// @param[in] test_case Тест-кейс
/// @param[in] correct Корректный или некорректный ответ на тест
/// @param[in] answer Неправильный ответ на тест, если он некорректен
/// @return Код окончания работы
OutputCode print_test_case_correctness(FILE* stream, const TestCase test_case,bool correct = true,
    const Answer answer = {.root1 = NAN, .root2 = NAN, .count_solutions = TWO_SOLUTIONS});


/// @brief Тестриует программу на 1 тест-кейсе
/// @param[out] stream Поток вывода результата
/// @param[in] test_case Тест-кейс
/// @return Код окончания работы
TestCode testing(FILE* stream, const TestCase test_case);

/// @brief Выполняет проверку программы на всех тест-кейсах (определены внутри функции)
/// @param[out] test_log Поток вывода результата тестирования
/// @return Код окончания работы
TestCode global_testing(FILE* test_log);


#endif /* SRC_TEST_H */