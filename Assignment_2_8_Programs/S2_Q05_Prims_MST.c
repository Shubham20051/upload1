#include <stdio.h>
#define MAX 100
#define INF 1000000000

int main(void)
{
    int n, graph[MAX][MAX], selected[MAX] = {0};
    long long total = 0;
    printf("PRIM'S MINIMUM COST SPANNING TREE\nEnter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    printf("Enter weighted adjacency matrix; use 0 for no edge and on the diagonal.\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1 || graph[i][j] < 0) {
                printf("Invalid weight. This implementation requires non-negative weights.\n");
                return 1;
            }
            if (i == j) graph[i][j] = 0;
        }
    selected[0] = 1;
    printf("Edges in the minimum spanning tree:\n");
    for (int edge = 0; edge < n - 1; edge++) {
        int min = INF, u = -1, v = -1;
        for (int i = 0; i < n; i++)
            if (selected[i])
                for (int j = 0; j < n; j++)
                    if (!selected[j] && graph[i][j] > 0 && graph[i][j] < min) {
                        min = graph[i][j]; u = i; v = j;
                    }
        if (u == -1) {
            printf("The graph is disconnected; a spanning tree does not exist.\n");
            return 1;
        }
        printf("%d - %d : %d\n", u + 1, v + 1, min);
        total += min;
        selected[v] = 1;
    }
    printf("Minimum total cost: %lld\n", total);
    return 0;
}
