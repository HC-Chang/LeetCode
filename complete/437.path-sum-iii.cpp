/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    static int sum(long pre, TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        long cur = pre + root->val;
        return (cur == targetSum) + sum(cur, root->left, targetSum) +
               sum(cur, root->right, targetSum);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return sum(0, root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};
// @lc code=end
