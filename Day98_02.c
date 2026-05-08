/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping 
intervals that cover all the intervals in the input.*/
#include <stdlib.h>
#include <math.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    // 1. Sort intervals based on start time
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // 2. Prepare result array
    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int count = 0;
    
    // Initialize with the first interval
    merged[count] = (int*)malloc(2 * sizeof(int));
    merged[count][0] = intervals[0][0];
    merged[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;

    // 3. Iterate and merge
    for (int i = 1; i < intervalsSize; i++) {
        int currentStart = intervals[i][0];
        int currentEnd = intervals[i][1];
        int lastEnd = merged[count - 1][1];

        if (currentStart <= lastEnd) {
            // Overlap: update the end of the last interval if current is further
            if (currentEnd > lastEnd) {
                merged[count - 1][1] = currentEnd;
            }
        } else {
            // No overlap: add as a new interval
            merged[count] = (int*)malloc(2 * sizeof(int));
            merged[count][0] = currentStart;
            merged[count][1] = currentEnd;
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return merged;
}
