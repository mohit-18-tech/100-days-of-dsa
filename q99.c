//Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination. Sort cars by position in descending order and calculate time to reach target.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

// Comparator: sort by position descending
int cmp(const void* a, const void* b) {
    Car* x = (Car*)a;
    Car* y = (Car*)b;
    return y->position - x->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    // Step 1: Build car array
    Car* cars = (Car*)malloc(positionSize * sizeof(Car));

    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, positionSize, sizeof(Car), cmp);

    // Step 3: Count fleets
    int fleets = 0;
    double prevTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > prevTime) {
            fleets++;                 // new fleet
            prevTime = cars[i].time;  // update slowest time
        }
    }

    free(cars);
    return fleets;
}