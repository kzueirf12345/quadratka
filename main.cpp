#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"

#define EPS 10e-7

enum CountSolutions
{
    ZERO_SOLUTIONS,
    ONE_SOLUTIONS,
    TWO_SOLUTIONS,
    INF_SOLUTIONS,
    NOT_REAL_SOLUTIONS
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

bool is_num(const char* const string);
void input(Coefs* coefs);

void linear_calculate(const Coefs* const coefs, Answer* const answer);
void quadratic_calculate(const Coefs* const coefs, Answer* const answer);
void calculate(const Coefs* const coefs, Answer* const answer);

double fix_double_zero(double num);
void print(const Answer* const answer);

int main()
{
    Coefs coefs = {0, 0, 0};
    input(&coefs);

    Answer answer = {0, 0, ZERO_SOLUTIONS};
    calculate(&coefs, &answer);

    print(&answer);

    return 0;
}

bool is_num(const char* const string)
{
    bool is_already_dot = false;
    size_t size = strlen(string);
    if (*string == '+' || *string == '-' || isdigit(*string))
    {
        for (size_t i = 1; i < size; ++i)
        {
            if (!isdigit(string[i]))
            {
                if (string[i] == '.')
                {
                    if (is_already_dot)
                    {
                        return false;
                    }
                    is_already_dot = true;
                } else
                {
                    return false;
                }
            }
        }
    } else
    {
        return false;
    }
    return true;
}

void input(Coefs* coefs)
{
    char buffer[100];

    printf("Input first coef: ");
    scanf("%s", buffer);
    assert(is_num(buffer) && "incorrect input\n");
    coefs->a = atof(buffer);

    printf("Input second coef: ");
    scanf("%s", buffer);
    assert(is_num(buffer) && "incorrect input\n");
    coefs->b = atof(buffer);

    printf("Input third coef: ");
    scanf("%s", buffer);
    assert(is_num(buffer) && "incorrect input\n");
    coefs->c = atof(buffer);
}

void linear_calculate(const Coefs* const coefs, Answer* const answer) 
{
    if (abs(coefs->b) < EPS) 
    {
        if (abs(coefs->c) < EPS) 
        {
            answer->count_solutions = INF_SOLUTIONS;
        } else 
        {
            answer->count_solutions = ZERO_SOLUTIONS;
        }
    } else 
    {
        answer->root1 = -coefs->c / coefs->b;
        answer->count_solutions = ONE_SOLUTIONS;
    }
}

void quadratic_calculate(const Coefs* const coefs, Answer* const answer)
{
    double discriminant = coefs->b * coefs->b - 4 * coefs->a * coefs->c;
    if (discriminant < 0) 
    {
        answer->count_solutions = NOT_REAL_SOLUTIONS;
    } else if (abs(discriminant) < EPS) 
    {
        answer->count_solutions = ONE_SOLUTIONS;
        answer->root1 = -coefs->b / (2 * coefs->a);
    } else 
    {
        answer->root1 = (-coefs->b - sqrt(discriminant)) / (2 * coefs->a);
        answer->root2 = (-coefs->b + sqrt(discriminant)) / (2 * coefs->a);
        answer->count_solutions = TWO_SOLUTIONS;
    }
}

void calculate(const Coefs* const coefs, Answer* const answer) 
{
    if (abs(coefs->a) < EPS) 
    {
        linear_calculate(coefs, answer);
    } else 
    {
        quadratic_calculate(coefs, answer);
    }
}

double fix_double_zero(double num) 
{
    if (abs(num) < EPS) 
    {
        return 0;
    }
    return num;
}

void print(const Answer* const answer) 
{
    printf("Answer: ");
    switch (answer->count_solutions) 
    {
        case ZERO_SOLUTIONS:
            printf("zero solutions\n");
            break;
        case ONE_SOLUTIONS: 
        {
            printf("x = %g\n", fix_double_zero(answer->root1));
            break;
        }
        case TWO_SOLUTIONS: 
        {
            printf("x = %g, %g\n", fix_double_zero(answer->root1), fix_double_zero(answer->root2));
            break;
        }
        case INF_SOLUTIONS: 
        {
            printf("x - any number\n");
            break;
        }
        case NOT_REAL_SOLUTIONS: 
        {
            printf("no real solutions\n");
            break;
        }
        default: 
        {
            assert("Unknown error\n");
            break;
        }
    }
}
