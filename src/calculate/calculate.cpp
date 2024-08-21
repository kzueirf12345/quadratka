#include "calculate.h"

#include "../utils/utils.h"

Answer linear_calculate(const Coefs coefs)
{
    Answer answer = {0, 0, INF_SOLUTIONS};
    if (is_zero(coefs.b)) 
    {
        answer.count_solutions = is_zero(coefs.c) ? INF_SOLUTIONS : ZERO_SOLUTIONS;
    }
    else
    {
        answer.root1 = -coefs.c / coefs.b;
        answer.count_solutions = ONE_SOLUTIONS;
    }
    return answer;
}

Answer quadratic_calculate(const Coefs coefs)
{
    Answer answer = {0, 0, INF_SOLUTIONS};
    const double discriminant = coefs.b * coefs.b - 4 * coefs.a * coefs.c;
    if (discriminant < 0) 
    {
        answer.count_solutions = NOT_REAL_SOLUTIONS;
    }
    else if (is_zero(discriminant)) 
    {
        answer.count_solutions = ONE_SOLUTIONS;
        answer.root1 = -coefs.b / (2 * coefs.a);
    }
    else
    {
        answer.root1 = (-coefs.b - sqrt(discriminant)) / (2 * coefs.a);
        answer.root2 = (-coefs.b + sqrt(discriminant)) / (2 * coefs.a);
        answer.count_solutions = TWO_SOLUTIONS;
    }
    return answer;
}

Answer calculate(const Coefs coefs)
{
    return is_zero(coefs.a) ? linear_calculate(coefs) : quadratic_calculate(coefs);
}