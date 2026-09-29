/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int result = 0;
    
    while (head != NULL) {
        // Multiply the current result by 2 and add the node's value
        result = result * 2 + head->val;
        head = head->next;
    }
    
    return result;
}