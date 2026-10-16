#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void merge(int a[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
        temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; i++) a[i] = temp[i];
}

void mergeSort(int a[], int temp[], int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(a, temp, left, mid);
    mergeSort(a, temp, mid + 1, right);
    merge(a, temp, left, mid, right);
}

int main(void)
{
    int *a, *temp, n;
    printf("MERGE SORT\nEnter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 1;
    }
    a = malloc((size_t)n * sizeof *a);
    temp = malloc((size_t)n * sizeof *temp);
    if (!a || !temp) {
        printf("Memory allocation failed.\n");
        free(a); free(temp);
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid array element.\n");
            free(a); free(temp);
            return 1;
        }
    mergeSort(a, temp, 0, n - 1);
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    free(a); free(temp);
    return 0;
}
