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
void input(int* a, int* b, int* c);
void calculate(int a, int b, int c, double* answer1, double* answer2, enum OutputState* state);
void print(double answer1, double answer2, enum OutputState state);

int main() {
    int a, b, c;
    input(&a, &b, &c);

    double answer1, answer2;
    enum OutputState state;

    calculate(a, b, c, &answer1, &answer2, &state);
    
    print(answer1, answer2, state);

    return 0;
}

void input(int* a, int* b, int* c) {
    printf("Input first coef: ");
    scanf("%d", a);
    printf("Input second coef: ");
    scanf("%d", b);
    printf("Input third coef: ");
    scanf("%d", c);
}

void calculate(int a, int b, int c, double* answer1, double* answer2, enum OutputState* state) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                *state = INF_SOLUTIONS;
            } else {
                *state = ZERO_SOLUTIONS;
            }
        } else {
            *state = ONE_SOLUTIONS;
            *answer1 = -c * 1. / b;
        }
    } else {
        int discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            *state = NOT_REAL_SOLUTIONS;
        } else if (discriminant == 0) {
            *state = ONE_SOLUTIONS;
            *answer1 = -b * 1. / 2 * a;
        } else {
            *state = TWO_SOLUTIONS;
            double numerator1 = -b - sqrt((double)discriminant),
                   numerator2 = -b + sqrt((double)discriminant);
            int denominator = 2 * a;

            *answer1 = numerator1 / denominator;
            *answer2 = numerator2 / denominator;
        }
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
