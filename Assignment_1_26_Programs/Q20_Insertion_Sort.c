#include <stdio.h>
#define MAX 10000

int main(void)
{
    int a[MAX], n, choice;
    printf("INSERTION SORT\nEnter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid array element.\n");
            return 1;
        }
    printf("Order: 1. Ascending  2. Descending\nEnter choice: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        return 1;
    }
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && (choice == 1 ? a[j] > key : a[j] < key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
