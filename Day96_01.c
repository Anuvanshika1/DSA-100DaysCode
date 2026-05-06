/*Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].*/
#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves and count inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There is an inversion
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); 
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

// Recursive function to implement merge sort and count inversions
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* temp = (int*)malloc(sizeof(int) * n);

    long long result = mergeSortAndCount(arr, temp, 0, n - 1);

    printf("Number of inversions: %lld\n", result);

    free(temp);
    return 0;
}
