#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPS 1e-7

enum ReturnCode
{
    RETURN_FAILURE,
    RETURN_SUCCESS
};

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

bool is_zero(double num);
double fix_double_zero(double num);

void flush(void);

ReturnCode scan_double(double* const num);
void input_coef(double* const num, const char* const message);
void input(Coefs* const coefs);

Answer linear_calculate(const Coefs coefs);
Answer quadratic_calculate(const Coefs coefs);
Answer calculate(const Coefs coefs);

void print(const Answer answer);

int main()
{
    Coefs coefs = {0, 0, 0};
    input(&coefs);

    const Answer answer = calculate(coefs);
    print(answer);

    return 0;
}

bool is_zero(double num) { return abs(num) < EPS; }

double fix_double_zero(double num) {
    if (is_zero(abs(num))) 
    {
        return 0;
    }
    return num;
}


void flush(void)
{
    for (int symbol = getchar(); symbol != '\n' && symbol != EOF; symbol = getchar());
}

ReturnCode scan_double(double* const num) 
{
    int correct_scan_count = scanf("%lg", num);
    int next_symbol = getchar();

    return (ReturnCode)(correct_scan_count != 0 && next_symbol == (int)'\n');
}

void input_coef(double* const num, const char* const message)
{
    printf("%s", message);
    while (scan_double(num) == RETURN_FAILURE)
    {
        printf("Incorrect input, try again!\n");
        printf("%s", message);
        flush();
    }
}

void input(Coefs* const coefs) {
    input_coef(&coefs->a, "Input first coef: ");
    input_coef(&coefs->b, "Input second coef: ");
    input_coef(&coefs->c, "Input third coef: ");
}


Answer linear_calculate(const Coefs coefs)
{
    Answer answer = {0, 0, INF_SOLUTIONS};
    if (is_zero(abs(coefs.b))) 
    {
        if (is_zero(abs(coefs.c))) 
        {
            answer.count_solutions = INF_SOLUTIONS;
        }
        else
        {
            answer.count_solutions = ZERO_SOLUTIONS;
        }
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
    double discriminant = coefs.b * coefs.b - 4 * coefs.a * coefs.c;
    if (discriminant < 0) 
    {
        answer.count_solutions = NOT_REAL_SOLUTIONS;
    }
    else if (is_zero(abs(discriminant))) 
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
    if (is_zero(abs(coefs.a))) 
    {
        return linear_calculate(coefs);
    }
    else 
    {
        return quadratic_calculate(coefs);
    }
}

void print(const Answer answer)
{
    printf("Answer: ");
    switch (answer.count_solutions) 
    {
        case ZERO_SOLUTIONS:
        {
            printf("zero solutions\n");
            break;
        }
        case ONE_SOLUTIONS: 
        {
            printf("x = %g\n", fix_double_zero(answer.root1));
            break;
        }
        case TWO_SOLUTIONS: 
        {
            printf("x = %g, %g\n", fix_double_zero(answer.root1), fix_double_zero(answer.root2));
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
            assert(0 && "Unknown error\n");
            break;
        }
    }
}
