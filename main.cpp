#include "math.h"
#include "stdio.h"

#define EPS 10e-7
#define NEPS -10e-7

int gcd(int a, int b);

int main() {
    int a, b, c;
    printf("Input first coef: ");
    scanf("%d", &a);
    printf("Input second coef: ");
    scanf("%d", &b);
    printf("Input third coef: ");
    scanf("%d", &c);

    printf("anwer: ");
    if (a == 0) {
        if (b == 0) {
            printf(c == 0 ? "x - any number\n" : "no solutions\n");
        } else {
            if (c % b == 0) {
                int answer = -c / b;
                printf("x = %d\n", answer);
            } else {
            int numerator = -c;
            int denominator = b;

            double answer = numerator / denominator;
            int sign = (numerator == 0 ? 0 : (int)answer / abs((int)answer));

            numerator = abs(numerator);
            denominator = abs(denominator);

            int gcd_num = gcd(numerator, denominator);
            numerator = sign * numerator / gcd_num;
            denominator /= gcd_num;

            printf("x = %f or %d/%d\n", answer, numerator, denominator);
            }
        }
    } else {
        int discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            printf("solutions is not real\n");
        } else if (discriminant == 0) {
            int numerator = -b;
            int denominator = 2 * a;

            double answer = numerator / denominator;
            int sign = (numerator == 0 ? 0 : (int)answer / abs((int)answer));

            numerator = abs(numerator);
            denominator = abs(denominator);

            int gcd_num = gcd(numerator, denominator);
            numerator = sign * numerator / gcd_num;
            denominator /= gcd_num;

            printf("x = %f or %d/%d\n", answer, numerator, denominator);
        } else {
            double discriminant_double = discriminant;
            double numerator1 = -b - sqrt(discriminant_double),
                   numerator2 = -b + sqrt(discriminant_double);
            int denominator = 2 * a;

            int numerator1_int = (int)numerator1, numerator2_int = (int)numerator2;
            bool is_numerator1_int = (abs((double)numerator1_int - numerator1) < EPS),
                 is_numerator2_int = (abs((double)numerator2_int - numerator2) < EPS);

            double answer1 = numerator1 / denominator, answer2 = numerator2 / denominator;

            if (is_numerator1_int) {
                int sign1 = (numerator1_int == 0 ? 0 : (int)answer1 / abs((int)answer1));

                numerator1_int = abs(numerator1_int);
                denominator = abs(denominator);

                int gcd_num1 = gcd(numerator1_int, denominator);
                numerator1 = sign1 * numerator1 / gcd_num1;
                int denominator1 = denominator / gcd_num1;
                printf("x = %f or %d/%d, ", answer1, numerator1_int, denominator1);
            } else {
                printf("x = %f, ", answer1);
            }

            if (is_numerator2_int) {
                int sign2 = (numerator2_int == 0 ? 0 : (int)answer2 / abs((int)answer2));

                numerator2_int = abs(numerator2_int);
                denominator = abs(denominator);

                int gcd_num2 = gcd(numerator2_int, denominator);
                numerator2 = sign2 * numerator2 / gcd_num2;
                int denominator2 = denominator / gcd_num2;
                printf("%f or %d/%d\n", answer2, numerator2_int, denominator2);
            } else {
                printf("%f\n", answer2);
            }
        }
    }
    return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }