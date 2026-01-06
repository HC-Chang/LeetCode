/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
    void traverse_tree(int level, vector<int> &v, TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (v.size() == level)
            v.push_back(root->val);
        else
            v[level] += root->val;

        if (root->left)
            traverse_tree(level + 1, v, root->left);
        if (root->right)
            traverse_tree(level + 1, v, root->right);
    }

    int maxLevelSum(TreeNode *root)
    {
        vector<int> v;
        traverse_tree(0, v, root);

        int n = v.size();
        int val = v[0];
        int idx = 0;
        for (int i = 1; i < n; i++)
            if (v[i] > val)
            {
                val = v[i];
                idx = i;
            }
        return idx + 1;
    }
};
// @lc code=end

// Note: tree + dfs