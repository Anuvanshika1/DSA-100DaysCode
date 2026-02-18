/* Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/

#include<stdio.h>
int main(){
    
    int n, i, k;
    int arr[50];
    int rotated[50];
    printf("Enter number of elements= ");
    scanf("%d", &n);

    printf("Enter the %d elements= ",n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter k (positions to rotate)= ");
    scanf("%d", &k);
    k = k % n;

    for(i = 0; i < n; i++){
        rotated[(i + k) % n] = arr[i];
    }

    printf("Rotated array= ");
    for(i = 0; i < n; i++){
        printf("%d ", rotated[i]);
    }
    printf("\n");

    return 0;
}
