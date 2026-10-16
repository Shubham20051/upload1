#include <stdio.h>
#define MAX 100

int main(void)
{
    int graph[MAX][MAX] = {0}, indegree[MAX] = {0}, queue[MAX], order[MAX];
    int n, m, u, v, front = 0, rear = 0, count = 0;
    printf("TOPOLOGICAL SORT OF A DIRECTED GRAPH\nEnter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    printf("Enter number of directed edges (0-%d): ", n * n);
    if (scanf("%d", &m) != 1 || m < 0 || m > n * n) {
        printf("Invalid number of edges.\n");
        return 1;
    }
    printf("Enter each edge as source destination (vertices numbered 1 to %d):\n", n);
    for (int i = 0; i < m; i++) {
        if (scanf("%d %d", &u, &v) != 2 || u < 1 || u > n || v < 1 || v > n || u == v) {
            printf("Invalid edge.\n");
            return 1;
        }
        if (!graph[u - 1][v - 1]) {
            graph[u - 1][v - 1] = 1;
            indegree[v - 1]++;
        }
    }
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;
    while (front < rear) {
        int current = queue[front++];
        order[count++] = current;
        for (int j = 0; j < n; j++)
            if (graph[current][j] && --indegree[j] == 0)
                queue[rear++] = j;
    }
    if (count != n) {
        printf("Topological ordering does not exist because the graph contains a directed cycle.\n");
        return 1;
    }
    printf("Topological order: ");
    for (int i = 0; i < n; i++)
        printf("%d%s", order[i] + 1, i == n - 1 ? "\n" : " -> ");
    return 0;
}
