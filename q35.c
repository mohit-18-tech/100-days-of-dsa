//Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

// Create queue
Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(n * sizeof(int));
    q->capacity = n;
    q->front = 0;
    q->rear = -1;
    return q;
}

// Enqueue
void enqueue(Queue* q, int x) {
    if (q->rear == q->capacity - 1) return; // overflow (ignored here)
    q->arr[++(q->rear)] = x;
}

// Display
void display(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    Queue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    display(q);

    return 0;
}