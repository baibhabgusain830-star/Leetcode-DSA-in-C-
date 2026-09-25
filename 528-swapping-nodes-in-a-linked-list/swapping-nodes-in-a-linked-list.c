/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode *left = head;
    struct ListNode *right = head;
    struct ListNode *curr = head;

    // 1. Move curr and left to the k-th node from the beginning
    for (int i = 1; i < k; i++) {
        curr = curr->next;
    }
    left = curr;

    // 2. Move right and curr together until curr reaches the end.
    // This perfectly positions 'right' at the k-th node from the end.
    while (curr->next != NULL) {
        curr = curr->next;
        right = right->next;
    }

    // 3. Swap the values of the two identified nodes
    int temp = left->val;
    left->val = right->val;
    right->val = temp;

    return head;
}