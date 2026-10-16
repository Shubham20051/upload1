#include <stdio.h>

int main(void)
{
    int n;
    long long sum = 0;
    printf("PERFECT NUMBER CHECK\nEnter a positive integer: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input. Enter a positive integer.\n");
        return 1;
    }
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
            sum += i;
    if (sum == n)
        printf("%d is a perfect number.\n", n);
    else
        printf("%d is not a perfect number.\n", n);
    return 0;
}
