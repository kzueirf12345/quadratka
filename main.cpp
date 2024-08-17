#include "math.h"
#include "stdio.h"

#define EPS 10e-7

enum CountSolutions {
    ZERO_SOLUTIONS,
    ONE_SOLUTIONS,
    TWO_SOLUTIONS,
    INF_SOLUTIONS,
    NOT_REAL_SOLUTIONS
};

void input(double* const a, double* const b, double* const c);

CountSolutions linear_calculate(const double b, const double c, double* const answer1);

CountSolutions quadratic_calculate(const double a, const double b, const double c,
                                   double* const answer1, double* const answer2);

CountSolutions calculate(const double a, const double b, const double c, double* const answer1,
                         double* const answer2);

double fix_double_zero(double num);

void print(const double answer1, const double answer2, const CountSolutions count_solutions);

int main() {
    double a = 0, b = 0, c = 0;
    input(&a, &b, &c);

    double answer1 = 0;
    double answer2 = 0;
    CountSolutions count_solutions = calculate(a, b, c, &answer1, &answer2);

    print(answer1, answer2, count_solutions);

    return 0;
}

void input(double* const a, double* const b, double* const c) {
    printf("Input first coef: ");
    scanf("%lf", a);
    printf("Input second coef: ");
    scanf("%lf", b);
    printf("Input third coef: ");
    scanf("%lf", c);
}

CountSolutions linear_calculate(const double b, const double c, double* const answer1) {
    if (abs(b) < EPS) {
        if (abs(c) < EPS) {
            return INF_SOLUTIONS;
        }
        return ZERO_SOLUTIONS;
    } else {
        *answer1 = -c / b;
        return ONE_SOLUTIONS;
    }
}

CountSolutions quadratic_calculate(const double a, const double b, const double c,
                                   double* const answer1, double* const answer2) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return NOT_REAL_SOLUTIONS;
    } else if (abs(discriminant) < EPS) {
        return ONE_SOLUTIONS;
        *answer1 = -b / (2 * a);
    } else {
        *answer1 = (-b - sqrt(discriminant)) / (2 * a);
        *answer2 = (-b + sqrt(discriminant)) / (2 * a);
        return TWO_SOLUTIONS;
    }
}

CountSolutions calculate(const double a, const double b, const double c, double* const answer1,
                         double* const answer2) {
    if (abs(a) < EPS) {
        return linear_calculate(b, c, answer1);
    } else {
        return quadratic_calculate(a, b, c, answer1, answer2);
    }
}

double fix_double_zero(double num) {
    if (abs(num) < EPS) {
        return 0;
    }
    return num;
}

void print(const double answer1, const double answer2, const CountSolutions count_solutions) {
    printf("Answer: ");
    switch (count_solutions) {
        case ZERO_SOLUTIONS:
            printf("zero solutions\n");
            break;
        case ONE_SOLUTIONS: {
            printf("x = %g\n", fix_double_zero(answer1));
            break;
        }
        case TWO_SOLUTIONS: {
            printf("x = %g, %g\n", fix_double_zero(answer1), fix_double_zero(answer2));
            break;
        }
        case INF_SOLUTIONS: {
            printf("x - any number\n");
            break;
        }
        case NOT_REAL_SOLUTIONS: {
            printf("no real solutions\n");
            break;
        }
        default: {
            fprintf(stderr, "Unknown error\n");
            break;
        }
    }
}
