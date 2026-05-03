//Problem: Given meeting intervals, find minimum number of rooms required. Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by start time
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

// Min Heap functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (2 * index + 1 < size) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index) break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

// Main function
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    // Step 1: Sort by start time
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int heapSize = 0;

    // Step 2: Add first meeting end time
    heap[heapSize++] = intervals[0][1];

    // Step 3: Process remaining meetings
    for (int i = 1; i < intervalsSize; i++) {
        // If room is free
        if (intervals[i][0] >= heap[0]) {
            heap[0] = intervals[i][1];
            heapifyDown(heap, heapSize, 0);
        } else {
            // Need new room
            heap[heapSize++] = intervals[i][1];
            heapifyUp(heap, heapSize - 1);
        }
    }

    int result = heapSize;
    free(heap);
    return result;
}