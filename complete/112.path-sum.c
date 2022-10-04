/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
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

bool hasPathSum(struct TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }
    if (!root->left && !root->right && root->val == targetSum)
    {
        return true;
    }
    else
    {
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
}
// @lc code=end
