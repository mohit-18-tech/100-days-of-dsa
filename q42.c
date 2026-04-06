//Problem Statement: Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Stack
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Queue functions
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue* q, int x) {
    q->arr[++(q->rear)] = x;
}

int dequeue(Queue* q) {
    return q->arr[(q->front)++];
}

int isQueueEmpty(Queue* q) {
    return q->front > q->rear;
}

// Stack