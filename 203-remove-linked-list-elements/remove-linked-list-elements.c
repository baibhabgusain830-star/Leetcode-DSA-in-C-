struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node that points to the head of the list
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* curr = &dummy;
    
    // Traverse the list
    while (curr->next != NULL) {
        if (curr->next->val == val) {
            // Node matches the value; bypass it and free the memory
            struct ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            free(toDelete);
        } else {
            // Move to the next node
            curr = curr->next;
        }
    }
    
    return dummy.next;
}