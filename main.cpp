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

struct Coefs {
    double a;
    double b;
    double c;
};

void input(Coefs* coefs);

CountSolutions linear_calculate(const Coefs* const coefs, double* const answer1);

CountSolutions quadratic_calculate(const Coefs* const coefs, double* const answer1,
                                   double* const answer2);

CountSolutions calculate(const Coefs* const coefs, double* const answer1, double* const answer2);

double fix_double_zero(double num);

void print(const double answer1, const double answer2, const CountSolutions count_solutions);

int main() {
    Coefs coefs = {0, 0, 0};
    input(&coefs);

    double answer1 = 0;
    double answer2 = 0;
    CountSolutions count_solutions = calculate(&coefs, &answer1, &answer2);

    print(answer1, answer2, count_solutions);

    return 0;
}

void input(Coefs* coefs) {
    printf("Input first coef: ");
    scanf("%lf", &coefs->a);
    printf("Input second coef: ");
    scanf("%lf", &coefs->b);
    printf("Input third coef: ");
    scanf("%lf", &coefs->c);
}

CountSolutions linear_calculate(const Coefs* const coefs, double* const answer1) {
    if (abs(coefs->b) < EPS) {
        if (abs(coefs->c) < EPS) {
            return INF_SOLUTIONS;
        }
        return ZERO_SOLUTIONS;
    } else {
        *answer1 = -coefs->c / coefs->b;
        return ONE_SOLUTIONS;
    }
}

CountSolutions quadratic_calculate(const Coefs* const coefs, double* const answer1,
                                   double* const answer2) {
    double discriminant = coefs->b * coefs->b - 4 * coefs->a * coefs->c;
    if (discriminant < 0) {
        return NOT_REAL_SOLUTIONS;
    } else if (abs(discriminant) < EPS) {
        return ONE_SOLUTIONS;
        *answer1 = -coefs->b / (2 * coefs->a);
    } else {
        *answer1 = (-coefs->b - sqrt(discriminant)) / (2 * coefs->a);
        *answer2 = (-coefs->b + sqrt(discriminant)) / (2 * coefs->a);
        return TWO_SOLUTIONS;
    }
}

CountSolutions calculate(const Coefs* const coefs, double* const answer1, double* const answer2) {
    if (abs(coefs->a) < EPS) {
        return linear_calculate(coefs, answer1);
    } else {
        return quadratic_calculate(coefs, answer1, answer2);
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
