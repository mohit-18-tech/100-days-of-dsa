//Problem Statement :Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

#include <stdio.h>

// Check if allocation is possible with given maxPages limit
int canAllocate(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages)
            return 0; // single book exceeds limit

        if (currentSum + pages[i] > maxPages) {
            students++;
            currentSum = pages[i];
        } else {
            currentSum += pages[i];
        }

        if (students > m)
            return 0;
    }

    return 1;
}

int findMinPages(int pages[], int n, int m) {
    if (m > n) return -1;

    int low = pages[0], high = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (pages[i] > low)
            low = pages[i];
        high += pages[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(pages, n, m, mid)) {
            ans = mid;        // valid answer
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // increase limit
        }
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("%d\n", findMinPages(pages, n, m));

    return 0;
}