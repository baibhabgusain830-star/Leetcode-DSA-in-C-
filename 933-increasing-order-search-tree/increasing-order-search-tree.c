/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void inorder(struct TreeNode* node,struct TreeNode** newroot,struct TreeNode**prev ){
    if(node==NULL)return;
    inorder(node->left,newroot,prev);
    node->left=NULL;
    if(*newroot==NULL)*newroot=node;
    else{
        (*prev)->right=node;
    }
    *prev=node;
    inorder(node->right,newroot,prev);
 }
struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode* newRoot = NULL;
    struct TreeNode* prev = NULL;

    inorder(root, &newRoot, &prev);

    return newRoot;
}