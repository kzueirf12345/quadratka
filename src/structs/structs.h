#ifndef SRC_STRUCTS_H
#define SRC_STRUCTS_H


#include <math.h>


enum CountSolutions
{
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTIONS  = 1,
    TWO_SOLUTIONS  = 2,
    INF_SOLUTIONS  = 808,
    NOT_REAL_SOLUTIONS = 228'666'1337
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

struct TestCase
{
    int num;
    Coefs coefs;
    Answer answer;
};


#endif /* SRC_STRUCTS_H */