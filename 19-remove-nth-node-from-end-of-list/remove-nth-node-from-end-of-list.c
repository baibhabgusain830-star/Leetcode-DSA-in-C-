/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    
    // If fast is NULL, the node to remove is the head of the list
    if (fast == NULL) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }
    
    // Move both pointers until fast reaches the last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow is now exactly before the node to delete
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    
    free(toDelete);
    
    return head;
}