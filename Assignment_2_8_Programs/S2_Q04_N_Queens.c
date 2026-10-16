#include <stdio.h>
#define MAX 15

int n, board[MAX], solutions;

int isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
        if (board[i] == col || board[i] - i == col - row ||
            board[i] + i == col + row)
            return 0;
    return 1;
}

int solve(int row)
{
    if (row == n) {
        solutions++;
        printf("\nSolution %d:\n", solutions);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%c ", board[i] == j ? 'Q' : '.');
            printf("\n");
        }
        return 1;
    }
    int found = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            found |= solve(row + 1);
        }
    }
    return found;
}

int main(void)
{
    printf("N-QUEENS USING BACKTRACKING\nEnter N (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid N. Enter a value from 1 to %d.\n", MAX);
        return 1;
    }
    if (!solve(0))
        printf("No solution exists for N = %d.\n", n);
    else
        printf("\nTotal solutions found: %d\n", solutions);
    return 0;
}
