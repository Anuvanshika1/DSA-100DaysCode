/*Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} Pair;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Pair heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].freq > heap[i].freq) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

void heapifyDown(Pair heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left].freq < heap[smallest].freq)
            smallest = left;

        if (right < size && heap[right].freq < heap[smallest].freq)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void push(Pair heap[], int* size, Pair p, int k) {
    if (*size < k) {
        heap[*size] = p;
        (*size)++;
        heapifyUp(heap, *size - 1);
    }
    else if (p.freq > heap[0].freq) {
        heap[0] = p;
        heapifyDown(heap, *size, 0);
    }
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    qsort(nums, numsSize, sizeof(int), cmp);

    Pair* heap = (Pair*)malloc(sizeof(Pair) * k);
    int heapSize = 0;

    for (int i = 0; i < numsSize; ) {
        int val = nums[i];
        int count = 0;

        while (i < numsSize && nums[i] == val) {
            count++;
            i++;
        }

        Pair p = {val, count};
        push(heap, &heapSize, p, k);
    }

    int* result = (int*)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }

    *returnSize = k;

    free(heap);
    return result;
}
