/* Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void display(struct node *head){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("Null");
}

int main(){
    
    int i, value, n;
    struct node *head = NULL;
    struct node *ptr, *temp, *slow, *fast;

    printf("Enter the number of nodes = ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter the node %d value = ", i + 1);
        scanf("%d", &value);
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = value;
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }

    printf("Linked List = ");
    display(head);

    if(head == NULL){
        printf("List is empty.");
    }else{
        slow = head;
        fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        printf("\nMiddle Element = %d", slow->data);
    }

    return 0;
    
}
