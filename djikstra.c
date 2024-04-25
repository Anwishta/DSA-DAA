#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printGraph(int V, int graph[V][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to print the solution (shortest distances and paths)
void printPath(int dist[], int parent[], int n, int src, int V) {
    printf("Output:\n");
    printf("Source -> Destination \t Distance \t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d -> %d \t\t\t %d \t\t ", src, i, dist[i]);
        int j = i;
        printf("%d", j);
        while (parent[j] != src) {
            printf(" <- %d", parent[j]);
            j = parent[j];
        }
        printf(" <- %d\n", src);
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(int V, int graph[V][V], int src) {
    int dist[V];    // The output array. dist[i] will hold the shortest distance from src to i
    
    // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    int sptSet[V];
    
    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Array to store the parent vertices in the shortest path tree
    int parent[V];
    parent[src] = src; // Source vertex has no parent
    
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, V);
        
        // Mark the picked vertex as processed
        sptSet[u] = 1;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Update parent of v
            }
        }
    }
    
    // Print the constructed distance array and shortest paths
    printPath(dist, parent, V, src, V);
}

// Driver program to test above functions
int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    // The graph adjacency matrix representing distances between intersections
    int graph[V][V];
    
    // Taking input for the graph
    printf("Enter the adjacency matrix for the graph:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("\nGraph[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Source node (warehouse)
    int source;
    printf("Enter the source node (warehouse): ");
    scanf("%d", &source);
    
    // Print the input graph
    printGraph(V, graph);
    
    // Call Dijkstra's algorithm
    dijkstra(V, graph, source);
    
    return 0;
}

