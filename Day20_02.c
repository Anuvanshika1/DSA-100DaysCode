/*3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 */

#include<stdio.h>
int main(){

    int n;
    printf("Enter number of elements= ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Triplets whose sum is 0:\n");

    int found = 0;
    int printed[100][3];
    int count = 0;

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){

                if(arr[i] + arr[j] + arr[k] == 0){

                    int a = arr[i];
                    int b = arr[j];
                    int c = arr[k];

                    if(a > b){
                        int t=a; a=b; b=t;
                    }if(a > c){
                        int t=a; a=c; c=t;
                    }if(b > c){
                        int t=b; b=c; c=t;
                    }

                    int duplicate = 0;
                    for(int x = 0; x < count; x++){
                        if(printed[x][0]==a && printed[x][1]==b && printed[x][2]==c){
                            duplicate = 1;
                            break;
                        }
                    }

                    if(!duplicate){
                        printf("[%d, %d, %d]\n", a, b, c);
                        printed[count][0] = a;
                        printed[count][1] = b;
                        printed[count][2] = c;
                        count++;
                        found = 1;
                    }
                }
            }
        }
    }

    if(found == 0) {
        printf("No triplet found");
    }

    return 0;
}
