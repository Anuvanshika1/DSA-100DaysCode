/* Basic Calculator II

Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5
*/

#include <ctype.h>

int calculate(char* s) {
    long result = 0;
    long last = 0;
    long num = 0;
    char sign = '+';

    for(int i = 0; s[i] != '\0'; i++) {

        if(isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {

            if(sign == '+'){
                result += last;
                last = num;
            }
            else if(sign == '-'){
                result += last;
                last = -num;
            }
            else if(sign == '*'){
                last = last * num;
            }
            else if(sign == '/'){
                last = last / num;
            }

            sign = s[i];
            num = 0;
        }
    }

    result += last;

    return result;
}
