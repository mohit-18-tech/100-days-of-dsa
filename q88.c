//Problem Statement:Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if we can place k cows with at least 'dist' minimum distance
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;              // place first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k) return 1;  // possible
    }
    return 0;  // not possible
}

int maxMinDistance(int stalls[], int n, int k) {
    // Step 1: sort the stalls
    qsort(stalls, n, sizeof(int), compare);

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Step 2: binary search on answer
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;         // valid distance
            left = mid + 1;    // try larger distance
        } else {
            right = mid - 1;   // try smaller distance
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    printf("%d\n", maxMinDistance(stalls, n, k));

    return 0;
}