/*Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].*/

#include <stdlib.h>

void merge(int* nums, int* indices, int* counts, int left, int mid, int right) {
    int size = right - left + 1;
    int* temp_indices = (int*)malloc(size * sizeof(int));
    int i = left;      // Pointer for left half
    int j = mid + 1;   // Pointer for right half
    int k = 0;
    int right_count = 0; // Tracks how many elements from right side are smaller

    while (i <= mid && j <= right) {
        if (nums[indices[j]] < nums[indices[i]]) {
            // Element in right half is smaller
            temp_indices[k] = indices[j];
            right_count++;
            j++;
        } else {
            // Element in left half is smaller or equal
            // Add the number of right-side elements seen so far to this index
            counts[indices[i]] += right_count;
            temp_indices[k] = indices[i];
            i++;
        }
        k++;
    }

    // Clean up remaining elements
    while (i <= mid) {
        counts[indices[i]] += right_count;
        temp_indices[k++] = indices[i++];
    }
    while (j <= right) {
        temp_indices[k++] = indices[j++];
    }

    // Copy back to original indices array
    for (int p = 0; p < size; p++) {
        indices[left + p] = temp_indices[p];
    }
    free(temp_indices);
}

void mergeSort(int* nums, int* indices, int* counts, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, indices, counts, left, mid);
    mergeSort(nums, indices, counts, mid + 1, right);
    merge(nums, indices, counts, left, mid, right);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));
    int* indices = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }

    mergeSort(nums, indices, counts, 0, numsSize - 1);

    free(indices);
    return counts;
}
