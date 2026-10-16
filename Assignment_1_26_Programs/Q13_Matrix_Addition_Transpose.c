#include <stdio.h>
#define MAX 20

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX], rows, cols;
    printf("MATRIX ADDITION AND TRANSPOSE\nEnter rows and columns (1-%d): ", MAX);
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (scanf("%d", &b[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Sum matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%6d", sum[i][j]);
        printf("\n");
    }
    printf("Transpose of the sum matrix:\n");
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++)
            printf("%6d", sum[i][j]);
        printf("\n");
    }
    return 0;
}
