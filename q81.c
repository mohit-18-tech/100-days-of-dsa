//Problem: Implement Bubble Sort - Implement the algorithm.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // Optimization: stop if already sorted
        if (!swapped) break;
    }

    // Output
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}