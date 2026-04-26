//Problem Statement : Implement a hash table using quadratic probing with formula: h(k, i) = (h(k) + i*i) % m

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);  // Size of hash table
    scanf("%d", &q);  // Number of operations

    int hashTable[m];

    // Initialize hash table with EMPTY
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            int inserted = 0;

            for (int j = 0; j < m; j++) {
                int index = (key % m + j * j) % m;

                if (hashTable[index] == EMPTY) {
                    hashTable[index] = key;
                    inserted = 1;
                    break;
                }
                // If key already exists, do nothing
                if (hashTable[index] == key) {
                    inserted = 1;
                    break;
                }
            }

            // Optional: Handle table full case (not required for output)
            if (!inserted) {
                printf("Hash table is full\n");
            }
        }
        else if (strcmp(operation, "SEARCH") == 0) {
            int found = 0;

            for (int j = 0; j < m; j++) {
                int index = (key % m + j * j) % m;

                if (hashTable[index] == key) {
                    found = 1;
                    break;
                }

                // Stop searching if an empty slot is encountered
                if (hashTable[index] == EMPTY) {
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}