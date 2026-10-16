#include <stdio.h>

unsigned long long fibonacciIterative(int n)
{
    unsigned long long a = 0, b = 1, c;
    if (n == 0)
        return 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

unsigned long long fibonacciRecursive(int n)
{
    if (n <= 1)
        return (unsigned long long)n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main(void)
{
    int n;
    printf("NTH FIBONACCI NUMBER\nEnter n (0-40): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 40) {
        printf("Invalid input. Enter an integer from 0 to 40.\n");
        return 1;
    }
    printf("Iterative result: %llu\n", fibonacciIterative(n));
    printf("Recursive result: %llu\n", fibonacciRecursive(n));
    return 0;
}
