#include "calculate.h"

#include "../utils/utils.h"

Answer linear_calculate(const Coefs coefs)
{
    assert(std::isfinite(coefs.a) && "coefs.a is not finite");
    assert(std::isfinite(coefs.b) && "coefs.a is not finite");
    assert(std::isfinite(coefs.c) && "coefs.a is not finite");

    Answer answer = {NAN, NAN, TWO_SOLUTIONS};
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
    assert(std::isfinite(coefs.a) && "coefs.a is not finite");
    assert(std::isfinite(coefs.b) && "coefs.a is not finite");
    assert(std::isfinite(coefs.c) && "coefs.a is not finite");

    Answer answer = {NAN, NAN, INF_SOLUTIONS};
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
        const double sqrt_discriminant = sqrt(discriminant);
        answer.root1 = (-coefs.b - sqrt_discriminant) / (2 * coefs.a);
        answer.root2 = (-coefs.b + sqrt_discriminant) / (2 * coefs.a);
        answer.count_solutions = TWO_SOLUTIONS;
    }
    return answer;
}

Answer calculate(const Coefs coefs)
{
    assert(std::isfinite(coefs.a) && "coefs.a is not finite");
    assert(std::isfinite(coefs.b) && "coefs.a is not finite");
    assert(std::isfinite(coefs.c) && "coefs.a is not finite");

    return is_zero(coefs.a) ? linear_calculate(coefs) : quadratic_calculate(coefs);
}