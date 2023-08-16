#include <stdio.h>

const double PI = 3.1415926535897931;
const int MAX_TERMS = 20;

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}


double custom_trigo(double x, int trigType) {
    double sum = 0.0;
    for (int i = 0; i <= MAX_TERMS; i++) {
        int powerOfX = 2 * i + trigType;
        double termPow = power(x, powerOfX);

        double term;
        if (i % 2 == 0) {
            term = termPow / factorial(powerOfX);
        } else {
            term = -termPow / factorial(powerOfX);
        }
        sum += term;
    }

    return sum;
}

double custom_sin(double x) {
    return custom_trigo(x,1);
}

double custom_cos(double x) {
   return custom_trigo(x,0);
}

double custom_exp(double x) {
    double sum = 0.0;
    for (int i = 0; i <= MAX_TERMS; i++) {
        double term = power(x, i) / factorial(i);
        sum += term;
    }

    return sum;
}

int main() {
    char op;
    double value;

    printf("Enter an operator (+, -, *, /, s for sin, c for cos, e for exp): ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/': {
            int first, second;
            printf("Enter two operands: ");
            scanf("%d %d", &first, &second);

            switch (op) {
                case '+':
                    printf("%d + %d = %d\n", first, second, first + second);
                    break;
                case '-':
                    printf("%d - %d = %d\n", first, second, first - second);
                    break;
                case '*':
                    printf("%d * %d = %d\n", first, second, first * second);
                    break;
                case '/':
                    if (second != 0) {
                        printf("%d / %d = %.2f\n", first, second, (double)first / second);
                    } else {
                        printf("Error: Division by zero!\n");
                    }
                    break;
            }
            break;
        }
        case 's':
        case 'S': {
            printf("Enter the degrees: ");
            scanf("%lf", &value);

            double radians = value * (PI / 180.0);
            double customSin = custom_sin(radians);

            printf("Angle in radians: %f\n", radians);
            printf("Custom sin(%f degrees): %f\n", value, customSin);
            break;
        }
        case 'c':
        case 'C': {
            printf("Enter the degrees: ");
            scanf("%lf", &value);

            double radians = value * (PI / 180.0);
            double customCos = custom_cos(radians);

            printf("Angle in radians: %f\n", radians);
            printf("Custom cos(%f degrees): %f\n", value, customCos);
            break;
        }
        case 'e':
        case 'E': {
            printf("Enter the value: ");
            scanf("%lf", &value);

            double customExp = custom_exp(value);
            printf("Custom exp(%f): %f\n", value, customExp);
            break;
        }
        default:
            printf("Error! Invalid operator.\n");
            break;
    }

    return 0;
}

