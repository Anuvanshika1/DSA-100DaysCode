/* Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

#include<stdio.h>
int main(){
    
    int n, i;
    int nums[50];
    int answer[50];
    printf("Enter size of array= ");
    scanf("%d", &n);

    printf("Enter elements= ");
    for(i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    answer[0] = 1;
    for(i = 1; i < n; i++){
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int rightProduct = 1;
    for(i = n - 1; i >= 0; i--){
        answer[i] = answer[i] * rightProduct;
        rightProduct = rightProduct * nums[i];
    }

    printf("Output array= ");
    for(i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}
