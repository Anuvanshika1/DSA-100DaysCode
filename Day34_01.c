/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = top;
    top = ptr;
}

int pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int evaluate(char exp[]){
    int i = 0;

    while(exp[i] != '\0'){

        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            int b = pop();
            int a = pop();
            int result;

            switch(exp[i]){
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main(){
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%[^\n]", exp);

    int result = evaluate(exp);

    printf("Result: %d", result);

    return 0;
}
