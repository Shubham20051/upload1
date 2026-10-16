#include <stdio.h>
#define MAX 10000

int searchIterative(const int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int searchRecursive(const int a[], int n, int key, int index)
{
    if (index == n)
        return -1;
    if (a[index] == key)
        return index;
    return searchRecursive(a, n, key, index + 1);
}

int main(void)
{
    int a[MAX], n, key, pos1, pos2;
    printf("SEQUENTIAL SEARCH\nEnter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid array element.\n");
            return 1;
        }
    }
    printf("Enter the value to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid search value.\n");
        return 1;
    }
    pos1 = searchIterative(a, n, key);
    pos2 = searchRecursive(a, n, key, 0);
    if (pos1 >= 0)
        printf("Iterative search: found at position %d.\n", pos1 + 1);
    else
        printf("Iterative search: value not found.\n");
    if (pos2 >= 0)
        printf("Recursive search: found at position %d.\n", pos2 + 1);
    else
        printf("Recursive search: value not found.\n");
    return 0;
}
