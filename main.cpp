#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPS 1e-7

enum InputCode
{
    INPUT_FAILURE = 0,
    INPUT_INCORRECT = 1,
    INPUT_SUCCESS = 2
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

InputCode flush();
InputCode scan_double(double* const num);
InputCode input_coef(double* const num, const char* const message);
InputCode input(Coefs* const coefs);

Answer linear_calculate(const Coefs coefs);
Answer quadratic_calculate(const Coefs coefs);
Answer calculate(const Coefs coefs);

void print(const Answer answer);

int main()
{
    Coefs coefs = {0, 0, 0};
    if (input(&coefs) == INPUT_FAILURE)
    {
        fprintf(stderr, "INPUT_FAILURE\t ferror(stdin) = %d", ferror(stdin));
        return 0;
    }
    
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


InputCode flush()
{
    for (int symbol = getchar(); symbol != '\n' && symbol != EOF && ferror(stdin) == 0; symbol = getchar());
    return ferror(stdin) ? INPUT_FAILURE : INPUT_SUCCESS;
}

InputCode scan_double(double* const num) 
{
    assert(num && "num is nullptr");

    int correct_scan_count = scanf("%lg", num);
    int next_symbol = getchar();

    return ferror(stdin) == 0
        ? ((correct_scan_count != 0 && next_symbol == (int)'\n')
            ? INPUT_SUCCESS
            : INPUT_INCORRECT)
        : INPUT_FAILURE;
}

InputCode input_coef(double* const num, const char* const message)
{
    assert(num && "num is nullptr");
    assert(message && "num is nullptr");

    InputCode input_code = INPUT_FAILURE;
    printf("%s", message);
    while ((input_code = scan_double(num)) == INPUT_INCORRECT)
    {
        printf("Incorrect input, try again!\n");
        printf("%s", message);
        flush();
    }
    return input_code;
}

InputCode input(Coefs* const coefs) {
    assert(coefs && "coefs is nullptr");

    InputCode input_code = INPUT_FAILURE;

    input_code = input_coef(&coefs->a, "Input first coef: ");
    if (input_code == INPUT_FAILURE) return input_code;

    input_code = input_coef(&coefs->b, "Input second coef: ");
    if (input_code == INPUT_FAILURE) return input_code;

    input_code = input_coef(&coefs->c, "Input third coef: ");

    return input_code;
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
