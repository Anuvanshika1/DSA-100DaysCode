Q1:-
#include <stdio.h>

int main() {
    int n, pos, x, i;
    int arr[100];

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &x);

    printf("Enter the position: ");
    scanf("%d", &pos);
    // shifting the array to the right
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;
    n++; // increase size

    printf("New array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
// LEETCODE PROBLEM
// Q2:- Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int i,j;
     int* result = (int*)malloc(2 * sizeof(int));
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target)
            {
                result[0]=i;
                result[1]=j;
                *returnSize=2;
                return result;
            }
        
        }
      
    }    
        return NULL;
}

 

