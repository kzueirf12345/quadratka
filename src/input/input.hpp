#ifndef SRC_INPUT_H
#define SRC_INPUT_H


#include <stdio.h>
#include <assert.h>

#include "../structs/structs.hpp"


/// @brief Код окончания работы в фукнциях ввода
enum InputCode
{
    INPUT_SUCCESS   = 0, ///< Успешное выполнение
    INPUT_FAILURE   = 1, ///< Фатальная ошибка
    INPUT_INCORRECT = 2, ///< Некорректный ввод
    INPUT_EXIT      = 3  ///< Выход для command_infinity()
};

/// @brief Очищает буфер ввода
/// @return Код окончания работы
InputCode flush();

/// @brief Сканирует число с плавающей точкой из стандартного потока ввода
/// @param[out] num Переменная, в которую будет записано сканируемое число
/// @return Код окончания работы
InputCode scan_double(double* const num);

/// @brief Осуществляет ввод коэффициентов из стандартного потока ввода
/// @param[out] num Переменная, в которую будет записано сканируемое число
/// @param[in] message Сообщение, которое будет отправлено пользователю перед вводом
/// @return Код окончания работы
InputCode input_coef(double* const num, const char* const message);

/// @brief Осуществляет ввод коэффициентов уравнения из стандартного потока ввода
/// @param[out] coefs Коэффициенты уравнения, которые будут введены
/// @return Код окончания работы
InputCode input(Coefs* const coefs);


#endif /* SRC_INPUT_H */