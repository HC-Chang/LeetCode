/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * setruct TreeNode {
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
    TreeNode *dfs(TreeNode *node, bool is_root, unordered_set<int> &set,
                  vector<TreeNode *> &ans)
    {
        if (!node)
            return nullptr;

        bool deleted = set.count(node->val);

        if (is_root && !deleted)
            ans.push_back(node);

        node->left = dfs(node->left, deleted, set, ans);
        node->right = dfs(node->right, deleted, set, ans);

        return deleted ? nullptr : node;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        dfs(root, true, set, ans);
        return ans;
    }
};
// @lc code=end
