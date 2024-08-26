#ifndef SRC_STRUCTS_H
#define SRC_STRUCTS_H


#include <math.h>


/// @brief Количество решений уравнения
enum CountSolutions
{
    ZERO_SOLUTIONS     = 0,           ///< Ноль решений
    ONE_SOLUTIONS      = 1,           ///< Одно решение (лежит в первом корне)
    TWO_SOLUTIONS      = 2,           ///< Два решения
    INF_SOLUTIONS      = 808,         ///< Бесконечное количество решений
    NOT_REAL_SOLUTIONS = 228'666'1337 ///< Не существует действительных решений, но есть мнимые
};


/// @brief Коэффициенты уравнения
struct Coefs
{
    /// @brief Первый коэффициент перед x^2
    double a;
    /// @brief Второй коэффициент перед x
    double b;
    /// @brief Третий коэффициент свободный
    double c;
};

/// @brief Ответ на уравнение
struct Answer
{
    /// @brief Первый корень
    double root1; 
    /// @brief Второй корень
    double root2;
    /// @brief Количество решений
    CountSolutions count_solutions;
};

/// @brief Тест-кейс, хранящий всю информацию об уравнении
struct TestCase
{
    /// @brief Номер тест-кейса. Номер отсутствует, если значение == -1
    int num;
    /// @brief Коэффициенты уравнения
    Coefs coefs;
    /// @brief Ответ на уравнение
    Answer answer;
};


#endif /* SRC_STRUCTS_H */