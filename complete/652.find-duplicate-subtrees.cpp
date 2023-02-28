/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    unordered_map<string, int> count;
    vector<TreeNode *> ans;
    string dfs(TreeNode *root)
    {
        if (!root)
            return "#";
        auto str = "(" + to_string(root->val) + dfs(root->left) + dfs(root->right) + ")";
        if (++count[str] == 2)
            ans.push_back(root);
        return str;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
// @lc code=end
