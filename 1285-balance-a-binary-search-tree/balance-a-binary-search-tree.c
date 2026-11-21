/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root, struct TreeNode** nodes, int* idx) {
    if (!root) return;
    inorder(root->left, nodes, idx);
    nodes[(*idx)++] = root;
    inorder(root->right, nodes, idx);
}

struct TreeNode* buildTree(struct TreeNode** nodes, int left, int right) {
    if (left > right) return NULL;
    int mid = left + (right - left) / 2;
    struct TreeNode* root = nodes[mid];
    root->left = buildTree(nodes, left, mid - 1);
    root->right = buildTree(nodes, mid + 1, right);
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    if (!root) return NULL;
    struct TreeNode* nodes[10005];
    int idx = 0;
    inorder(root, nodes, &idx);
    return buildTree(nodes, 0, idx - 1);
}