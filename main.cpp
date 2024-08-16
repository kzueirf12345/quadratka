#include "math.h"
#include "stdio.h"

#define EPS 10e-7
#define NEPS -10e-7

enum OutputState {
    ZERO_SOLUTIONS,
    ONE_SOLUTIONS,
    TWO_SOLUTIONS,
    INF_SOLUTIONS,
    NOT_REAL_SOLUTIONS
};
void input(double* a, double* b, double* c);
void calculate(double a, double b, double c, double* answer1, double* answer2,
               enum OutputState* state);
void print(double answer1, double answer2, enum OutputState state);

int main() {
    double a, b, c;
    input(&a, &b, &c);

    double answer1, answer2;
    enum OutputState state;

    calculate(a, b, c, &answer1, &answer2, &state);

    print(answer1, answer2, state);

    return 0;
}

void input(double* a, double* b, double* c) {
    printf("Input first coef: ");
    scanf("%lf", a);
    printf("Input second coef: ");
    scanf("%lf", b);
    printf("Input third coef: ");
    scanf("%lf", c);
}

void calculate(double a, double b, double c, double* answer1, double* answer2,
               enum OutputState* state) {
    if (abs(a) < EPS) {
        if (abs(b) < EPS) {
            if (abs(c) < EPS) {
                *state = INF_SOLUTIONS;
            } else {
                *state = ZERO_SOLUTIONS;
            }
        } else {
            *state = ONE_SOLUTIONS;
            *answer1 = -c / b;
        }
    } else {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            *state = NOT_REAL_SOLUTIONS;
        } else if (abs(discriminant) < EPS) {
            *state = ONE_SOLUTIONS;
            *answer1 = -b / (2 * a);
        } else {
            *state = TWO_SOLUTIONS;
            double numerator1 = -b - sqrt(discriminant), numerator2 = -b + sqrt(discriminant);
            double denominator = 2 * a;

            *answer1 = numerator1 / denominator;
            *answer2 = numerator2 / denominator;
        }
    }

    if (abs(*answer1) < EPS) {
        *answer1 = 0;
    }
    if (abs(*answer2) < EPS) {
        *answer2 = 0;
    }
}

void print(double answer1, double answer2, enum OutputState state) {
    printf("Answer: ");
    switch (state) {
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
