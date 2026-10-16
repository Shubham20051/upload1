#include <stdio.h>

double fastPowerRecursive(double x, unsigned int n)
{
    double half;
    if (n == 0)
        return 1.0;
    half = fastPowerRecursive(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    return half * half * x;
}

double fastPowerIterative(double x, int n)
{
    unsigned int exponent = n < 0 ? (unsigned int)(-(long long)n) : (unsigned int)n;
    double result = 1.0;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result *= x;
        x *= x;
        exponent /= 2;
    }
    return n < 0 ? 1.0 / result : result;
}

int main(void)
{
    double x;
    int n;
    printf("FAST POWER IN O(log n) TIME\nEnter base x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid base.\n");
        return 1;
    }
    printf("Enter exponent (-1000000 to 1000000): ");
    if (scanf("%d", &n) != 1 || n < -1000000 || n > 1000000 || (x == 0.0 && n < 0)) {
        printf("Invalid exponent or undefined operation.\n");
        return 1;
    }
    printf("Iterative fast power: %.10g\n", fastPowerIterative(x, n));
    printf("Recursive fast power: %.10g\n",
           n < 0 ? 1.0 / fastPowerRecursive(x, (unsigned int)(-(long long)n))
                 : fastPowerRecursive(x, (unsigned int)n));
    return 0;
}
