/*Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        minVal = MIN(minVal, nums[i]);
        maxVal = MAX(maxVal, nums[i]);
    }

    if (minVal == maxVal) return 0;

    // Calculate bucket size and count
    int bucketSize = MAX(1, (maxVal - minVal) / (numsSize - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    // Track min and max for each bucket
    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));
    int* bucketUsed = (int*)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Distribute numbers into buckets
    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        bucketUsed[idx] = 1;
        bucketMin[idx] = MIN(bucketMin[idx], nums[i]);
        bucketMax[idx] = MAX(bucketMax[idx], nums[i]);
    }

    // Find the maximum gap
    int maxGap = 0;
    int prevMax = minVal;
    for (int i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i]) continue;
        
        // Gap is between current bucket's min and previous bucket's max
        maxGap = MAX(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(bucketUsed);

    return maxGap;
}

int main() {
    int nums[] = {3, 6, 9, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("Maximum Gap: %d\n", maximumGap(nums, size)); // Output: 3
    return 0;
}
