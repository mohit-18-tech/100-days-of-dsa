//Problem Statement : Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

#include <stdio.h>

// Check if we can paint with <= k painters within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0; // single board exceeds limit

        if (currentTime + boards[i] > maxTime) {
            painters++;
            currentTime = boards[i];
        } else {
            currentTime += boards[i];
        }

        if (painters > k)
            return 0;
    }

    return 1;
}

int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;        // valid time
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));

    return 0;
}