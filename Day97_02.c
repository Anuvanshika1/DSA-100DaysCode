/*Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.

Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.*/
#include <stdio.h>
#include <stdlib.h>

// Function for sorting
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minRooms(int start[], int end[], int n)
{
    // Sort both arrays
    qsort(start, n, sizeof(int), compare);
    qsort(end, n, sizeof(int), compare);

    int rooms = 0;
    int maxRooms = 0;

    int i = 0; // pointer for start[]
    int j = 0; // pointer for end[]

    while (i < n && j < n)
    {
        // Need new room
        if (start[i] < end[j])
        {
            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        }
        else
        {
            // Room becomes free
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main()
{
    int start[] = {0, 5, 15};
    int end[]   = {30, 10, 20};

    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum rooms required = %d\n",
           minRooms(start, end, n));

    return 0;
}
