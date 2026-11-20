/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) {
        return 0;
    }

    // Current node is smaller than low: only the right subtree can have values >= low
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }

    // Current node is larger than high: only the left subtree can have values <= high
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }

    // Current node is within [low, high]: include it and check both subtrees
    return root->val +
           rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
}