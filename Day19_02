/* Maximum Sum Circular Subarray

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


Example 1:
Input: nums = [1,-2,3,-2]
Output: 3

Example 2:
Input: nums = [5,-3,5]
Output: 10

Example 3:
Input: nums = [-3,-2,-3]
Output: -2
*/

#include<stdio.h>
int main(){
    
    int n, result, i;
    int nums[50];
    printf("Enter size of array= ");
    scanf("%d", &n);
    printf("Enter elements= \n");
    for(i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    
    int totalSum = nums[0];
    
    int currentMax = nums[0];
    int maxSum = nums[0];
    
    int currentMin = nums[0];
    int minSum = nums[0];
    
    
    for(i = 1; i < n; i++){
        if(currentMax + nums[i] > nums[i]){
            currentMax = currentMax + nums[i];
        }else{
            currentMax = nums[i];
        }
        if(currentMax > maxSum){
            maxSum = currentMax;
        }
        
        
        if(currentMin + nums[i] < nums[i]){
            currentMin = currentMin + nums[i];
        }else{
            currentMin = nums[i];
        }
        if(currentMin < minSum){
            minSum = currentMin;
        }
        
        totalSum = totalSum + nums[i];
    }
    

    if(maxSum < 0){
        result = maxSum;
    }else{
        if(totalSum - minSum > maxSum){
            result = totalSum - minSum;
        }else{
            result = maxSum;
        }
    }
    
    printf("Maximum Circular Subarray Sum =  %d", result);
    
    return 0;
}
