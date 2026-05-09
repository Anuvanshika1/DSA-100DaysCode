/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

// Comparator for sorting in descending order of position
int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Store position and speed together
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        // Time to reach target
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet formed
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {
    int target = 12;

    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};

    int n = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, speed, n);

    printf("Number of Car Fleets = %d\n", result);

    return 0;
}
