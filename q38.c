//Problem: Deque (Double-Ended Queue) A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} Deque;

// Create
Deque* createDeque(int k) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(sizeof(int) * k);
    dq->capacity = k;
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
    return dq;
}

// Check empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// Size
int size(Deque* dq) {
    return dq->size;
}

// Push front
void push_front(Deque* dq, int val) {
    if (dq->size == dq->capacity) return;

    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = val;

    if (dq->size == 0)
        dq->rear = (dq->front + 1) % dq->capacity;

    dq->size++;
}

// Push back
void push_back(Deque* dq, int val) {
    if (dq->size == dq->capacity) return;

    dq->arr[dq->rear] = val;
    dq->rear = (dq->rear + 1) % dq->capacity;

    dq->size++;
}

// Pop front
void pop_front(Deque* dq) {
    if (dq->size == 0) return;

    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
}

// Pop back
void pop_back(Deque* dq) {
    if (dq->size == 0) return;

    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;
}

// Get front
int front_val(Deque* dq) {
    if (dq->size == 0) return -1;
    return dq->arr[dq->front];
}

// Get back
int back_val(Deque* dq) {
    if (dq->size == 0) return -1;
    return dq->arr[(dq->rear - 1 + dq->capacity) % dq->capacity];
}

// Display
void display(Deque* dq) {
    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->capacity;
    }
}

// Clear
void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
}