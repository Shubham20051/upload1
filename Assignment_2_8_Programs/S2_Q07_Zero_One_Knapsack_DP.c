#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, capacity;
    printf("0/1 KNAPSACK USING DYNAMIC PROGRAMMING\nEnter number of items (1-1000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        printf("Invalid number of items.\n");
        return 1;
    }
    printf("Enter knapsack capacity (0-100000): ");
    if (scanf("%d", &capacity) != 1 || capacity < 0 || capacity > 100000) {
        printf("Invalid capacity.\n");
        return 1;
    }
    int *weight = malloc((size_t)n * sizeof *weight);
    int *value = malloc((size_t)n * sizeof *value);
    if (!weight || !value) {
        printf("Memory allocation failed.\n");
        free(weight); free(value);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        if (scanf("%d %d", &weight[i], &value[i]) != 2 ||
            weight[i] <= 0 || value[i] < 0) {
            printf("Invalid item. Weight must be positive and value non-negative.\n");
            free(weight); free(value);
            return 1;
        }
    }
    size_t cols = (size_t)capacity + 1;
    int *dp = calloc(((size_t)n + 1) * cols, sizeof *dp);
    if (!dp) {
        printf("Memory allocation failed. Try a smaller capacity.\n");
        free(weight); free(value);
        return 1;
    }
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= capacity; w++) {
            int *cell = &dp[(size_t)i * cols + w];
            *cell = dp[(size_t)(i - 1) * cols + w];
            if (weight[i - 1] <= w) {
                int candidate = value[i - 1] + dp[(size_t)(i - 1) * cols + w - weight[i - 1]];
                if (candidate > *cell) *cell = candidate;
            }
        }
    printf("Maximum obtainable value: %d\n", dp[(size_t)n * cols + capacity]);
    printf("Selected items (item numbers): ");
    int w = capacity, selected = 0;
    for (int i = n; i > 0; i--)
        if (dp[(size_t)i * cols + w] != dp[(size_t)(i - 1) * cols + w]) {
            printf("%d ", i);
            w -= weight[i - 1];
            selected = 1;
        }
    if (!selected) printf("None");
    printf("\n");
    free(dp); free(weight); free(value);
    return 0;
}
