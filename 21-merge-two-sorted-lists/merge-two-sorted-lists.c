/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* h1, struct ListNode* h2) {
    if(h1==NULL|h2==NULL){
        return h1==NULL?h2:h1;
    }
    if(h1->val<h2->val){
        h1->next=mergeTwoLists(h1->next,h2);
        return h1;
    }
    else{
        h2->next=mergeTwoLists(h1,h2->next);
        return h2;
    }
}