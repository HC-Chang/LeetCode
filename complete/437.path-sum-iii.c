/*
 * @lc app=leetcode id=437 lang=c
 *
 * [437] Path Sum III
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
int sum(long pre, struct TreeNode *root, int targetSum)
{
    if (!root)
        return 0;
    long cur = pre + root->val;
    return (cur == targetSum) + sum(cur, root->left, targetSum) + sum(cur, root->right, targetSum);
}
int pathSum(struct TreeNode *root, int targetSum)
{
    if (!root)
        return 0;
    return sum(0, root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}
// @lc code=end
