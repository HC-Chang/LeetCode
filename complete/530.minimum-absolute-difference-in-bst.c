/*
 * @lc app=leetcode id=530 lang=c
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minn(int a, int b) { return a < b ? a : b; }

void inorder(struct TreeNode *root, int *min, struct TreeNode **prev)
{
    if (!root)
        return;
    inorder(root->left, min, prev);
    if (*prev != NULL)
        *min = minn(*min, root->val - (*prev)->val);
    *prev = root;
    inorder(root->right, min, prev);
}

int getMinimumDifference(struct TreeNode *root)
{
    int min = INT_MAX;
    struct TreeNode *prev = NULL;
    inorder(root, &min, &prev);
    return min;
}
// @lc code=end

// Note:
// This question is the same as 783