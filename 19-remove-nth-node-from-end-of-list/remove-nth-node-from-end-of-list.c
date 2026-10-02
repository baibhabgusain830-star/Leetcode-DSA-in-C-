/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node to handle edge cases (e.g., removing the first node)
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;
    
    // Move fast pointer n + 1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both pointers simultaneously until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow is now pointing to the node right before the one to delete
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    
    // Free the memory of the deleted node to prevent memory leaks
    free(toDelete);
    
    struct ListNode* newHead = dummy->next;
    free(dummy); // Free the dummy node as well
    
    return newHead;
}