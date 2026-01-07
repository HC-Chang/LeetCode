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
    long mod = 1e9 + 7;
    long postorder(vector<int> &sums, TreeNode *root)
    {
        if (!root)
            return 0;
        long sum = root->val + postorder(sums, root->left) + postorder(sums, root->right);
        sums.push_back(sum);
        return sum;
    }

public:
    int maxProduct(TreeNode *root)
    {
        vector<int> sums;
        long total = postorder(sums, root);
        long ans = 0;
        for (const auto &s : sums)
            ans = max(ans, s * (total - s));
        return ans % mod;
    }
};
// @lc code=end

// Note: binary tree
