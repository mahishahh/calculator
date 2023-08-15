#include <stdio.h>
#include <conio.h>

const double PI = 3.1415926535897931;
const int MAX_TERMS = 20;

double power(double base, int exponent)
{
    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

double factorial(int n)
{
    double result = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

// sin(x) =  x^1/1! - x^3/3! + x^5/5! - x^7/7! + ...
double custom_sin(double x)
{
    double sum = 0.0;
    for (int i = 0; i <= MAX_TERMS; i++)
    {
        int powerOfX = 2 * i + 1;
        // printf("\n%d", powerOfX);

        double termPow = power(x, powerOfX);

        double term;
        if (i % 2 == 0)
        {
            term = termPow / factorial(powerOfX);
        }
        else
        {
            term = -termPow / factorial(powerOfX);
        }
        sum += term;
    }

    return sum;
}

int main()
{
    double degrees;

    printf("Enter the degrees: ");
    scanf("%lf", &degrees);

    double radians = degrees * (PI / 180.0); // Convert degrees to radians

    printf("Angle in radians: %f\n", radians);

    double standardSin = sin(radians);
    double customSin = custom_sin(radians);

    printf("sin(%f degrees) using math.h: %f\n", degrees, standardSin);
    printf("Custom sin(%f degrees): %f\n", degrees, customSin);

    return 0;
}
