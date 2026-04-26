// Problem Statement : Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = u;
    newNode->w = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int key[MAX];
    int visited[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // start from node 1
    int total = 0;

    for (int i = 1; i <= n; i++) {

        int u = -1;
        int min = INT_MAX;

        // pick minimum key vertex not visited
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        visited[u] = 1;
        total += key[u];

        // update neighbors
        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
            }

            temp = temp->next;
        }
    }

    printf("%d\n", total);
    return 0;
}