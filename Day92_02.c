/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4*/
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    int target = k - 1; // Looking for k-th largest (0-indexed)

    while (left <= right) {
        // Random pivot to avoid worst-case
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];
        
        // Hoare Partition Logic
        int i = left, j = right;
        while (i <= j) {
            while (nums[i] > pivot) i++; // Find element smaller than pivot
            while (nums[j] < pivot) j--; // Find element larger than pivot
            if (i <= j) {
                swap(&nums[i], &nums[j]);
                i++;
                j--;
            }
        }

        // Narrow the search range
        if (target <= j) {
            right = j;
        } else if (target >= i) {
            left = i;
        } else {
            return nums[target];
        }
    }
    return nums[left];
}
