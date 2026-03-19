/*Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) return NULL;

    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* deque = (int*)malloc(sizeof(int) * numsSize);

    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        if (front <= rear && deque[front] <= i - k)
            front++;
        while (front <= rear && nums[deque[rear]] < nums[i])
            rear--;
        deque[++rear] = i;
        if (i >= k - 1)
            result[idx++] = nums[deque[front]];
    }

    *returnSize = idx;

    free(deque);
    return result;
}
