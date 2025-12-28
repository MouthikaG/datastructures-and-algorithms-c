#include <stdio.h>
#define MAX 100

int adjMatrix[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1;

void BFS(int start, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[++rear] = start;
    front++;

    printf("BFS Traversal: ");
    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    BFS(start, n);

    return 0;
}
