/*
 * @lc app=leetcode id=1302 lang=c
 *
 * [1302] Deepest Leaves Sum
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
int max(int a, int b) { return a > b ? a : b; }
int getDepth(struct TreeNode *root)
{
    return root ? 1 + max(getDepth(root->left), getDepth(root->right)) : 0;
}
int getSumAtDepth(struct TreeNode *root, int d, int depth)
{
    if (!root)
        return 0;
    if (d == depth)
        return root->val;
    return getSumAtDepth(root->left, d + 1, depth) + getSumAtDepth(root->right, d + 1, depth);
}
int deepestLeavesSum(struct TreeNode *root)
{
    int depth = getDepth(root);
    return getSumAtDepth(root, 1, depth);
}
// @lc code=end

// Note: DFS