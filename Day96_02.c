/*Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].*/
#include <stdio.h>
#include <stdlib.h>

// Function to count reverse pairs between two sorted halves
int countPairs(int* nums, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        // Use long long to prevent overflow during 2 * nums[j]
        while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }
    return count;
}

// Standard merge function
void merge(int* nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = nums[left + i];
    for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) nums[k++] = L[i++];
        else nums[k++] = R[j++];
    }
    while (i < n1) nums[k++] = L[i++];
    while (j < n2) nums[k++] = R[j++];

    free(L);
    free(R);
}

int modifiedMergeSort(int* nums, int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    int count = modifiedMergeSort(nums, left, mid);
    count += modifiedMergeSort(nums, mid + 1, right);
    
    // Count reverse pairs before merging
    count += countPairs(nums, left, mid, right);
    
    // Merge sorted halves
    merge(nums, left, mid, right);
    
    return count;
}

int reversePairs(int* nums, int numsSize) {
    return modifiedMergeSort(nums, 0, numsSize - 1);
}

int main() {
    int nums[] = {1, 3, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("Number of reverse pairs: %d\n", reversePairs(nums, size)); // Output: 2
    return 0;
}
