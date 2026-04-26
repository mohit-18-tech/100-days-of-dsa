//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

int main() {
    int V = 6;
    int E = 6;
    int edges[][2] = {
        {5, 2}, {5, 0}, {4, 0},
        {4, 1}, {2, 3}, {3, 1}
    };

    // Step 1: count outdegree for adjacency list
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

    // Step 3: indegree array
    int* indegree = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        indegree[v]++;
    }

    // Step 4: queue
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 5: process queue
    int* result = (int*)malloc(V * sizeof(int));
    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // Step 6: check for cycle
    if (count != V) {
        printf("Cycle exists! Topological sort not possible.\n");
        return 0;
    }

    // Step 7: print result
    printf("Topological Order:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}