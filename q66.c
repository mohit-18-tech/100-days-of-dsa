//Problem: Detect cycle in directed graph using DFS and recursion stack.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int** adj, int* adjSize, int* visited, int* path) {
    visited[node] = 1;
    path[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, path))
                return true;
        }
        else if (path[neighbor]) {
            return true; // cycle found
        }
    }

    path[node] = 0; // backtrack
    return false;
}

int main() {
    int V = 4;
    int E = 4;
    int edges[][2] = {{0,1}, {1,2}, {2,3}, {3,1}}; // cycle exists

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

        adj[u][adjSize[u]++] = v; // directed edge u → v
    }

    // Step 3: visited + path arrays
    int* visited = (int*)calloc(V, sizeof(int));
    int* path = (int*)calloc(V, sizeof(int));

    // Step 4: check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, path)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}