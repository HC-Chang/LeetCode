/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int traverse(TreeNode *root, int *hash)
    {
        if (!root)
            return 0;
        int result = 0;
        *hash ^= (1 << root->val);
        if (!root->left && !root->right && __builtin_popcount(*hash) <= 1)
            ++result;
        result += traverse(root->left, hash) + traverse(root->right, hash);
        *hash ^= (1 << root->val);
        return result;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int hash = 0;
        return traverse(root, &hash);
    }
};
// @lc code=end

// Note: DFS + bit manipulation