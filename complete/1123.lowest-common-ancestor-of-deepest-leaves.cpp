/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
    pair<TreeNode *, int> dfs(TreeNode *root)
    {
        if (!root)
        {
            return {nullptr, 0};
        }

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        if (l.second > r.second)
        {
            return {l.first, l.second + 1};
        }
        if (l.second < r.second)
        {
            return {r.first, r.second + 1};
        }
        return {root, l.second + 1};
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root) { return dfs(root).first; }
};
// @lc code=end

// Note; hash table + tree + DFS