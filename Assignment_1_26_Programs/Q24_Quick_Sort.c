#include <stdio.h>
#define MAX 100000

void quickSort(int a[], int low, int high)
{
    if (low >= high) return;
    int pivot = a[low + (high - low) / 2];
    int i = low, j = high;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++; j--;
        }
    }
    if (low < j) quickSort(a, low, j);
    if (i < high) quickSort(a, i, high);
}

int main(void)
{
    int a[MAX], n;
    printf("QUICK SORT\nEnter number of elements (1-%d): ", MAX);
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
    quickSort(a, 0, n - 1);
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
