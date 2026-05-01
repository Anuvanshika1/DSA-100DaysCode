/*A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 */
#include <stdio.h>

// Check if we can ship within given days
int canShip(int weights[], int n, int days, int capacity) {
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++) {
        // If single package exceeds capacity
        if (weights[i] > capacity) {
            return 0;
        }

        if (currentLoad + weights[i] > capacity) {
            requiredDays++;
            currentLoad = weights[i];

            if (requiredDays > days) {
                return 0;
            }
        } else {
            currentLoad += weights[i];
        }
    }
    return 1;
}

// Main function
int shipWithinDays(int weights[], int n, int days) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += weights[i];
        if (weights[i] > max)
            max = weights[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canShip(weights, n, days, mid)) {
            result = mid;
            high = mid - 1;  // try smaller capacity
        } else {
            low = mid + 1;   // increase capacity
        }
    }

    return result;
}

int main() {
    int n, days;
    scanf("%d %d", &n, &days);

    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("%d\n", shipWithinDays(weights, n, days));

    return 0;
}
