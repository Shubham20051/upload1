#include <stdio.h>
#define MAX 10000

int main(void)
{
    int a[MAX], n, minimum;
    printf("MINIMUM ELEMENT IN AN ARRAY\nEnter number of elements (1-%d): ", MAX);
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
    minimum = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < minimum)
            minimum = a[i];
    printf("Minimum element: %d\n", minimum);
    return 0;
}
