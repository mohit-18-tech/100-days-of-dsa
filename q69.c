//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005
#define INF INT_MAX

// Structure for adjacency list
typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

// Structure for priority queue node
typedef struct {
    int vertex;
    int distance;
} HeapNode;

// Min-Heap structure
typedef struct {
    int size;
    HeapNode* arr[MAX];
} MinHeap;

// Create a new edge
Edge* createEdge(int to, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

// Add edge to graph
void addEdge(Edge* adj[], int u, int v, int w) {
    Edge* newEdge = createEdge(v, w);
    newEdge->next = adj[u];
    adj[u] = newEdge;
}

// Swap heap nodes
void swap(HeapNode** a, HeapNode** b) {
    HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap* heap, int idx) {
    while (idx && heap->arr[(idx - 1) / 2]->distance > heap->arr[idx]->distance) {
        swap(&heap->arr[(idx - 1) / 2], &heap->arr[idx]);
        idx = (idx - 1) / 2;
    }
}

// Heapify down
void heapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size &&
        heap->arr[left]->distance < heap->arr[smallest]->distance)
        smallest = left;

    if (right < heap->size &&
        heap->arr[right]->distance < heap->arr[smallest]->distance)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->arr[smallest], &heap->arr[idx]);
        heapifyDown(heap, smallest);
    }
}

// Create a new heap node
HeapNode* newHeapNode(int v, int dist) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = v;
    node->distance = dist;
    return node;
}

// Insert into heap
void insertHeap(MinHeap* heap, int v, int dist) {
    heap->arr[heap->size] = newHeapNode(v, dist);
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract minimum node
HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    HeapNode* root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// Dijkstra's Algorithm
void dijkstra(Edge* adj[], int V, int src) {
    int dist[V + 1];
    int visited[V + 1];

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        HeapNode* minNode = extractMin(&heap);
        int u = minNode->vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        for (Edge* temp = adj[u]; temp != NULL; temp = temp->next) {
            int v = temp->to;
            int weight = temp->weight;

            if (!visited[v] && dist[u] != INF &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}