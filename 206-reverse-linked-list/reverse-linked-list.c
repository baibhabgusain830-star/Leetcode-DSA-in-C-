/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* P1=NULL;
    struct ListNode* P2= head;
    struct ListNode* P3= NULL;
    while(P2!=NULL){
        P3=P2->next;
        P2->next=P1;
        P1=P2;
        P2=P3;
    }
    return P1;
}