#include <stdio.h>

int main(void)
{
    long long n, temp, digit, sum = 0;
    int digits = 0;
    printf("ARMSTRONG NUMBER CHECK\nEnter a non-negative integer: ");
    if (scanf("%lld", &n) != 1 || n < 0) {
        printf("Invalid input. Enter a non-negative integer.\n");
        return 1;
    }
    temp = n;
    do {
        digits++;
        temp /= 10;
    } while (temp > 0);
    temp = n;
    do {
        long long power = 1;
        digit = temp % 10;
        for (int i = 0; i < digits; i++)
            power *= digit;
        sum += power;
        temp /= 10;
    } while (temp > 0);
    if (sum == n)
        printf("%lld is an Armstrong number.\n", n);
    else
        printf("%lld is not an Armstrong number.\n", n);
    return 0;
}
