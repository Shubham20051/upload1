#include <stdio.h>
#define MAX 100000

int binarySearchIterative(const int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(const int a[], int low, int high, int key)
{
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key) return binarySearchRecursive(a, mid + 1, high, key);
    return binarySearchRecursive(a, low, mid - 1, key);
}

int main(void)
{
    int a[MAX], n, key;
    printf("BINARY SEARCH\nEnter number of sorted elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter %d integers in non-decreasing order:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid array element.\n");
            return 1;
        }
        if (i > 0 && a[i] < a[i - 1]) {
            printf("Invalid input. The array must be sorted in non-decreasing order.\n");
            return 1;
        }
    }
    printf("Enter value to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid search value.\n");
        return 1;
    }
    int p1 = binarySearchIterative(a, n, key);
    int p2 = binarySearchRecursive(a, 0, n - 1, key);
    if (p1 == -1) printf("Iterative search: value not found.\n");
    else printf("Iterative search: found at position %d.\n", p1 + 1);
    if (p2 == -1) printf("Recursive search: value not found.\n");
    else printf("Recursive search: found at position %d.\n", p2 + 1);
    return 0;
}
