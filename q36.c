//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

// Create queue
CircularQueue* createQueue(int n) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->arr = (int*)malloc(n * sizeof(int));
    q->capacity = n;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Enqueue
void enqueue(CircularQueue* q, int x) {
    if (q->size == q->capacity) return; // full

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->size++;
}

// Dequeue
void dequeue(CircularQueue* q) {
    if (q->size == 0) return; // empty

    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

// Display
void display(CircularQueue* q) {
    int i = q->front;
    for (int count = 0; count < q->size; count++) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->capacity;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    CircularQueue* q = createQueue(n);

    // enqueue n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    int m;
    scanf("%d", &m);

    // dequeue m elements
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    return 0;
}