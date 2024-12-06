#include <stdio.h>
#define INF 99999

void floydWarshall(int n, int graph[n][n]) {
    int dist[n][n];

    // Initialize dist array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (i == j) ? 0 : (graph[i][j] ? graph[i][j] : INF);

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Output shortest paths
    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%s%d", (dist[i][j] == INF) ? "INF\t" : "%d\t", dist[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];

    // Input adjacency matrix
    printf("Enter adjacency matrix (0 for no edge, non-zero for weight):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(n, graph);
    return 0;
}

// Enter number of vertices: 4
// Enter adjacency matrix (0 for no edge, non-zero for weight):
// 0 3 0 7
// 8 0 2 0
// 5 0 0 1
// 2 0 0 0
// Shortest distances:
//0   3   5    6
//5   0   2    3
//3   6   0    1
//2   5   7    0