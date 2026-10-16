#include <stdio.h>
#define MAX 10000

int main(void)
{
    int a[MAX], n, maximum;
    printf("MAXIMUM ELEMENT IN AN ARRAY\nEnter number of elements (1-%d): ", MAX);
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
    maximum = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maximum)
            maximum = a[i];
    printf("Maximum element: %d\n", maximum);
    return 0;
}
