/*Problem: A secret system stores code names in forward order. To display them in mirror format, 
  you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored
*/


#include <stdio.h>
#include <string.h>

int main() {
    char code[1001];         
    scanf("%s", code);
    int len = strlen(code);
    for(int i = 0; i < len/2; i++) {
        char temp = code[i];
        code[i] = code[len-1-i];
        code[len-1-i] = temp;
    }
    printf("%s\n", code);
    
    return 0;
}

/*
  Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 */

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;
        right--;
    }
}
