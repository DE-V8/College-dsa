#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Visited array for DFS and BFS
int queue[MAX];          // Queue for BFS
int front = -1, rear = -1;

// Function to add an edge between two buildings (undirected)
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1; // Remove this line for directed graph
}

// DFS function (recursive)
void DFS(int vertex, int numVertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    int i;
    for (i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices);
        }
    }
}

// BFS function
void BFS(int start, int numVertices) {
    front = rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        int i;

        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// Reset visited array
void resetVisited(int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
}

int main() {
    int numVertices, numEdges, startVertex;
    int src, dest;

    printf("Enter the number of buildings (vertices): ");
    scanf("%d", &numVertices);

    printf("Enter the number of paths (edges): ");
    scanf("%d", &numEdges);

    printf("Enter %d pairs of connected buildings (0 to %d):\n", numEdges, numVertices - 1);
    int i;
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter starting building for traversal: ");
    scanf("%d", &startVertex);

    // DFS
    printf("\nDFS Traversal: ");
    resetVisited(numVertices);
    DFS(startVertex, numVertices);

    // BFS
    printf("\nBFS Traversal: ");
    resetVisited(numVertices);
    BFS(startVertex, numVertices);

    return 0;
}
