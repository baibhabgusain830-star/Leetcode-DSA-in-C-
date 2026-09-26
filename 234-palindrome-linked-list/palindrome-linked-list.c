/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // 1. Find the middle of the linked list using slow & fast pointers
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half of the list
    struct ListNode* secondHalfStart = reverseList(slow->next);

    // 3. Compare the first and second halves
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfStart;
    bool isPalin = true;
    while (isPalin && p2 != NULL) {
        if (p1->val != p2->val) {
            isPalin = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4. Restore the list (optional but good practice)
    slow->next = reverseList(secondHalfStart);

    return isPalin;
}