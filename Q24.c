// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, i;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    // Input number of nodes
    scanf("%d", &n);
    
    // Create linked list
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    // Input key to delete
    scanf("%d", &key);
    
    struct Node *current = head;
    struct Node *previous = NULL;
    
    // If head node itself holds the key
    if(current != NULL && current->data == key) {
        head = current->next;
        free(current);
    } else {
        // Search for the key
        while(current != NULL && current->data != key) {
            previous = current;
            current = current->next;
        }
        
        // If key found
        if(current != NULL) {
            previous->next = current->next;
            free(current);
        }
    }
    
    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    return 0;
}