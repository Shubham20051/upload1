#include <stdio.h>

unsigned long long factorialIterative(int n)
{
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

unsigned long long factorialRecursive(int n)
{
    if (n <= 1)
        return 1;
    return (unsigned long long)n * factorialRecursive(n - 1);
}

int main(void)
{
    int n;
    printf("FACTORIAL OF A NUMBER\nEnter a non-negative integer (0-20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Invalid input. Enter an integer from 0 to 20.\n");
        return 1;
    }
    printf("Iterative factorial: %llu\n", factorialIterative(n));
    printf("Recursive factorial: %llu\n", factorialRecursive(n));
    return 0;
}
