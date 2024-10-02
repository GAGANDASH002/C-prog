#include <stdio.h>
#include <limits.h>

#define MAX 100  // Maximum number of vertices (you can adjust as needed)

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the path from the source to the destination
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

// Function to print the constructed distance array and paths
void printSolution(int dist[], int parent[], int src, int V) {
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < V; i++) {
        if (i == src) {
            printf("%d\t\t%d\t\t%d\t-\n", src + 1, i + 1, dist[i]);
        } else {
            printf("%d\t\t%d\t\t%d\t%d", src + 1, i + 1, dist[i], src + 1);
            printPath(parent, i);
            printf("\n");
        }
    }
}

// Dijkstra's Algorithm for a graph represented using an adjacency matrix
void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[V];  // dist[i] holds the shortest distance from src to i
    int visited[V];  // visited[i] will be true if vertex i is included in shortest path tree
    int parent[V];  // Array to store shortest path tree

    // Initialize all distances as INFINITE, visited[] as false and parent[] as -1
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Distance to the source vertex itself is 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);  // Pick the minimum distance vertex
        visited[u] = 1;  // Mark the picked vertex as processed

        // Update dist[] value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not visited, there's an edge from u to v,
            // and the total weight of path through u to v is smaller than the current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;  // Keep track of the path
            }
        }
    }

    // Print the shortest distances and paths
    printSolution(dist, parent, src, V);
}

// Function to read the adjacency matrix from a file
void readGraphFromFile(const char *filename, int graph[MAX][MAX], int V) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);
}

int main() {
    int V;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    if (V > MAX) {
        printf("Number of vertices exceeds the maximum limit.\n");
        return 1;
    }

    int graph[MAX][MAX];

    // Read the graph from the input file
    readGraphFromFile("inDijkstra.dat", graph, V);

    int source;
    printf("Enter the Source Vertex: ");
    scanf("%d", &source);

    if (source < 1 || source > V) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    // Call Dijkstra's algorithm from the source vertex (adjusted for 0-indexing)
    dijkstra(graph, source - 1, V);

    return 0;
}
