#ifndef SRC_CALCULATE_H
#define SRC_CALCULATE_H


#include <math.h>
#include <assert.h>

#include "../structs/structs.hpp"

/// @brief Решает случай линейного уравнения, с нулевым первым коэффициентом
/// @param[in] coefs Коэффициенты решаемого уравнения
/// @return Ответ на уравнение
Answer linear_calculate(const Coefs coefs);

/// @brief Решает случай квадратного уравнения, с НЕнулевым первым коэффициентом
/// @param[in] coefs Коэффициенты решаемого уравнения
/// @return Ответ на уравнение
Answer quadratic_calculate(const Coefs coefs);


/// @brief Решает квадратное уравнение
/// @param[in] coefs Коэффициенты решаемого уравнения
/// @return Ответ на уравнение
Answer calculate(const Coefs coefs);


#endif /* SRC_CALCULATE_H */