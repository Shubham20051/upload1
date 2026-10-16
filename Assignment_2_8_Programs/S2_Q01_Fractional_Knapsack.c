#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double weight;
    double value;
    double ratio;
} Item;

int compareItems(const void *x, const void *y)
{
    const Item *a = x, *b = y;
    if (a->ratio < b->ratio) return 1;
    if (a->ratio > b->ratio) return -1;
    return 0;
}

int main(void)
{
    int n;
    double capacity, totalValue = 0.0, remaining;
    printf("FRACTIONAL KNAPSACK - GREEDY METHOD\nEnter number of items (1-10000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 10000) {
        printf("Invalid number of items.\n");
        return 1;
    }
    printf("Enter knapsack capacity: ");
    if (scanf("%lf", &capacity) != 1 || capacity < 0) {
        printf("Invalid capacity.\n");
        return 1;
    }
    Item *items = malloc((size_t)n * sizeof *items);
    if (!items) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        if (scanf("%lf %lf", &items[i].weight, &items[i].value) != 2 ||
            items[i].weight <= 0 || items[i].value < 0) {
            printf("Invalid weight or value. Weight must be positive and value non-negative.\n");
            free(items);
            return 1;
        }
        items[i].id = i + 1;
        items[i].ratio = items[i].value / items[i].weight;
    }
    qsort(items, (size_t)n, sizeof *items, compareItems);
    remaining = capacity;
    printf("\nSelected fractions:\n");
    for (int i = 0; i < n && remaining > 0; i++) {
        double fraction = items[i].weight <= remaining ? 1.0 : remaining / items[i].weight;
        if (fraction > 0) {
            printf("Item %d: %.2f%% taken\n", items[i].id, fraction * 100.0);
            totalValue += items[i].value * fraction;
            remaining -= items[i].weight * fraction;
        }
    }
    printf("Maximum obtainable value: %.2f\n", totalValue);
    free(items);
    return 0;
}
