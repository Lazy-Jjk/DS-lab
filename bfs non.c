#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100  // Maximum number of vertices in the graph

// Queue data structure for BFS
int i,j;
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;  // Reset the queue when it's empty
    }
    return item;
}

// Graph structure using adjacency list
struct Graph {
    int vertices;
    
    int adj[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize the graph
void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;  // Initialize all edges to 0 (no edges)
        }
    }
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;  // For undirected graph
}

// Function to perform BFS traversal
void bfs(struct Graph* g, int start) {
    struct Queue q;
    initQueue(&q);
    bool visited[MAX_VERTICES] = {false};
    
    visited[start] = true;
    enqueue(&q, start);

    printf("BFS traversal starting from vertex %d: ", start);
    
    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);

        // Visit all the neighbors of the dequeued vertex
        for (i = 0; i < g->vertices; i++) {
            if (g->adj[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    struct Graph g;
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter the edges (u v) for an undirected graph:\n");
    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    int start;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    
    bfs(&g, start);

    return 0;
}

