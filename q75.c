//Problem Statement Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007  // A prime number for better hashing

// Structure for hash table node
typedef struct Node {
    int key;        // prefix sum
    int value;      // first index of occurrence
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Hash function
int hash(int key) {
    if (key < 0)
        key = -key;
    return key % TABLE_SIZE;
}

// Insert key-value pair into hash table
void insert(int key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search for a key in the hash table
int search(int key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;  // Not found
}

// Function to find the longest subarray with sum 0
int maxLenZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If prefix sum is zero
        if (sum == 0) {
            maxLen = i + 1;
        }

        int prevIndex = search(sum);

        // If sum seen before, update max length
        if (prevIndex != -1) {
            if (i - prevIndex > maxLen)
                maxLen = i - prevIndex;
        } else {
            // Store first occurrence of this sum
            insert(sum, i);
        }
    }

    return maxLen;
}

// Driver code
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}