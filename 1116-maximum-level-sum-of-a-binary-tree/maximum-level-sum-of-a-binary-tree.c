/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    struct TreeNode** queue = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int level = 1;
    int bestLevel = 1;
    long long maxSum = LLONG_MIN;

    while (front < rear) {
        int levelSize = rear - front;
        long long levelSum = 0;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[front++];
            levelSum += curr->val;

            if (curr->left != NULL) {
                queue[rear++] = curr->left;
            }
            if (curr->right != NULL) {
                queue[rear++] = curr->right;
            }
        }

        if (levelSum > maxSum) {
            maxSum = levelSum;
            bestLevel = level;
        }

        level++;
    }

    free(queue);
    return bestLevel;
}