/* Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
*/

#include<stdio.h>
int main(){
    
    int n, i;
    int nums[50];
    printf("Enter number of elements= ");
    scanf("%d", &n);

    printf("Enter the elements= \n");
    for(i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    
    int currentSum = nums[0];
    int maxSum = nums[0];
    for(i = 1; i < n; i++){
        if(currentSum < 0){
            currentSum = nums[i];
        }else{
            currentSum += nums[i];
        }

        if(currentSum > maxSum){
            maxSum = currentSum;
        }
    }

    printf("Maximum Subarray Sum = %d\n", maxSum);

    return 0;
}
