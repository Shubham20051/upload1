#include <stdio.h>

int isPrimeRecursive(int n, int divisor)
{
    if (n < 2)
        return 0;
    if (divisor > n / divisor)
        return 1;
    if (n % divisor == 0)
        return 0;
    return isPrimeRecursive(n, divisor + 1);
}

int isPrimeIterative(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int nthPrimeIterative(int n)
{
    int count = 0;
    for (int value = 2; ; value++) {
        if (isPrimeIterative(value) && ++count == n)
            return value;
    }
}

int nthPrimeRecursiveSearch(int value, int count, int target)
{
    if (isPrimeRecursive(value, 2))
        count++;
    if (count == target)
        return value;
    return nthPrimeRecursiveSearch(value + 1, count, target);
}

int main(void)
{
    int n;
    printf("NTH PRIME NUMBER\nEnter n (1-1000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        printf("Invalid input. Enter an integer from 1 to 1000.\n");
        return 1;
    }
    printf("Nth prime using iterative method: %d\n", nthPrimeIterative(n));
    printf("Nth prime using recursive method: %d\n", nthPrimeRecursiveSearch(2, 0, n));
    return 0;
}
