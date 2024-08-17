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

struct Answer {
    double root1;
    double root2;
    CountSolutions count_solutions;
};

void input(Coefs* coefs);

void linear_calculate(const Coefs* const coefs, Answer* const answer);

void quadratic_calculate(const Coefs* const coefs, Answer* const answer);

void calculate(const Coefs* const coefs, Answer* const answer);

double fix_double_zero(double num);

void print(const Answer* const answer);

int main() {
    Coefs coefs = {0, 0, 0};
    input(&coefs);

    Answer answer = {0, 0, ZERO_SOLUTIONS};
    calculate(&coefs, &answer);

    print(&answer);

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

void linear_calculate(const Coefs* const coefs, Answer* const answer) {
    if (abs(coefs->b) < EPS) {
        if (abs(coefs->c) < EPS) {
            answer->count_solutions = INF_SOLUTIONS;
        } else {
            answer->count_solutions = ZERO_SOLUTIONS;
        }
    } else {
        answer->root1 = -coefs->c / coefs->b;
        answer->count_solutions = ONE_SOLUTIONS;
    }
}

void quadratic_calculate(const Coefs* const coefs, Answer* const answer) {
    double discriminant = coefs->b * coefs->b - 4 * coefs->a * coefs->c;
    if (discriminant < 0) {
        answer->count_solutions = NOT_REAL_SOLUTIONS;
    } else if (abs(discriminant) < EPS) {
        answer->count_solutions = ONE_SOLUTIONS;
        answer->root1 = -coefs->b / (2 * coefs->a);
    } else {
        answer->root1 = (-coefs->b - sqrt(discriminant)) / (2 * coefs->a);
        answer->root2 = (-coefs->b + sqrt(discriminant)) / (2 * coefs->a);
        answer->count_solutions = TWO_SOLUTIONS;
    }
}

void calculate(const Coefs* const coefs, Answer* const answer) {
    if (abs(coefs->a) < EPS) {
        linear_calculate(coefs, answer);
    } else {
        quadratic_calculate(coefs, answer);
    }
}

double fix_double_zero(double num) {
    if (abs(num) < EPS) {
        return 0;
    }
    return num;
}

void print(const Answer* const answer) {
    printf("Answer: ");
    switch (answer->count_solutions) {
        case ZERO_SOLUTIONS:
            printf("zero solutions\n");
            break;
        case ONE_SOLUTIONS: {
            printf("x = %g\n", fix_double_zero(answer->root1));
            break;
        }
        case TWO_SOLUTIONS: {
            printf("x = %g, %g\n", fix_double_zero(answer->root1), fix_double_zero(answer->root2));
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
