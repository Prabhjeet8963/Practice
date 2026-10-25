#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Initialize adjacency lists
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS function
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX] = {0}; // Array to track visited vertices
    int queue[MAX], front = -1, rear = -1;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS starting from vertex %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[++front]; // Dequeue a vertex
        printf("%d ", currentVertex); // Print the vertex

        // Enqueue all unvisited adjacent vertices
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1; // Mark as visited
                queue[++rear] = adjVertex; // Enqueue
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS function
void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex); // Print the vertex

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited); // Recursive call
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // BFS Traversal
    BFS(graph, 0);

    // DFS Traversal
    int visited[MAX] = {0}; // Initialize visited array
    printf("DFS starting from vertex 0: ");
    DFS(graph, 0, visited);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph); // Free the graph structure

    return 0;
}
