/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void inorder(struct TreeNode* node,int*prevval,int*hasval,int *mindiff){
    if(node==NULL)return;
    inorder(node->left,prevval,hasval,mindiff);
    if(*hasval){
        int dif=node->val-*prevval;
        if(dif<*mindiff)
        *mindiff=dif;
    }
    *prevval=node->val;
    *hasval=1;
    inorder(node->right,prevval,hasval,mindiff);
 }
int minDiffInBST(struct TreeNode* root) {
    int prevval=0;
    int hasval=0;
    int mindiff=INT_MAX;
    inorder(root,&prevval,&hasval,&mindiff);
    return mindiff;
}