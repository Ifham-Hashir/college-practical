#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Adjacency matrix representation of graph
int graph[MAX][MAX], visited[MAX];

// Depth First Search (DFS)
void DFS(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

// Breadth First Search (BFS)
void BFS(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, edges, u, v;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph as 0 (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;  // Undirected graph
    }

    // Initialize visited array as 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // DFS traversal
    printf("DFS Traversal: ");
    DFS(0, n);
    printf("\n");

    // Reset visited array for BFS
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // BFS traversal
    printf("BFS Traversal: ");
    BFS(0, n);
    printf("\n");

    return 0;
}

// Enter number of vertices: 5
// Enter number of edges: 4
// Enter edge (u v): 0 1
// Enter edge (u v): 0 2
// Enter edge (u v): 1 3
// Enter edge (u v): 1 4
// DFS Traversal: 0 1 3 4 2 
// BFS Traversal: 0 1 2 3 4 