#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 99999

// Structure for an edge
struct Edge {
    int u, v, weight;
};

// Structure to represent a disjoint set (Union-Find)
struct DisjointSet {
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
};

// Function to initialize the disjoint set
void initDisjointSet(struct DisjointSet* ds, int n) {
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

// Function to find the parent of a node with path compression
int find(struct DisjointSet* ds, int x) {
    if (ds->parent[x] != x)
        ds->parent[x] = find(ds, ds->parent[x]);
    return ds->parent[x];
}

// Function to union two sets
void unionSets(struct DisjointSet* ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);

    if (rootX != rootY) {
        // Union by rank
        if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
    }
}

// Function to implement Kruskal's algorithm
void kruskal(int n, struct Edge edges[], int m) {
    struct DisjointSet ds;
    initDisjointSet(&ds, n);

    // Sort edges by weight (Bubble sort used here for simplicity)
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i].weight > edges[j].weight) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    printf("Kruskal's MST:\n");
    int mstWeight = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check if adding this edge forms a cycle
        if (find(&ds, u) != find(&ds, v)) {
            printf("%d - %d: %d\n", u, v, weight);
            mstWeight += weight;
            unionSets(&ds, u, v);
        }
    }
    printf("Total Weight of MST: %d\n", mstWeight);
}

// Function to implement Prim's algorithm
void prim(int n, int graph[n][n]) {
    int parent[n];
    int key[n];
    int inMST[n];
    int mstWeight = 0;

    // Initialize key values, parent, and MST set
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    // Apply Prim's algorithm
    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        // Find the vertex with the minimum key value
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        // Include the vertex u in MST
        inMST[u] = 1;

        // Update the key values of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    printf("Prim's MST:\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d: %d\n", parent[i], i, graph[i][parent[i]]);
        mstWeight += graph[i][parent[i]];
    }
    printf("Total Weight of MST: %d\n", mstWeight);
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    struct Edge edges[MAX_VERTICES];

    // Initialize the graph with 0 (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Read the edges for Kruskal's algorithm
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        graph[edges[i].u][edges[i].v] = edges[i].weight;
        graph[edges[i].v][edges[i].u] = edges[i].weight; // For undirected graph
    }

    // Run Kruskal's and Prim's algorithms
    kruskal(n, edges, m);
    prim(n, graph);

    return 0;
}
