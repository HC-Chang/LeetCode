/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
    long total = 0, mod = 1e9 + 7, ans = 0;
    long postorder(TreeNode *root)
    {
        if (!root)
            return 0;
        long sum = root->val + postorder(root->left) + postorder(root->right);
        if (total)
            ans = max(ans, sum * (total - sum));
        return sum;
    }

public:
    int maxProduct(TreeNode *root)
    {
        total = postorder(root);
        postorder(root);
        return ans % mod;
    }
};

// @lc code=end

// Note: binary tree
