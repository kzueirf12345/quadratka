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
void calculate(const double a, const double b, const double c, double* const answer1,
               double* const answer2, CountSolutions* const count_solutions);
void print(const double answer1, const double answer2, const CountSolutions count_solutions);

int main() {
    double a = 0, b = 0, c = 0;
    input(&a, &b, &c);

    double answer1 = 0, answer2 = 0;
    CountSolutions count_solutions = ZERO_SOLUTIONS;

    calculate(a, b, c, &answer1, &answer2, &count_solutions);

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

void calculate(const double a, const double b, const double c, double* const answer1,
               double* const answer2, CountSolutions* const count_solutions) {
    if (abs(a) < EPS) {
        if (abs(b) < EPS) {
            if (abs(c) < EPS) {
                *count_solutions = INF_SOLUTIONS;
            } else {
                *count_solutions = ZERO_SOLUTIONS;
            }
        } else {
            *count_solutions = ONE_SOLUTIONS;
            *answer1 = -c / b;
        }
    } else {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            *count_solutions = NOT_REAL_SOLUTIONS;
        } else if (abs(discriminant) < EPS) {
            *count_solutions = ONE_SOLUTIONS;
            *answer1 = -b / (2 * a);
        } else {
            *count_solutions = TWO_SOLUTIONS;
            *answer1 = (-b - sqrt(discriminant)) / (2 * a);
            *answer2 = (-b + sqrt(discriminant)) / (2 * a);
        }
    }

    if (abs(*answer1) < EPS) {
        *answer1 = 0;
    }
    if (abs(*answer2) < EPS) {
        *answer2 = 0;
    }
}

void print(const double answer1, const double answer2, const CountSolutions count_solutions) {
    printf("Answer: ");
    switch (count_solutions) {
        case ZERO_SOLUTIONS:
            printf("zero solutions\n");
            break;
        case ONE_SOLUTIONS: {
            printf("x = %g\n", answer1);
            break;
        }
        case TWO_SOLUTIONS: {
            printf("x = %g, %g\n", answer1, answer2);
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
