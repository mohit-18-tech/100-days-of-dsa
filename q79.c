//Problem Statement : Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

// ---------- Graph ----------
struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

void addEdge(int u, int v, int w) {
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->v = v; n1->w = w; n1->next = adj[u];
    adj[u] = n1;

    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->v = u; n2->w = w; n2->next = adj[v];
    adj[v] = n2;
}

// ---------- Min Heap ----------
struct HeapNode {
    int v, dist;
};

struct Heap {
    int size;
    struct HeapNode arr[MAX];
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct Heap* h, int idx) {
    while (idx && h->arr[(idx - 1) / 2].dist > h->arr[idx].dist) {
        swap(&h->arr[(idx - 1) / 2], &h->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

void heapifyDown(struct Heap* h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < h->size && h->arr[left].dist < h->arr[smallest].dist)
        smallest = left;

    if (right < h->size && h->arr[right].dist < h->arr[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&h->arr[smallest], &h->arr[idx]);
        heapifyDown(h, smallest);
    }
}

void push(struct Heap* h, int v, int dist) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

struct HeapNode pop(struct Heap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// ---------- Dijkstra ----------
int dist[MAX];

void dijkstra(int n, int src) {
    struct Heap h;
    h.size = 0;

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        struct HeapNode curr = pop(&h);
        int u = curr.v;

        if (curr.dist > dist[u]) continue;

        struct Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }
}

// ---------- Main ----------
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

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}