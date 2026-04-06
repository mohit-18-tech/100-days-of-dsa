//Problem Statement: Implement a Queue using a linked list supporting enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Initialize queue
void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Enqueue
void enqueue(Queue* q, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL) { // empty queue
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Dequeue
void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }

    Node* temp = q->front;
    printf("%d\n", temp->data);

    q->front = q->front->next;

    if (q->front == NULL) // queue becomes empty
        q->rear = NULL;

    free(temp);
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    init(&q);

    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(&q, x);
        }
        else if (strcmp(op, "dequeue") == 0) {
            dequeue(&q);
        }
    }

    return 0;
}