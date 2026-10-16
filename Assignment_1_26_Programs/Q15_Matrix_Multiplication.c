#include <stdio.h>
#define MAX 20

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX];
    long long product[MAX][MAX] = {0};
    int r1, c1, r2, c2;
    printf("MATRIX MULTIPLICATION\nEnter rows and columns of first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
        printf("Invalid dimensions for first matrix.\n");
        return 1;
    }
    printf("Enter rows and columns of second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
        printf("Invalid dimensions for second matrix.\n");
        return 1;
    }
    if (c1 != r2) {
        printf("Matrix multiplication is not possible: columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }
    printf("Enter first matrix elements:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
    printf("Enter second matrix elements:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            if (scanf("%d", &b[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                product[i][j] += (long long)a[i][k] * b[k][j];
    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%10lld", product[i][j]);
        printf("\n");
    }
    return 0;
}
