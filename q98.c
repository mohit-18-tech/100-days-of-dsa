// Problem: Given intervals, merge all overlapping ones. Sort first, then compare with previous.

#include <stdio.h>
#include <stdlib.h>

// Comparator: sort by start time
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

/**
 * Return a 2D array of merged intervals.
 * Note: Caller (LeetCode) will free the returned arrays.
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Step 1: sort by start
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // Allocate worst-case size (no merges)
    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    // Initialize with first interval
    int curStart = intervals[0][0];
    int curEnd   = intervals[0][1];

    // Step 2: iterate and merge
    for (int i = 1; i < intervalsSize; i++) {
        int s = intervals[i][0];
        int e = intervals[i][1];

        if (s <= curEnd) {
            // overlap → extend
            if (e > curEnd) curEnd = e;
        } else {
            // no overlap → store current
            res[idx] = (int*)malloc(2 * sizeof(int));
            res[idx][0] = curStart;
            res[idx][1] = curEnd;
            (*returnColumnSizes)[idx] = 2;
            idx++;

            // start new interval
            curStart = s;
            curEnd = e;
        }
    }

    // push the last interval
    res[idx] = (int*)malloc(2 * sizeof(int));
    res[idx][0] = curStart;
    res[idx][1] = curEnd;
    (*returnColumnSizes)[idx] = 2;
    idx++;

    *returnSize = idx;
    return res;
}