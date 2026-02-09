/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100005]; 
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if(n <= 1) {
     
        for(int i = 0; i < n; i++) {
            if(i > 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
        return 0;
    }
    
    int write = 1;  
    
    for(int read = 1; read < n; read++) {
        if(arr[read] != arr[write-1]) {
            arr[write] = arr[read];
            write++;
        }
    }
    for(int i = 0; i < write; i++) {
        if(i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    
    return 0;
}

/*
  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

void moveZeroes(int* nums, int numsSize) {
    int left = 0;  
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            if (left != i) {
                int temp = nums[left];
                nums[left] = nums[i];
                nums[i] = temp;
            }
            left++;
        }
    }
}
