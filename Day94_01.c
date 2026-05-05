/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/

#include <stdio.h>

void countingSort(int arr[], int n) {
    int i;

    // Step 1: Find max
    int max = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int count[max + 1];
    for(i = 0; i <= max; i++)
        count[i] = 0;

    for(i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 3: Prefix sum
    for(i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 4: Output array (stable)
    int output[n];
    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back
    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;

    countingSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
