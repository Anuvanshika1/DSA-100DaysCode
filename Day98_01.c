/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Compare function for sorting
int compare(const void *a, const void *b)
{
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

void mergeIntervals(Interval arr[], int n)
{
    // Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // First interval
    int start = arr[0].start;
    int end = arr[0].end;

    printf("Merged Intervals:\n");

    for(int i = 1; i < n; i++)
    {
        // Overlapping
        if(arr[i].start <= end)
        {
            // Extend end if needed
            if(arr[i].end > end)
                end = arr[i].end;
        }
        else
        {
            // Print previous interval
            printf("[%d, %d]\n", start, end);

            // Move to next interval
            start = arr[i].start;
            end = arr[i].end;
        }
    }

    // Print last interval
    printf("[%d, %d]\n", start, end);
}

int main()
{
    Interval arr[] = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}
