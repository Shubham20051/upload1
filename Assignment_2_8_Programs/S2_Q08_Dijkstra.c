#include <stdio.h>
#define MAX 100
#define INF 1000000000000LL

int main(void)
{
    int n, source;
    long long graph[MAX][MAX], dist[MAX];
    int visited[MAX] = {0}, parent[MAX];
    printf("DIJKSTRA SHORTEST PATHS\nEnter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    printf("Enter weighted adjacency matrix. Use -1 for no edge and 0 on the diagonal.\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            long long w;
            if (scanf("%lld", &w) != 1 || w < -1) {
                printf("Invalid edge weight.\n");
                return 1;
            }
            graph[i][j] = (i == j) ? 0 : (w == -1 ? INF : w);
        }
    printf("Enter source vertex (1-%d): ", n);
    if (scanf("%d", &source) != 1 || source < 1 || source > n) {
        printf("Invalid source vertex.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        for (int j = 0; j < n; j++)
            if (graph[i][j] != INF && graph[i][j] < 0) {
                printf("Dijkstra's algorithm does not support negative edge weights.\n");
                return 1;
            }
    }
    dist[source - 1] = 0;
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1 || dist[u] == INF) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
    printf("Shortest distances and paths from vertex %d:\n", source);
    for (int v = 0; v < n; v++) {
        printf("Vertex %d: ", v + 1);
        if (dist[v] == INF) {
            printf("unreachable\n");
            continue;
        }
        printf("distance = %lld, path = ", dist[v]);
        int path[MAX], length = 0, current = v;
        while (current != -1 && length < MAX) {
            path[length++] = current;
            current = parent[current];
        }
        for (int i = length - 1; i >= 0; i--)
            printf("%d%s", path[i] + 1, i == 0 ? "\n" : " -> ");
    }
    return 0;
}
