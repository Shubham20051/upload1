#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
#define RANGE_LIMIT 1000000

int main(void)
{
    int *a, *output, n, choice, min, max;
    printf("COUNTING SORT\nEnter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 1;
    }
    a = malloc((size_t)n * sizeof *a);
    output = malloc((size_t)n * sizeof *output);
    if (!a || !output) {
        printf("Memory allocation failed.\n");
        free(a); free(output);
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid array element.\n");
            free(a); free(output);
            return 1;
        }
    printf("Order: 1. Ascending  2. Descending\nEnter choice: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        free(a); free(output);
        return 1;
    }
    min = max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    long long range = (long long)max - min + 1;
    if (range > RANGE_LIMIT) {
        printf("Value range is too large for counting sort (maximum range %d).\n", RANGE_LIMIT);
        free(a); free(output);
        return 1;
    }
    int *count = calloc((size_t)range, sizeof *count);
    if (!count) {
        printf("Memory allocation failed.\n");
        free(a); free(output);
        return 1;
    }
    for (int i = 0; i < n; i++)
        count[a[i] - min]++;
    int index = 0;
    if (choice == 1) {
        for (long long i = 0; i < range; i++)
            while (count[i]-- > 0)
                output[index++] = (int)(i + min);
    } else {
        for (long long i = range - 1; i >= 0; i--)
            while (count[i]-- > 0)
                output[index++] = (int)(i + min);
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d%s", output[i], i == n - 1 ? "\n" : " ");
    free(a); free(output); free(count);
    return 0;
}
