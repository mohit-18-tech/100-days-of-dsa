//Problem Statement: Implement a Min Heap using an array where the smallest element is always at the root.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(MinHeap* h, int i) {
    while (i > 0 && h->arr[(i - 1) / 2] > h->arr[i]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;

    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// Insert
void insert(MinHeap* h, int x) {
    h->arr[h->size] = x;
    heapifyUp(h, h->size);
    h->size++;
}

// Extract Min
void extractMin(MinHeap* h) {
    if (h->size == 0) {
        printf("-1\n");
        return;
    }

    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapifyDown(h, 0);

    printf("%d\n", min);
}

// Peek
void peek(MinHeap* h) {
    if (h->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", h->arr[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    MinHeap h;
    h.size = 0;

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(&h, x);
        }
        else if (strcmp(op, "extractMin") == 0) {
            extractMin(&h);
        }
        else if (strcmp(op, "peek") == 0) {
            peek(&h);
        }
    }

    return 0;
}