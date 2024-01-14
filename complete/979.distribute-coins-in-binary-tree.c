/*
 * @lc app=leetcode id=979 lang=c
 *
 * [979] Distribute Coins in Binary Tree
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
int traverse(struct TreeNode *root, int *res)
{
    if (!root)
        return 0;
    int l = traverse(root->left, res);
    int r = traverse(root->right, res);
    *res += abs(l) + abs(r);
    return root->val + l + r - 1;
}
int distributeCoins(struct TreeNode *root)
{
    int res = 0;
    traverse(root, &res);
    return res;
}
// @lc code=end

// Note: binary tree