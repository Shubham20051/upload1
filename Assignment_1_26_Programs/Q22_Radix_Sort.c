#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void countingByDigit(int a[], int n, long long exp)
{
    int *output = malloc((size_t)n * sizeof *output);
    int count[10] = {0};
    if (!output)
        return;
    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (int)((a[i] / exp) % 10);
        output[--count[digit]] = a[i];
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
    free(output);
}

int main(void)
{
    int *a, n, choice, max;
    printf("RADIX SORT\nEnter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 1;
    }
    a = malloc((size_t)n * sizeof *a);
    if (!a) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d non-negative integers:\n", n);
    max = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1 || a[i] < 0) {
            printf("Invalid input. Radix sort requires non-negative integers.\n");
            free(a);
            return 1;
        }
        if (a[i] > max) max = a[i];
    }
    printf("Order: 1. Ascending  2. Descending\nEnter choice: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        free(a);
        return 1;
    }
    for (long long exp = 1; max / exp > 0; exp *= 10) {
        countingByDigit(a, n, exp);
        if (exp > max / 10)
            break;
    }
    if (choice == 2)
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i]; a[i] = a[n - 1 - i]; a[n - 1 - i] = temp;
        }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    free(a);
    return 0;
}
