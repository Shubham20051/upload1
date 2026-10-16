#include <stdio.h>

double powerIterative(double x, int n)
{
    double result = 1.0;
    int exponent = n < 0 ? -n : n;
    for (int i = 0; i < exponent; i++)
        result *= x;
    return n < 0 ? 1.0 / result : result;
}

double powerRecursive(double x, int n)
{
    if (n == 0)
        return 1.0;
    if (n < 0)
        return 1.0 / powerRecursive(x, -n);
    return x * powerRecursive(x, n - 1);
}

int main(void)
{
    double x;
    int n;
    printf("POWER x^n\nEnter base x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid base.\n");
        return 1;
    }
    printf("Enter integer exponent n (-1000 to 1000): ");
    if (scanf("%d", &n) != 1 || n < -1000 || n > 1000 || (x == 0.0 && n < 0)) {
        printf("Invalid exponent or undefined operation.\n");
        return 1;
    }
    printf("Iterative result: %.10g\n", powerIterative(x, n));
    printf("Recursive result: %.10g\n", powerRecursive(x, n));
    return 0;
}
