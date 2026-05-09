/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

// Merge function
void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pair L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2) {

        // Right element is smaller
        if (L[i].value > R[j].value) {
            rightCount++;
            arr[k++] = R[j++];
        }
        else {
            // Count smaller elements on right
            count[L[i].index] += rightCount;
            arr[k++] = L[i++];
        }
    }

    // Remaining left elements
    while (i < n1) {
        count[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }

    // Remaining right elements
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort
void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Pair arr[n];
    int count[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Counts of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}
