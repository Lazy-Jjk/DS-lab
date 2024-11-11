#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void bfsRecursive(int n, int graph[n][n], int *currentLevel, bool visited[], int nodeCount) {
    if (nodeCount == 0) return; 
    
    
    int i;
    for (i = 0; i < n; i++) {
        if (currentLevel[i] == 1 && !visited[i]) {
            visited[i] = true;
            printf("%d ", i);
        }
    }

   
    int nextLevel[n];
    
    for (i = 0; i < n; i++) {
        nextLevel[i] = 0; 
    
    for (i = 0; i < n; i++) {
        if (visited[i]) {
        	int j;
            for (j = 0; j < n; j++) {
                if (graph[i][j] == 1 && !visited[j]) {
                    nextLevel[j] = 1; 
                }
            }
        }
    }

    
    bfsRecursive(n, graph, nextLevel, visited, nodeCount - 1);
}

int main() {
    int n, e;

    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    
    int graph[n][n];
    int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    
    printf("Enter the edges (format: u v where u and v are the vertices connected by an edge):\n");
    
    for (i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }
    
    
    int start;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    
    bool visited[n];
    
    for (i = 0; i < n; i++) {
        visited[i] = false;
    }

    
    int currentLevel[n];
    
    for (i = 0; i < n; i++) {
        currentLevel[i] = 0; 
    }

    visited[start] = true;
    currentLevel[start] = 1; 

    
    printf("BFS Traversal starting from node %d: ", start);
    printf("%d ", start); 
    bfsRecursive(n, graph, currentLevel, visited, n); 
    printf("\n");

    return 0;
}


