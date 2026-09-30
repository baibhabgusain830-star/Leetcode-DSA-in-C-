/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    
    // Traverse the list until the end
    while (current != NULL && current->next != NULL) {
        // If the current node's value equals the next node's value, it's a duplicate
        if (current->val == current->next->val) {
            struct ListNode* duplicate = current->next;
            // Bypass the duplicate node
            current->next = current->next->next;
            // Free the memory of the duplicate node (good practice in C)
            free(duplicate);
        } else {
            // Move to the next node if no duplicate was found
            current = current->next;
        }
    }
    
    return head;
}