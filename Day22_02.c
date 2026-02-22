/* Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node* reverseList(struct Node* head){
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while(curr != NULL){
        next = curr->next;   
        curr->next = prev;  
        prev = curr;         
        curr = next;         
    }
    return prev;
}

void printList(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n == 0){
        printf("List is empty.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++){
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = value;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Original List: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
