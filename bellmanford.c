#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Structure to represent an edge
struct Edge {
    char source, destination;
    int weight;
};

// Function to find the vertex index from its character representation
int vertexIndex(char vertex, int numVertices, char *vertices) {
    for (int i = 0; i < numVertices; ++i) {
        if (vertices[i] == vertex) {
            return i;
        }
    }
    return -1; // Vertex not found
}

// Function to perform Bellman-Ford algorithm using a queue
void bellmanFord(int numVertices, char *vertices, struct Edge *edges, int numEdges, char source) {
    // Step 1: Initialize distances
    int *distances = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; ++i) {
        distances[i] = INT_MAX;
    }
    distances[vertexIndex(source, numVertices, vertices)] = 0;

    // Step 2: Relax edges using a queue
    bool *inQueue = (bool *)malloc(numVertices * sizeof(bool));
    for (int i = 0; i < numVertices; ++i) {
        inQueue[i] = false;
    }
    int *queue = (int *)malloc(numVertices * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = vertexIndex(source, numVertices, vertices);
    inQueue[vertexIndex(source, numVertices, vertices)] = true;

    while (front != rear) {
        int u = queue[front++];
        inQueue[u] = false;
        for (int i = 0; i < numEdges; ++i) {
            char v = edges[i].destination;
            int weight = edges[i].weight;
            if (edges[i].source == vertices[u] && distances[u] != INT_MAX && distances[u] + weight < distances[vertexIndex(v, numVertices, vertices)]) {
                distances[vertexIndex(v, numVertices, vertices)] = distances[u] + weight;
                if (!inQueue[vertexIndex(v, numVertices, vertices)]) {
                    queue[rear++] = vertexIndex(v, numVertices, vertices);
                    inQueue[vertexIndex(v, numVertices, vertices)] = true;
                }
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int i = 0; i < numEdges; ++i) {
        char u = edges[i].source;
        char v = edges[i].destination;
        int weight = edges[i].weight;
        if (distances[vertexIndex(u, numVertices, vertices)] != INT_MAX && distances[vertexIndex(u, numVertices, vertices)] + weight < distances[vertexIndex(v, numVertices, vertices)]) {
            printf("Graph contains negative weight cycle\n");
            free(distances);
            free(inQueue);
            free(queue);
            return;
        }
    }

    // Print shortest distances from source
    printf("Shortest paths from source %c:\n", source);
    for (int i = 0; i < numVertices; ++i) {
        if (distances[i] != INT_MAX) {
            printf("%c-> %c-> %d\n", source, vertices[i], distances[i]);
        } else {
            printf("%c-> %c-> INF\n", source, vertices[i]);
        }
    }

    free(distances);
    free(inQueue);
    free(queue);
}

// Driver program to test the function
int main() {
    int numVertices, numEdges;
    char source;
    char *vertices;
    struct Edge *edges;

    // Input number of vertices and edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    // Dynamically allocate memory for vertices
    vertices = (char *)malloc(numVertices * sizeof(char));

    // Input vertices
    printf("Enter the vertices (characters):\n");
    for (int i = 0; i < numVertices; ++i) {
        scanf(" %c", &vertices[i]);
    }

    // Dynamically allocate memory for edges
    edges = (struct Edge *)malloc(numEdges * sizeof(struct Edge));

    // Input edges
    printf("Enter source, destination, and weight for each edge:\n");
    for (int i = 0; i < numEdges; ++i) {
        scanf(" %c %c %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    // Input source vertex
    printf("Enter the source vertex: ");
    scanf(" %c", &source);

    // Call Bellman-Ford algorithm
    bellmanFord(numVertices, vertices, edges, numEdges, source);

    // Free dynamically allocated memory
    free(vertices);
    free(edges);

    return 0;
}
