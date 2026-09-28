/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    // If the list is empty or has only one node, return as is
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Initialize pointers for odd and even nodes
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    
    // Keep a reference to the start of the even list to connect it later
    struct ListNode* evenHead = even;
    
    // Traverse the list, updating the next pointers to skip one node at a time
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;       // Link the current odd node to the next odd node
        odd = odd->next;              // Move the odd pointer forward
        
        even->next = odd->next;       // Link the current even node to the next even node
        even = even->next;            // Move the even pointer forward
    }
    
    // Append the head of the even list to the tail of the odd list
    odd->next = evenHead;
    
    return head;
}