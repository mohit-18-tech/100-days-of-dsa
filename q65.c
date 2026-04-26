//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int parent, int** adj, int* adjSize, int* visited) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, adjSize, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

int main() {
    int V = 4;
    int E = 4;
    int edges[][2] = {{0,1}, {0,2}, {1,2}, {2,3}};

    // Step 1: count degree
    int* degree = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < E; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    // Step 2: build adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Step 3: visited array
    int* visited = (int*)calloc(V, sizeof(int));

    // Step 4: check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, adjSize, visited)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}