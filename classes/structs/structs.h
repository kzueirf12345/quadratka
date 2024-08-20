#pragma once

#include <math.h>

constexpr double EPS = 1e-7;

enum CountSolutions
{
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTIONS  = 1,
    TWO_SOLUTIONS  = 2,
    INF_SOLUTIONS  = 808,
    NOT_REAL_SOLUTIONS = 2286661337
};

struct Coefs
{
    double a;
    double b;
    double c;
};

struct Answer
{
    double root1;
    double root2;
    CountSolutions count_solutions;
};

bool is_zero(double num);
double fix_double_zero(double num);