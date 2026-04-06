//Problem Statement: Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int size;
} PriorityQueue;

// Initialize
void init(PriorityQueue* pq) {
    pq->size = 0;
}

// Insert
void insert(PriorityQueue* pq, int x) {
    pq->arr[pq->size++] = x;
}

// Find index of minimum element
int findMinIndex(PriorityQueue* pq) {
    if (pq->size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i] < pq->arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove and print min)
void deleteMin(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex(pq);
    int minValue = pq->arr[minIndex];

    // shift elements left
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }

    pq->size--;
    printf("%d\n", minValue);
}

// Peek (print min without removing)
void peek(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex(pq);
    printf("%d\n", pq->arr[minIndex]);
}

int main() {
    int n;
    scanf("%d", &n);

    PriorityQueue pq;
    init(&pq);

    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(&pq, x);
        }
        else if (strcmp(op, "delete") == 0) {
            deleteMin(&pq);
        }
        else if (strcmp(op, "peek") == 0) {
            peek(&pq);
        }
    }

    return 0;
}