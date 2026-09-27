/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // Handle empty list or single node without a cycle
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Traverse the list until fast pointer reaches the end (NULL)
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If they meet, a cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end, there is no cycle
    return false;
}