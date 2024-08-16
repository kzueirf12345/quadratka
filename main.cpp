#include "math.h"
#include "stdio.h"

#define EPS 10e-7
#define NEPS -10e-7

int gcd(int a, int b);
void print_one_answer(double answer);
void print_two_answer(double answer1, double answer2);

int main() {
    int a, b, c;
    printf("Input first coef: ");
    scanf("%d", &a);
    printf("Input second coef: ");
    scanf("%d", &b);
    printf("Input third coef: ");
    scanf("%d", &c);

    printf("answer: ");
    if (a == 0) {
        if (b == 0) {
            printf(c == 0 ? "x - any number\n" : "no solutions\n");
        } else {
            print_one_answer(-c * 1. / b);
        }
    } else {
        int discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            printf("solutions is not real\n");
        } else if (discriminant == 0) {
            print_one_answer(-b * 1. / 2 * a);
        } else {
            double discriminant_double = discriminant;
            double numerator1 = -b - sqrt(discriminant_double),
                   numerator2 = -b + sqrt(discriminant_double);
            int denominator = 2 * a;
            print_two_answer(numerator1 / denominator, numerator2 / denominator);
        }
    }
    return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void print_one_answer(double answer) {
    if (abs(answer - (int)answer) < EPS) {
        printf("x = %d\n", (int)answer);
    } else {
        printf("x = %f\n", answer);
    }
}

void print_two_answer(double answer1, double answer2) {
    if (abs(answer1 - (int)answer1) < EPS) {
        printf("x = %d, ", (int)answer1);
    } else {
        printf("x = %f, ", answer1);
    }
    if (abs(answer2 - (int)answer2) < EPS) {
        printf("%d\n", (int)answer2);
    } else {
        printf("%f\n", answer2);
    }
}