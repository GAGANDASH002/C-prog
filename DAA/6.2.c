#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a subset for Union-Find
typedef struct {
    int parent, rank;
} Subset;

// Function prototypes
int compareEdges(const void *a, const void *b);
int find(Subset subsets[], int i);
void unionSets(Subset subsets[], int x, int y);
void kruskalMST(Edge edges[], int numEdges, int numVertices);

int main() {
    int numVertices, numEdges;
    
    // Input number of vertices
    printf("Enter the Number of Vertices: ");
    scanf("%d", &numVertices);

    // Input number of edges
    printf("Enter the Number of Edges: ");
    scanf("%d", &numEdges);

    if (numVertices < 2 || numEdges < numVertices - 1) {
        printf("Invalid number of vertices or edges.\n");
        return EXIT_FAILURE;
    }

    Edge edges[numEdges];

    // Input edges
    printf("Enter the edges (src, dest, weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        edges[i].src--; // Convert to 0-based index
        edges[i].dest--; // Convert to 0-based index
    }

    // Run Kruskal's algorithm to find the MST
    kruskalMST(edges, numEdges, numVertices);

    return 0;
}

// Function to compare two edges based on their weight
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Function to find the representative of a set
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to implement Kruskal's algorithm and find the MST
void kruskalMST(Edge edges[], int numEdges, int numVertices) {
    Edge result[numVertices - 1]; // Array to store the resulting MST
    int e = 0; // Index for result[]
    int i = 0; // Initial index of sorted edges
    int totalCost = 0;

    // Step 1: Sort all edges in non-decreasing order of their weight
    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    Subset *subsets = (Subset *)malloc(numVertices * sizeof(Subset));
    for (int v = 0; v < numVertices; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far
    while (e < numVertices - 1 && i < numEdges) {
        // Get the next edge
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not form a cycle
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
            totalCost += next_edge.weight;
        }
    }

    // Print the selected edges and total cost of MST
    printf("Selected edges in the Minimum Spanning Tree:\n");
    for (int j = 0; j < e; ++j) {
        printf("%d -- %d == %d\n", result[j].src + 1, result[j].dest + 1, result[j].weight);
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalCost);

    // Free allocated memory
    free(subsets);
}
