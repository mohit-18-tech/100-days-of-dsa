//Problem Statement Using BFS or DFS, check if the entire graph is connected.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int visited[MAX];
int **graph;
int size[MAX];

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // allocate graph
    graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        graph[i] = NULL;
    }

    // initialize
    for (int i = 1; i <= n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    // input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u] = realloc(graph[u], (size[u] + 1) * sizeof(int));
        graph[u][size[u]++] = v;
        graph[v] = realloc(graph[v], (size[v] + 1) * sizeof(int));
        graph[v][size[v]++] = u;
    }

    // run DFS from node 1
    dfs(1);

    // check if all nodes visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}