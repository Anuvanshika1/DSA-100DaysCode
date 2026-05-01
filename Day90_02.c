/*Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.*/

#include <stdio.h>

// Check if we can split into <= k subarrays
int canSplit(int nums[], int n, int k, int maxSum) {
    int subarrays = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > maxSum) {
            return 0;
        }

        if (currentSum + nums[i] > maxSum) {
            subarrays++;
            currentSum = nums[i];

            if (subarrays > k) {
                return 0;
            }
        } else {
            currentSum += nums[i];
        }
    }
    return 1;
}

// Main function
int splitArray(int nums[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (nums[i] > max)
            max = nums[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSplit(nums, n, k, mid)) {
            result = mid;
            high = mid - 1;  // try smaller max sum
        } else {
            low = mid + 1;   // increase limit
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", splitArray(nums, n, k));

    return 0;
}
