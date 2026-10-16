#include <stdio.h>

int main(void)
{
    int a, b, c, temp;
    printf("SORT THREE INTEGERS IN NON-DECREASING ORDER\nEnter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Invalid input. Enter exactly three integers.\n");
        return 1;
    }
    if (a > b) { temp = a; a = b; b = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    if (a > b) { temp = a; a = b; b = temp; }
    printf("Sorted order: %d %d %d\n", a, b, c);
    return 0;
}
