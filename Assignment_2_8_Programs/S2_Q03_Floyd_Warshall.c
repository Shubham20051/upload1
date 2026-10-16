#include <stdio.h>
#define MAX 100
#define INF 1000000000000LL

int main(void)
{
    int n;
    long long d[MAX][MAX];
    printf("FLOYD-WARSHALL ALL-PAIRS SHORTEST PATHS\nEnter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    printf("Enter adjacency matrix row by row. Use -1 for no edge; use 0 on the diagonal.\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long w;
            if (scanf("%lld", &w) != 1 || w < -1) {
                printf("Invalid matrix value.\n");
                return 1;
            }
            if (i == j) d[i][j] = 0;
            else d[i][j] = w == -1 ? INF : w;
        }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] != INF && d[k][j] != INF &&
                    d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    for (int i = 0; i < n; i++)
        if (d[i][i] < 0) {
            printf("The graph contains a negative-weight cycle.\n");
            return 1;
        }
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF) printf("%8s", "INF");
            else printf("%8lld", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
