#include <stdio.h>
#define MAX 100000

void heapify(int a[], int n, int root)
{
    int largest = root, left = 2 * root + 1, right = 2 * root + 2;
    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;
    if (largest != root) {
        int temp = a[root]; a[root] = a[largest]; a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0]; a[0] = a[i]; a[i] = temp;
        heapify(a, i, 0);
    }
}

int main(void)
{
    int a[MAX], n;
    printf("HEAP SORT\nEnter number of elements (1-%d): ", MAX);
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
    heapSort(a, n);
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
