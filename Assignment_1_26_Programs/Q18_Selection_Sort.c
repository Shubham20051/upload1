#include <stdio.h>
#define MAX 10000

void sortArray(int a[], int n, int ascending)
{
    for (int i = 0; i < n - 1; i++) {
        int selected = i;
        for (int j = i + 1; j < n; j++)
            if (ascending ? a[j] < a[selected] : a[j] > a[selected])
                selected = j;
        if (selected != i) {
            int temp = a[i];
            a[i] = a[selected];
            a[selected] = temp;
        }
    }
}

int main(void)
{
    int a[MAX], n, choice;
    printf("SELECTION SORT\nEnter number of elements (1-%d): ", MAX);
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
    sortArray(a, n, choice == 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
