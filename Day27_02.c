/* Remove loop in Linked List

Given the head of a singly linked list, the task is to remove a cycle if present. 
A cycle exists when a node's next pointer points back to a previous node, forming a loop. 
Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. 
The terminal will print true if a cycle is removed otherwise, it will print false.

Examples:
Input: head = 1 -> 3 -> 4, pos = 2
Output: true

Examples:
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true

Examples:
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
*/

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    void removeLoop(Node* head) {

        if(head == NULL || head->next == NULL)
            return;

        Node *slow = head, *fast = head;


        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        if(slow != fast)
            return;

        slow = head;

        if(slow == fast){
            while(fast->next != slow)
                fast = fast->next;
        }else{
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = NULL;
    }
};
