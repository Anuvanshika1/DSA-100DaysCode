/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity*/

#include <stdio.h>

int main()
{
    int n, target;

    // Input size of array
    scanf("%d", &n);

    int nums[n];

    // Input sorted array
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    // Input target
    scanf("%d", &target);

    int low = 0, high = n - 1;
    int found = -1;

    // Binary Search
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(nums[mid] == target)
        {
            found = mid;
            break;
        }
        else if(nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%d", found);

    return 0;
}
