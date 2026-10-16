#include <stdio.h>
#define MAX 100000

long long sumIterative(const int a[], int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

long long sumRecursive(const int a[], int n)
{
    if (n == 0)
        return 0;
    return a[n - 1] + sumRecursive(a, n - 1);
}

int main(void)
{
    int a[MAX], n;
    printf("SUM OF N NUMBERS\nEnter n (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid n.\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    printf("Iterative sum: %lld\n", sumIterative(a, n));
    if (n > 10000)
        printf("Recursive sum skipped because a large recursion depth may exhaust the stack.\n");
    else
        printf("Recursive sum: %lld\n", sumRecursive(a, n));
    return 0;
}
