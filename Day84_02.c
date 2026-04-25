/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.*/

#include <stdio.h>

int findPeak(int nums[], int n) {
    int low = 0, high = n - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        // If middle is greater than next element,
        // peak is on left side including mid
        if(nums[mid] > nums[mid+1]) {
            high = mid;
        }

        // Peak lies on right side
        else {
            low = mid + 1;
        }
    }

    return low; // Peak index
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d",&n);

    int nums[n];

    printf("Enter array elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d",&nums[i]);
    }

    int peakIndex = findPeak(nums,n);

    printf("Peak element index = %d", peakIndex);

    return 0;
}
