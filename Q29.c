// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, i, value;

    scanf("%d", &n);

    if (n <= 0)
        return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if (k == 0 || head->next == NULL) {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Step 1: Find length and last node
    int length = 1;
    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Make circular
    temp->next = head;

    // Step 3: Adjust k
    k = k % length;

    // Step 4: Move to (length - k)th node
    int steps = length - k;
    struct Node* newTail = head;

    for (i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: Set new head and break circle
    head = newTail->next;
    newTail->next = NULL;

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}