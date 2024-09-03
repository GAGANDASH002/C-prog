#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function prototypes
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex);
int minKey(int key[], bool inMST[], int numVertices);

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int startVertex;

    // Input number of vertices
    printf("Enter the Number of Vertices: ");
    scanf("%d", &numVertices);

    if (numVertices < 2 || numVertices > MAX_VERTICES) {
        printf("The number of vertices should be between 2 and %d.\n", MAX_VERTICES);
        return EXIT_FAILURE;
    }

    // Input adjacency matrix
    printf("Enter the Adjacency Matrix (%d x %d):\n", numVertices, numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input starting vertex
    printf("Enter the Starting Vertex (1 to %d): ", numVertices);
    scanf("%d", &startVertex);

    // Validate starting vertex
    if (startVertex < 1 || startVertex > numVertices) {
        printf("Invalid starting vertex. It should be between 1 and %d.\n", numVertices);
        return EXIT_FAILURE;
    }

    // Convert starting vertex to 0-based index
    startVertex -= 1;

    // Run Prim's algorithm to find the MST
    primMST(graph, numVertices, startVertex);

    return 0;
}

// Function to find the vertex with the minimum key value
int minKey(int key[], bool inMST[], int numVertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to implement Prim's algorithm
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int parent[MAX_VERTICES];  // Array to store constructed MST
    int key[MAX_VERTICES];     // Key values used to pick minimum weight edge in cut
    bool inMST[MAX_VERTICES];  // To keep track of vertices included in MST
    int totalCost = 0;

    // Initialize all keys as INFINITE and parent[] as -1
    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

    // Start from the given starting vertex
    key[startVertex] = 0;
    parent[startVertex] = -1;

    // Pick the minimum key vertex from the set of vertices not yet included in MST
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, inMST, numVertices);
        inMST[u] = true;

        // Update key values of adjacent vertices of the picked vertex
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the cost adjacency matrix of the MST
    printf("Cost Adjacency Matrix of MST:\n");
    int mstMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    for (int i = 1; i < numVertices; i++) {
        int u = parent[i];
        int v = i;
        mstMatrix[u][v] = graph[u][v];
        mstMatrix[v][u] = graph[u][v];
    }
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (mstMatrix[i][j] == 0 && i != j)
                printf("0\t");
            else
                printf("%d\t", mstMatrix[i][j]);
        }
        printf("\n");
    }

    // Calculate and print the total cost of the MST
    for (int i = 1; i < numVertices; i++) {
        totalCost += graph[i][parent[i]];
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalCost);
}
