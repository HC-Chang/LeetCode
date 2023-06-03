/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
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
int minDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    else if (!root->left && !root->right)
        return 1;
    else if (!root->left)
        return minDepth(root->right) + 1;
    else if (!root->right)
        return minDepth(root->left) + 1;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    return l < r ? l + 1 : r + 1;
}
// @lc code=end
