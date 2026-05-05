/*Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head) {
    // If the list is empty or has only one node, it's already sorted
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Create a dummy node to serve as the start of the sorted list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        // Save the next node to process
        struct ListNode* next_node = curr->next;
        
        // Find the correct position in the sorted part (starting from dummy)
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }
        
        // Insert curr between prev and prev->next
        curr->next = prev->next;
        prev->next = curr;
        
        // Move to the next node in the original list
        curr = next_node;
    }
    
    struct ListNode* sorted_head = dummy->next;
    free(dummy); // Clean up the dummy node
    return sorted_head;
}
