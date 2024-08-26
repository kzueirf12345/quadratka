#ifndef SRC_UTILS_H
#define SRC_UTILS_H


#include <math.h>

/// @brief Ключевое слово, обозначающие вывод в стандартный поток вывода
#define KWORD_TO_STDOUT "__CONCOLE__"
/// @brief Стандартный файл для логов, если не уточнён другой
constexpr const char *const DEFAULT_USER_LOGOUT = "./user.log";


/// @brief Массив строк переданных флагов и его размер
struct Args
{
    /// @brief Массив строк преденнах флагов
    const char* const * const argv;
    /// @brief Размер переданных массива флагов
    const int argc;
};


/// @brief Вычисляет максимум из двух чисел с плавающей точкой
/// @param[in] a Первое число сравнения
/// @param[in] b Второе число сравнения
/// @return Максимум из двух чисел
inline double max(const double a, const double b) { return a > b ? a : b; }
/// @brief Вычисляет минимум из двух чисел с плавающей точкой
/// @param[in] a Первое число сравнения
/// @param[in] b Второе число сравнения
/// @return Минимум из двух чисел
inline double min(const double a, const double b) { return a < b ? a : b; }


/// @brief Проверяет, что число с плавающей точкой равно 0 с определённой погрешностью
/// @param[in] num Число для проверки
/// @return true - число равно нулю c погрешностью, false - число не равно нулю с погрешностью
inline bool is_zero(double num)
{
    static constexpr double EPS = 1e-7;
    
    return abs(num) < EPS;
}


#endif /* SRC_UTILS_H */