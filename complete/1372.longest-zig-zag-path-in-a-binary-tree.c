/*
 * @lc app=leetcode id=1372 lang=c
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
void dfs(int l, int r, int *max_count, struct TreeNode *root)
{
    if (!root)
        return;
    *max_count = max(*max_count, max(l, r));
    dfs(r + 1, 0, max_count, root->left);
    dfs(0, l + 1, max_count, root->right);
}
int longestZigZag(struct TreeNode *root)
{
    int max_count = 0;
    dfs(0, 0, &max_count, root);
    return max_count;
}
// @lc code=end
