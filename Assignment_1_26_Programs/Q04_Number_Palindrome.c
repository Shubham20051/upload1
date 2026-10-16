#include <stdio.h>

int main(void)
{
    long long n, original, reversed = 0, digit;
    printf("NUMBER PALINDROME CHECK\nEnter a non-negative integer: ");
    if (scanf("%lld", &n) != 1 || n < 0) {
        printf("Invalid input. Enter a non-negative integer.\n");
        return 1;
    }
    original = n;
    do {
        digit = n % 10;
        if (reversed > (9223372036854775807LL - digit) / 10) {
            printf("Number is too large to reverse safely.\n");
            return 1;
        }
        reversed = reversed * 10 + digit;
        n /= 10;
    } while (n > 0);
    if (original == reversed)
        printf("%lld is a palindrome number.\n", original);
    else
        printf("%lld is not a palindrome number.\n", original);
    return 0;
}
