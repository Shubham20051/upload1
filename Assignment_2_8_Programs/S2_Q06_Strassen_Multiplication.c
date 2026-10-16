#include <stdio.h>
#include <stdlib.h>
#define MAX_N 64

void add(int n, int a[MAX_N][MAX_N], int b[MAX_N][MAX_N], int c[MAX_N][MAX_N], int sign)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + sign * b[i][j];
}

void strassen(int n, int A[MAX_N][MAX_N], int B[MAX_N][MAX_N], int C[MAX_N][MAX_N])
{
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int h = n / 2;
    int a11[MAX_N][MAX_N] = {{0}}, a12[MAX_N][MAX_N] = {{0}};
    int a21[MAX_N][MAX_N] = {{0}}, a22[MAX_N][MAX_N] = {{0}};
    int b11[MAX_N][MAX_N] = {{0}}, b12[MAX_N][MAX_N] = {{0}};
    int b21[MAX_N][MAX_N] = {{0}}, b22[MAX_N][MAX_N] = {{0}};
    int m1[MAX_N][MAX_N] = {{0}}, m2[MAX_N][MAX_N] = {{0}};
    int m3[MAX_N][MAX_N] = {{0}}, m4[MAX_N][MAX_N] = {{0}};
    int m5[MAX_N][MAX_N] = {{0}}, m6[MAX_N][MAX_N] = {{0}};
    int m7[MAX_N][MAX_N] = {{0}}, x[MAX_N][MAX_N] = {{0}};
    int y[MAX_N][MAX_N] = {{0}}, z[MAX_N][MAX_N] = {{0}};

    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++) {
            a11[i][j] = A[i][j]; a12[i][j] = A[i][j + h];
            a21[i][j] = A[i + h][j]; a22[i][j] = A[i + h][j + h];
            b11[i][j] = B[i][j]; b12[i][j] = B[i][j + h];
            b21[i][j] = B[i + h][j]; b22[i][j] = B[i + h][j + h];
        }

    add(h, a11, a22, x, 1); add(h, b11, b22, y, 1); strassen(h, x, y, m1);
    add(h, a21, a22, x, 1); strassen(h, x, b11, m2);
    add(h, b12, b22, y, -1); strassen(h, a11, y, m3);
    add(h, b21, b11, y, -1); strassen(h, a22, y, m4);
    add(h, a11, a12, x, 1); strassen(h, x, b22, m5);
    add(h, a21, a11, x, -1); add(h, b11, b12, y, 1); strassen(h, x, y, m6);
    add(h, a12, a22, x, -1); add(h, b21, b22, y, 1); strassen(h, x, y, m7);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++) {
            C[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
            C[i][j + h] = m3[i][j] + m5[i][j];
            C[i + h][j] = m2[i][j] + m4[i][j];
            C[i + h][j + h] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
        }
}

int main(void)
{
    int n, A[MAX_N][MAX_N] = {{0}}, B[MAX_N][MAX_N] = {{0}}, C[MAX_N][MAX_N] = {{0}};
    printf("STRASSEN MATRIX MULTIPLICATION\nEnter matrix order (power of 2, 1-64): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_N || (n & (n - 1)) != 0) {
        printf("Invalid order. Use a power of 2 between 1 and 64.\n");
        return 1;
    }
    printf("Enter elements of first %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &A[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
    printf("Enter elements of second %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &B[i][j]) != 1) {
                printf("Invalid matrix element.\n");
                return 1;
            }
    strassen(n, A, B, C);
    printf("Product matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%8d", C[i][j]);
        printf("\n");
    }
    return 0;
}
