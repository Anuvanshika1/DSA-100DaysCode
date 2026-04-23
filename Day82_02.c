/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/

#include <stdio.h>

int main()
{
    int n, target;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input target
    scanf("%d", &target);

    int low = 0, high = n - 1;
    int ans = n;  // default insert at end

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
        {
            printf("%d", mid);
            return 0;
        }
        else if(arr[mid] > target)
        {
            ans = mid;       // possible insert position
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}
