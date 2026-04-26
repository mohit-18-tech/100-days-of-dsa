//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

// DFS function
void dfs(int node, int** adj, int* adjSize, int* visited, int* stack, int* top) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, adjSize, visited, stack, top);
        }
    }

    // push after visiting all neighbors
    stack[(*top)++] = node;
}

int main() {
    int V = 6;
    int E = 6;
    int edges[][2] = {
        {5, 2}, {5, 0}, {4, 0},
        {4, 1}, {2, 3}, {3, 1}
    };

    // Step 1: count outgoing edges
    int* outDegree = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < E; i++) {
        outDegree[edges[i][0]]++;
    }

    // Step 2: build adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(outDegree[i] * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
    }

    // Step 3: visited array
    int* visited = (int*)calloc(V, sizeof(int));

    // Step 4: stack
    int* stack = (int*)malloc(V * sizeof(int));
    int top = 0;

    // Step 5: run DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, adjSize, visited, stack, &top);
        }
    }

    // Step 6: print in reverse order
    printf("Topological Order:\n");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}